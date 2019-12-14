#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste
{
    int plaka;
    char isim[30];
    char bolge[2];
    int komsuSayisi;
    struct liste *next;
    struct liste *prev;
} liste,head;

struct komsu
{
    char isim[30];
    int plaka[10];
    struct komsu *next;

};

liste *listeOku(liste *head)
{
    int virgul=0,i;
    FILE *dosya,*yaz;
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

            if (head == NULL)
            {
                head = malloc(sizeof(liste));



                satirOku=fgets(satir,90,dosya);

                for(i=0; i<strlen(satir); i++)
                {
                    if(satir[i]==',')
                    {
                        virgul++;
                    }
                }

                yaz=fopen("OUTPUT.txt","w+");

                 satirTut = strtok(satir,",");
                 sscanf(satirTut,"%d",&head->plaka);
                 printf("%d,", head -> plaka);
                 fprintf(yaz,"%d,", head -> plaka);
                 satirTut = strtok(NULL,",");
                 sscanf(satirTut,"%s",&head->isim);
                 printf("%s,", head -> isim);
                 fprintf(yaz,"%s,", head -> isim);
                 satirTut = strtok(NULL,",");
                 sscanf(satirTut,"%s",&head->bolge);
                 printf("%s,", head -> bolge);
                 fprintf(yaz,"%s,", head -> bolge);
                 head->komsuSayisi=virgul-2;
                 fprintf(yaz,"%d\n",head->komsuSayisi);
                 printf("%d\n",head->komsuSayisi);
                     fprintf(yaz," |     /|\\\n");
                     fprintf(yaz,"\\|/     |\n");
                 virgul=0;
                 head -> next=NULL;
            }
            else
            {
                struct liste *current = head;
            struct liste *temp = malloc(sizeof(liste));

                while(current -> next != NULL)
                {
                    current = current -> next;
                }

                 if(temp->next !=NULL)
                 {
                     satirOku=fgets(satir,90,dosya);
                     for(i=0; i<strlen(satir); i++)
                     {
                         if(satir[i]==',')
                         {
                             virgul++;
                         }
                     }

                     yaz=fopen("OUTPUT.txt","a+");
                     satirTut = strtok(satir,",");
                     sscanf(satirTut,"%d",&temp->plaka);
                     printf("%d,", temp -> plaka);
                     fprintf(yaz,"%d,", temp -> plaka);
                     satirTut = strtok(NULL,",");
                     sscanf(satirTut,"%s",&temp->isim);
                     printf("%s,", temp -> isim);
                     fprintf(yaz,"%s,", temp -> isim);
                     satirTut = strtok(NULL,",");
                     sscanf(satirTut,"%s",&temp->bolge);
                     printf("%s,", temp -> bolge);
                     fprintf(yaz,"%s,", temp -> bolge);
                     temp->komsuSayisi=virgul-2;

                     printf("%d\n",temp->komsuSayisi);
                     fprintf(yaz,"%d\n",temp->komsuSayisi);
                     fprintf(yaz," |     /|\\\n");
                     fprintf(yaz,"\\|/     |\n");
                     virgul=0;


                 }
                 current -> next = temp;
                 temp -> next = NULL;





            }
        }

    }
    return head;
}
void printList(liste *head)
{
    liste *current = head;
    while (current != NULL)
    {
       printf("%d,",current->plaka);
       printf("%s,",current->isim);
       printf("%s,",current->bolge);
       printf("%d\n",current->komsuSayisi);
        current = current -> next;
    }






    return;
}

int main()
{

    liste *A = NULL;
    A=listeOku(A);
    printList(A);


    return 0;
}
