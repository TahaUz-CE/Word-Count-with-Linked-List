#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

typedef struct struct_kelime_t
{
    char *veri;
    int kelimaSayaci;
    struct struct_kelime_t* sonraki;
} kelime_t;


kelime_t* bagilListe_kelime_t(char* kelime)
{
    int uzunluk = strlen(kelime);

    kelime_t* yeniKelime = malloc(sizeof(kelime_t));
    if (NULL != yeniKelime)
    {
        yeniKelime->veri = (char *)malloc((uzunluk)+1);
        strcpy(yeniKelime->veri, kelime);
        yeniKelime->veri[uzunluk]='\0';

        yeniKelime->kelimaSayaci = 1;

        yeniKelime->sonraki = NULL;
    }
    return yeniKelime;
}

kelime_t* kelimeEkle(kelime_t* kelimeListe, char* kelime)
{
    bool kontrol=false;
    kelime_t *temp=kelimeListe;

    while (temp != NULL)
    {
        if (strcmp(temp->veri, kelime) == 0)
        {
            kontrol=true;
            temp->kelimaSayaci = temp->kelimaSayaci+1;
            return kelimeListe;
        }
        else
        {
            temp = temp->sonraki;
        }
    }
    if (kontrol==false)
    {
        kelime_t* yeniKelime = bagilListe_kelime_t(kelime);
        if (NULL != yeniKelime)
        {
            yeniKelime->sonraki = kelimeListe;
        }
        return yeniKelime;
    }
}

kelime_t* kelimeSirala(kelime_t* kelimeListe,int eleman_sayisi)
{

    kelime_t *temp = kelimeListe;
    char *swap;
    int swap_1=0;
    for (int i=0; i<eleman_sayisi; i++)
    {
        temp = kelimeListe;
        while(temp->sonraki!=NULL)
        {
            if(temp->kelimaSayaci < temp->sonraki->kelimaSayaci)
            {
                swap=temp->sonraki->veri;
                swap_1=temp->sonraki->kelimaSayaci;
                temp->sonraki->veri=temp->veri;
                temp->sonraki->kelimaSayaci=temp->kelimaSayaci;
                temp->veri=swap;
                temp->kelimaSayaci = swap_1;
            }
            temp=temp->sonraki;
        }

    }
    return kelimeListe;
}

kelime_t* SonaKelimeEkle(kelime_t* kelimeListe, char* kelime)
{
    bool kontrol=false;
    kelime_t *temp=kelimeListe;

    while (temp->sonraki != NULL)
    {
        if (strcmp(temp->veri, kelime) == 0)
        {
            kontrol=true;
            temp->kelimaSayaci = temp->kelimaSayaci+1;
            printf("Girdiginiz Kelimenin Aynisi Bagil Listede oldugu icin kelimeniz araya eklenemedi sadece kelimenin sayaci arttirildi. !\n");
            return kelimeListe;
        }
        else
        {
            temp = temp->sonraki;
        }
    }
    if (strcmp(temp->veri, kelime) == 0)
    {
        kontrol=true;
        temp->kelimaSayaci = temp->kelimaSayaci+1;
        printf("Girdiginiz Kelimenin Aynisi Bagil Listede oldugu icin kelimeniz araya eklenemedi sadece kelimenin sayaci arttirildi. !\n");
        return kelimeListe;
    }
    if (kontrol==false)
    {
        kelime_t* yeniKelime = bagilListe_kelime_t(kelime);
        temp->sonraki = yeniKelime;
        printf("Kelime[%s] bagli listenin sonuna eklendi.\n",kelime);
        return kelimeListe;
    }
}

kelime_t* ArayaKelimeEkle(kelime_t* kelimeListe, char* kelime,char* ara)
{
    bool kontrol=false;
    int buldu=0;
    kelime_t *temp=kelimeListe;
    kelime_t *temp_2=kelimeListe;
    kelime_t *eskiList_Temp;

    while (temp_2 != NULL)
    {
        if (strcmp(temp_2->veri, ara) == 0)
        {
            buldu=1;
            break;
        }

        temp_2 = temp_2->sonraki;

    }

    if(buldu == 0)
    {
        printf("Normalde Bagli Listede Olan Girdiginiz Kelimeyi Yanlis Girdiniz Bagli Listede Yok!\n");
        return kelimeListe;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->veri, kelime) == 0)
        {
            kontrol=true;
            temp->kelimaSayaci = temp->kelimaSayaci+1;
            printf("Girdiginiz Kelimenin Aynisi Bagil Listede oldugu icin kelimeniz araya eklenemedi sadece kelimenin sayaci arttirildi. !\n");
            return kelimeListe;
        }
        else
        {
            temp = temp->sonraki;
        }
    }
    if (kontrol==false)
    {


        if(buldu == 1)
        {
            kelime_t* yeniKelime = bagilListe_kelime_t(kelime);
            eskiList_Temp=temp_2->sonraki;
            temp_2->sonraki=yeniKelime;
            yeniKelime->sonraki=eskiList_Temp;
            printf("Kelime[%s] bagli listenin [%s] kelimesinin sonrasina eklendi.\n",kelime,ara);

        }

        return kelimeListe;
    }
}

kelime_t* basaKelimeEkle(kelime_t* kelimeListe, char* kelime)
{
    bool kontrol=false;
    kelime_t *temp=kelimeListe;

    while (temp != NULL)
    {
        if (strcmp(temp->veri, kelime) == 0)
        {
            kontrol=true;
            temp->kelimaSayaci = temp->kelimaSayaci+1;
            printf("Girdiginiz Kelimenin Aynisi Bagil Listede oldugu icin kelimeniz araya eklenemedi sadece kelimenin sayaci arttirildi. !\n");
            return kelimeListe;
        }
        else
        {
            temp = temp->sonraki;
        }
    }
    if (kontrol==false)
    {
        kelime_t* yeniKelime = bagilListe_kelime_t(kelime);


        yeniKelime->sonraki=kelimeListe;
        printf("Kelime[%s] bagli listenin basina eklendi.\n",kelime);

        return yeniKelime;
    }
}


int main()
{
    setlocale(LC_ALL,"Turkish");

    kelime_t *mykelime_t;
    mykelime_t=NULL;

    FILE *myFile;

    myFile = fopen("Metin.txt", "r");
    if (myFile==0)
    {
        printf("Dosya Bulunamadi.\n");
        return 1;
    }


    int ch = 0, kelime = 1, k = 0;
    char kelime_tut[100];

    while ((ch = fgetc(myFile)) != EOF )
    {

        if (ch == ' ' || ch == '\n')
        {

            if ( kelime == 1 )
            {
                kelime = 0;
                kelime_tut[k] = '\0';
                mykelime_t = kelimeEkle(mykelime_t, kelime_tut);
                k=0;
            }
        }
        else
        {
            kelime = 1;
            kelime_tut[k] = tolower(ch);
            k++;
        }
    }
    if (kelime == 1)
    {
        kelime_tut[k] = '\0';
        mykelime_t = kelimeEkle(mykelime_t, kelime_tut);
    }

    kelime_t *currword3;

    int kullanici_giris_menu = 1;
    printf("*****************************************************\n");
    printf("BAGLI LISTE ILE KELIME SAYMA PROGRAMINA HOSGELDINIZ\n");
    while(kullanici_giris_menu != 6)
    {
        currword3 = mykelime_t;
        printf("*****************************************************\n");
        printf("----------------ANA MENU----------------\n");
        printf("*****************************************************\n");
        printf("1-)Bagli Listeyi Goster\n");
        printf("2-)Bagli Listenin Basina Kelime Ekle\n");
        printf("3-)Bagli Listenin Arasina Kelime Ekle\n");
        printf("4-)Bagli Listenin Sonuna Kelime Ekle\n");
        printf("5-)Bagli Listeyi Buyukten Kucuge Dogru Sirala\n");
        printf("6-)Programdan Cikis\n");
        printf("*****************************************************\n");

        printf("Lutfen Deger Giriniz [1-6 arasi rakam giriniz!]: ");
        scanf("%d",&kullanici_giris_menu);
        printf("*****************************************************\n");

        int elemanSayisi=0;
        while(currword3->sonraki != NULL)
        {
            elemanSayisi++;
            currword3 = currword3->sonraki;
        }

        elemanSayisi++;
        kelime_t *listeSirala;
        listeSirala = mykelime_t;

        kelime_t *temp_listeSirala;
        temp_listeSirala = listeSirala;
        if(kullanici_giris_menu == 1)
        {
            int sira=1;
            printf("----------------BAGLI LISTE----------------\n");
            printf("*****************************************************\n");
            while(temp_listeSirala->sonraki != NULL)
            {
                printf("%d-)%s -->  %d\n",sira,temp_listeSirala->veri,temp_listeSirala->kelimaSayaci);
                temp_listeSirala = temp_listeSirala->sonraki;
                sira++;
            }
            printf("%d-)%s -->  %d\n",sira,temp_listeSirala->veri,temp_listeSirala->kelimaSayaci);


        }
        else if(kullanici_giris_menu == 2)
        {
            char kullanici_kelime[20];
            printf("Bagli Listeye Ekliceginiz Kelimeyi Giriniz : ");
            scanf("%s",&kullanici_kelime);
            for(int i = 0;i<20;i++){
                kullanici_kelime[i] = tolower(kullanici_kelime[i]);
            }
            mykelime_t = basaKelimeEkle(mykelime_t, kullanici_kelime);


        }
        else if(kullanici_giris_menu == 3)
        {
            char kullanici_kelime[20];
            char kullanici_kelime_sec[20];
            printf("Bagli Listeye Ekliceginiz Kelimeyi Giriniz : ");
            scanf("%s",&kullanici_kelime);
            printf("Bagli Listeye Hangi Kelimeden Sonra Eklesin : ");
            scanf("%s",&kullanici_kelime_sec);
            for(int i = 0;i<20;i++){
                kullanici_kelime[i] = tolower(kullanici_kelime[i]);
            }
            mykelime_t = ArayaKelimeEkle(mykelime_t, kullanici_kelime,kullanici_kelime_sec);

        }
        else if(kullanici_giris_menu == 4)
        {
            char kullanici_kelime[20];
            printf("Bagli Listeye Ekliceginiz Kelimeyi Giriniz : ");
            scanf("%s",&kullanici_kelime);
            for(int i = 0;i<20;i++){
                kullanici_kelime[i] = tolower(kullanici_kelime[i]);
            }
            mykelime_t = SonaKelimeEkle(mykelime_t, kullanici_kelime);


        }
        else if(kullanici_giris_menu == 5)
        {
            listeSirala = kelimeSirala(listeSirala,elemanSayisi);
            printf("Listeniz Basariyla Siralandi Lutfen Yeni Listeyi Gormek Icin Tekrar 'Bagli Listeyi Goster' secenegini seciniz .\n");
        }
        else if(kullanici_giris_menu == 6)
        {
            printf("Program Sona Erdi.");
        }
        else
        {
            printf("Hatali Bir Deger Girdiniz[1-6 arasi rakam giriniz!]\n");
        }

    }


    return 0;

}

