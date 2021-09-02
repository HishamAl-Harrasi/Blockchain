#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <string.h>
#include <chrono>
#include "hash.hpp"



int main(){

	const char* myString = "hello my name is hisham";
	size_t length = strlen(myString);

	unsigned char hash[SHA256_DIGEST_LENGTH];
	hasher::sha256(myString, length, hash);

	hasher::printsha256(hash);
	
	return 0;
}