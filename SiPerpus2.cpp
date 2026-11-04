#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    vector <string> judulbuku = {"Pemrograman C++", "Algoritma", "Basis Data"};
    vector <string> penulis = {"Budi", "Siti", "Andi"};
    vector <int> tahunterbit = {2020, 2019, 2021};
    vector <int> stoktotal = {5, 3, 4};
    const int pin = 4444;
    int login, pilih, pininput;

    cout << "=================================" << endl;
    cout << "   Selamat Datang di SiPerpus" << endl;
    cout << "=================================" << endl;
    cout << "[1] Admin\n[2] Pengunjung" << endl;
    cout << "Silahkan login sebagai Admin atau Pengunjung: " << endl;
    cin >> login;

    if (login == 1) {
        cout << "Masukkan PIN Admin: ";
        cin >> pininput;
       
        if (pininput == pin) {
            cout << "Login Berhasil!\n Anda masuk sebagai Admin." << endl;
            cout << "Anda masuk sebagai Pengunjung." << endl;
            cout << "=================================" << endl;
            cout << "   Menu SiPerpus" << endl;
            cout << "=================================" << endl;
            cout << "[1] Cari Buku" << endl;
            cout << "[2] Tampilkan Semua Buku yang Tersedia" << endl;
            cout << "[3] Aturan Perpustakaan" << endl;
            cout << "[4] Rekap Peminjaman" << endl;
            cout << "[5] Tambah Buku" << endl;
            cout << "[6] Keluar" << endl;
            cout << "Silahkan pilih menu: ";
            cin >> pilih;

        } else {
            cout << "PIN Salah! Akses Ditolak." << endl;
            return 0;
        }
    } else if (login == 2) {
        cout << "Anda masuk sebagai Pengunjung." << endl;
        cout << "=================================" << endl;
        cout << "   Menu SiPerpus" << endl;
        cout << "=================================" << endl;
        cout << "[1] Cari Buku" << endl;
        cout << "[2] Tampilkan Semua Buku yang Tersedia" << endl;
        cout << "[3] Aturan Perpustakaan" << endl;
        cout << "[4] Peminjaman Buku" << endl;
        cout << "[5] Keluar" << endl;
    } else {
        cout << "Pilihan tidak valid. Program dihentikan." << endl;
        return 0;
    }

    
    return 0;
}