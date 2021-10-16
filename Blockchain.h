#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Blockas.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void PridekBlock(Block bNew);
    void data(Block bNew);
    void MininkNonce(Block bNew,int limitas);

private:
    uint32_t _nDifficulty;
    int limitas;
    vector<Block> _vChain;
    Block _GetLastBlock() const;
};

#endif //TESTCHAIN_BLOCKCHAIN_H