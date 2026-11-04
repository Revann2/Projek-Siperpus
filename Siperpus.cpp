// =====================================================================
// SIPERPUS - Penyimpanan Data Input (sesuai poin 4b rancangan)
// Konsep : variabel, array, vector
// =====================================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    // 1) Pin admin
    int pinAdmin = 123456;

    // 2) Tempat penyimpanan data peminjaman
    //    Satu baris = satu transaksi, dengan urutan kolom:
    //    [0] NIM mahasiswa
    //    [1] Kode buku
    //    [2] Judul buku
    //    [3] Penulis buku
    //    [4] Tahun terbit
    //    [5] Tanggal peminjaman
    //    [6] Tanggal pengembalian ("-" jika belum dikembalikan)
    vector< vector<string> > dataPeminjaman;

    // 3) Data dump untuk pengujian
    dataPeminjaman.push_back({"2604130109", "B001", "Dasar Pemrograman C++",       "Andi Pratama",   "2019", "01-11-2026", "-"});
    dataPeminjaman.push_back({"2604130155", "B002", "Struktur Data dan Algoritma", "Budi Santoso",   "2018", "02-11-2026", "-"});
    dataPeminjaman.push_back({"2604130103", "B003", "Matematika Diskrit",          "Citra Lestari",  "2017", "20-10-2026", "-"});
    dataPeminjaman.push_back({"2604130176", "B004", "Basis Data untuk Pemula",     "Dewi Anggraini", "2020", "10-10-2026", "15-10-2026"});
    dataPeminjaman.push_back({"2604130109", "B005", "Jaringan Komputer",          "Eko Nugroho",    "2016", "01-10-2026", "12-10-2026"});

    // ---------------------------------------------------------------
    // Pengujian singkat: tampilkan isi penyimpanan
    // ---------------------------------------------------------------
    cout << "Pin admin : " << pinAdmin << endl;
    cout << "Jumlah data peminjaman : " << dataPeminjaman.size() << endl << endl;

    for (int i = 0; i < dataPeminjaman.size(); i++) {
        cout << i + 1 << ". NIM: " << dataPeminjaman[i][0]
             << " | Kode: "    << dataPeminjaman[i][1]
             << " | Judul: "   << dataPeminjaman[i][2]
             << " | Penulis: " << dataPeminjaman[i][3]
             << " | Tahun: "   << dataPeminjaman[i][4]
             << " | Pinjam: "  << dataPeminjaman[i][5]
             << " | Kembali: " << dataPeminjaman[i][6] << endl;
    }

    return 0;
}