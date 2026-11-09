#include <iostream>
#include <vector>
#include <string>
using namespace std;

int login()
{
    int pilih;
    cout << "=================================" << endl;
    cout << "   Selamat Datang di SiPerpus" << endl;
    cout << "=================================" << endl;
    cout << "[1] Admin\n[2] Pengunjung" << endl;
    cout << "Silahkan login sebagai Admin atau Pengunjung: " << endl;
    cin >> pilih;
    return pilih;
}

bool loginadmin(int pilih)
{
    if (pilih == 1)
    {
        vector<string> kode = {"B01", "B02", "B03"};
        vector<string> judulbuku = {"Pemrograman C++", "Algoritma", "Basis Data"};
        vector<string> penulis = {"Budi", "Siti", "Andi"};
        vector<int> tahunterbit = {2020, 2019, 2021};
        vector<int> stoktotal = {5, 3, 4};
        vector<string> peminjam = {"", "", ""};
        vector<string> nim = {"", "", ""};
        const int maxpeminjam = 7;
        const int denda = 1000;
        const int pin = 4444;
        int pilih, pininput, kembali;
        string kodeinp, judulinp, penulisinp;
        int tahunterbitinp, stoktotalinp;

        cout << "Kembali ke menu login ketik 0" << endl;
        cout << "Masukkan PIN Admin: " << endl;
        cin >> pininput;

        if (pininput == 0)
        {
            cout << "Kembali ke menu Login." << endl;
            login();
            return false;
        }

        else if (pininput == pin)
        {
            cout << "Login Berhasil!\n Anda masuk sebagai Admin." << endl;
            return true;
        }

        else
        {
            cout << "PIN Salah! Akses Ditolak." << endl;
            login();
            return false;
        }
    }

    else if (pilih == 2)
    {
        return false;
    }

    else
    {
        return false;
    }
}

bool loginpengunjung(int pilih)
{
    if (pilih == 2)
    {
        /*int user = login();
        if (user == 1)
        {
            return false;
        }
        else if (user == 2)
        {*/
        cout << "Anda masuk sebagai Pengunjung." << endl;
        return true;
        /*}
        else
        {
            cout << "Pilihan tidak valid. Program dihentikan." << endl;
            return false;
        }*/
    }

    else
    {
        return false;
    }
}

int main()
{
    vector<string> kode = {"B01", "B02", "B03"};
    vector<string> judulbuku = {"Pemrograman C++", "Algoritma", "Basis Data"};
    vector<string> penulis = {"Budi", "Siti", "Andi"};
    vector<int> tahunterbit = {2020, 2019, 2021};
    vector<int> stoktotal = {5, 3, 4};
    vector<string> peminjam = {"", "", ""};
    vector<string> nim = {"", "", ""};
    const int maxpeminjam = 7;
    const int denda = 1000;
    const int pin = 4444;
    int pilih, kembali;
    string kodeinp, judulinp, penulisinp;
    int tahunterbitinp, stoktotalinp;
    int user = login();

    if (loginadmin(user) && user == 1)
    {
        bool jalan = true;
        while (jalan)
        {
            cout << "=================================" << endl;
            cout << "         Menu SiPerpus" << endl;
            cout << "=================================" << endl;
            cout << "[1] Cari Buku" << endl;
            cout << "[2] Tampilkan Semua Buku yang Tersedia" << endl;
            cout << "[3] Aturan Perpustakaan" << endl;
            cout << "[4] Rekap Peminjaman" << endl;
            cout << "[5] Pendataan Ulang Buku" << endl;
            cout << "[6] Keluar" << endl;
            cout << "Silahkan pilih menu: ";
            cin >> pilih;

            // CARI BUKU
            if (pilih == 1)
            {
                cout << "[1] Kode buku \n[2] Judul buku \n[3] Penulis buku \n[4] Tahun terbit" << endl;
                cout << "Cari buku berdasarkan: ";
                cin >> pilih;

                if (pilih == 1)
                {
                    // string kodeinp;
                    cout << "Masukkan kode buku: ";
                    cin >> kodeinp;
                    for (int i = 0; i < judulbuku.size(); i++)
                    {
                        if (kodeinp == kode[i] && stoktotal[i] == 0)
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                            cout << "Buku ini sedang tidak tersedia." << endl;
                            cout << "Kembali ke menu dengan cara ketik 0 lalu tekan enter." << endl;
                            cin >> kembali;
                            if (kembali == 0)
                            {
                                break;
                            }
                            //break;
                        }
                        else if (kodeinp == kode[i])
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                            // for (int j = 1; j != 0; j++)
                            //{
                            cout << "Kembali ke menu? \nSilahkan ketik 0 lalu tekan enter untuk kembali ke menu." << endl;
                            cin >> kembali;
                            // jalan = false;
                            if (kembali == 0)
                            {
                                break;
                            }
                            //break;

                            //}
                        }
                        else if (kodeinp != kode[judulbuku.size() - 1] && i == judulbuku.size() - 1)
                        {
                            cout << "Buku tidak ditemukan." << endl;
                            // for (int j = 1; j != 0; j++)
                            //{
                            cout << "Kembali ke menu? \nSilahkan ketik 0 lalu tekan enter untuk kembali ke menu." << endl;
                            cin >> kembali;
                            if (kembali == 0)
                            {
                                break;
                            }
                            //break;
                        }
                    }
                }
                else if (pilih == 2)
                {
                    // string judulinp;
                    cout << "Masukkan judul buku: ";
                    cin >> judulinp;
                    for (int i = 0; i < judulbuku.size(); i++)
                    {
                        if (judulinp == judulbuku[i] && stoktotal[i] == 0)
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                            cout << "Buku ini sedang tidak tersedia." << endl;
                        }
                        else if (judulinp == judulbuku[i])
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                        }
                        else
                        {
                            cout << "Buku tidak ditemukan." << endl;
                        }
                    }
                }
                else if (pilih == 3)
                {
                    // string penulisinp;
                    cout << "Masukkan nama penulis: ";
                    cin >> penulisinp;
                    for (int i = 0; i < judulbuku.size(); i++)
                    {
                        if (penulisinp == penulis[i] && stoktotal[i] == 0)
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                            cout << "Buku ini sedang tidak tersedia." << endl;
                        }
                        else if (penulisinp == penulis[i])
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                        }
                        else
                        {
                            cout << "Buku tidak ditemukan." << endl;
                        }
                    }
                }
                else if (pilih == 4)
                {
                    // int tahunterbitinp;
                    cout << "Masukkan tahun terbit: ";
                    cin >> tahunterbitinp;
                    for (int i = 0; i < judulbuku.size(); i++)
                    {
                        if (tahunterbitinp == tahunterbit[i] && stoktotal[i] == 0)
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                            cout << "Buku ini sedang tidak tersedia." << endl;
                        }
                        else if (tahunterbitinp == tahunterbit[i])
                        {
                            cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                        }
                        else
                        {
                            cout << "Buku tidak ditemukan." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Pilihan tidak valid. Program dihentikan." << endl;
                }
                // TAMPILKAN SEMUA BUKU
            }
            else if (pilih == 2)
            {
                for (int i = 0; i < judulbuku.size(); i++)
                {
                    cout << i + 1 << ". " << kode[i] << " - " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                }

                // ATURAN PERPUSTAKAAN
            }
            else if (pilih == 3)
            {
                cout << "===========================" << endl;
                cout << "   ATURAN PERPUSTAKAAN   " << endl;
                cout << "===========================" << endl;
                cout << "1. Dilarang berisik dan membuat kegaduhan di perpustakaan. \n 2. Dilarang mengotori perpustakaan" << endl;
            }
            else if (pilih == 4)
            {
                cout << "===========================" << endl;
                cout << "  REKAPITULASI PEMINJAMAN  " << endl;
                cout << "===========================" << endl;

                if (peminjam.size() == 0)
                {
                    cout << "Belum ada peminjaman buku." << endl;
                }
                else
                {
                    for (int i = 0; i < judulbuku.size(); i++)
                    {
                        cout << i + 1 << ". " << peminjam[i] << " (" << nim[i] << ")" << endl;
                        cout << kode[i] << ". " << judulbuku[i] << " - " << penulis[i] << "(" << tahunterbit[i] << ")." << endl;
                    }
                }

                // PENDATAAN ULANG BUKU
            }
            else if (pilih == 5)
            {

                cout << "Masukkan kode buku: ";
                getline(cin, kodeinp);

                cout << "Masukkan judul buku: ";
                getline(cin, judulinp);

                cout << "Masukkan nama penulis: ";
                getline(cin, penulisinp);

                cout << "Masukkan tahun terbit: ";
                cin >> tahunterbitinp;
                cin.ignore();

                cout << "Jumlah: ";
                cin >> stoktotalinp;
                cin.ignore();

                cout << "[1] Simpan \n[2] Hapus" << endl;
                int konfirmasi;
                cin >> konfirmasi;

                if (konfirmasi == 1)
                {
                    kode.push_back(kodeinp);
                    judulbuku.push_back(judulinp);
                    penulis.push_back(penulisinp);
                    tahunterbit.push_back(tahunterbitinp);
                    stoktotal[judulbuku.size() - 1] += stoktotalinp;
                    // stoktotal.push_back(stoktotalinp);
                    peminjam.push_back("");
                    nim.push_back("");
                    cout << "Buku berhasil ditambahkan." << endl;
                }
                else if (konfirmasi == 2)
                {
                    for (int i = 0; i < judulbuku.size(); i++)
                    {
                        if (kodeinp == kode[i] && judulinp == judulbuku[i] && penulisinp == penulis[i] && tahunterbitinp == tahunterbit[i])
                        {
                            kode.erase(kode.begin() + i);
                            judulbuku.erase(judulbuku.begin() + i);
                            penulis.erase(penulis.begin() + i);
                            tahunterbit.erase(tahunterbit.begin() + i);
                            stoktotal.erase(stoktotal.begin() + i);
                            peminjam.erase(peminjam.begin() + i);
                            nim.erase(nim.begin() + i);
                            cout << "Buku berhasil dihapus." << endl;
                            break;
                        }
                        else if (i == judulbuku.size() - 1)
                        {
                            cout << "Buku tidak ditemukan." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Pendataan ulang buku dibatalkan." << endl;
                }

                // KELUAR
            }
            else if (pilih == 6)
            {
                cout << "Terima kasih telah menggunakan SiPerpus." << endl;
                return 0;
            }
            else
            {
                cout << "Pilihan tidak valid. Program dihentikan." << endl;
            }
        }
    }
    else if (user == 2 && loginpengunjung(user))
    {
    }

    else
    {
        cout << "Pilihan tidak valid. Program dihentikan." << endl;
        return 0;
    }
}
