#ifndef BLOCK_H
#define BLOCK_H


#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <string.h>
#include <chrono>
#include "hash.hpp"
#include "transaction.hpp"
#include <vector>

class Block{
	private:
		unsigned int index;
		uint32_t nonce;
		const long timestamp = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::vector <Transaction> transactions;

		
	public:
		
		std::string prevBlockHash;
		
		
		Block(std::string prevBlockHash, unsigned int index);

		unsigned int getIndex();

		const long getTimestamp();

	};

Block::Block(std::string prevBlockHash, unsigned int index){
	this -> prevBlockHash = prevBlockHash;
	this -> index = index; 	
};

const long Block::getTimestamp(){
	return timestamp;
};

unsigned int Block::getIndex(){
	return index;
};




#endif
