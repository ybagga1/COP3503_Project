#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include "Number.h"
#include <stdlib.h>
#include <iostream>
#include <string>
class Operations {
public:
	Operations();
	~Operations();
	Number* add(Number* a, Number* b);
	Number* subtract(Number* a, Number* b);
	Number* multiply(Number* a, Number* b);
	Number* divide(Number* a, Number* b);
	Number* exponentiate(Number* a, Number* b);
	Number* logbase(Number* a, Number* b);
	Number* nthroot(Number* a, Number* b);
	Number* simplifyAns(Number* a);
	Number* toRational(double a);
private:
	int aNum, aDenom, bNum, bDenom, ansNum, ansDenom;
	float irrVal, irrVal2, ansVal;
	string irrAns, irrStr, irrStr2;
};

#endif /* OPERATIONS_H_ */

