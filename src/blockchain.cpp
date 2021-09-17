#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "block.hpp"
#include "hash.hpp"


class Blockchain{
    private:
        std::vector <Block> chain;
        
        uint8_t difficulty = 6;

        std::ostringstream serializeBlock(Block* block);
    public:
        Blockchain();

        void addBlock(Block block);

        void printSerializedBlock(Block* block);

        void hashBlock(Block* block, unsigned char* o_hash);

        uint64_t mineBlock(Block* block);

        void setDifficulty(uint8_t difficulty);
        
        uint8_t getDifficulty();

};


// Constructor: On construction of the blockchain, the chain should automatically include the genesis block. The genesis block is special because there
// are no blocks behind it, and therefore the prevBlockHash attribute will not be filled with a real hash of a previous block 
Blockchain::Blockchain(){
     
    
}

void Blockchain::addBlock(Block block){
    chain.push_back(block);
}

std::ostringstream Blockchain::serializeBlock(Block* block){
    
    std::ostringstream serializedBlockStream;

    serializedBlockStream << block -> getIndex() << " " << block -> getNonce() << " " << block -> getTimestamp() << " " << block -> getPrevBlockHash() << " ";

    
    std::vector <Transaction> blockTransactions = block -> getTransactions();
    
    for (int i = 0; i < blockTransactions.size(); i++){
        serializedBlockStream << blockTransactions[i];
    }
    
    return serializedBlockStream;
}

void Blockchain::printSerializedBlock(Block* block){
    std::ostringstream serializedBlockStream = serializeBlock(block);
    
    std::string serializedBlockString = serializedBlockStream.str();

    std::cout << serializedBlockString << std::endl;
}

void Blockchain::hashBlock(Block* block, unsigned char* o_hash){
    
    std::ostringstream serializedBlockStream = serializeBlock(block);
    
    std::string serializedBlockString = serializedBlockStream.str();

    const char* serializedBlock = serializedBlockString.c_str();
    uint32_t strLength = strlen(serializedBlock);
    
    hasher::sha256(serializedBlock, strLength, o_hash);
    
}

uint64_t Blockchain::mineBlock(Block* block){
    unsigned char* hash;
    char strHash[64];
    
    while (true){
        
        hashBlock(block, hash);
            
        hasher::sha256str(hash, strHash);

        uint64_t nonce = block -> getNonce();

        int i = 0;
        while (i < difficulty){
            if (strHash[i] == '0'){
                
                if (i == difficulty - 1) {
                    std::cout <<"\n\nHash: " << strHash << "\n\n";
                    return nonce;
                }
                else {
                    i++;
                    continue;
                }

            } else {
                i = 0;
                uint64_t newNonce = nonce + 1;
                block -> setNonce(newNonce);
                break;
            }
        }
    }    
   

}

void Blockchain::setDifficulty(uint8_t difficulty){
    this -> difficulty = difficulty;
}

uint8_t Blockchain::getDifficulty(){
    return difficulty;
}





int main(){
    
    unsigned int index = 0;
    std::string prevBlockHash = "NULL";
    Block genesis (prevBlockHash, index);

    Blockchain myBlockchain;
    
    // genesis.setNonce(12345);

    std::string sender = "hisham";
    std::string reciever = "zak";

    Transaction newTransaction {sender, reciever, 28282, 1};

    genesis.addTransaction(newTransaction);

    myBlockchain.addBlock(genesis);
    
    uint64_t nonce = myBlockchain.mineBlock(&genesis);
    myBlockchain.printSerializedBlock(&genesis);
    std::cout << "\n\nNonce: " << nonce << std::endl;


    return 0;
}

