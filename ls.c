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

    struct komsu *next;
    struct komsu *prev;

};
struct liste *ilk=NULL,*son=NULL;
struct komsu *ilkK=NULL,*sonK=NULL;
void listeOku()
{

    int virgul=0,i;
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
            if(ilk==NULL)
            {
                ilk=yeni;
                son=yeni;
                son->next=NULL;
                son->prev=son;
            }
            else
            {
                son->next=yeni;
                yeni->prev=son;
                yeni->next=NULL;
                son=yeni;
            }


        }

    }

    dosya2=fopen("sehirler.txt","r");
    if(dosya2 == NULL)
    {
        printf("Acilamadi!\n");
    }
    else
    {

        while (!feof (dosya2))
        {

            char *satirOku, *satirTut;
            char satir[90];

            struct komsu *yeni=(struct komsu*) malloc(sizeof(struct komsu));


            satirOku=fgets(satir,90,dosya2);

            satirTut = strtok(satir,",");
            satirTut = strtok(NULL,",");
            satirTut = strtok(NULL,",");
            struct liste *devam = ilk;
            struct liste *gecici=ilk;
             int a=0;
            while(devam !=NULL)
            {

                int j=0;
                int tempDizi[10];
                for(i=0; i<devam->komsuSayisi; i++)
                {
                     satirTut = strtok(NULL,",");

                    while(gecici!= NULL)
                    {

                        if(strcmp(satirTut,gecici->isim)==0)
                        {
                            printf("%s ",satirTut);

                        }

                        gecici=gecici->next;
                    }

                }

                devam = devam->next;
            }


            if(ilkK==NULL)
            {
                ilkK=yeni;
                sonK=yeni;
                sonK->next=NULL;
                sonK->prev=sonK;
            }
            else
            {
                sonK->next=yeni;
                yeni->prev=sonK;
                yeni->next=NULL;
                sonK=yeni;
            }
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
    printf("%d\n",current->komsuSayisi);
    fprintf(yaz,"%d,",current->plaka);
    fprintf(yaz,"%s,",current->isim);
    fprintf(yaz,"%s,",current->bolge);
    fprintf(yaz,"%d\n",current->komsuSayisi);


}

void komsuList()
{

    struct komsu *komsu = ilkK;
    struct liste *devam = ilk;
    struct liste *gecici= ilk;
    int i;
    while(devam !=NULL)
    {
        int j=0;
        for(i=0; i<devam->komsuSayisi; i++)
        {



                printf("%d ",komsu->plaka[j]);
                j++;



        }
           printf("\n");

        devam = devam->next;
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
