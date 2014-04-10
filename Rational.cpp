#include "Rational.h"
Rational::Rational() {

}
Number Rational::simplify(int a, int b) {
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
