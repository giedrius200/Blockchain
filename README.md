# Blockchain
## **Išvados**

- [x] Hash'avimo procesui turite naudoti Jūsų pirmąjam darbui sukurtas hash funkcijas.
- [x] Output'as: transakcijų ir naujų blokų kūrimas turi būti matomas, t.y., output'inimas

| Output |
| ------------- |
| Mining block 1
Previous hash: 99NE4AASN0KEOP1I04SRIL6I63B8ESGDSS1rdbizlmxirozzuxsvzbyhceqafhwk
Block mined: 091388dfb9r63n8d23qz8nldieSe684efmrnn89h35l3w7aia16d1rra4h6rznfy
Sunkumas: 1
Time: 1634189649
POW - 1  |

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

- [x] Atnaujinta hash funkcija

```
srand(time(0));
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
		bitset<8> bs5(bs3 <<= skaicius );
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
```
