// Mano blockchain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SHAmano.h";

#include <fstream>
#include <stdlib.h> 
#include <vector>

#include <limits>

using namespace std;

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

class block {
    string prevhash;
    string hash;
    int timestamp;
    int ver;
    string roothash;
    int nonce;
    int diff;
};
class blockchain {
private:
    block blokas;

};
int main()
{
    int iSecret;
    ofstream balansas("balansas.txt");
    ofstream var("vartotojai.txt");
    for (int i = 0; i < 1000; i++) {
        iSecret = rand() % 999901 + 100;
        balansas << iSecret << endl;
    }
    balansas.close();
    fstream vardai("vardai.txt");
    fstream public_key("raktai.txt");
    fstream kieki("balansas.txt");
    ofstream transakcijos("transakcijos.txt");

    ofstream pool("pool.txt");

    string vardas;
    string raktas;

    vector<string>raktai;
    vector<int>sumavisu;

    int gavejas, siuntejas;

    int suma;

    int piniga;

    int max;

    int kiek;

    int skaiciukas;

    string pradinis = "pradinis";

    string hash;

    while (kieki) {
        vardai >> vardas;
        public_key >> raktas;
        raktai.push_back(raktas);
        kieki >> kiek;
        sumavisu.push_back(kiek);

        var << vardas << " " << raktas << " " << kiek << endl;
    }

    kiek = 0;

    for (int i = 0; i < 10000; i++) {
        gavejas = rand() % 500 + 0;
        siuntejas = rand() % 501 + 500;
        piniga = rand() % 999901 + 100;
        if (piniga > sumavisu[siuntejas]) {
            max = rand() % sumavisu[siuntejas] + 1;
        }
        else { 
            max = piniga; 
        }
        hash = paverstihex(pradinis,true);
        pradinis = hash;
        pool << pradinis <<" "<< raktai[siuntejas] <<" "<< raktai[gavejas] <<" "<< max << endl;

        skaiciukas = rand() % 2 + 0;
        if (skaiciukas == 1 && kiek !=100) {
            transakcijos << pradinis << " " << raktai[siuntejas] << " " << raktai[gavejas] << " " << max << endl;
            kiek ++;
        }
    }
    
    fstream ispool("pool.txt");

    //ofstream transakcijos("transakcijos.txt");

    string transakcija;

    for (int i = 0; i < 100; i++) {

    }

}

