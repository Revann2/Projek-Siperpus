#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string kodeBuku;
    string judul;
    string penulis;
    int tahunTerbit;
    int stok;
};

struct Peminjaman {
    string nim;
    string kodeBuku;
    string tglPinjam;
    string tglKembali;
    bool statusPinjam; 
};

int main() {
    const int MAX_BUKU = 10;
    const int MAX_PINJAM = 5;
    Buku daftarBuku[MAX_BUKU] = {
        {"B001", "Pemrograman C++ Dasar", "Budi Raharjo", 2020, 3},
        {"B002", "Struktur Data & Algoritma dalam Phyton", "Heru Saputra,dkk", 2026, 3},
        {"B003", "Perempuan-Perempuan Perkasa", "Peter Carey", 2023, 3},
        {"B004", "Negeri Para Bedebah", "Tere Liye", 2023, 3},
        {"B005", "Sukses Bisnis Online", "Geoffrey Mahendra", 2026, 3},
        {"B006", "Rekayasa Perangkat Lunak", "Roger S. Pressman", 2023, 3},
        {"B007", "Manajemen Farmasi", "Anggraeni Widya Putri, S.Farm.", 2025, 3},
        {"B008", "Matematika Diskrit", "Rinaldi Munir", 2016, 3},
        {"B009", "Antologi Rasa", "Ika Natassa", 2019, 3},
        {"B010", "Pengantar Teknologi Informasi", "Asrul,dkk", 2025, 3}
    };
    
    Peminjaman daftarPeminjaman[MAX_PINJAM] = {
        {"220101001", "B001", "01-11-2026", "08-11-2026", true}
    };

    cout << "=========================================================" << endl;
    cout << "              DAFTAR BUKU PERPUSTAKAAN                   " << endl;
    cout << "=========================================================" << endl;

    for (int i = 0; i < MAX_BUKU; i++) {
        cout << i + 1 << ". Kode: " << daftarBuku[i].kodeBuku 
             << " | Judul: " << daftarBuku[i].judul 
             << " | Penulis: " << daftarBuku[i].penulis 
             << " | Tahun: " << daftarBuku[i].tahunTerbit 
             << " | Stok: " << daftarBuku[i].stok << endl;
    }

    cout << "=========================================================" << endl;

    return 0;
}