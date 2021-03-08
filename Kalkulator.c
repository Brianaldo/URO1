/* Program Kalkulator */
/* Program Kalkulator penjumlahan, pengurangan, perkalian, pembagian, pemangkatan (pangkat > 1),
dan integral tentu menggunakan pendekatan riemann metode trapesium */

#include <stdio.h>
#include <stdbool.h> 

/* Prototype Fungsi */
/* Fungsi Penjumlahan */
float penjumlahan (float a, float b)
/* Fungsi menerima 2 float dan menjumlahkannya (a + b) */
{
/* KAMUS LOKAL */

/* ALGORITMA */
    return a + b;
}

/* Fungsi Penngurangan */
float pengurangan (float a, float b)
/* Fungsi menerima 2 float dan mengurangkannya (a - b) */
{
/* KAMUS LOKAL */

/* ALGORITMA */
    return a - b;
}

/* Fungsi Perkalian */
float perkalian (float a, float b)
/* Fungsi menerima 2 float dan mengalikannya (a * b) */
{
/* KAMUS LOKAL */

/* ALGORITMA */
    return a * b;
}

/* Fungsi Pembagian */
float pembagian (float a, float b)
/* Fungsi menerima 2 float dan membaginya (a / b) */
{
/* KAMUS LOKAL */

/* ALGORITMA */
    return a / b;
}

/* Fungsi perpangkatan */
float perpangkatan (float a, float b)
/* Fungsi menerima 2 float dan membaginya (a ^ b) */
{
/* KAMUS LOKAL */
    float c;
/* ALGORITMA */
    c = 1;
    while (b > 0) {
        c = c * a;
        b = b - 1;
    }
    return c;
}

/* Fungsi Integral Riemann */
float integralRiemann ()
/* Fungsi menghitung integral tertentu dari y = x^3 + x + 1 menggunakan Riemann */
{
/* KAMUS LOKAL */
    int d, i;
    float koef[d + 1], a, b, partisi, interval, luas, bKiri, bKanan;
/* ALGORITMA */
    printf("Polinomial berderajat? ");
    scanf("%d", &d);
    i = d;
    while (i >= 0) {
        printf("Koefisien derajat ke-%d = ", i);
        scanf("%f", &koef[i]);
        i = i - 1;
    }
    i = d;
    printf("\nf(x) = ");
    while (i >= 0) {
        if (i == 0) {
            printf("%f\n", koef[i]);
        } else if (i == 1) {
            printf("%f x + ", koef[i]);
        } else {
            printf("%f x^(%d) + ", koef[i], i);
        }
        i = i - 1;
    }

    printf("\nMasukan batas bawah: ");
    scanf("%f", &a);
    printf("Masukan batas atas: ");
    scanf("%f", &b);
    while (b < a) {
        printf("INPUT TIDAK VALID (Batas atas harus lebih besar dari batas bawah)\n");
        printf("Masukan batas atas: ");
        scanf("%f", &b);
    }
    printf("Masukan banyak partisi: ");
    scanf("%f", &partisi);
    while (partisi <= 0) {
        printf("INPUT TIDAK VALID (Partisi harus lebih besar dari 0)\n");
        printf("Masukan banyak partisi: ");
        scanf("%f", &partisi);
    }
    interval = (b - a) / partisi;
    luas = 0;
    while (a < b) {
        i = d;
        bKiri = 0;
        bKanan = 0;
        while (i >= 0) {
            bKiri = bKiri + (perpangkatan(a, i) * koef[i]);
            bKanan = bKanan + (perpangkatan((a + interval), i) * koef[i]);
            i = i - 1;
        }
        luas = luas + ((bKiri + bKanan) * interval / 2);
        a = a + interval;
    }
    return luas;
}

/* Fungsi Cek Integer */
bool cekInteger (float b)
/* Fungsi memeriksa apakah masukan merupakan integer*/
{
/* KAMUS LOKAL */

/* ALGORITMA */
    while (b > 0) {
        b = b - 1;
    }
    if (b == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
/* KAMUS */
    float a, b, hasil;
    int pilih, partisi;
    char operasi; 

/* ALGORITMA */
/* input */
    printf("\n===========PROGRAM KALKULATOR===========\n\n");
    printf("Pilih operasi yang diinginkan:\n");
    printf("1. Kalkulator Sederharna\n");
    printf("2. Integral tentu (trapesium Riemman)\n");
    printf("Pilih operasi (1 atau 2): ");
    scanf(" %d", &pilih);
    while ((pilih != 1) && (pilih != 2)) {
        printf("INPUT TIDAK VALID\n");
        printf("Pilih operasi (1 atau 2): ");
        scanf(" %d", &pilih);
    }
    
/* Kalkulator */
    if (pilih == 1) {
        printf("\n==========KALKULATOR SEDERHANA==========\n\n");
        printf("List operasi: \n");
        printf("(+) Penjumlahan\n");
        printf("(-) Pengurangan\n");
        printf("(*) Perkalian\n");
        printf("(/) Pembagian\n");
        printf("(^) Perpangkatan\n");
        printf("(x) Keluar\n");
        printf("Masukan bilangan: ");
        scanf("%f", &a);
        hasil = a;
        printf("Operasi: ");
        scanf(" %c", &operasi);
        while (operasi != 'x') {
            if (operasi == '+' || operasi == '-' || operasi == '*' || operasi == '/' || operasi == '^') {
                if (operasi == '+') {
                    printf("Masukan bilangan: ");
                    scanf("%f", &b);
                    hasil = penjumlahan(hasil, b);
                }
                else if (operasi == '-') {
                    printf("Masukan bilangan: ");
                    scanf("%f", &b);
                    hasil = pengurangan(hasil, b);
                }
                else if (operasi == '*') {
                    printf("Masukan bilangan: ");
                    scanf("%f", &b);
                    hasil = perkalian(hasil, b);
                }
                else if (operasi == '/') {
                    printf("Masukan bilangan: ");
                    scanf("%f", &b);
                    hasil = pembagian(hasil, b);
                } else if (operasi == '^') {
                    printf("Masukan bilangan: ");
                    scanf("%f", &b);
                    while (cekInteger(b) == false) {
                        printf("INPUT TIDAK VALID (Harus Bilangan Bulat)");
                        printf("Masukan bilangan: ");
                        scanf("%f", &b);
                    }
                    hasil = perpangkatan(hasil, b);
                }
                printf("%f %c %f = %f\n", a, operasi, b, hasil);
                a = hasil;
            } else {
                printf("INPUT TIDAK VALID\n");
            }
            printf("Operasi: ");
            scanf(" %c", &operasi);
        }
    }
    else if (pilih == 2) {
        printf("\n================INTEGRAL================\n");
        printf("\nHasil = %f\n",integralRiemann());
    return 0;
    } else {
        printf("Input tidak valid\n");
    }
    return 0;
}