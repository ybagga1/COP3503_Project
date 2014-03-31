#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational : public Number {
public:
	Rational(int numerator,int denominator);
	// integer constructor
	Rational(int numerator);
	~Rational();
	Number simplify();
	int getNum();
	int getDenom();
private:
	int numerator, denominator;
};

#endif /* RATIONAL_H_ */
