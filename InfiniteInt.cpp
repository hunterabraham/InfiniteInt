///////////////////////////////////////////////////////////////////////////////
// Main File:        demo.cpp
// This File:        InfiniteInt.cpp
// Semester:         CS 368 Spring 2020
//
// Author:           Hunter Abraham
// Email:            hjabraham@wisc.edu
// CS Login:         habraham
// Student ID:       9079608908
////////////////////////////////////////////////////////////////////////////////

#include "InfiniteInt.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


InfiniteInt& InfiniteInt::operator+(const InfiniteInt &rhs){
	vector<unsigned int>::const_reverse_iterator smallit;
    vector<unsigned int>::const_reverse_iterator smallend;
	vector<unsigned int>* sum;	
    // copy the larger vector
    if (rhs.getDigits()->size() > this->getDigits()->size() ) {
        sum = new vector<unsigned int>(*rhs.getDigits());
        smallit  = (*this->getDigits()).rbegin();
        smallend = (*this->getDigits()).rend();
    }
    else {
        sum = new vector<unsigned int> (*this->getDigits());
        smallit = (*rhs.getDigits()).rbegin();
        smallend = (*rhs.getDigits()).rend();
    }
    // add the smaller one, index by index, starting from the back
	vector<unsigned int>::reverse_iterator it;
	for (it = sum->rbegin(); smallit != smallend; ++it, ++smallit) {
        *it += *smallit;
	}
	// go over the summed vector, carry any values necessary
	for (it = sum->rbegin(); it != sum->rend(); ++it) {
		if (*it > 9) {
			if (it != sum->rend() &&  it == --sum->rend()) {
				*(it) = *it % 10;
				sum->insert(sum->begin(), 1);
				break;
			} else {
				*it = *it % 10;
				*(it + 1) += 1;
			}
    	}
	}	
	InfiniteInt* ret = new InfiniteInt(sum);
	
	return *ret;
}



InfiniteInt& InfiniteInt::operator -(const InfiniteInt &rhs) {
	if (rhs.getDigits()->size() > this->getDigits()->size()) {
		return *(new InfiniteInt(static_cast<unsigned long long int>(0)));
	}

	vector<unsigned int>::const_reverse_iterator smallit;
    vector<unsigned int>::const_reverse_iterator smallend;
	vector<int>* sum;	
    sum = new vector<int>();
	// deep copy left vector into sum vector
	for (vector<unsigned int>::iterator i = this->getDigits()->begin(); i != this->getDigits()->end(); ++i) {
		sum->push_back(static_cast<int>(*i));
	}
    smallit  = (*rhs.getDigits()).rbegin();
    smallend = (*rhs.getDigits()).rend();

	if (rhs.getDigits()->size() > this->getDigits()->size()) {
		return *(new InfiniteInt(static_cast<unsigned long long int>(0)));
	}

    // subtract the right vector, starting from the back
	for (vector<int>::reverse_iterator it = sum->rbegin(); smallit != smallend; ++it, ++smallit) {
		*it -= *smallit;
	}

	// remove any negative values by performing borrows
	unsigned int count = 0;
	for (vector<int>::reverse_iterator it = sum->rbegin(); it != sum->rend(); ++it) {
		count++;
		if (*it < 0) {
			if (count == sum->size()) {
				unsigned long long int val = 0;
				return *(new InfiniteInt(val));
			} else {
				*it = *it + 10;
				*(it + 1) -= 1;
			}
		}	
	}	
	
	// remove any leading 0s
	vector<unsigned int>* retVec = new vector<unsigned int>();
	for (vector<int>::iterator i = sum->begin(); i != sum->end(); ++i) {
		retVec->push_back(static_cast<unsigned int>(*i));
	}

	unsigned int i = 0;
	while ((*retVec)[i] == 0 && i < retVec->size()) {
		i++;
	}

	reverse(retVec->begin(), retVec->end());
	retVec->resize(retVec->size() - i);
	if (retVec->size() == 0) {
		retVec->insert(retVec->begin(), 0);
	}
	

	reverse(retVec->begin(), retVec->end());
	InfiniteInt* ret = new InfiniteInt(retVec);
	
	return *ret;
}
	


InfiniteInt& InfiniteInt::operator=(const InfiniteInt& rhs){
	if (*this != rhs) {
		this->digits = new vector<unsigned int>;
		for (vector<unsigned int>::iterator itr = rhs.getDigits()->begin(); itr != rhs.getDigits()->end(); ++itr)
			this->digits->push_back(*itr);
	}
	return *this;
}

InfiniteInt& InfiniteInt::operator +=(const InfiniteInt &num) {
	*this = *this + num;
	return *this;
}
	
InfiniteInt& InfiniteInt::operator -=(const InfiniteInt &num) {
	*this = *this - num;
	return *this;
}


InfiniteInt& InfiniteInt::operator --() {
	*this = *this - InfiniteInt(1);
	return *this;
}

InfiniteInt& InfiniteInt::operator ++() {
	*this += InfiniteInt(1);
	return *this;
}


InfiniteInt InfiniteInt::operator ++(int) {
	*this += InfiniteInt(1);
	return (*this - InfiniteInt(1));
}

InfiniteInt InfiniteInt::operator --(int) {
	*this = *this - InfiniteInt(1);
	return (*this + InfiniteInt(1));
}

std::ostream& operator <<(std::ostream& os, const InfiniteInt& rhs) {
	for (vector<unsigned int>::iterator itr = rhs.getDigits()->begin(); itr != rhs.getDigits()->end(); ++itr) {
		os << *itr;
	}
	return os;
}

std::istream& operator >>(std::istream& is, InfiniteInt& rhs) {
	string s;
	is >> s;
	// make sure entry is valid
	for(unsigned int i = 0; i < s.length(); i++) {
      if(!(((s[i] >= '0') && (s[i] <= '9')) || (s[i] == ' '))) {
		cout << "Invalid entry" << endl;
		return is;
	  }
	}
	rhs = InfiniteInt(stoi(s));
	return is;
}


bool operator <(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs.getDigits()->size() < rhs.getDigits()->size()) {
		return true;
	} else if (lhs.getDigits()->size() > rhs.getDigits()->size()) {
		return false;
	}
	vector<unsigned int>::iterator lhsBegin = lhs.getDigits()->begin();
	vector<unsigned int>::iterator rhsBegin = rhs.getDigits()->begin();
	vector<unsigned int>::iterator lhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator rhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator lhsIterator;
	vector<unsigned int>::iterator rhsIterator;
	// iterate from the front. if any value is smaller, return true. if any value is larger, return false
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator < *rhsIterator) {
			return true;
		} else if (*lhsIterator > *rhsIterator) {
			return false;
		}
	}
	return false;
}

bool operator >(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs.getDigits()->size() > rhs.getDigits()->size()) {
		return true;
	} else if (lhs.getDigits()->size() < rhs.getDigits()->size()) {
		return false;
	}
	vector<unsigned int>::iterator lhsBegin = lhs.getDigits()->begin();
	vector<unsigned int>::iterator rhsBegin = rhs.getDigits()->begin();
	vector<unsigned int>::iterator lhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator rhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator lhsIterator;
	vector<unsigned int>::iterator rhsIterator;
	// iterate from the front, if any value is larger, return true. if any value is smaller, return false
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator > *rhsIterator) {
			return true;
		} else if (*lhsIterator < *rhsIterator) {
			return false;
		}
	}
	return false;
}

bool operator <=(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs < rhs || lhs == rhs) {
		return true;
	}
	return false;
}

bool operator >=(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs > rhs || lhs == rhs) {
		return true;
	}
	return false;

}

bool operator ==(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs.getDigits()->size() > rhs.getDigits()->size()) {
		return false;
	} else if (lhs.getDigits()->size() < rhs.getDigits()->size()) {
		return false;
	}
	vector<unsigned int>::iterator lhsBegin = lhs.getDigits()->begin();
	vector<unsigned int>::iterator rhsBegin = rhs.getDigits()->begin();
	vector<unsigned int>::iterator lhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator rhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator lhsIterator;
	vector<unsigned int>::iterator rhsIterator;
	// if any value is unequal, return false
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator != *rhsIterator) {
			return false;
		}
	}
	return true;
}

bool operator !=(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs.getDigits()->size() > rhs.getDigits()->size()) {
		return true;
	} else if (lhs.getDigits()->size() < rhs.getDigits()->size()) {
		return true;
	}
	vector<unsigned int>::iterator lhsBegin = lhs.getDigits()->begin();
	vector<unsigned int>::iterator rhsBegin = rhs.getDigits()->begin();
	vector<unsigned int>::iterator lhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator rhsEnd = lhs.getDigits()->end();
	vector<unsigned int>::iterator lhsIterator;
	vector<unsigned int>::iterator rhsIterator;
	// if any value is unequal, return true
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator != *rhsIterator) {
			return true;
		}
	}
	return false;
}




