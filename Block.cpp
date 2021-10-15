#include "Blockas.h"
#include "SHAmano.h"

Block::Block(uint32_t nIndexIn, const string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tStamp = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MininkBlock(uint32_t nDifficulty)
{
    char* cstr = new char[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
        /*cout << sHash << endl;*/
    } while (sHash.substr(0, nDifficulty) != str);
    delete cstr;
    cout << "Previous hash: " << PrevBlockHash << endl;
    cout << "Block mined: " << sHash << endl;
    cout << "Sunkumas: " << nDifficulty << endl;
    cout << "Time: " << _tStamp << endl;
    cout << "POW - " << _nNonce << endl;
    cout << "Ar norite pamatyti data? (true, false)  " << endl;
    string t;
    cin >> t;
    if (t == "true") {
        cout << _sData << endl;
    }
    cout << "------------------------------------------" << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << PrevBlockHash << _tStamp << _sData << _nNonce;
    string hex = ss.str();
    return paverstihex(hex);
}