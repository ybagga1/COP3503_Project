#ifndef IRRATIONAL_H_
#define IRRATIONAL_H_
#include <string>
#include "Number.h"
using namespace std;

class Irrational : public Number {
public:
	// default constructor
	Irrational();
	// addition/subtraction/division/multiplication/nthroot/log constructor
	Irrational(string irr);
	~Irrational();
	Number simplify();
	string toString();
	string getType();
	float getValue();
private:
	string base;
	string logOf;
	string sqrtOf;
	string rootOf;
	string n;
};

#endif /* IRRATIONAL_H_ */
