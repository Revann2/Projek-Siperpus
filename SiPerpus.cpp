#include <iostream>
using namespace std;

int main () {
    const int maxbook = 20;
    const int maxpinjam = 5;
    int pilihan;

    string kodebuku[maxbook]  = {"B001", "B002", "B003"};
    string judulbuku[maxbook] = {"Pemrograman C++", "Algoritma", "Basis Data"};
    string penulis[maxbook]   = {"Budi", "Siti", "Andi"};
    int tahunterbit[maxbook]  = {2020, 2019, 2021};
    int stoktotal[maxbook]    = {5, 3, 4};
    int stoksedia[maxbook]    = {5, 3, 4};
    int jumlahbuku = 3;

    string nimPinjam[maxpinjam];
    string kodePinjam[maxpinjam];
    int tglPinjam[maxpinjam];     // disimpan sebagai angka hari ke-1..365
    int tglTenggat[maxpinjam];
    int statusPinjam[maxpinjam];  // 1 = masih dipinjam, 0 = sudah kembali
    int jumlahPinjam = 0;

    int denda = 5000;
    int frekuensi = 7;
    int pin = 4444;

    // untuk mencari buku berdasarkan kode
    int caribuku (string kode) {
        for (int i=0; i<jumlahbuku ; i++) {
            if (kodebuku[i] == kode) {
        }
        return -1;
    }


    cout << "\n[1] Pinjam buku\n[2] Lihat daftar pinjam\n[0] Keluar\nPilih: ";



    return 0;
}