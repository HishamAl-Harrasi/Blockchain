#ifndef HASH_H
#define HASH_H

#include "hash.cpp"

namespace hasher{


	void sha256(const char* input, size_t length, unsigned char* ptr);

	void printsha256(unsigned char* hash);


};



#endif