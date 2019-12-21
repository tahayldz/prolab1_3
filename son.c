#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct liste
{
    int plaka;
    char isim[30];
    char bolge[3];
    int komsuSayisi;

    struct liste *next;
    struct liste *prev;
};

struct komsu
{
    int plaka[10];
    char **isim[20][100];
    int tutulanIl;
    int komsuSay;

    struct komsu *next;

};
struct liste *ilk=NULL,*son=NULL;
struct komsu *ilkK=NULL,*sonK=NULL;
void listeOku()
{

    int virgul=0,i,j;
    char dizi[10][30];
    FILE *dosya,*dosya2;
    dosya=fopen("sehirler.txt","r");

    if(dosya == NULL)
    {
        printf("Acilamadi!\n");
    }
    else
    {
        while (!feof (dosya))
        {

            char *satirOku, *satirTut;
            char satir[90];

            struct liste *yeni=(struct liste*) malloc(sizeof(struct liste));
            struct komsu *komsu=(struct komsu*) malloc(sizeof(struct liste));

            satirOku=fgets(satir,90,dosya);

            for(i=0; i<strlen(satir); i++)
            {
                if(satir[i]==',')
                {
                    virgul++;
                }
            }

            satirTut = strtok(satir,",");

            sscanf(satirTut,"%d",&yeni->plaka);
            satirTut = strtok(NULL,",");
            sscanf(satirTut,"%s",&yeni->isim);
            satirTut = strtok(NULL,",");
            sscanf(satirTut,"%s",&yeni->bolge);
            yeni->komsuSayisi=virgul-2;
            virgul=0;

            for(i=0; i<yeni->komsuSayisi; i++)
            {
                satirTut=strtok(NULL,",");
                memcpy(komsu->isim[i],satirTut,strlen(satirTut)+1);
            }

            for(i=0; i<yeni->komsuSayisi; i++)
            {
                printf("%s ",komsu->isim[i]);
            }
            komsu->tutulanIl=yeni->plaka;
            komsu->komsuSay=yeni->komsuSayisi;

            if(ilk==NULL)
            {
                ilk=yeni;
                son=yeni;
                son->next=NULL;
                son->prev=son;


                ilkK=komsu;
                sonK=komsu;
                sonK->next=NULL;


            }
            else
            {
                son->next=yeni;
                yeni->prev=son;
                yeni->next=NULL;
                son=yeni;


                sonK->next=komsu;
                sonK=komsu;
                sonK->next=NULL;

            }


        }

    }
}

void KomsuListeOku()
{
    FILE *dosya2;
    char *satirOku,satir[90],*satirTut;
    char dizi[10][30];
    dosya2=fopen("sehirler.txt","r");

    if(dosya2==NULL)
    {
        printf("acilamadi.");
    }
    else
    {
        while(!feof(dosya2))
        {
            int i;

            struct liste *devam = ilk;
            satirOku=fgets(satir,90,dosya2);
            satirTut = strtok(satir,",");
            satirTut = strtok(NULL,",");
            satirTut = strtok(NULL,",");


        }
    }
}



void printList()
{
    int i;
    FILE *yaz;
    yaz=fopen("OUTPUT.txt","a+");
    struct liste *current = ilk;
    while (current -> next!= NULL)
    {
        printf("%d,",current->plaka);
        printf("%s,",current->isim);
        printf("%s,",current->bolge);
        printf("%d,",current->komsuSayisi);




        printf("\n");
        printf(" |     /|\\\n");
        printf("\\|/     |\n");



        fprintf(yaz,"%d,",current->plaka);
        fprintf(yaz,"%s,",current->isim);
        fprintf(yaz,"%s,",current->bolge);
        fprintf(yaz,"%d\n",current->komsuSayisi);
        fprintf(yaz," |     /|\\\n");
        fprintf(yaz,"\\|/     |\n");

        current = current -> next;
    }
    printf("%d,",current->plaka);
    printf("%s,",current->isim);
    printf("%s,",current->bolge);
    printf("%d,",current->komsuSayisi);

    fprintf(yaz,"%d,",current->plaka);
    fprintf(yaz,"%s,",current->isim);
    fprintf(yaz,"%s,",current->bolge);
    fprintf(yaz,"%d\n",current->komsuSayisi);


}

void komsuList()
{

    struct komsu *komsu = ilkK;

    struct komsu *gecici= ilkK;
    int i=0;

   while(komsu != NULL){


        for(i=0;i<komsu->komsuSay;i++){

            struct liste *devam = ilk;
           int j=0;
            while(devam !=NULL){
                    if(strcmp(komsu->isim[i],devam->isim)==0){

                        komsu->plaka[j]=devam->plaka;
                        printf("%d ",komsu->plaka[j]);
                        j++;
                        i++;

                    }


                devam=devam->next;
            }

            printf("\n");
        }

    komsu = komsu->next;
   }

   while(gecici !=NULL){
    for(i=0;i<gecici->komsuSay;i++){
        printf("%d ",gecici->plaka[i]);
    }
    gecici=gecici->next;
   }





}


int main()
{

    listeOku();

    int a;

    printf("1- Listede olan illeri ve bilgilerini ekrana yazar.\n");

    scanf("%d",&a);
    if(a==1)
        printList();
    if(a==2)
        komsuList();










    return 0;
}
