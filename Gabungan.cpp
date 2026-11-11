#include <iostream>
#include <string>
#include <vector>
using namespace std;

int role;

// ---------- DATA BUKU (vektor paralel: index sama = buku yang sama) ----------
vector<string> kode = {"B001", "B002", "B003", "B004", "B005",
                       "B006", "B007", "B008", "B009", "B010"};
vector<string> judul = {"Pemrograman C++ Dasar",
                        "Struktur Data & Algoritma dalam Phyton",
                        "Perempuan-Perempuan Perkasa",
                        "Negeri Para Bedebah",
                        "Sukses Bisnis Online",
                        "Rekayasa Perangkat Lunak",
                        "Manajemen Farmasi",
                        "Matematika Diskrit",
                        "Antologi Rasa",
                        "Pengantar Teknologi Informasi"};
vector<string> penulis = {"Budi Raharjo", "Heru Saputra,dkk", "Peter Carey",
                          "Tere Liye", "Geoffrey Mahendra", "Roger S. Pressman",
                          "Anggraeni Widya Putri, S.Farm.", "Rinaldi Munir",
                          "Ika Natassa", "Asrul,dkk"};
vector<int> tahun = {2020, 2026, 2023, 2023, 2026, 2023, 2025, 2016, 2019, 2025};
vector<int> stok = {2, 3, 3, 3, 3, 3, 3, 3, 3, 3};

// ---------- DATA PEMINJAMAN (pStatus: true = dipinjam, false = sudah kembali) ----------
vector<string> pNim = {"220101001"};
vector<string> pKode = {"B001"};
vector<string> pTglPinjam = {"01-11-2026"};
vector<string> pTglKembali = {"08-11-2026"};
vector<bool> pStatus = {true};

int PIN_ADMIN = 4444;
int MAKS_PINJAM = 7; // maksimal buku yang boleh dipinjam satu NIM

// ---------- FUNGSI BANTU ----------
void garis() {
    cout << "=========================================================" << endl;
}

// Mencari posisi buku berdasarkan kode. Kalau tidak ada, idx = -1
void cariIndex(string k, int &idx) {
    int n = kode.size();
    idx = -1;
    for (int i = 0; i < n; i++) {
        if (kode[i] == k) {
            idx = i;
            break;
        }
    }
}

// Menampilkan satu buku (i = posisi buku di vektor)
void tampilBuku(int i) {
    cout << kode[i] << ". " << judul[i] << " - " << penulis[i]
         << " (" << tahun[i] << ") | Stok: " << stok[i] << endl;
    if (stok[i] == 0) {
        cout << "   -> Buku ini sedang tidak tersedia." << endl;
    }
}

// ---------- FITUR-FITUR ----------
void tampilSemuaBuku() {
    int n = kode.size();
    garis();
    cout << "              DAFTAR BUKU PERPUSTAKAAN" << endl;
    garis();
    if (n == 0) {
        cout << "Belum ada buku." << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        tampilBuku(i);
    }
    garis();
}

void cariBuku() {
    int pilih, thn = 0;
    string kata = "";
    bool valid = true;

    cout << "[1] Kode buku\n[2] Judul buku\n[3] Penulis buku\n[4] Tahun terbit" << endl;
    cout << "Cari buku berdasarkan: ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
    case 1:
        cout << "Masukkan kode buku: ";
        getline(cin, kata);
        break;
    case 2:
        cout << "Masukkan judul buku: ";
        getline(cin, kata);
        break;
    case 3:
        cout << "Masukkan nama penulis: ";
        getline(cin, kata);
        break;
    case 4:
        cout << "Masukkan tahun terbit: ";
        cin >> thn;
        cin.ignore();
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
        valid = false;
    }

    if (valid) {
        int n = kode.size();
        bool ketemu = false;
        for (int i = 0; i < n; i++) {
            bool cocok = false;
            switch (pilih) {
            case 1:
                cocok = (kode[i] == kata);
                break;
            case 2:
                cocok = (judul[i] == kata);
                break;
            case 3:
                cocok = (penulis[i] == kata);
                break;
            case 4:
                cocok = (tahun[i] == thn);
                break;
            }

            if (cocok) {
                tampilBuku(i);
                ketemu = true;
            }
        }
        // Dicetak sekali saja di akhir, bukan di tiap putaran
        if (!ketemu) {
            cout << "Buku tidak ditemukan." << endl;
        }
    }
}

void aturanPerpustakaan() {
    cout << "===========================" << endl;
    cout << "   ATURAN PERPUSTAKAAN" << endl;
    cout << "===========================" << endl;
    cout << "1. Dilarang berisik dan membuat kegaduhan di perpustakaan." << endl;
    cout << "2. Dilarang mengotori perpustakaan." << endl;
}

void rekapPeminjaman() {
    int n = pNim.size();
    cout << "===========================" << endl;
    cout << "  REKAPITULASI PEMINJAMAN" << endl;
    cout << "===========================" << endl;
    if (n == 0) {
        cout << "Belum ada peminjaman buku." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            int idx;
            cariIndex(pKode[i], idx);
            cout << i + 1 << ". NIM: " << pNim[i] << endl;
            cout << "   Buku    : " << pKode[i];
            if (idx >= 0) {
                cout << " - " << judul[idx];
            }
            cout << endl;
            cout << "   Pinjam  : " << pTglPinjam[i]
                 << " | Kembali: " << pTglKembali[i] << endl;
            if (pStatus[i]) {
                cout << "   Status  : Sedang dipinjam" << endl;
            } else {
                cout << "   Status  : Sudah kembali" << endl;
            }
        }
    }
}

// Tambah buku baru, atau tambah stok kalau kodenya sudah ada
void tambahBuku() {
    string kodeInp, judulInp, penulisInp;
    int tahunInp, stokInp, idx;

    cout << "Masukkan kode buku: ";
    getline(cin, kodeInp);
    cariIndex(kodeInp, idx);

    if (idx >= 0) {
        // Kode sudah ada -> cukup tambah stoknya
        cout << "Kode sudah terdaftar: " << judul[idx] << endl;
        cout << "Tambah stok sebanyak: ";
        cin >> stokInp;
        cin.ignore();
        if (stokInp < 0) {
            cout << "Jumlah tidak boleh negatif." << endl;
        } else {
            stok[idx] = stok[idx] + stokInp;
            cout << "Stok berhasil ditambah. Stok sekarang: " << stok[idx] << endl;
        }
    } else {
        cout << "Masukkan judul buku: ";
        getline(cin, judulInp);
        cout << "Masukkan nama penulis: ";
        getline(cin, penulisInp);
        cout << "Masukkan tahun terbit: ";
        cin >> tahunInp;
        cin.ignore();
        cout << "Jumlah: ";
        cin >> stokInp;
        cin.ignore();

        if (stokInp < 0) {
            cout << "Jumlah tidak boleh negatif." << endl;
        } else {
            kode.push_back(kodeInp);
            judul.push_back(judulInp);
            penulis.push_back(penulisInp);
            tahun.push_back(tahunInp);
            stok.push_back(stokInp);
            cout << "Buku berhasil ditambahkan." << endl;
        }
    }
}

void hapusBuku() {
    string kodeInp;
    int idx;
    cout << "Masukkan kode buku yang ingin dihapus: ";
    getline(cin, kodeInp);
    cariIndex(kodeInp, idx);

    if (idx < 0) {
        cout << "Buku tidak ditemukan." << endl;
    } else {
        kode.erase(kode.begin() + idx);
        judul.erase(judul.begin() + idx);
        penulis.erase(penulis.begin() + idx);
        tahun.erase(tahun.begin() + idx);
        stok.erase(stok.begin() + idx);
        cout << "Buku berhasil dihapus." << endl;
    }
}

// Pendataan ulang buku (khusus admin)
void pendataanBuku() {
    int menu;
    cout << "[1] Tambah / Simpan buku\n[2] Hapus buku\n[0] Batal" << endl;
    cout << "Pilih: ";
    cin >> menu;
    cin.ignore();

    switch (menu) {
    case 1:
        tambahBuku();
        break;
    case 2:
        hapusBuku();
        break;
    default:
        cout << "Pendataan ulang buku dibatalkan." << endl;
    }
}

// Peminjaman buku (menu [4] untuk pengunjung)
void pinjamBuku() {
    string nim, kodeInp;
    int idx, aktif = 0;
    int n = pNim.size();

    cout << "Masukkan NIM: ";
    getline(cin, nim);

    // Hitung buku yang sedang dipinjam NIM ini
    for (int i = 0; i < n; i++) {
        if (pNim[i] == nim && pStatus[i]) {
            aktif++;
        }
    }

    if (nim == "") {
        cout << "NIM tidak boleh kosong." << endl;
    } else if (aktif >= MAKS_PINJAM) {
        cout << "Batas peminjaman (" << MAKS_PINJAM << " buku) sudah tercapai." << endl;
    } else {
        cout << "Masukkan kode buku yang ingin dipinjam: ";
        getline(cin, kodeInp);
        cariIndex(kodeInp, idx);

        if (idx < 0) {
            cout << "Buku tidak ditemukan." << endl;
        } else if (stok[idx] == 0) {
            cout << "Maaf, buku ini sedang tidak tersedia." << endl;
        } else {
            // Cek apakah NIM ini masih meminjam buku yang sama
            bool sudahPinjam = false;
            for (int i = 0; i < n; i++) {
                if (pNim[i] == nim && pKode[i] == kode[idx] && pStatus[i]) {
                    sudahPinjam = true;
                }
            }

            if (sudahPinjam) {
                cout << "Kamu masih meminjam buku ini." << endl;
            } else {
                string tglPinjam, tglKembali;
                cout << "Tanggal pinjam (dd-mm-yyyy): ";
                getline(cin, tglPinjam);
                cout << "Tanggal kembali (dd-mm-yyyy): ";
                getline(cin, tglKembali);

                pNim.push_back(nim);
                pKode.push_back(kode[idx]);
                pTglPinjam.push_back(tglPinjam);
                pTglKembali.push_back(tglKembali);
                pStatus.push_back(true);
                stok[idx] = stok[idx] - 1;
                cout << "Peminjaman berhasil: " << judul[idx] << endl;
            }
        }
    }
}

// ---------- LOGIN ----------
void pilihRole(int &role) {
    cout << "=================================" << endl;
    cout << "   Selamat Datang di SiPerpus" << endl;
    cout << "=================================" << endl;
    cout << "[1] Admin\n[2] Pengunjung" << endl;
    cout << "Silahkan login sebagai Admin atau Pengunjung: ";
    cin >> role;
    cin.ignore();
}

// berhasil = true kalau PIN benar
void loginAdmin(bool &berhasil) {
    int pin;
    berhasil = false;
    cout << "Kembali ke menu login ketik 0" << endl;
    cout << "Masukkan PIN Admin: ";
    cin >> pin;
    cin.ignore();

    if (pin == 0) {
        cout << "Kembali ke menu Login." << endl;
    } else if (pin == PIN_ADMIN) {
        cout << "Login Berhasil!\nAnda masuk sebagai Admin." << endl;
        berhasil = true;
    } else {
        cout << "PIN Salah! Akses Ditolak." << endl;
    }
}
void menuAdmin(){
     cout << "\n=================================" << endl;
        cout << "     Menu SiPerpus (Admin)" << endl;
        cout << "=================================" << endl;
        cout << "[1] Cari Buku" << endl;
        cout << "[2] Tampilkan Semua Buku yang Tersedia" << endl;
        cout << "[3] Aturan Perpustakaan" << endl;
        cout << "[4] Rekap Peminjaman" << endl;
        cout << "[5] Pendataan Ulang Buku" << endl;
        cout << "[6] Keluar (kembali memilih mode)" << endl;
        cout << "[7] Keluar" << endl;
        cout << "Silahkan pilih menu: ";
    }
    // ---------- MENU ----------
bool selesai = false;
void admin() {
    int pilih;
    do {
        menuAdmin();
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
        case 1:
            cariBuku();
            break;
        case 2:
            tampilSemuaBuku();
            break;
        case 3:
            aturanPerpustakaan();
            break;
        case 4:
            rekapPeminjaman();
            break;
        case 5:
            pendataanBuku();
            break;
        case 6:
            break;
        case 7:
        selesai = true;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih != 6 && pilih != 7);
}
void menuPengunjung(){
     cout << "\n=================================" << endl;
        cout << "     Menu SiPerpus (Pengunjung)" << endl;
        cout << "=================================" << endl;
        cout << "[1] Cari Buku" << endl;
        cout << "[2] Tampilkan Semua Buku yang Tersedia" << endl;
        cout << "[3] Aturan Perpustakaan" << endl;
        cout << "[4] Peminjaman Buku" << endl;
        cout << "[5] Keluar (kembali memilih mode)" << endl;
        cout << "[6] Keluar" << endl;
        cout << "Silahkan pilih menu: ";
}
void pengunjung() {
    int pilih;
    cout << "Anda masuk sebagai Pengunjung." << endl;
    do {
        menuPengunjung();
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
        case 1:
            cariBuku();
            break;
        case 2:
            tampilSemuaBuku();
            break;
        case 3:
            aturanPerpustakaan();
            break;
        case 4:
            pinjamBuku();
            break;
        case 5:
            break;
        case 6:
        selesai = true;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih != 5 && pilih != 6);
}

// ---------- MAIN ----------
int main() {
    bool berhasil;

    do {
        pilihRole(role);

        switch (role) {
        case 1:
            loginAdmin(berhasil);
            if (berhasil) {
                admin();
            }
            break;
        case 2:
            pengunjung();
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (!selesai);

    cout << "Terima kasih telah menggunakan SiPerpus." << endl;
    return 0;
}