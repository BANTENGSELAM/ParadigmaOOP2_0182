#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
    protected :
        string namaNasabah;
        int saldo;

    public :
        RekeningBank(string nama, int pSaldo){
            namaNasabah = nama;
            saldo = pSaldo;
        }

        virtual void potongAdmin() = 0;

        void tampilSaldo(){
            cout << "Nama Nasabah : " << namaNasabah << endl;
            cout << "Saldo Akhir  : Rp " << saldo << endl;
            cout << endl;
        }
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank{
    public :
        RekeningSyariah(string nama, int pSaldo)
        : RekeningBank(nama, pSaldo)
        {

        }

        void potongAdmin(){
            cout << "Rekening Syariah tidak dikenakan biaya admin" << endl;
        }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank{
    public :
        RekeningKonvensional(string nama, int pSaldo)
        : RekeningBank(nama, pSaldo)
        {

        }

        void potongAdmin(){
            saldo = saldo - 15000;
            cout << "Biaya admin Rekening Konvensional : Rp 15000" << endl;
        }
};

// Rekening Premium
class RekeningPremium : public RekeningBank{
    public :
        RekeningPremium(string nama, int pSaldo)
        : RekeningBank(nama, pSaldo)
        {

        }

        void potongAdmin(){
            if(saldo > 10000000){
                cout << "Rekening Premium bebas biaya admin" << endl;
            }
            else{
                saldo = saldo - 50000;
                cout << "Biaya admin Rekening Premium : Rp 50000" << endl;
            }
        }
};

int main(){

    RekeningBank* rekening;

    RekeningSyariah syariah("Ahmad", 5000000);
    RekeningKonvensional konvensional("Budi", 3000000);
    RekeningPremium premium("Candra", 8000000);
    RekeningPremium premium2("Dina", 15000000);

    // Rekening Syariah
    rekening = &syariah;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    // Rekening Konvensional
    rekening = &konvensional;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    // Rekening Premium saldo <= 10 juta
    rekening = &premium;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    // Rekening Premium saldo > 10 juta
    rekening = &premium2;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    return 0;
}