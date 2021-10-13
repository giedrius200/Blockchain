#include <iostream>
#include "SHAmano.h"

#include <fstream>
#include <stdlib.h> 
#include <vector>

#include <algorithm>

#include <iterator>

#include <limits>

#include "Blockchain.h"

std::vector<std::string> get_words(std::istream& stm)
{
    return { std::istream_iterator<std::string>(stm),
             std::istream_iterator<std::string>{} };
}

std::string random_word_from_file(const std::string& file_name)
{
    static std::mt19937 rng(std::random_device{}());

    std::ifstream file(file_name);
    const auto words = get_words(file);
    if (words.empty()) return {};

    std::uniform_int_distribution<std::size_t> distrib(0, words.size() - 1);
    return words[distrib(rng)];
}

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}
class vartotojai {
public:
    vector<string>vardai;
    vector<string>raktas;
    vector<int>balansas;
    vector<string> info;
};

int main()
{
    int iSecret;
    ofstream balansas("balansas.txt");
    ofstream var("vartotojai.txt");

    int balansokiek = 1000;
    for (int i = 0; i < balansokiek; i++) {
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
    string pradinis1 = "pradinis";

    cout << paverstihex(pradinis) << " " << paverstihex(pradinis1);

    string hash;

    vartotojai vart = vartotojai();

    while (kieki) {
        vardai >> vardas;
        public_key >> raktas;
        raktai.push_back(raktas);
        kieki >> kiek;
        sumavisu.push_back(kiek);

        var << vardas << " " << raktas << " " << kiek << endl;

        vart.vardai.push_back(vardas);
        vart.balansas.push_back(kiek);
        vart.raktas.push_back(raktas);
    }

    kiek = 0;

    Blockchain chain1 = Blockchain();
#include <ctime>
    /*std::default_random_engine rng{ 1 };
    std::uniform_int_distribution<> dist{ 0, balansokiek / 2 };
    std::uniform_int_distribution<> dist1{ balansokiek / 2, balansokiek };
    std::uniform_int_distribution<> dist6{ 100, 1000000 };*/
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, balansokiek / 2);
    std::uniform_int_distribution<> dist1{ balansokiek / 2, balansokiek };
    std::uniform_int_distribution<> dist6{ 100, 1000000 };
    int pooldydis = 600;
    for (int i = 0; i < pooldydis; i++) {
        //srand((int)time(0));
        //gavejas = rand() % (balansokiek/2) + 0;
        gavejas = dis(gen);
        //siuntejas = rand() % (balansokiek / 2)+1 + (balansokiek / 2) + 0;
        siuntejas = dist1(gen);
        //piniga = rand() % 999901 + 100;
        piniga = dist6(gen);
        if (piniga > sumavisu[siuntejas]) {
            std::uniform_int_distribution<> dist8{ 0, sumavisu[siuntejas] };
            //max = rand() % sumavisu[siuntejas] + 0;
            max = dist8(gen);
        }
        else if(piniga < sumavisu[siuntejas]){
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
    string linija;

    string line;
    ifstream poola("pool.txt");

    ofstream newpoola("newpool.txt");

    string data;

    string transakcijoss;

    string blokoid;

    vector<string> text_file;

    string linee;

    string hashasu, gavejasu, siuntejasu;
    int sumau;
    string info;

    int i = 1;

    stringstream ss;

    string info1;

    vector <string> siuntejai;
    vector <string> gavejai;
    vector <int> sumas;

    while (std::getline(poola, info1))
    {
       text_file.push_back(info1);
    }

    poola.close();
    poola.open("pool.txt");

    ifstream poolaa("pool.txt");
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

            poola >> hashasu >> siuntejasu >> gavejasu >> sumau;

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
                i++;
            }
    }

    for (auto i : text_file) {
        //cout << i << endl;
    }

    ofstream block;
    kiek = 1;
    blokoid = std::to_string(kiek) + "Bloko.txt";

  
    transakcijoss = "";
    
                for (int a = 0; a < 600; a = a + 100) {

                    block.open(blokoid);

                    for (int i = 0+a; i < 100+a; i++) {
                        block << text_file[i] << endl;
                        transakcijoss = transakcijoss + text_file[i]+"\n";
                    }
                    kiek++;
                    block.close();
                    blokoid = std::to_string(kiek) + "Bloko.txt";

                    cout << "Mining block " << kiek - 1 << endl;
                    chain1.PridekBlock(Block(kiek - 1, transakcijoss));
                    
                }
                

    ofstream updatevartotojai("atnaujinta.txt");

    for (auto a : vart.info) {
        updatevartotojai << a << endl;
    }

    string labas = "sveikas";
    string labas1 = "sveikas";
    
    fstream ispool("pool.txt");

    

    string transakcija;

    

}

