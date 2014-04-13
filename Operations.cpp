#include "Operations.h"
#include "Rational.h"
#include "Irrational.h"
#include "Number.h"
#include <sstream>
#include <ostream>
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
			irrStr = b->toString();
			stringstream ss, tt;
			ss<<aNum;
			tt<<aDenom;
			irrAns = "( " + ss.str() + " + " + tt.str() + irrStr + " )" + " / " + tt.str();
			irrVal = b->getValue();
			ansVal = (float) (aNum/aDenom) + irrVal;
			ans = new Irrational(ansVal, irrAns);
		}
		else {
			bNum = b->getNum();
			bDenom = b->getDenom();
			irrStr = a->toString();
			stringstream ss, tt;
			ss<<bNum;
			tt<<bDenom;
			irrAns = "( " + ss.str() + " + " + tt.str() + irrStr + " )" + " / " + tt.str();
			irrVal = a->getValue();
			ansVal = (float) (bNum/bDenom) + irrVal;
			ans = new Irrational(ansVal, irrAns);
		}

	}
	else {
		irrStr  = a->toString();
		irrStr2 = b->toString();
		irrAns = irrStr + " + " + irrStr2;
		irrVal = a->getValue();
		irrVal2 = b->getValue();
		ansVal = (float) irrVal + irrVal2;
		ans = new Irrational(ansVal, irrAns);
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
					irrStr = b->toString();
					stringstream ss, tt;
					ss<<aNum;
					tt<<aDenom;
					irrAns = "( " + ss.str() + " - " + tt.str() + irrStr + " )" + " / " + tt.str();
					irrVal = b->getValue();
					ansVal = (float) (aNum/aDenom) - irrVal;
					ans = new Irrational(ansVal, irrAns);
				}
				else {
					bNum = b->getNum();
					bDenom = b->getDenom();
					irrStr = a->toString();
					stringstream ss, tt;
					ss<<bNum;
					tt<<bDenom;
					irrAns = "( " + ss.str() + " - " + tt.str() + irrStr + " )" + " / " + tt.str();
					irrVal = a->getValue();
					ansVal = (float) (bNum/bDenom) - irrVal;
					ans = new Irrational(ansVal, irrAns);
				}

			}
			else {
				irrStr  = a->toString();
				irrStr2 = b->toString();
				irrAns = irrStr + " - " + irrStr2;
				irrVal = a->getValue();
				irrVal2 = b->getValue();
				ansVal = (float) irrVal - irrVal2;
				ans = new Irrational(ansVal, irrAns);
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
					irrStr = b->toString();
					stringstream ss, tt;
					ss<<aNum;
					tt<<aDenom;
					irrAns = "( " + ss.str() + " * " + irrStr + " )" + " / " + tt.str();
					irrVal = b->getValue();
					ansVal = (float) (aNum/aDenom) * irrVal;
					ans = new Irrational(ansVal, irrAns);
				}
				else {
					bNum = b->getNum();
					bDenom = b->getDenom();
					irrStr = a->toString();
					stringstream ss, tt;
					ss<<bNum;
					tt<<bDenom;
					irrAns = "( " + ss.str() + " * " + irrStr + " )" + " / " + tt.str();
					irrVal = a->getValue();
					ansVal = (float) (bNum/bDenom) * irrVal;
					ans = new Irrational(ansVal, irrAns);
				}

			}
			else {
				irrStr  = a->toString();
				irrStr2 = b->toString();
				irrAns = irrStr + " * " + irrStr2;
				irrVal = a->getValue();
				irrVal2 = b->getValue();
				ansVal = (float) irrVal * irrVal2;
				ans = new Irrational(ansVal, irrAns);
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
					irrStr = b->toString();
					stringstream ss, tt;
					ss<<aNum;
					tt<<aDenom;
					irrAns = ss.str() + " / ( " + tt.str() +  " * " + irrStr + " )";
					irrVal = b->getValue();
					ansVal = (float) (aNum/aDenom) / irrVal;
					ans = new Irrational(ansVal, irrAns);
				}
				else {
					bNum = b->getNum();
					bDenom = b->getDenom();
					irrStr = a->toString();
					stringstream ss, tt;
					ss<<bNum;
					tt<<bDenom;
					irrAns = "( " + irrStr + " * " + tt.str() + " ) / " + ss.str();
					irrVal = a->getValue();
					ansVal = (float) (bNum/bDenom) + irrVal;
					ans = new Irrational(ansVal, irrAns);
				}

			}
			else {
				irrStr  = a->toString();
				irrStr2 = b->toString();
				irrAns = irrStr + " / " + irrStr2;
				irrVal = a->getValue();
				irrVal2 = b->getValue();
				ansVal = (float) irrVal / irrVal2;
				ans = new Irrational(ansVal, irrAns);
			}
	ans->simplify();
	return ans;
}
Number * Operations::exponentiate(Number * a, Number * b) {
		Number* ans;
		if (a->getType() == "Rational" && b->getType() == "Rational") {
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
				aNum = a->getNum();
				aDenom = a->getDenom();
				bNum = b->getNum();
				bDenom = b->getDenom();
				Number* tempB = new Rational(bNum);
				Number* tempAns = exponentiate(a,tempB);
				stringstream ss;
				ss<<bDenom;
				string ansStr = ss.str() + "rt:" + tempAns->toString();
				ans = new Irrational(ansStr);
			}
		}
		else { //a is not rational
			string str = a->toString() + "^" + b->toString();
			float v = pow (a->getValue(), b->getValue());
			ans = new Irrational(v, str);
		}
	return ans;
}
Number * Operations::simplifyAns(Number * a) {
	Number* ans;
	return ans;
}
Number * Operations::toRational(string a) {
	Number* ans;
	for (int i =0; i < a.size(); i++) {
		if (a.at(i) == "." ) {
			a.erase(i);
			int power = a.size() - (i + 1);
			tenPower = pow (10, power);
			char *b=new char[a.size()];
			b[str.size()]=0;
			memcpy(b,a.c_str(),a.size());
			ans = new Rational(atoi(b), tenPower);
			break;
		}
		else {
			char* b = new char[a.size()];
			b[a.size()]= 0;
			memcpy(b,a.c_str(),a.size());
			ans = new Rational (atoi(b));
		}
	}
	return ans;
}
