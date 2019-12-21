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

struct liste *ilk=NULL,*son=NULL;

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
int main()
{

    listeOku();

    int a;

        printf("1- Listede olan illeri ve bilgilerini ekrana yazar.\n");

        scanf("%d",&a);
        if(a==1)
            printList();











    return 0;
}
