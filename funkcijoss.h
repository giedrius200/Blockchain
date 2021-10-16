#ifndef funkcijoss_H
#define funkcijoss_H

#include <iostream>
#include "SHAmano.h"

#include <fstream>
#include <stdlib.h> 
#include <vector>

#include <algorithm>

#include <iterator>

#include <limits>

#include <ctime>

#include <random>

#include "Blockchain.h"

const int balansokiek = 1000;

class vartotojai {
public:
    vector<string>vardai;
    vector<string>raktas;
    vector<int>balansas;
    vector<string> info;
    void putData(string vardas, int kiek, string raktai);
};
void vartotojai::putData(string vardas, int kiek, string raktai) {
    vardai.push_back(vardas);
    raktas.push_back(raktai);
    balansas.push_back(kiek);
}

void nuskaityk(const string vardufailas, const string raktufailas, const string balansofailas, vector<string>& raktai, vector<int>& balansai, vartotojai& vart) {
    string vardas;
    string raktas;
    int kiek;
    ofstream var("vartotojai.txt");
    fstream vardai(vardufailas);
    fstream public_key(raktufailas);
    fstream kieki(balansofailas);

    while (kieki) {
        vardai >> vardas;
        public_key >> raktas;
        raktai.push_back(raktas);
        kieki >> kiek;
        balansai.push_back(kiek);
        //cout << vardas << endl;
        var << vardas << " " << raktas << " " << kiek << endl;

        vart.putData(vardas, kiek, raktas);
    }
}

void generuokpool(int pooldydis, vartotojai& vart, vector<string>& text_file) {

    int iSecret;
    ofstream balansas("balansas.txt");
    //ofstream var("vartotojai.txt");
    for (int i = 0; i < balansokiek; i++) {
        iSecret = rand() % 999901 + 100;
        balansas << iSecret << endl;
    }
    balansas.close();
    int gavejas, siuntejas;
    int piniga;
    int max;
    vector<string>raktai;
    string hash;
    vector<int>sumavisu;
    string pradinis = "pradinis";

    ofstream pool("pool.txt");

    nuskaityk("vardai.txt", "raktai.txt", "balansas.txt", raktai, sumavisu, vart);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, balansokiek / 2);
    std::uniform_int_distribution<> dist1{ balansokiek / 2, balansokiek };
    std::uniform_int_distribution<> dist6{ 100, 1000000 };
    int pooldydiss = pooldydis;
    for (int i = 0; i < pooldydiss; i++) {
        gavejas = dis(gen);
        siuntejas = dist1(gen);
        piniga = dist6(gen);
        if (piniga > sumavisu[siuntejas]) {
            std::uniform_int_distribution<> dist8{ 0, sumavisu[siuntejas] };
            max = dist8(gen);
        }
        else if (piniga < sumavisu[siuntejas]) {
            max = piniga;
        }
        else if (piniga == sumavisu[siuntejas]) {
            max = piniga;
        }
        hash = paverstihex(pradinis);
        pradinis = hash;
        if (i == pooldydis - 1) {
            pool << pradinis << " " << raktai[siuntejas] << " " << raktai[gavejas] << " " << max;
        }

        else {
            pool << pradinis << " " << raktai[siuntejas] << " " << raktai[gavejas] << " " << max << endl;
        }

    }
    pool.close();

    string info1;

    ifstream poolread("pool.txt");
    while (std::getline(poolread, info1))
    {
        text_file.push_back(info1);
    }

    poolread.close();

}
void atnaujinkbalansa(vartotojai& vart) {

    string linee;

    string hashasu, gavejasu, siuntejasu;

    int sumau;

    string info;

    ifstream poolaa("pool.txt");
    ifstream poola("pool.txt");

    poolaa >> hashasu >> siuntejasu >> gavejasu >> sumau;
    auto ita = std::find(vart.raktas.begin(), vart.raktas.end(), siuntejasu);
    if (ita != vart.raktas.end()) {
        int index = ita - vart.raktas.begin();
        vart.balansas[index] = vart.balansas[index] - sumau;
        info = vart.vardai[index] + " " + to_string(vart.balansas[index]);
        vart.info.push_back(info);
    }
    auto itb = std::find(vart.raktas.begin(), vart.raktas.end(), gavejasu);
    if (itb != vart.raktas.end()) {
        int index = itb - vart.raktas.begin();
        vart.balansas[index] = vart.balansas[index] + sumau;
        info = vart.vardai[index] + " " + to_string(vart.balansas[index]);
        vart.info.push_back(info);
    }
    while (getline(poola, linee))
    {

        poolaa >> hashasu >> siuntejasu >> gavejasu >> sumau;

        //cout << gavejasu <<" "<< siuntejasu << endl;
        auto it = std::find(vart.raktas.begin(), vart.raktas.end(), siuntejasu);
        if (it != vart.raktas.end()) {
            int index = it - vart.raktas.begin();
            vart.balansas[index] = vart.balansas[index] - sumau;
            if (vart.balansas[index] < 0) {
                continue;
            }
            info = vart.vardai[index] + " " + to_string(vart.balansas[index]);
            vart.info.push_back(info);
        }
        auto it1 = std::find(vart.raktas.begin(), vart.raktas.end(), gavejasu);
        if (it1 != vart.raktas.end()) {
            int index = it1 - vart.raktas.begin();
            vart.balansas[index] = vart.balansas[index] + sumau;
            if (vart.balansas[index] < 0) {
                continue;
            }
            info = vart.vardai[index] + " " + to_string(vart.balansas[index]);
            vart.info.push_back(info);
        }
    }
    ofstream updatevartotojai("atnaujinta.txt");

    for (auto a : vart.info) {
        updatevartotojai << a << endl;
    }
}
void blokukurimas(Blockchain& chain1, vector<string>& text_file) {
    string transakcijoss = "";
    int kiek = 1;
    string blokoid = std::to_string(kiek) + "Bloko.txt";

    ofstream block(blokoid);

    int kiekei = 1;
    int blocou = 1;
    for (auto i : text_file) {
        block << i << endl;
        transakcijoss = transakcijoss + i + "\n";
        if (kiekei == 100) {
            cout << "Mining block " << blocou << endl;
            chain1.PridekBlock(Block(blocou, transakcijoss));
            block.close();
            blokoid = std::to_string(blocou + 1) + "Bloko.txt";
            block.open(blokoid);
            blocou++;
            kiekei = 1;
            continue;
        }
        kiekei++;
    }
}
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}
void mininimas(Blockchain& chain1, int limitas)
{
    int blocou = 1;
    int kiek = 1;
    string info = "";
    string bendrasinfo = "";
    vector<int>skaiciai = { 1,2,3,4,5 };

    string data;

    string t;

    int kiekdidinti;

    int r;

    while (!skaiciai.empty()) {
            r = *select_randomly(skaiciai.begin(), skaiciai.end());

            string blokoid = std::to_string(r) + "Bloko.txt";
            ifstream bandym(blokoid);
            skaiciai.erase(std::remove(skaiciai.begin(), skaiciai.end(), r), skaiciai.end());
            while (getline(bandym, info)) {
                bendrasinfo = bendrasinfo + info + "\n";
            }

            cout << "------------------------------------------------"<< endl;
            cout << "Mining block " << blocou << endl;
            chain1.MininkNonce(Block(blocou, bendrasinfo), limitas);

            cout << endl;
            cout << endl;

            info = "";
            bendrasinfo = "";
            kiek++;

            blocou++;

            if (skaiciai.empty()) {
                cout << "Ar norite padidinti bandymu kieki (true,false) ?" << endl;
                cin >> t;

                int laikin = limitas;

                if (t == "true") {
                    cout << "Iveskite kiek kartu norite padidinti " << endl;
                    cin >> kiekdidinti;
                    skaiciai.push_back(1);
                    skaiciai.push_back(2);
                    skaiciai.push_back(3);
                    skaiciai.push_back(4);
                    skaiciai.push_back(5);
                    limitas = limitas * kiekdidinti;
                    continue;
                }
                else { 
                    break;
                }

            }
    }

}
#endif