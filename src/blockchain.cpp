#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "block.hpp"
#include "hash.hpp"


class Blockchain{
    private:
        std::vector <Block> chain;
    public:
        Blockchain();

        void addBlock(Block block);

        // const unsigned char* hashBlock();
        void hashBlock(Block* block);

        const char* serializeBlock(Block* block);
};


// Constructor: On construction fo the blockchain, the chain should automatically include the genesis block. The genesis block is special because there
// are no blocks behind it, and therefore the prevBlockHash attribute will not be filled with a real hash of a previous block 
Blockchain::Blockchain(){
     
    
}

void Blockchain::addBlock(Block block){
    chain.push_back(block);
}

const char* Blockchain::serializeBlock(Block* block){
    
    std::ostringstream serializedBlockStream;

    serializedBlockStream << block -> getIndex() << " " << block -> getNonce() << " " << block -> getTimestamp() << " " << block -> getPrevBlockHash() << " ";

    
    std::vector <Transaction> blockTransactions = block -> getTransactions();
    
    for (int i = 0; i < blockTransactions.size(); i++){
        serializedBlockStream << blockTransactions[i];
    }
    
    std::string serializedBlockString = serializedBlockStream.str();

    const char* serializedBlock = serializedBlockString.c_str();
    
    return serializedBlock;
}

// const unsigned char* Blockchain::hashBlock(){
void Blockchain::hashBlock(Block* block){
        // LATEST ISSUE - for some reason running serializeBlock() does not return anything at the moment - probably problem with pointers
    const char* test = serializeBlock(block);

    std::cout << test[0] << std::endl;

    // hasher::sha256()
}

int main(){
    
    unsigned int index = 0;
    std::string prevBlockHash = "NULL";
    Block genesis (prevBlockHash, index);

    Blockchain myBlockchain;
    
    genesis.setNonce(12345);

    std::string sender = "hisham";
    std::string reciever = "zak";

    Transaction newTransaction {sender, reciever, 28282, 1};

    genesis.addTransaction(newTransaction);

    myBlockchain.addBlock(genesis);
    myBlockchain.hashBlock(&genesis);


    return 0;
}