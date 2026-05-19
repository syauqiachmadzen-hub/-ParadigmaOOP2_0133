#include <iostream>
using namespace std;

class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) : namaNasabah(nama), saldo(saldoAwal) {}

    virtual void potongAdmin() = 0;

    virtual void tampilkanInfo() {
        cout << "Nama Nasabah   : " << namaNasabah << endl;
        cout << "Saldo Saat Ini : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Sedang Memproses Transaksi " << namaNasabah << " (Syariah) -> Bebas biaya admin!." << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Sedang Memproses Transaksi " << namaNasabah << " (Konvensional) -> Potong saldo Rp 15.000." << endl;
        saldo -= 15000;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Sedang Memproses Transaksi " << namaNasabah << " (Premium) -> Saldo di atas Rp 10 Juta, Bebas biaya admin!." << endl;
        } else {
            cout << "Sedang Memproses Transaksi " << namaNasabah << " (Premium) -> Saldo <= Rp 10 Juta, Potong saldo Rp 50.000." << endl;
            saldo -= 50000;
        }
    }
};

int main() {
    int jumlahNasabah = 4;
    RekeningBank* daftarNasabah[4];

    daftarNasabah[0] = new RekeningSyariah("Riyadi", 5000000);
    daftarNasabah[1] = new RekeningKonvensional("Nughroho", 5000000);
    daftarNasabah[2] = new RekeningPremium("Asep", 15000000);
    daftarNasabah[3] = new RekeningPremium("Budi", 9000000);

    cout << "===================\n";
    cout << " BANK GIBRAN JAYA \n";
    cout << "===================\n\n";

    for (int i = 0; i < jumlahNasabah; i++) {
        daftarNasabah[i]->potongAdmin();
        daftarNasabah[i]->tampilkanInfo();
        cout << "------------------------------------------\n";
    }

    cout << "Terimakasih telah menggunakan layanan Bank Gibran Jaya.\n";
    cout << endl;

    for (int i = 0; i < jumlahNasabah; i++) {
        delete daftarNasabah[i];
    }

    return 0;
}