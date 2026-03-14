#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[20];
    int berat[100];
    char kota[100][10];
    int total_paket = 0;

    printf("==========================================\n");
    printf("     SISTEM PENGIRIMAN DEL-EXPRESS\n");
    printf("==========================================\n");
    printf("Format Input: [Berat] lalu [Kode Kota]\n");
    printf("Ketik 'END' untuk mengakhiri inputan.\n\n");

    // Loop untuk menerima input terus menerus sampai "END"
    while (1) {
        // Membaca input berat paket atau perintah END
        scanf("%s", input);
        if (strcmp(input, "END") == 0) {
            break;
        }
        berat[total_paket] = atoi(input);

        // Membaca input kode kota atau perintah END
        scanf("%s", input);
        if (strcmp(input, "END") == 0) {
            break;
        }
        strcpy(kota[total_paket], input);

        total_paket++;
    }

    // Variabel untuk perhitungan
    int total_berat = 0;
    double total_ongkos = 0;
    int dapat_asuransi = 0; // Flag asuransi (0 = tidak, 1 = ya)

    printf("\n==========================================\n");
    printf("       STRUK PEMBAYARAN DEL-EXPRESS       \n");
    printf("==========================================\n");

    // Proses data setiap paket yang dimasukkan
    for (int i = 0; i < total_paket; i++) {
        char nama_kota[20];
        char keterangan[20];
        int harga_per_kg = 0;

        // Pencocokan Kode Kota
        if (strcmp(kota[i], "MDN") == 0) {
            strcpy(nama_kota, "Medan");
            strcpy(keterangan, "Dalam Pulau");
            harga_per_kg = 8000;
        } else if (strcmp(kota[i], "BLG") == 0) {
            strcpy(nama_kota, "Balige");
            strcpy(keterangan, "Dalam Pulau");
            harga_per_kg = 5000;
        } else if (strcmp(kota[i], "JKT") == 0) {
            strcpy(nama_kota, "Jakarta");
            strcpy(keterangan, "Luar Pulau");
            harga_per_kg = 12000;
            dapat_asuransi = 1; // Memenuhi syarat asuransi gratis
        } else if (strcmp(kota[i], "SBY") == 0) {
            strcpy(nama_kota, "Surabaya");
            strcpy(keterangan, "Luar Pulau");
            harga_per_kg = 13000;
            dapat_asuransi = 1; // Memenuhi syarat asuransi gratis
        } else {
            strcpy(nama_kota, "Tidak Diketahui");
            strcpy(keterangan, "-");
            harga_per_kg = 0;
        }

        // Kalkulasi ongkos per paket
        int ongkos_paket = berat[i] * harga_per_kg;
        total_berat += berat[i];
        total_ongkos += ongkos_paket;

        // Penamaan pengirim sesuai contoh instruksi
        char nama_pengirim[20];
        if (i == 0) strcpy(nama_pengirim, "Butet");
        else if (i == 1) strcpy(nama_pengirim, "Ucok");
        else sprintf(nama_pengirim, "Pengirim %d", i + 1);

        // Cetak detail per paket
        printf("Kota Tujuan          : %s (%s)\n", nama_kota, keterangan);
        printf("Berat Paket %-8s : %d kg\n", nama_pengirim, berat[i]);
        printf("Ongkos Kirim         : Rp %d\n", ongkos_paket);
        printf("------------------------------------------\n");
    }

    // Kalkulasi Diskon Promo Lebaran (Jika berat > 10 kg)
    double diskon = 0;
    if (total_berat > 10) {
        diskon = total_ongkos * 0.10;
    }

    // Cetak Total
    printf("Total Berat          : %d kg\n", total_berat);
    printf("Total Ongkos Kirim   : Rp %.0f\n", total_ongkos);

    // Cetak Informasi Promo
    printf("\n--- INFORMASI PROMO LEBARAN ---\n");
    if (diskon > 0) {
        printf("[+] Diskon Ongkir 10%% (Berat > 10kg) : - Rp %.0f\n", diskon);
    } else {
        printf("[-] Tidak ada diskon ongkir (Berat <= 10kg)\n");
    }

    if (dapat_asuransi) {
        printf("[+] Mendapatkan Asuransi Gratis (Tujuan Luar Pulau)\n");
    } else {
        printf("[-] Tidak dapat asuransi (Hanya Tujuan Dalam Pulau)\n");
    }

  
    double total_bayar = total_ongkos - diskon;
    printf("\n==========================================\n");
    printf("TOTAL YANG HARUS DIBAYAR : Rp %.0f\n", total_bayar);
    printf("==========================================\n");

    return 0;
}