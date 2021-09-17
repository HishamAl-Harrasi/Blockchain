#include <iostream>
#include <openssl/sha.h>

namespace hasher{

	void sha256(const char* input, size_t length, unsigned char* ptr){
		unsigned char hash[SHA256_DIGEST_LENGTH];
		
		const unsigned char* p = reinterpret_cast<const unsigned char*> (input);
		
		SHA256(p, length, ptr);

	};

	// Reference: https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
	void sha256str(unsigned char* hash,  char strHash[64]){

		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			sprintf(strHash + (i * 2), "%02x", hash[i]);
		
	}

	void printsha256(unsigned char* hash){
		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			printf("%02x", hash[i]);

	}

}