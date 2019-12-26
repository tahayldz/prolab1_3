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
    struct komsu *gecici = ilkK;
    int i=0;
    int a=99;
    while(gecici !=NULL)
    {
        for(i=0; i<10; i++)
        {
            gecici->plaka[i]=99;
        }
        gecici=gecici->next;
    }

    while(komsu != NULL)
    {
        int j=0;
        for(i=0; i<10; i++)
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
        diziSirala(komsu->plaka,10);
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
    struct liste *dolas, *adim=ilk;
    int temPlaka, temKomsuSayisi;
    char temIsim[30];
    char  temBolge[3];
    while(adim!=son)
    {
        dolas=ilk;
        while(dolas!=son)
        {
            if(dolas->plaka > dolas->next->plaka)
            {
                temPlaka=dolas->plaka;
                dolas->plaka=dolas->next->plaka;
                dolas->next->plaka=temPlaka;

                temKomsuSayisi=dolas->komsuSayisi;
                dolas->komsuSayisi=dolas->next->komsuSayisi;
                dolas->next->komsuSayisi=temKomsuSayisi;


                memcpy(temIsim,dolas->isim,30);
                memcpy(dolas->isim,dolas->next->isim,30);
                memcpy(dolas->next->isim,temIsim,30);

                memcpy(temBolge,dolas->bolge,3);
                memcpy(dolas->bolge,dolas->next->bolge,3);
                memcpy(dolas->next->bolge,temBolge,3);
            }
            dolas=dolas->next;
        }
        adim=adim->next;
    }

}

void komsuSirala()
{
    struct komsu *dolas, *adim=ilkK;
    int temp[10];
    int temp2;
    int temp3;
    int i;
    while(adim!=sonK)
    {

        dolas=ilkK;
        while(dolas!=sonK)
        {
            if(dolas->tutulanIl > dolas->next->tutulanIl)
            {
                temp2=dolas->tutulanIl;
                dolas->tutulanIl=dolas->next->tutulanIl;
                dolas->next->tutulanIl=temp2;

                temp3=dolas->komsuSay;
                dolas->komsuSay=dolas->next->komsuSay;
                dolas->next->komsuSay=temp3;

                memcpy(temp,dolas->plaka,10);
                memcpy(dolas->plaka,dolas->next->plaka,10);
                memcpy(dolas->next->plaka,temp,10);

            }
            dolas=dolas->next;
        }
        adim=adim->next;
    }
}
void komsuKriter(int x)
{
    struct liste *dolas=ilk;
    FILE *yaz;
    yaz=fopen("OUTPUT.txt","a+");
    while(dolas!=NULL)
    {
        if(dolas->komsuSayisi>x)
        {
            printf("%d,",dolas->plaka);
            printf("%s,",dolas->isim);
            printf("%s,",dolas->bolge);
            printf("%d\n",dolas->komsuSayisi);
            fprintf(yaz,"%d,",dolas->plaka);
            fprintf(yaz,"%s,",dolas->isim);
            fprintf(yaz,"%s,",dolas->bolge);
            fprintf(yaz,"%d\n",dolas->komsuSayisi);
        }
        dolas=dolas->next;
    }
}
void sehirAra(char c[30])
{
    int b,i,kontrol=0,plaka,komsuSayisi,komsuPlaka[10];
    char isim[30],bolge[3];
    struct liste *dolas=ilk;
    FILE *yaz;
    yaz=fopen("OUTPUT.txt","a+");
    struct komsu *komsu = ilkK;
    while(dolas!=NULL)
    {

        if(strcmp(c,dolas->isim)==0)
        {
            printf("%d,",dolas->plaka);
            printf("%s,",dolas->isim);
            printf("%s,",dolas->bolge);
            printf("%d\n",dolas->komsuSayisi);
            fprintf(yaz,"%d,",dolas->plaka);
            fprintf(yaz,"%s,",dolas->isim);
            fprintf(yaz,"%s,",dolas->bolge);
            fprintf(yaz,"%d\n",dolas->komsuSayisi);
            printf("Komsu illerin bilgileri:\n");
            fprintf(yaz,"Komsu illerin bilgileri:\n");
            for(int i=0; i<komsu->komsuSay; i++)
            {
                struct liste *dolas2=ilk;
                while(dolas2!=NULL)
                {
                    if(komsu->plaka[i]==dolas2->plaka)
                    {
                        printf("%d,",dolas2->plaka);
                        printf("%s,",dolas2->isim);
                        printf("%s,",dolas2->bolge);
                        printf("%d\n",dolas2->komsuSayisi);
                        fprintf(yaz,"%d,",dolas2->plaka);
                        fprintf(yaz,"%s,",dolas2->isim);
                        fprintf(yaz,"%s,",dolas2->bolge);
                        fprintf(yaz,"%d\n",dolas2->komsuSayisi);
                        break;
                    }
                    dolas2=dolas2->next;
                }
            }

            kontrol=1;
        }
        komsu=komsu->next;

        dolas=dolas->next;
    }
    printf("\n");
    fprintf(yaz,"\n");
    if(kontrol==0)
    {
        printf("Sehir listede yok eklemek icin 1'e Menuye donmek icin 0'a basiniz.\n ");
        scanf("%d",&b);
        if(b==1)
        {
            printf("Sehrin plakasi: ");
            scanf("%d",&plaka);
            printf("Sehrin ismi: ");
            scanf("%s",&isim);
            printf("Sehrin bulundugu bolge: ");
            scanf("%s",&bolge);
            printf("Sehrin komsu sayisi: "), scanf("%d",&komsuSayisi);
            printf("Sehrin komsularinin plakasi: ");
            for(i=0; i<komsuSayisi; i++)
            {
                scanf("%d",&komsuPlaka[i]);
            }
            ekle(plaka,isim,bolge,komsuSayisi,komsuPlaka);
        }
    }
}
void bolgeYaz(char c[3])
{
    struct liste *dolas=ilk;
    FILE *yaz;
    yaz=fopen("OUTPUT.txt","a+");
    while(dolas!=NULL)
    {

        if(strcmp(c,dolas->bolge)==0)
        {
            printf("%d,",dolas->plaka);
            printf("%s,",dolas->isim);
            printf("%s,",dolas->bolge);
            printf("%d\n",dolas->komsuSayisi);
            fprintf(yaz,"%d,",dolas->plaka);
            fprintf(yaz,"%s,",dolas->isim);
            fprintf(yaz,"%s,",dolas->bolge);
            fprintf(yaz,"%d\n",dolas->komsuSayisi);

        }


        dolas=dolas->next;
    }
    printf("\n");
    fprintf(yaz,"\n");


}




void plakaAra(int a)
{

    int b,i,kontrol=0,plaka,komsuSayisi,komsuPlaka[10];
    char isim[30],bolge[3];
    struct liste *dolas=ilk;

    FILE *yaz;
    yaz=fopen("OUTPUT.txt","a+");
    struct komsu *komsu = ilkK;
    while(dolas!=NULL)
    {

        if(dolas->plaka==a)
        {
            printf("%d,",dolas->plaka);
            printf("%s,",dolas->isim);
            printf("%s,",dolas->bolge);
            printf("%d\n",dolas->komsuSayisi);
            fprintf(yaz,"%d,",dolas->plaka);
            fprintf(yaz,"%s,",dolas->isim);
            fprintf(yaz,"%s,",dolas->bolge);
            fprintf(yaz,"%d\n",dolas->komsuSayisi);
            printf("Komsu illerin bilgileri:\n");
            fprintf(yaz,"Komsu illerin bilgileri:\n");
            for(int i=0; i<komsu->komsuSay; i++)
            {
                struct liste *dolas2=ilk;
                while(dolas2!=NULL)
                {
                    if(komsu->plaka[i]==dolas2->plaka)
                    {
                        printf("%d,",dolas2->plaka);
                        printf("%s,",dolas2->isim);
                        printf("%s,",dolas2->bolge);
                        printf("%d\n",dolas2->komsuSayisi);
                        fprintf(yaz,"%d,",dolas2->plaka);
                        fprintf(yaz,"%s,",dolas2->isim);
                        fprintf(yaz,"%s,",dolas2->bolge);
                        fprintf(yaz,"%d\n",dolas2->komsuSayisi);
                        break;
                    }
                    dolas2=dolas2->next;
                }
            }

            kontrol=1;
        }
        komsu=komsu->next;

        dolas=dolas->next;
    }
    printf("\n");
    fprintf(yaz,"\n");
    if(kontrol==0)
    {
        printf("Sehir listede yok eklemek icin 1'e cikmak icin 0'a basiniz.\n ");
        scanf("%d",&b);
        if(b==1)
        {
            printf("Sehrin plakasi: ");
            scanf("%d",&plaka);
            printf("Sehrin ismi: ");
            scanf("%s",&isim);
            printf("Sehrin bulundugu bolge: ");
            scanf("%s",&bolge);
            printf("Sehrin komsu sayisi: "), scanf("%d",&komsuSayisi);
            printf("Sehrin komsularinin plakasi: ");
            for(i=0; i<komsuSayisi; i++)
            {
                scanf("%d",&komsuPlaka[i]);
            }
            ekle(plaka,isim,bolge,komsuSayisi,komsuPlaka);
        }
    }
}
void ekle(int plaka, char isim[30], char bolge[3], int komsuSayisi, int komsuPlaka[10])
{
    struct liste *yeni=(struct liste*) malloc(sizeof(struct liste));
    struct komsu *komsu=(struct komsu*) malloc(sizeof(struct komsu));
    int i;
    yeni->plaka=plaka;
    memcpy(yeni->isim,isim,30);
    memcpy(yeni->bolge,bolge,3);
    yeni->komsuSayisi=komsuSayisi;
    komsu->tutulanIl=plaka;
    komsu->komsuSay=komsuSayisi;
    for(i=0; i<komsu->komsuSay; i++)
    {
        komsu->plaka[i]=komsuPlaka[i];
    }
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
int main()
{

    listeOku();
    komsuList();
    Sirala();
    komsuSirala();
    int a,x,b,i,plaka,plaka2,komsuSayisi,komsuPlaka[10],s;
    char bolge[3],bolge2[3],isim[30];


    while(1)
    {


        printf("1- Listede olan illeri ve bilgilerini ekrana yazar.\n");
        printf("2- Listeden sehir siler.\n");
        printf("3- Listeye sehir ekler.\n");
        printf("4- Komsu sayisina gore Il listeleme.\n");
        printf("5- Girilen bolgenin illerinin bilgilerini listeler\n");
        printf("6- Arama\n");
        printf("7- Programi sonlandirir.\n");
        scanf("%d",&a);
        if(a==1)
            printList();
        if(a==2)
        {
            printf("silmek istediginiz sehrin plakasini girin: ");
            scanf("%d",&s);
            Sil(s);
            komsuSil(s);

        }
        if(a==3)
        {
            printf("Sehrin plakasi: ");
            scanf("%d",&plaka);
            printf("Sehrin ismi: ");
            scanf("%s",&isim);
            printf("Sehrin bulundugu bolge: ");
            scanf("%s",&bolge);
            printf("Sehrin komsu sayisi: "), scanf("%d",&komsuSayisi);
            printf("Sehrin komsularinin plakasi: ");
            for(i=0; i<komsuSayisi; i++)
            {
                scanf("%d",&komsuPlaka[i]);
            }
            ekle(plaka,isim,bolge,komsuSayisi,komsuPlaka);
             Sirala();
            komsuSirala();
        }
        if(a==4)
        {
            printf("Kriteri giriniz:");
            scanf("%d",&x);
            komsuKriter(x);
        }
        if(a==5)
        {
            printf("Bolge ismi giriniz:");
            scanf("%s",&bolge2);
            bolgeYaz(bolge2);
        }
        if(a==6)
        {
            printf("Sehir aratmak icin 1'e,Plaka aratmak ici 2'ye basiniz:");
            scanf("%d",&b);
            if(b==1)
            {
                printf("Aranan Sehrin Ismi:");
                scanf("%s",&isim);
                sehirAra(isim);
            }
            if(b==2)
            {
                printf("Aranan Sehrin Plakasi:");
                scanf("%d",&plaka2);
                plakaAra(plaka2);

            }

        }
        if(a==7)
        {
            exit(1);
        }

    }
    return 0;
}
