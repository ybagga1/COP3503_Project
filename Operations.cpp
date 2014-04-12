#include "Operations.h"
#include "Rational.h"
#include "Irrational.h"
#include <cmath>
using namespace std;

Operations::Operations() {

}
Operations::~Operations() {

}
Number * Operations::add(Number * a, Number * b) {
	Number * ans;
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		Rational r1 = a;
		Rational r2 = b;
		aNum = r1.getNum();
		aDenom = r1.getDenom();
		bNum = r2.getNum();
		bDenom = r2.getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = (aNum * bDenom) + (bNum * aDenom);
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			Rational r1 = a;
			aNum = r1.getNum();
			aDenom = r1.getDenom();
		}
		else {
			Rational r2 = b;
			bNum = r2.getNum();
			bDenom = r2.getDenom();
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
		Rational r1 = a;
		Rational r2 = b;
		aNum = r1.getNum();
		aDenom = r1.getDenom();
		bNum = r2.getNum();
		bDenom = r2.getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = (aNum * bDenom) - (bNum * aDenom);
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			Rational r1 = a;
			aNum = r1.getNum();
			aDenom = r1.getDenom();
		}
		else {
			Rational r2 = b;
			bNum = r2.getNum();
			bDenom = r2.getDenom();
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
		Rational r1 = a;
		Rational r2 = b;
		aNum = r1.getNum();
		aDenom = r1.getDenom();
		bNum = r2.getNum();
		bDenom = r2.getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = aNum * bNum;
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			Rational r1 = a;
			aNum = r1.getNum();
			aDenom = r1.getDenom();
		}
		else {
			Rational r2 = b;
			bNum = r2.getNum();
			bDenom = r2.getDenom();
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
		Rational r1 = a;
		Rational r2 = b;
		aNum = r1.getNum();
		aDenom = r1.getDenom();
		bNum = r2.getNum();
		bDenom = r2.getDenom();
		ansDenom = aDenom * bNum;
		ansNum = aNum * bDenom;
		ans = new Rational(ansNum, ansDenom);
	}
	else if ((a->getType() == "Rational" && b->getType() == "Irrational") || (b->getType() == "Rational" && a->getType() == "Irrational")) {
		if (a->getType() == "Rational") {
			Rational r1 = a;
			aNum = r1.getNum();
			aDenom = r1.getDenom();
		}
		else {
			Rational r2 = b;
			bNum = r2.getNum();
			bDenom = r2.getDenom();
		}

	}
	else {
		//sum two irrational numbers
	}
	ans->simplify();
	return ans;
}
Number * Operations::exponentiate(Number * a, Number * b) {
		if (a->getType() == "Rational") {
			Rational r1 = a;
			Rational r2 = b;
			aNum = r1.getNum();
			aDenom = r1.getDenom();
			bNum = r2.getNum();
			bDenom = r2.getDenom();
		if (bDenom == 1) {
			for (int i = 0; i < bNum; i++) {
				aNum   *= aNum;
				aDenom *= aDenom;
			}
			Number * ans = new Rational(aNum, aDenom);
		}
		else {
			// denominator of exponent not 1;
		}
	}
}
Number * Operations::simplifyAns(Number * a) {

}
Number * Operations::toRational(double a) {

}
