#include <stdio.h>

int main() {
    int N;

    printf("==========================================\n");
    printf("        SISTEM REKAP STOK GUDANG\n");
    printf("==========================================\n");

    // 1. Input jumlah total data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);

    // Deklarasi array sesuai jumlah N
    int stok[N];
    int kategori[N];

    // 2. Input deret stok (s1, s2, ..., sN)
    printf("Masukkan deret stok (%d data, pisahkan dengan spasi):\n> ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &stok[i]);
    }

    // 3. Input deret kode kategori barang
    printf("Masukkan deret kode kategori (%d data, pisahkan dengan spasi):\n> ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &kategori[i]);
    }

    // 4. Input kode kategori yang ingin dihitung totalnya
    int kode_cari;
    printf("Masukkan kode kategori yang ingin dihitung totalnya: ");
    scanf("%d", &kode_cari);

    // 5. Proses pencarian dan penjumlahan stok
    int total_stok = 0;
    for (int i = 0; i < N; i++) {
        if (kategori[i] == kode_cari) {
            total_stok += stok[i];
        }
    }

    // Output Hasil
    printf("\n==========================================\n");
    printf("Total stok untuk kategori %d adalah: %d pcs\n", kode_cari, total_stok);
    printf("==========================================\n");

    return 0;
}