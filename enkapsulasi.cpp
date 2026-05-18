#include <iostream>
using namespace std;

class remotelampu{
    private : 
        string saklarNo[5];
    public :
        void setSaklarNo(int i, string value) {
            saklarNo[i] = value;
        }
};