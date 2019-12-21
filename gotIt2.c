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
    struct komsu *prev;

};
struct liste *ilk=NULL,*son=NULL;
struct komsu *ilkK=NULL,*sonK=NULL;
void listeOku()
{

    int virgul=0,i;
    FILE *dosya;
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
            struct komsu *komsu=(struct komsu*) malloc(sizeof(struct komsu));

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

            for(i=0; i<yeni->komsuSayisi-1; i++)
            {
                satirTut=strtok(NULL,",");
                memcpy(komsu->isim[i],satirTut,strlen(satirTut)+1);
            }
            satirTut=strtok(NULL,"\n");
            memcpy(komsu->isim[yeni->komsuSayisi-1],satirTut,strlen(satirTut)+1);
            for(i=0; i<yeni->komsuSayisi; i++)
            {

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
                sonK->prev=sonK;


            }
            else
            {
                son->next=yeni;
                yeni->prev=son;
                yeni->next=NULL;
                son=yeni;


                sonK->next=komsu;
                komsu->prev=sonK;
                komsu->next=NULL;
                sonK=komsu;


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
    struct komsu *komsu = ilkK;
    while (current -> next!= NULL)
    {
        printf("%d,",current->plaka);
        printf("%s,",current->isim);
        printf("%s,",current->bolge);
        printf("%d,",current->komsuSayisi);
        for(i=0; i<komsu->komsuSay; i++)
        {
            printf("->%d",komsu->plaka[i]);
        }

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
        komsu = komsu->next;
    }
    printf("%d,",current->plaka);
    printf("%s,",current->isim);
    printf("%s,",current->bolge);
    printf("%d,",current->komsuSayisi);
    for(i=0; i<komsu->komsuSay; i++)
    {
        printf("->%d",komsu->plaka[i]);
    }
    printf("\n");
    fprintf(yaz,"%d,",current->plaka);
    fprintf(yaz,"%s,",current->isim);
    fprintf(yaz,"%s,",current->bolge);
    fprintf(yaz,"%d\n",current->komsuSayisi);


}

void komsuList()
{

    struct komsu *komsu = ilkK;
    int i=0;

    while(komsu != NULL)
    {
        int j=0;
        for(i=0; i<komsu->komsuSay; i++)
        {
            struct liste *devam = ilk;
            while(devam != NULL)
            {
                if(strcmp(devam->isim,komsu->isim[i])==0)
                {
                    komsu->plaka[j]=devam->plaka;
                    j++;
                }
                devam = devam->next;
            }
        }
        diziSirala(komsu->plaka,komsu->komsuSay);
        komsu = komsu->next;
    }
}

void diziSirala(int dizi[], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(dizi[i]>dizi[j])
            {
                int temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }


}

void Sil(int x)
{
    struct liste *sil=ilk;
    int sayac=0;
    while(sil!=NULL)
    {
        if(sil->plaka==x)
        {
            sayac=1;
            break;
        }

        else
        {
            sil=sil->next;
        }

    }
    if(sayac==0)
    {
        printf("Girilen plakali sehir listede yok.\n");
    }
    if(sil!=NULL)
    {
        if(sil==ilk)
        {
            sil->prev->next=sil->next;
            sil->next->prev=NULL;
            ilk=ilk->next;

        }
        else if(sil==son)
        {
            sil->prev->next=NULL;
            sil->prev=son;
            son=son->prev;

        }
        else
        {
            sil->prev->next=sil->next;
            sil->next->prev=sil->prev;

        }
        free(sil);
    }

}

void komsuSil(int x)
{
    struct komsu *sil=ilkK;

    while(sil!=NULL)
    {
        if(sil->tutulanIl==x)
        {

            break;
        }

        else
        {
            sil=sil->next;
        }

    }
    if(sil!=NULL)
    {
        if(sil==ilkK)
        {
            sil->prev->next=sil->next;
            sil->next->prev=NULL;
            ilkK=ilkK->next;
        }
        else if(sil==sonK)
        {
            sil->prev->next=NULL;
            sil->prev=sonK;
            sonK=sonK->prev;
        }
        else
        {
            sil->prev->next=sil->next;
            sil->next->prev=sil->prev;

        }
        free(sil);
    }

}

void Sirala()
{
    struct liste *dolas, *adim;
    struct liste *tmp,*nextNode;

    for(adim = ilk; adim != NULL ; adim = adim->next)
    {
        for(dolas = adim; dolas != NULL; dolas = dolas->next)
        {


            if(dolas->plaka > dolas->next->plaka)
            {

                nextNode = dolas->next;
                tmp = dolas->prev;

                if(tmp)
                    tmp->next=nextNode;

                if(nextNode->next)
                    nextNode->next->prev=dolas;

                dolas->next=nextNode->next;
                dolas->prev=nextNode->prev;
                nextNode->next=dolas;
                nextNode->prev=tmp;
                printf("noluyo");
            }

        }

    }

}




int main()
{

    listeOku();
    komsuList();

    int a,x;


    while(1)
    {


        printf("1- Listede olan illeri ve bilgilerini ekrana yazar.\n");
        printf("2- Listeden sehir siler.\n");
        printf("3- Listeye sehir ekler.\n");
        printf("4- SIRALA\n");
        printf("5- Programi sonlandirir.\n");
        scanf("%d",&a);
        if(a==1)
            printList();
        if(a==2)
        {
            printf("silmek istediginiz sehrin plakasini girin: ");
            scanf("%d",&x);
            Sil(x);
            komsuSil(x);
        }
        if(a==4)
        {
            Sirala();
        }
        if(a==5)
        {
            exit(1);
        }

    }
    return 0;
}
