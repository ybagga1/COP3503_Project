#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <Number.h>
#include <string>

class Rational : public Number {
public:
	Rational();
	Rational(int numerator,int denominator);
	// integer constructor
	Rational(int numerator);
	virtual ~Rational();
	int getNum();
	int getDenom();

	Number* simplify() = 0;
	string toString() = 0;
	string getType() = 0;
	float getValue() = 0;

private:
	int numerator, denominator;
	//float value;
	//string type;
};

#endif /* RATIONAL_H_ */
