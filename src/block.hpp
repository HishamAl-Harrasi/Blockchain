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
		uint64_t index;
		uint64_t nonce = 0;
		const uint32_t timestamp = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::vector <Transaction> transactions;
		std::string prevBlockHash;

		
	public:
		
		
		Block(std::string prevBlockHash, uint64_t index);

		void setNonce(uint64_t nonce);
		
		uint64_t getNonce();

		const uint32_t getTimestamp();

		uint64_t getIndex();

		std::string getPrevBlockHash();

		bool addTransaction(Transaction transaction);

		std::vector <Transaction> getTransactions();

};

Block::Block(std::string prevBlockHash, uint64_t index){
	this -> prevBlockHash = prevBlockHash;
	this -> index = index;
};

void Block::setNonce(uint64_t nonce){
	this -> nonce = nonce;
}

uint64_t Block::getNonce(){
	return nonce;
}

const uint32_t Block::getTimestamp(){
	return timestamp;
};

uint64_t Block::getIndex(){
	return index;
};

std::string Block::getPrevBlockHash(){
	return prevBlockHash;
}

bool Block::addTransaction(Transaction newTransaction){
	
	if (transactions.size() <= 3000){  // Setting a limit of 3000 transactions per block so each block does not get too large in size
		transactions.push_back(newTransaction);
		return true;
	} else {
		std::cout << "Too many transactions in the current block. Wait for current block to be mined and add your transaction to the next block. " << std::endl;
		return false;
	}

}

std::vector <Transaction> Block::getTransactions(){
	return transactions;
}

#endif
