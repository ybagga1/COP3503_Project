#include "Operations.h"
#include "Rational.h"
#include "Irrational.h"
#include "Number.h"
#include <cmath>
using namespace std;

Operations::Operations() {
	aNum = 0;
	aDenom = 0;
	bNum = 0;
	bDenom = 0;
	ansNum = 0;
	ansDenom = 0;
}
Operations::~Operations() {

}
Number * Operations::add(Number * a, Number * b) {
	Number * ans;
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		aNum = a->getNum();
		aDenom = a->getDenom();
		bNum = b->getNum();
		bDenom = b->getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = (aNum * bDenom) + (bNum * aDenom);
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			aNum = a->getNum();
			aDenom = a->getDenom();
		}
		else {
			bNum = b->getNum();
			bDenom = b->getDenom();
		}

	}
	else {
		//sum two irrational numbers
	}
	ans->simplify();
	return ans;
}
Number * Operations::subtract(Number * a, Number * b) {
	Number * ans;
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		aNum = a->getNum();
		aDenom = a->getDenom();
		bNum = b->getNum();
		bDenom = b->getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = (aNum * bDenom) - (bNum * aDenom);
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			aNum = a->getNum();
			aDenom = a->getDenom();
		}
		else {
			bNum = b->getNum();
			bDenom = b->getDenom();
		}

	}
	else {
		//sum two irrational numbers
	}
	ans->simplify();
	return ans;
}
Number * Operations::multiply(Number * a, Number * b) {
	Number * ans;
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		aNum = a->getNum();
		aDenom = a->getDenom();
		bNum = b->getNum();
		bDenom = b->getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = aNum * bNum;
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			aNum = a->getNum();
			aDenom = a->getDenom();
		}
		else {
			bNum = b->getNum();
			bDenom = b->getDenom();
		}

	}
	else {
		//sum two irrational numbers
	}
	ans->simplify();
	return ans;
}
Number * Operations::divide(Number * a, Number * b) {
	Number * ans;
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		aNum = a->getNum();
		aDenom = a->getDenom();
		bNum = b->getNum();
		bDenom = b->getDenom();
		ansDenom = aDenom * bNum;
		ansNum = aNum * bDenom;
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			aNum = a->getNum();
			aDenom = a->getDenom();
		}
		else {
			bNum = b->getNum();
			bDenom = b->getDenom();
		}

	}
	else {
		//sum two irrational numbers
	}
	ans->simplify();
	return ans;
}
Number * Operations::exponentiate(Number * a, Number * b) {
		Number* ans;
		if (a->getType() == "Rational") {
			aNum = a->getNum();
			aDenom = a->getDenom();
		if (bDenom == 1) {
			for (int i = 0; i < bNum; i++) {
				aNum   *= aNum;
				aDenom *= aDenom;
			}
			ans = new Rational(aNum, aDenom);
		}
		else {
			// denominator of exponent not 1;
		}
	}
	return ans;
}
Number * Operations::simplifyAns(Number * a) {
	Number* ans;
	return ans;
}
Number * Operations::toRational(double a) {
	Number* ans;
	return ans;
}
