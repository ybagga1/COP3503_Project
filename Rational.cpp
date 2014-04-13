#include "Rational.h"
#include <string>
#include <sstream>
using namespace std;

Rational::Rational(int numerator){
	this->numerator = numerator;
	this->denominator = 1;
	sType = "Rational";
	fValue = numerator;
}

Rational::Rational(int numerator, int denominator){
	if(denominator == 0)
		throw invalid_argument("Cannot divide by zero");
		
	this->numerator = numerator;
	this->denominator = denominator;
	
	sType = "Rational";
	fValue = (float)numerator / (float)denominator;
	
}


int Rational::getNum(){
	return this->numerator;
}

int Rational::getDenom(){
	return this->denominator;
}


//if denominator = 1, return the numerator as a string
//else return "numerator '/' denominator"
string Rational::toString() {
	string number;
	if (this->denominator == 0) {
		return "Cannot divide by zero.";
	}
	else if (this->denominator == 1) {
		stringstream ss;
		ss<<this->numerator;
		number = ss.str();
	}
	else {
		stringstream ss, tt;
		ss<<this->numerator;
		tt<<this->denominator;
		number = ss.str() + "/" + tt.str();
	}
	return number;
}
string Rational::getType()
{
	return this->sType;
}

float Rational::getValue()
{
	return this->fValue;
}
Number* Rational::simplify() {
	
	int a= this->getNum();
	int b = this->getDenom();
	if (a < b) {
		for (int i = 2; i < b; i++) {
			if (a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
			}
		}
	}
	else {
		for (int i = 2; i < a; i++) {
			if (b % i == 0 && a % i == 0) {
				a /= i;
				b /= i;
			}
		}
	}
	Number* fraction = new Rational(a, b);
	return fraction;
}
