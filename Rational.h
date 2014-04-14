#ifndef RATIONAL_H_
#define RATIONAL_H_
#include "Number.h"
#include <string>
using namespace std;
class Rational : public Number {
public:
	Rational(int numerator,int denominator);
	// integer constructor
	Rational(int numerator);
	int getNum();
	int getDenom();

	Number* simplify();
	string toString();
	string getType();
	float getValue();
	string getType2();
	string getBase();
	string getLogOf();

private:
	int numerator, denominator;
	//float value;
	string stype;
};

#endif /* RATIONAL_H_ */
