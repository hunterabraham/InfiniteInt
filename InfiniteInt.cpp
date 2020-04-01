#include "InfiniteInt.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


InfiniteInt& InfiniteInt::operator+(const InfiniteInt &rhs){
	vector<unsigned int>::iterator lhsBegin = this->getDigits()->begin();
	vector<unsigned int>::iterator rhsBegin = rhs.getDigits()->begin();
	vector<unsigned int>::iterator lhsEnd = this->getDigits()->end();
	vector<unsigned int>::iterator rhsEnd = rhs.getDigits()->end();
	vector<unsigned int>::iterator lhsIterator;
	vector<unsigned int>::iterator rhsIterator;
	vector<unsigned int>* retVec = new vector<unsigned int>;
	int carryOver = 0;
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		int newDigit = *lhsIterator + *rhsIterator;
		newDigit += carryOver;
		if (newDigit > 9) {
			carryOver = 1;
			retVec->push_back(newDigit % 10);
			continue;
		}
		retVec->push_back(newDigit);
	}
	*this->digits = *retVec;
	return *this;
}



InfiniteInt& InfiniteInt::operator-(const InfiniteInt &rhs){
	vector<unsigned int>::iterator lhsBegin = this->getDigits()->begin();
	vector<unsigned int>::iterator rhsBegin = rhs.getDigits()->begin();
	vector<unsigned int>::iterator lhsEnd = this->getDigits()->end();
	vector<unsigned int>::iterator rhsEnd = rhs.getDigits()->end();
	vector<unsigned int>::iterator lhsIterator;
	vector<unsigned int>::iterator rhsIterator;
	vector<unsigned int>* retVec = new vector<unsigned int>;
	int carryOver = 0;
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		int newDigit = *lhsIterator - *rhsIterator;
		newDigit -= carryOver;
		if (newDigit < 0) {
			carryOver = 1;
			retVec->push_back(newDigit + 10);
			continue;
		}
		retVec->push_back(newDigit);
	}
	*this->digits = *retVec;
	return *this;
}



InfiniteInt& InfiniteInt::operator=(const InfiniteInt& rhs){
	if(this != &rhs) {
		this->digits = new vector<unsigned int>;
		for (vector<unsigned int>::iterator i = rhs.getDigits()->begin(); i != rhs.getDigits()->end(); ++i) {
			this->digits->push_back(*i);
		}
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
		
InfiniteInt& InfiniteInt::operator ++() {
	*this += InfiniteInt(1);
	return (*this - InfiniteInt(1));
}
	
InfiniteInt& InfiniteInt::operator --() {
	*this -= InfiniteInt(1);
	return (*this + InfiniteInt(1));
}
		
InfiniteInt InfiniteInt::operator ++(int) {
	*this += InfiniteInt(1);
	return *this;
}
	
InfiniteInt InfiniteInt::operator --(int) {
	*this -= InfiniteInt(1);
	return *this;
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
		if(!is) {
			for (string::iterator it = s.begin(); it < s.end(); ++it) {
				rhs.getDigits()->push_back(*it);
			}
	}
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
	if (lhs.getDigits()->size() <= rhs.getDigits()->size()) {
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
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator <= *rhsIterator) {
			return true;
		} else if (*lhsIterator > *rhsIterator) {
			return false;
		}
	}
	return false;
}

bool operator >=(const InfiniteInt& lhs, const InfiniteInt& rhs) {
	if (lhs.getDigits()->size() >= rhs.getDigits()->size()) {
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
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator >= *rhsIterator) {
			return true;
		} else if (*lhsIterator < *rhsIterator) {
			return false;
		}
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
	for (lhsIterator = lhsBegin, rhsIterator = rhsBegin; (lhsIterator != lhsEnd) && (rhsIterator != rhsEnd); ++lhsIterator, ++rhsIterator) {
		if (*lhsIterator != *rhsIterator) {
			return true;
		}
	}
	return false;
}




