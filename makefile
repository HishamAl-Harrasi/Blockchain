make:
	g++ -std=c++17 block.cpp -o block -lssl -lcrypto
run:
	./block
