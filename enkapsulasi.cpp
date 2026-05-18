#include <iostream>
using namespace std;

class remotelampu{
    private : 
        string saklarNo[5];
    public :
        void setSaklarNo(int i, string value) {
            saklarNo[i] = value;
        }
        string getSaklarNo(int i){
            return saklarNo[i];
        }
};

int main(){
    remotelampu lampuRumah;

    lampuRumah.setSaklarNo(0, "Lampu Teras Ruamh");
    lampuRumah.setSaklarNo(1, "Lampu Ruang Tamu");
    lampuRumah.setSaklarNo(2, "Lampu Kamar Tidur");
    lampuRumah.setSaklarNo(3, "Lampu Tidur");

    cout << lampuRumah.getSaklarNo(0) << endl;
    cout << lampuRumah.getSaklarNo(1) << endl;
    cout << lampuRumah.getSaklarNo(2) << endl;
    cout << lampuRumah.getSaklarNo(3) << endl;

    return 0;
}