#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pilihan_utama, pilihan_sub, pilihan_makanan;
    int shot, pax;
    char nama[50];
    char nama_pesanan[50];
    long harga = 0;
    char konfirmasi, ganti;

    // Array Menu Kopi
    char menu_kopi[11][50] = {
        "Kopi Tubruk", "Americano", "V60", "French Press", "Cold Brew",
        "Caffe Latte", "Cappuccino", "Flat White", "Tiramisu (Latte/Blend)",
        "Red Velvet (Latte/Blend)", "Avocado Coffee"
    };
    long harga_kopi[11] = {15000, 25000, 40000, 35000, 40000, 35000, 35000, 35000, 35000, 35000, 45000};

    // Array Menu Makanan Berat
    char menu_makanan_berat[6][50] = {
        "Chicken Cordon Bleu / Chop", "Burger & Fries", "Spaghetti",
        "Nasi Goreng Spesial", "Rice Bowl", "Indomie Kekinian"
    };
    long harga_berat[6] = {65000, 65000, 60000, 55000, 50000, 35000};

    // Array Menu Makanan Ringan
    char menu_makanan_ringan[7][50] = {
        "Mix Platter", "Chicken Wings", "Croissant / Pastry",
        "French Fries", "Dimsum", "Churros", "Pisang Goreng Cokelat Keju"
    };
    long harga_ringan[7] = {55000, 45000, 45000, 35000, 35000, 35000, 30000};

    while (1) {
        harga = 0; // Reset harga setiap kali mulai ulang
        
        printf("\n==========================================\n");
        printf("     SISTEM PEMESANAN KAFETARIA IT DEL\n");
        printf("==========================================\n");
        printf("1. Pesan Kopi\n");
        printf("2. Pesan Makanan\n");
        printf("3. Booking Meja\n");
        printf("4. Keluar\n");
        printf("Pilih layanan (1-4): ");
        scanf("%d", &pilihan_utama);

        if (pilihan_utama == 4) {
            printf("\nTerimakasih sudah berkunjung ke Kafetaria IT Del!\n");
            break;
        }

        printf("\nMasukkan Nama Pemesan: ");
        scanf(" %[^\n]", nama); // Membaca string dengan spasi

        // ================= FLOW 1: KOPI =================
        if (pilihan_utama == 1) {
            printf("\n--- MENU KOPI ---\n");
            for (int i = 0; i < 11; i++) {
                printf("%d. %s - Rp %ld\n", i + 1, menu_kopi[i], harga_kopi[i]);
            }
            printf("Pilih Kopi (1-11): ");
            scanf("%d", &pilihan_sub);
            
            if(pilihan_sub >= 1 && pilihan_sub <= 11) {
                strcpy(nama_pesanan, menu_kopi[pilihan_sub - 1]);
                harga = harga_kopi[pilihan_sub - 1];
            } else {
                printf("Pilihan tidak valid!\n"); continue;
            }

            printf("Berapa shot espresso tambahan/yang diminta? (Misal: 1, 2, dll): ");
            scanf("%d", &shot);
        }
        
        // ================= FLOW 2: MAKANAN =================
        else if (pilihan_utama == 2) {
            printf("\n1. Makanan Berat\n2. Makanan Ringan\nPilih Kategori (1-2): ");
            scanf("%d", &pilihan_sub);

            if (pilihan_sub == 1) {
                printf("\n--- MENU MAKANAN BERAT ---\n");
                for (int i = 0; i < 6; i++) {
                    printf("%d. %s - Rp %ld\n", i + 1, menu_makanan_berat[i], harga_berat[i]);
                }
                printf("Pilih Makanan (1-6): ");
                scanf("%d", &pilihan_makanan);
                
                if(pilihan_makanan >= 1 && pilihan_makanan <= 6) {
                    strcpy(nama_pesanan, menu_makanan_berat[pilihan_makanan - 1]);
                    harga = harga_berat[pilihan_makanan - 1];
                } else {
                    printf("Pilihan tidak valid!\n"); continue;
                }
            } else if (pilihan_sub == 2) {
                printf("\n--- MENU MAKANAN RINGAN ---\n");
                for (int i = 0; i < 7; i++) {
                    printf("%d. %s - Rp %ld\n", i + 1, menu_makanan_ringan[i], harga_ringan[i]);
                }
                printf("Pilih Makanan (1-7): ");
                scanf("%d", &pilihan_makanan);
                
                if(pilihan_makanan >= 1 && pilihan_makanan <= 7) {
                    strcpy(nama_pesanan, menu_makanan_ringan[pilihan_makanan - 1]);
                    harga = harga_ringan[pilihan_makanan - 1];
                } else {
                    printf("Pilihan tidak valid!\n"); continue;
                }
            } else {
                printf("Kategori tidak valid!\n"); continue;
            }
        }
        
        // ================= FLOW 3: BOOKING MEJA =================
        else if (pilihan_utama == 3) {
            printf("\n--- BOOKING MEJA ---\n");
            printf("Meja untuk berapa orang? (2-6): ");
            scanf("%d", &pax);

            if (pax >= 2 && pax <= 6) {
                harga = pax * 50000; // Karena kelipatannya 50rb per orang
                sprintf(nama_pesanan, "Meja untuk %d Orang", pax);
            } else {
                printf("Maaf, kapasitas meja hanya untuk 2 hingga 6 orang.\n"); continue;
            }
        } else {
            printf("Pilihan tidak valid!\n"); continue;
        }

        // ================= FLOW KONFIRMASI =================
        printf("\n------------------------------------------\n");
        printf("Pesanan Anda: %s\n", nama_pesanan);
        printf("Total Harga : Rp %ld\n", harga);
        printf("Apakah Anda setuju dengan pesanan & harga ini? (Y/N): ");
        scanf(" %c", &konfirmasi);

        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            // Output Struk Akhir
            printf("\n==========================================\n");
            printf("             STRUK PESANAN\n");
            printf("==========================================\n");
            printf("Nama Pemesan : %s\n", nama);
            
            if (pilihan_utama == 1) {
                printf("Jenis Kopi   : %s\n", nama_pesanan);
                printf("Jumlah Shot  : %d shot\n", shot);
            } else if (pilihan_utama == 2) {
                printf("Jenis Makanan: %s\n", nama_pesanan);
            } else if (pilihan_utama == 3) {
                printf("Nomor Meja   : VIP-%d (Kapasitas %d)\n", rand() % 20 + 1, pax); // Nomor meja random 1-20
            }
            
            printf("Total Biaya  : Rp %ld\n", harga);
            printf("==========================================\n");
            printf("Terimakasih sudah berkunjung ke Kafetaria IT Del!\n");
            printf("==========================================\n");
            break; // Keluar dari program setelah pesanan selesai
            
        } else {
            // Jika Batal (Cancel)
            printf("\nPesanan dibatalkan.\n");
            printf("Apakah Anda ingin mengganti pesanan? (Y/N): ");
            scanf(" %c", &ganti);

            if (ganti == 'Y' || ganti == 'y') {
                printf("\nSilakan buat pesanan baru...\n");
                continue; // Mengulang program dari awal (menu utama)
            } else {
                printf("\nTerimakasih sudah berkunjung ke Kafetaria IT Del!\n");
                break; 
            }
        }
    }

    return 0;
}