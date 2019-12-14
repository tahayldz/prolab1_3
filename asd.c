#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste
{
    int plaka;
    char isim[30];
    char bolge[3];
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
                satirTut = strtok(NULL,",");
                sscanf(satirTut,"%s",&head->isim);
                satirTut = strtok(NULL,",");
                sscanf(satirTut,"%s",&head->bolge);
                head->komsuSayisi=virgul-2;
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
                    satirTut = strtok(NULL,",");
                    sscanf(satirTut,"%s",&temp->isim);
                    satirTut = strtok(NULL,",");
                    sscanf(satirTut,"%s",&temp->bolge);
                    temp->komsuSayisi=virgul-2;
                    virgul=0;
                }
                current -> next = temp;
                temp -> next = NULL;

            }
        }

    }
    return head;
}
liste *printList(liste *head)
{

    liste *current = head;
    while (current != NULL)
    {
        printf("%d,",current->plaka);
        printf("%s,",current->isim);
        printf("%s,",current->bolge);
        printf("%d\n",current->komsuSayisi);
        printf(" |     /|\\\n");
        printf("\\|/     |\n");

        current = current -> next;
    }

    return;
}

int main()
{

    liste *A = listeOku(A);

    printList(A);



    return 0;
}
