#include 'Rational.h'


Rational:: Rational(){
	numerator = 1;
	denominator = 1;
	type = "Rational";
	value = 1;
}

Rational:: Rational(int numerator){
	this.numerator = numerator;
	this.denominator = 1;
	type = "Rational";
	value = numerator;
}

Rational:: Rational(int numerator, int denominator){
	this.numerator = numerator;
	this.denominator = denominator;
	simplify();
	type = "Rational";
	value = (float)numerator / (float)denominator;
	
}

int Rational:: getNum(){
	return numerator;
}

int Rational:: getDenom(){
	return denominator;
}

string Rational:: toString(){
	return numerator + ' '
	
}

Rational Rational::simplify(int a, int b) {
	if (a < b) {
		for (int i = 2, i < b, i++) {
			if (a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
			}
		}
	}
	else {
		for (int i = 2, i < a, i++) {
			if (b % i == 0 && a % i == 0) {
				a /= i;
				b /= i;
			}
		}
	}
	Number fraction = new Number(a, b);
	return fraction;
}
