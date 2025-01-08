#include <stdio.h>
#include <stdlib.h>

#define TAX_RATE 0.10
#define sertifikasi 0.1 // Diperbaiki: definisi sertifikasi tanpa titik koma

// Deklarasi fungsi
void rubah(int x, int y);
void rubah_1(int *x, int *y);

int main()
{
    int n_1;
    printf("Input nilai n: ");
    scanf("%d", &n_1);

    // Mencetak angka dengan format tertentu
    for (int i = 1; i <= n_1; i++) {
        if (i < 10)
            printf("0%d ", i);
        else
            printf("%d ", i);

        // Menambahkan baris baru setelah kelipatan 5
        if (i % 5 == 0) {
            printf("\n");
            for (int j = i + 5; j > i; j--) {
                if (j < 10)
                    printf("0%d ", j);
                else
                    printf("%d ", j);
            }
            printf("\n");
            i += 5; // Langsung loncat 5 angka
        }
    }
    printf("\n---------------------------------------------\n\n");

    // Menghitung jumlah bilangan ganjil
    int bil_2, _$bil_2 = 0;
    printf("Input bilangan: ");
    scanf("%d", &bil_2);
    for (int i = 1; i <= bil_2; i++) {
        if (i % 2 == 1)
            _$bil_2 += i;
    }
    printf("%d", _$bil_2); // Output jumlah bilangan ganjil
    printf("\n---------------------------------------------\n\n");

    // Fungsi untuk mengubah nilai tanpa menggunakan pointer (passing by value)
    int a = 5, b = 3;
    printf("Sebelum pemanggilan fungsi\n");
    printf("a=%d, b=%d\n", a, b);
    rubah(a, b); // Panggil fungsi rubah
    printf("Sesudah pemanggilan fungsi\n");
    printf("a=%d, b=%d\n", a, b); // Tidak ada perubahan pada a dan b karena passing by value
    printf("\n---------------------------------------------\n\n");

    // Fungsi untuk mengubah nilai dengan menggunakan pointer (passing by reference)
    int a_1 = 5, b_1 = 3;
    printf("Sebelum pemanggilan fungsi\n");
    printf("a=%d, b=%d\n", a_1, b_1);
    rubah_1(&a_1, &b_1); // Panggil fungsi rubah_1
    printf("Sesudah pemanggilan fungsi\n");
    printf("a=%d, b=%d\n", a_1, b_1); // Nilai a_1 dan b_1 berubah karena passing by reference
    printf("\n---------------------------------------------\n\n");

    // Menghitung pajak berdasarkan saldo
    float balance, tax;
    balance = 72.10;
    tax = balance * TAX_RATE;
    printf("The tax on %.2f is %.2f\n", balance, tax);
    printf("\n---------------------------------------------\n\n");

    // Menghitung gaji pokok dengan bonus dan sertifikasi
    int gaji_pokok = 2000000;
    int job, bonus;
    char sert;

    // Pilihan jenis pekerjaan
    printf("coder_jn [1]\ncoder_sn [2]\ndata_analis [3]\nprojec_nanag [4]\nlainlain [5]\n");
    printf("Apa bidang anda: ");
    scanf("%d", &job);
    printf("Apakah anda memiliki sertifikasi [y/t]? ");
    scanf(" %c", &sert); // Menambahkan spasi agar scanf membaca input dengan benar

    // Penentuan bonus berdasarkan pekerjaan
    switch (job) {
        case 1: bonus = 1000000; gaji_pokok += bonus; break;
        case 2: bonus = 1250000; gaji_pokok += bonus; break;
        case 3: bonus = 1500000; gaji_pokok += bonus; break;
        case 4: bonus = 2000000; gaji_pokok += bonus; break;
        case 5: bonus = 500000; gaji_pokok += bonus; break;
    }

    // Menambah bonus jika ada sertifikasi
    if (sert == 'y') {
        bonus *= sertifikasi;
        gaji_pokok += bonus;
    }

    // Menampilkan gaji akhir
    printf("Gaji: %d\n", gaji_pokok);

    return 0;
}

// Fungsi untuk mengubah nilai tanpa pointer (passing by value)
void rubah(int x, int y) {
    x = x + 5;
    y = y * 5;
    printf("\nNilai di akhir fungsi tukar()\n");
    printf("x = %d y = %d\n", x, y);
}

// Fungsi untuk mengubah nilai dengan pointer (passing by reference)
void rubah_1(int *x, int *y) {
    *x = *x + 5;
    *y = *y * 5;
    printf("\nNilai di akhir fungsi tukar()\n");
    printf("x = %d y = %d\n", *x, *y);
}
