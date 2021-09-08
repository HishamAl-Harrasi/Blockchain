#include <iostream>
#include <vector>
#include <string>
#include "block.hpp"
#include "transaction.hpp"

class Blockchain{
    private:
    
    public:
        Blockchain(bool isGenesis);

        const unsigned char* hashBlock();

        char* serializeBlock();
};

Blockchain::Blockchain(bool isGenesis){
    if (isGenesis){
        std::vector<Block> chain;
        
        // chain.push_back();       
    }
}

char* Blockchain::serializeBlock(){
    
}

const unsigned char* Blockchain::hashBlock(){

}

int main(){
    
    unsigned int index = 0;
    std::string prevBlockHash = "NULL";
    Block genesis (prevBlockHash, index);

    Transaction firstTransaction("test", "test2", 123, 1);
    
    std::cout << firstTransaction;
    

    return 0;
}