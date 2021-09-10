#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "block.hpp"

class Blockchain{
    private:
        std::vector <Block> chain;
    public:
        Blockchain();

        void addBlock(Block block);

        // const unsigned char* hashBlock();
        void hashBlock();

        // char* serializeBlock(Block* block);
        void serializeBlock(Block* block);
};


// Constructor: On construction fo the blockchain, the chain should automatically include the genesis block. The genesis block is special because there
// are no blocks behind it, and therefore the prevBlockHash attribute will not be filled with a real hash of a previous block 
Blockchain::Blockchain(){
     
    
}

void Blockchain::addBlock(Block block){
    chain.push_back(block);
}

// char* Blockchain::serializeBlock(Block* block){
void Blockchain::serializeBlock(Block* block){
    
    std::ostringstream serializedBlockStream;

    serializedBlockStream << block -> getIndex() << " " << block -> getNonce() << " " << block -> getTimestamp() << " " << block -> getPrevBlockHash() << " ";

    std::string serializedBlock = serializedBlockStream.str();

    std::cout << serializedBlock << std::endl;



}

// const unsigned char* Blockchain::hashBlock(){
void Blockchain::hashBlock(){

}

int main(){
    
    unsigned int index = 0;
    std::string prevBlockHash = "NULL";
    Block genesis (prevBlockHash, index);

    Blockchain myBlockchain;
    
    genesis.setNonce(12345);

    myBlockchain.addBlock(genesis);

    myBlockchain.serializeBlock(&genesis);
    

    // std::string sender = "hisham";
    // std::string reciever = "zak";

    // Transaction newTransaction {sender, reciever, 28282, 1};

    // genesis.addTransaction(newTransaction);

    return 0;
}