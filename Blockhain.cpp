#include "Blockchain.h"

Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "PRADINIS GENESESIS BLOKAS"));
    _nDifficulty = 1;
}
void Blockchain::PridekBlock(Block bNew)
{
    bNew.PrevBlockHash = _GetLastBlock().sHash;
    bNew.MininkBlock(_nDifficulty);
    _vChain.push_back(bNew);
}
void Blockchain::data(Block bNew)
{
    bNew.data();
}

void Blockchain::MininkNonce(Block bNew,int limitas)
{
    bNew.PrevBlockHash = _GetLastBlock().sHash;
    bNew.MininkNonce(_nDifficulty, limitas);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}