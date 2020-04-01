#include "InfiniteInt.h"

#include <iostream>

int main() {
    
    // Make sure to first implement stream insertion operator!
    
    // Testing long param constructor and no-arg constructor
	std::cout << "Constructing n1..." << std::endl;
	InfiniteInt n1(412);
	for (std::vector<unsigned int>::iterator itr = n1.getDigits()->begin(); itr != n1.getDigits()->end(); ++itr) {
		std::cout << *itr;
	}
	std::cout << std::endl;
	
	
	std::cout << "Constructing n2..." << std::endl;
	InfiniteInt n2;
    std::cout << "n1 should be 412: " << n1 << std::endl;
    std::cout << "n2 should be 0: " << n2 << std::endl;
    std::cout << std::endl;

    // Testing copy Op=
    std::cout << "Changing value of n2..." << std::endl;
    n2 = 3;
    std::cout << "n2 should be 3: " << n2 << std::endl;
    std::cout << std::endl;

    // Testing copy constructor
    std::cout << "Constructing n3..." << std::endl;
    InfiniteInt n3(n2);
    std::cout << "n3 should be 3: " << n3 << std::endl;

	std::cout << "Constructing n3..." << std::endl;
	InfiniteInt n4(n3 + n2);
    // Add more code here to test InfiniteInt here!

    return 0;
}
