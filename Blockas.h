#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

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

#endif