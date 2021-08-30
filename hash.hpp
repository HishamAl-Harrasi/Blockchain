#ifndef HASH_H
#define HASH_H

#include <openssl/sha.h>

namespace hishamsHash{


	void sha256(const char* input, size_t length, unsigned char* ptr){
		unsigned char hash[SHA256_DIGEST_LENGTH];
		
		const unsigned char* p = reinterpret_cast<const unsigned char*> (input);

		int index = 0;
		while (p[index] != '\0'){
			std::cout << p[index];
			index++;
		}
		std::cout << std::endl;

		SHA256(p, length - 1, ptr);		
	};

	void printsha256(unsigned char* hash){
		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			printf("%02x", hash[i]);

		std::cout << std::endl;
	}


};



#endif