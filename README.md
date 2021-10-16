# Blockchain v0.2
## **Išvados**

- [x] Transakcijos hash'o tikrinimas
- [x] Sugeneruoti ~1000 tinklo vartotojų
- [x] Sugeneruoti ~10000 naujų, į jokį bloką dar neįdėtų, transakcijų pool'ą
- [x] Iš transakcijų pool'o atsitiktinai pasirinkti 100-ą transakcijų
- [x] Realizuokite naujų blokų kasimo (angl. mining) Proof-of-Work (PoW) tipo procesą

| Output |
| ------------- |
| Mining block 1
Previous hash: 99NE4AASN0KEOP1I04SRIL6I63B8ESGDSS1rdbizlmxirozzuxsvzbyhceqafhwk
Block mined: 091388dfb9r63n8d23qz8nldieSe684efmrnn89h35l3w7aia16d1rra4h6rznfy
Sunkumas: 1
Time: 1634189649
POW - 1  |

- [x] Patobulintas blokų kasimo (mining) procesas pagal v0.2 logiką

```
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
```
- [x] OOP saugumo praktikos, bloko struktūra

```
class Block {
public:
    string sHash;
    string PrevBlockHash;

    Block(uint32_t nIndexIn, const string& sDataIn);

    void MininkBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    uint32_t _nNonce;
    string _sData;
    time_t _tStamp;

    string _CalculateHash() const;
};
```
- [x] Grandinės struktūra
```
class Blockchain {
public:
    Blockchain();

    void PridekBlock(Block bNew);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

```
- [x] Atnaujinta hash funkcija

```
string paverstihex(string& s)
{
	ostringstream ret;

	string pridedas = "";
	string simbolis = "";
	string tuscia = "";

	char simbolisc;

	string stringas = "kriptografija";

	int bitai;

	int skaicius;

	int dydis = s.length();

	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 10000000000000);
	srand(dis(gen));
	random_shuffle(s.begin(), s.end());
	random_shuffle(stringas.begin(), stringas.end());

	if (s.length() < 66) {
		while (s.length() < 66) {
			char cch = 'a' + rand() % 26;

			s.push_back(cch);
		}
	}
	for (int i = 0; i < s.length(); i++) {
		bitset<8> bs4(s[i]);
		skaicius = rand() % 2 + 1;
		bitset<8> bar(skaicius);
		bitset<8> bs3(bs4 <<= skaicius & skaicius);
		bitset<8> bs5(bs3 <<= skaicius);
		bitset<8> rez(bs5 ^= bar);

		tuscia = bitset_to_string(rez);
		random_shuffle(tuscia.begin(), tuscia.end());
	}
	s.append(tuscia);
	s.append(stringas);
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
	if (s.length() > 64) {
		while (s.length() != 64) {
			s.pop_back();
		}
	}
	return s;
}

```
- [x] Balanso tikrinimas

```
while (getline(poola, linee))
    {
	poola >> hashasu >> siuntejasu >> gavejasu >> sumau;
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
```
## **Paleidimas**
```
gcc -lstdc++ \
    -o TestChain \
    -std=c++11 \
    -stdlib=libc++ \
    -x c++ \
    Mano blockchain.cpp Block.cpp Blockchain.cpp SHAmano.h
./TestChain
```
___

