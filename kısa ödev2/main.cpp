#include <stdio.h>
#include <stdbool.h>

// Yap� tan�mlamalar�
typedef struct {
    char isim[50];
    double teklif;
} Katilimci;

typedef struct {
    Katilimci katilimcilar[10]; // �rnek olarak 10 kat�l�mc� tutuyoruz
    int katilimci_sayisi;
} Artirma;

// Fonksiyon prototipleri
void acikarttirma(Artirma a);

int main() {
    // �rnek verilerle bir Artirma yap�s� olu�tural�m
    Artirma artirma;
    artirma.katilimci_sayisi = 0;

    char devam;

    do {
        // Kat�l�mc�n�n bilgilerini al
        printf("Katilimci Adi: ");
        scanf("%s", artirma.katilimcilar[artirma.katilimci_sayisi].isim);

        printf("Teklif: ");
        scanf("%lf", &artirma.katilimcilar[artirma.katilimci_sayisi].teklif);

        // Kat�l�mc� say�s�n� art�r
        artirma.katilimci_sayisi++;

        // Devam etmek isteyip istemedi�ini sor
        printf("Devam etmek istiyor musunuz? (E/e: Evet, H/h: Hayir): ");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');

    // A��k art�rmay� ger�ekle�tir
    acikarttirma(artirma);

    return 0;
}

// Fonksiyon tan�mlamalar�
void acikarttirma(Artirma a) {
    double enyuksek_teklif = -1.0;
    int kazanan_no = -1;

    for (int i = 0; i < a.katilimci_sayisi; ++i) {
        if (a.katilimcilar[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = a.katilimcilar[i].teklif;
            kazanan_no = i;
        }
    }

    printf("\nKazanan: %s\n", a.katilimcilar[kazanan_no].isim);
    printf("Teklif: %.2f\n", enyuksek_teklif);
}

