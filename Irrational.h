#ifndef IRRATIONAL_H_
#define IRRATIONAL_H_
#include <string>
using namespace std;

class Irrational : public Number {
public:
	// default constructor
	Irrational();
	// addition/subtraction/division/multiplication/nthroot/log constructor
	Irrational(Number a, string operand, Number b);
	~Irrational();
};

#endif /* IRRATIONAL_H_ */







TEst
