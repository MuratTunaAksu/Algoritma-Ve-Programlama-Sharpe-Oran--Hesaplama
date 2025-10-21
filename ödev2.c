
#include <stdio.h>

int main() {
    float yatirimGetirisi, risksizOran, standartSapma, sharpeOrani;

    // Burada kullanicidan yuzde olarak girdileri aliyoruz
    printf("Lutfen Yatirim Getirisini Yuzde Olarak Giriniz (Orn: 15): ");
    scanf("%f", &yatirimGetirisi);

    printf("Lutfen Risksiz Faiz Oranini Yuzde Olarak Giriniz (Orn: 5): ");
    scanf("%f", &risksizOran);

    printf("Lutfen Portfoyun Standart Sapmasini Yuzde Olarak Giriniz (Orn: 12): ");
    scanf("%f", &standartSapma);

    // Standart sapmanin 0 olma durumunu kontrol ettigimiz kisim
    if (standartSapma == 0) {
        printf("HATA: Standart Sapma (Risk) 0 olamaz. Hesaplama yapilamiyor.\n");
    } else {
        // Sharpe Orani Formulu: (Yatirim Getirisi - Risksiz Faiz Orani) / Standart Sapma
        sharpeOrani = (yatirimGetirisi - risksizOran) / standartSapma;

        // Sonucu ekrana yazdiriyoruz
        printf("\n----------------------------------\n");
        printf("Hesaplanan Sharpe Orani: %.2f\n", sharpeOrani);
        printf("----------------------------------\n");

        // Sonucu ses dosyasindaki kriterlere gore yorumla
        if (sharpeOrani >= 3) {
            printf("Yorum: Mukemmel. (3'un uzeri)\n");
        } else if (sharpeOrani >= 2) {
            printf("Yorum: Cok Iyi. (2'nin uzeri)\n");
        } else if (sharpeOrani >= 1) {
            printf("Yorum: Iyi. (1'in uzeri)\n");
        } else {
            printf("Yorum: 1'in altinda. Risk-getiri performansi 'iyi' kabul edilen seviyenin altinda.\n");
        }
    }

    return 0;
}
