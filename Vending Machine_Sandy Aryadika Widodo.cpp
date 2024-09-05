#include <iostream>
using namespace std;

const int MAX_BARANG = 3;

struct Barang
{
    string nama;
    int harga;
    int stok;
};

struct Transaksi
{
    string namaBarang;
    int jumlah;
    int totalHarga;
};

struct MesinOtomatis
{
    Barang daftarBarang[MAX_BARANG];
    Transaksi riwayatTransaksi[MAX_BARANG];
    int jumlahTransaksi;
};

void inisialisasiMesinOtomatis(MesinOtomatis &mesin)
{
    mesin.daftarBarang[0] = {"Coca cola", 10000, 10};
    mesin.daftarBarang[1] = {"Aqua", 3000, 8};
    mesin.daftarBarang[2] = {"Pop Ice", 5000, 15};
    mesin.jumlahTransaksi = 0;
}

void tampilkanMenu(MesinOtomatis &mesin)
{
    system("cls");
    cout << "========= MENU MESIN OTOMATIS =========" << endl;
    for (int i = 0; i < MAX_BARANG; ++i)
    {
        cout << i + 1 << ". " << mesin.daftarBarang[i].nama << " (Rp. " << mesin.daftarBarang[i].harga
             << ") - Stok: " << mesin.daftarBarang[i].stok << endl;
    }
    cout << "========================================" << endl;
}

void prosesPesanan(MesinOtomatis &mesin, int indeksBarang, int jumlah)
{
    if (indeksBarang >= 1 && indeksBarang <= MAX_BARANG)
    {
        indeksBarang--; // Sesuaikan indeks dengan array (dimulai dari 0)

        if (jumlah > 0 && mesin.daftarBarang[indeksBarang].stok >= jumlah)
        {
            // Proses pesanan
            mesin.riwayatTransaksi[mesin.jumlahTransaksi].namaBarang = mesin.daftarBarang[indeksBarang].nama;
            mesin.riwayatTransaksi[mesin.jumlahTransaksi].jumlah = jumlah;
            mesin.riwayatTransaksi[mesin.jumlahTransaksi].totalHarga = mesin.daftarBarang[indeksBarang].harga * jumlah;

            // Kurangi stok barang
            mesin.daftarBarang[indeksBarang].stok -= jumlah;

            cout << "Pesanan berhasil ditempatkan. Total harga: Rp. " << mesin.riwayatTransaksi[mesin.jumlahTransaksi].totalHarga << endl;

            mesin.jumlahTransaksi++;
        }
        else
        {
            cout << "Jumlah tidak valid atau stok tidak mencukupi." << endl;
        }
    }
    else
    {
        cout << "Indeks barang tidak valid. Harap pilih barang yang valid." << endl;
    }
}

void tampilkanRiwayatTransaksi(MesinOtomatis &mesin)
{
    system("cls");
    if (mesin.jumlahTransaksi == 0)
    {
        cout << "Tidak ada riwayat transaksi." << endl;
    }
    else
    {
        cout << "========= RIWAYAT TRANSAKSI ==========" << endl;
        for (int i = 0; i < mesin.jumlahTransaksi; ++i)
        {
            cout << "Barang: " << mesin.riwayatTransaksi[i].namaBarang
                 << ", Jumlah: " << mesin.riwayatTransaksi[i].jumlah
                 << ", Total Harga: Rp. " << mesin.riwayatTransaksi[i].totalHarga << endl;
        }
        cout << "========================================" << endl;
    }
}

void tambahStock(MesinOtomatis &mesin, int indeksBarang, int jumlah)
{
    system("cls");
    if (indeksBarang >= 1 && indeksBarang <= MAX_BARANG)
    {
        indeksBarang--;
        if (jumlah > 0)
        {
            mesin.daftarBarang[indeksBarang].stok += jumlah;
            cout << "Stok barang telah diperbarui" << endl;
        }
        else
        {
            cout << "Jumlah tidak valid";
        }
    }
    else
    {
        cout << "Indeks barang tidak valid. Harap pilih barang yang valid." << endl;
    }
}

int main()
{
    MesinOtomatis mesin;
    inisialisasiMesinOtomatis(mesin);
    int pilihan;
    do
    {
        cout << "\n======== SIMULATOR MESIN OTOMATIS ========" << endl;
        cout << "1. Tampilkan Menu" << endl;
        cout << "2. Pesan Barang" << endl;
        cout << "3. Tampilkan Riwayat Transaksi" << endl;
        cout << "4. Tambah Stock" << endl;
        cout << "5. Keluar" << endl;
        cout << "==========================================" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tampilkanMenu(mesin);
            break;
        case 2:
            int indeksBarang, jumlah;
            cout << "Masukkan indeks barang (1-" << MAX_BARANG << "): ";
            cin >> indeksBarang;
            cout << "Masukkan jumlah: ";
            cin >> jumlah;
            prosesPesanan(mesin, indeksBarang, jumlah);
            break;
        case 3:
            tampilkanRiwayatTransaksi(mesin);
            break;
        case 4:
            cout << "Masukkan indeks barang (1-" << MAX_BARANG << "): ";
            cin >> indeksBarang;
            cout << "Masukkan jumlah yang ingin ditambah: ";
            cin >> jumlah;
            tambahStock(mesin, indeksBarang, jumlah);
        case 5:
            cout << "Keluar dari program. Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Harap masukkan opsi yang valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
