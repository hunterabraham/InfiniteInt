#ifndef H_HEADER
#define H_HEADER
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
class InfiniteInt {

	friend std::ostream& operator <<(std::ostream&, const InfiniteInt&);
	friend std::istream& operator >>(std::istream&, InfiniteInt&);
	friend bool operator <(const InfiniteInt&, const InfiniteInt&);
	friend bool operator >(const InfiniteInt&, const InfiniteInt&);
	friend bool operator <=(const InfiniteInt&, const InfiniteInt&);
	friend bool operator >=(const InfiniteInt&, const InfiniteInt&);
	friend bool operator ==(const InfiniteInt&, const InfiniteInt&);
	friend bool operator !=(const InfiniteInt&, const InfiniteInt&);


	public:
		/**
		  * getter function for this class's digits field
		  *
		  * @return this class' digits
		  */
		std::vector<unsigned int>* getDigits() const {
			return this->digits;
		}

		/**
		 * Create a default constructor for InfiniteInt that sets the value of your InfiniteInt to
		 * a default value of 0.i
		 */
		InfiniteInt() {
			digits = new std::vector<unsigned int>;
			digits->push_back(0);
		}
		

		/**
		 * InfiniteInt(unsigned long long val) Create a parameterized constructor for InfiniteInt that
		 * sets the starting value to val.
		 * @param val - the value of digits
	     */
		InfiniteInt(unsigned long long val) {
			digits = new std::vector<unsigned int>;
			while (val != 0) {
				int num = val % 10;
				digits->push_back(num);
				val /= 10;
			}
			std::reverse(digits->begin(), digits->end());
		}

		/**
		 * explicit InfiniteInt(std::vector<unsigned int>* new_digits) Create a parameterized constructor for InfiniteInt that sets the starting value 
		 * equal to the digits pointed to by new_digits.
		 * @param new_digits - a vector of new digits that will make the digits vector
		 */
		explicit InfiniteInt(std::vector<unsigned int>* new_digits) {
			digits = new std::vector<unsigned int>;
			for (std::vector<unsigned int>::iterator it = new_digits->begin(); it < new_digits->end(); ++it) {
				digits->push_back(*it);
			}
		}


		/**
		  * a copy constructor for InfiniteInt that allocates
		  * new memory for digits and then copies each digit from the obj vector to the newly allocated
		  * vector.
		  * 
		  * @param obj - the address to the InfiniteInt
		  */
		InfiniteInt(const InfiniteInt &obj) {
			std::vector<unsigned int>* new_digits = obj.getDigits();
			digits = new std::vector<unsigned int>;
			for (std::vector<unsigned int>::iterator it = new_digits->begin(); it < new_digits->end(); ++it) {
				digits->push_back(*it);
			}
		}
		

		/**
		 * Overload the copy-assignment operator. This
		 * will look similar to the copy constructor, but make sure to perform a self-assignment test
		 * @param - an InfiniteInt object that will be copied 
		 */
		InfiniteInt& operator=(const InfiniteInt &);
	
		/**
		 * Overload of the addition operator
		 *
		 * @param - the number to add
		 */
		InfiniteInt& operator+(const InfiniteInt &);
	
		/**
		 * Overload of the subtraction operator
		 *
		 * @param - the number to subtract
		 */
		InfiniteInt& operator-(const InfiniteInt &);
	

		/**
		 * Overload the add-assignment operator. This will add a number to the current val and 
		 * Assign
		 *
		 * @param - an InfiniteInt to add
		 */
		InfiniteInt& operator +=(const InfiniteInt &);
	
		/**
		 * Overload the subtract-assignment operator. This will subtract a number from the current
		 * val and assign.
		 *
		 * @param - the number to subtract from this InfiniteInt
		 */
		InfiniteInt& operator -=(const InfiniteInt &);
		
		/**
		 * Overload the prefix addition operator.
		 */
		InfiniteInt& operator ++();     // Prefix
	
		/**
		 * Overload the prefix subtraction operator.
		 */
		InfiniteInt& operator --();     // Prefix
		
		/**
		 * Overload the postfix addition operator
		 */
		InfiniteInt operator ++(int); // Postfix
	
		/**
		 * Overload the postfix subtraction operator
		 */
		InfiniteInt operator --(int); // Postfix
		
		/**
		 * Overload the class destructor
		 */
		~InfiniteInt() {
			free(digits);
		}
	private:
		std::vector<unsigned int>* digits;

		const unsigned int radix = 10;

};


#endif
