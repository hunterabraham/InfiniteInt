#include "InfiniteInt.h"

#include <iostream>

int main() {
    
    // Make sure to first implement stream insertion operator!
	std::cout << "****** CONSTRUCTORS ******" << std::endl << std::endl;    
    // Testing long param constructor and no-arg constructor
	std::cout << "Constructing n1..." << std::endl;
	InfiniteInt n1(412);
	
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

	std::cout << "Constructing n4..." << std::endl;
	InfiniteInt n4();
	std::cout << "n4 should be 0: " << n4 << std::endl;
    std::cout << std::endl << "****** ADDITION ******" << std::endl << std::endl;	
	InfiniteInt n5 = n3 + n1;
	std::cout << "n5 should be 415 (412 + 3): " << n5 << std::endl;

	InfiniteInt n6 = n1 + n3;
	std::cout << "n6 should be 415 ( 3 + 412): " << n6 << std::endl;
	// Add more code here to test InfiniteInt here!
	InfiniteInt n7(9223372036854775807);
	InfiniteInt n8(9223372036854775807);
	InfiniteInt n9 = n7 + n8;
	std::cout << "n9 should be 18446744073709551614: " << n9 << std::endl;
	n9 = InfiniteInt(9223372036854775807) + InfiniteInt(9223372036854775807);
	std::cout << "n9 should be 18446744073709551614: " << n9 << std::endl;
	
	InfiniteInt n11(999);
	InfiniteInt n10 = InfiniteInt(4556) + n11;
	std::cout << "n10 should be 5555 (999 + 4556): " << n10 << std::endl;	
	InfiniteInt n12 = n11 + InfiniteInt(2);
	std::cout << "n12 should be 1001: " << n12 << std::endl;

	InfiniteInt n13 = InfiniteInt(5557) + InfiniteInt(4556);
	std::cout << "n13 should be 10113: " << n13 << std::endl;
	

	std::cout << std::endl << "****** SUBTRACTION ******" << std::endl << std::endl;
	InfiniteInt n15 = InfiniteInt(412) - InfiniteInt(45);
	std::cout << "n15 should be 367: " << n15 << std::endl;
	std::cout << "n15 should be 998: " << InfiniteInt(1000) - InfiniteInt(2) << std::endl;	
	std::cout << "n15 should be 0: " << InfiniteInt(2) - InfiniteInt(998) << std::endl;
	std::cout << "n15 should be 996: " << InfiniteInt(998) - InfiniteInt(2) << std::endl;	
	std::cout << "n15 shoudl be 0: " << InfiniteInt(971) - InfiniteInt(987) << std::endl;
	std::cout << "n15 should be 0: " << InfiniteInt(971) - InfiniteInt(971) << std::endl;

	std::cout << std::endl << "****** INCREMENT AND DECREMENT ******" << std::endl << std::endl;
	std::cout << "n13 should be 10114: " << ++n13 << std::endl;
	std::cout << "n13 should be 10114: " << n13++ << std::endl;
	std::cout << "n13 should be 10115: " << n13 << std::endl;
	std::cout << "n13 should be 10114: " << --n13 << std::endl;
	std::cout << "n13 should be 10114: " << n13-- << std::endl;
	std::cout << "n13 should be 10113: " << n13 << std::endl;

	std::cout << std::endl << "****** PLUS-EQUAL AND MINUS-EQUAL ******" << std::endl << std::endl;
	n13 += InfiniteInt(2);
	std::cout << "n13 should be 10115: " << n13 << std::endl;
	n13 -= InfiniteInt(2);
	std::cout << "n13 should be 10113: " << n13 << std::endl;
	
	std::cout << std::endl << "****** COMPARISON OPERATORS ******" << std::endl << std::endl;
	n13 = InfiniteInt(23);
	InfiniteInt n14 = InfiniteInt(28);
	std::cout << "n13 > n14 should be false: " << (n13 > n14) << std::endl;
	std::cout << "n14 > n13 should be true: " << (n14 > n13) << std::endl;
	std::cout << "n13 >= n14 should be false: " << (n13 >= n14) << std::endl;
	std::cout << "n14 >= n13 should be true: " << (n14 >= n13) << std::endl;

	
	n13 = InfiniteInt(28);
	n14 = InfiniteInt(23);
	std::cout << "n13 < n14 should be false: " << (n13 < n14) << std::endl;
	std::cout << "n14 < n13 should be true: " << (n14 < n13) << std::endl;
	std::cout << "n13 <= n14 should be false: " << (n13 <= n14) << std::endl;
	std::cout << "n14 <= n13 should be true: " << (n14 <= n13) << std::endl;
	std::cout << "n14 == n13 should be false: " << (n13 == n14) << std::endl;
	std::cout << "n14 != n13 should be true: " << (n13 != n14) << std::endl;

	n13 = InfiniteInt(23);
	std::cout << "n13 == n14 should be true: " << (n13 == n14) << std::endl;
	std::cout << "n13 != should be false: " << (n13 != n14) << std::endl;
	std::cout << "n13 >= n14 should be true: " << (n13 >= n14) << std::endl;
	std::cout << "n13 <= n14 should be true: " << (n13 <= n14) << std::endl;
	return 0;
}
