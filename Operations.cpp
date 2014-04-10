#include "Operations.h"
#include <math>
Operations::Operations() {
	
}
Operations::~Operations() {
	
}
Number Operations::add(Number a, Number b) {
	if (a.type() == "Rational" && b.type() == "Rational") {
		aNum = a.getNum();
		aDenom = a.getDenom();
		bNum = b.getNum();
		bDenom = b.getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = (aNum * bDenom) + (bNum * aDenom);
		Number ans = new Rational(ansNum, ansDenom);
	}
	else if ((a.type() == "Rational" && b.type() == "Irrational") || (b.type() == "Rational" && a.type() == "Irrational")) {
		if (a.type() == "Rational") {
			aNum = a.getNum();
			aDenom = a.getDenom();
		}
		else {
			bNum = b.getNum();
			bDenom = b.getDenom();
		}
		
	}
	else {
		//sum two irrational numbers
	}
	ans.simplify();
	return ans;
}
Number Operations::subtract(Number a, Number b) {
	if (a.type() == "Rational" && b.type() == "Rational") {
		aNum = a.getNum();
		aDenom = a.getDenom();
		bNum = b.getNum();
		bDenom = b.getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = (aNum * bDenom) - (bNum * aDenom);
		Number ans = new Rational(ansNum, ansDenom);
	}
	else if ((a.type() == "Rational" && b.type() == "Irrational") || (b.type() == "Rational" && a.type() == "Irrational")) {
		if (a.type() == "Rational") {
			aNum = a.getNum();
			aDenom = a.getDenom();
		}
		else {
			bNum = b.getNum();
			bDenom = b.getDenom();
		}
		
	}
	else {
		//sum two irrational numbers
	}
	ans.simplify();
	return ans;
}
Number Operations::multiply(Number a, Number b) {
	if (a.type() == "Rational" && b.type() == "Rational") {
		aNum = a.getNum();
		aDenom = a.getDenom();
		bNum = b.getNum();
		bDenom = b.getDenom();
		ansDenom = aDenom * bDenom;
		ansNum = aNum * bNum;
		Number ans = new Rational(ansNum, ansDenom);
	}
	else if ((a.type() == "Rational" && b.type() == "Irrational") || (b.type() == "Rational" && a.type() == "Irrational")) {
		if (a.type() == "Rational") {
			aNum = a.getNum();
			aDenom = a.getDenom();
		}
		else {
			bNum = b.getNum();
			bDenom = b.getDenom();
		}
		
	}
	else {
		//sum two irrational numbers
	}
	ans.simplify();
	return ans;
}
Number Operations::divide(Number a, Number b) {
	if (a.type() == "Rational" && b.type() == "Rational") {
		aNum = a.getNum();
		aDenom = a.getDenom();
		bNum = b.getNum();
		bDenom = b.getDenom();
		ansDenom = aDenom * bNum;
		ansNum = aNum * bDenom;
		Number ans = new Rational(ansNum, ansDenom);
	}
	else if ((a.type() == "Rational" && b.type() == "Irrational") || (b.type() == "Rational" && a.type() == "Irrational")) {
		if (a.type() == "Rational") {
			aNum = a.getNum();
			aDenom = a.getDenom();
		}
		else {
			bNum = b.getNum();
			bDenom = b.getDenom();
		}
		
	}
	else {
		//sum two irrational numbers
	}
	ans.simplify();
	return ans;
}
Number Operations::exponentiate(Number a, Number b) {
		if (a.type() == "Rational") {
		aNum = a.getNum();
		aDenom = a.getDenom();
		bNum = b.getNum();
		bDenom = b.getDenom();
		if (bDenom == 1) {
			for (int i = 0; i < bNum; i++) {
				aNum   *= aNum;
				aDenom *= aDenom;
			}
			Number ans = new Rational(aNum, aDenom);
		}
		else {
			// denominator of exponent not 1;
		}
	}
}
Number Operations::logbase(Number a, Number b) {

}
Number Operations::nthroot(Number a, Number b) 
	int answer;
	double a, b, ans;
	if (a.type() == "Rational") {
		aNum = a.getNum();
		aDenom = a.getDenom();
		bNum = b.getNum();
		bDenom = b.getDenom();
		a = aNum / aDenom;
		b = bNum / bDenom;
		ans = pow(b, a);
		if (ans == (int)ans) {
			answer = ans;
		}
		else {
			//irrational
		}
		Number solution = new Rational(answer);
	}
	return solution;
}
Number Operations::simplifyAns(Number a) {

}
Number Operations::toRational(double a) {
	
}
