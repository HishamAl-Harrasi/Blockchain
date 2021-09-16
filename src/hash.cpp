#include <iostream>
#include <openssl/sha.h>

namespace hasher{

	void sha256(const char* input, size_t length, unsigned char* ptr){
		unsigned char hash[SHA256_DIGEST_LENGTH];
		
		const unsigned char* p = reinterpret_cast<const unsigned char*> (input);
		
		SHA256(p, length, ptr);

		// ---------------------------------------
	};


	void printsha256(unsigned char* hash){
		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			printf("%02x", hash[i]);


		printf("\n\n"); // -------------------------------------

		printf("%02x", hash[SHA256_DIGEST_LENGTH - 1]);

		char hexHash[SHA256_DIGEST_LENGTH];

		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			sprintf(hexHash + i, "%02x", hash[i]);

		std::cout << hexHash;
			
		printf("%s", hexHash);

		std::cout << std::endl;
	}

}