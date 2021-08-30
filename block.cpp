#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <string.h>
#include <chrono>
#include "hash.hpp"

// class Block{
// 	public:
		
		

// 	private:
// 		unsigned int index;
// 		uint32_t nonce;
// 		std::string prevBlockHash;
// 		std::string prevBlockHash;
// }


	// long microsecondsUTC = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

int main(){

	const char* myString = "meow";
	size_t length = strlen(myString);

	unsigned char hash[SHA256_DIGEST_LENGTH];
	hishamsHash::sha256(myString, length, hash);

	hishamsHash::printsha256(hash);
	
	return 0;
}



#endif
