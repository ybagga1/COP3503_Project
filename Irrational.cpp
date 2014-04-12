#include "Irrational.h"
#include <cmath>

Irrational::Irrational(){
}

Irrational::Irrational(string irr){
	if(irr.at(0) == 'e'){
		sType = "e";
		fValue = 2.7;
	}
	else if(irr.at(0) == 'l'){
		sType = "log";
		int i;
		for(i = 4; ':'!=irr.at(i); i++){
			base += irr.at(i);
		}
		for(i += 1; i<irr.length(); i++){
			logOf = irr.at(i);
		}
		//fValue = (log (strToD logOf)/log (base);
	}
	else if(irr.at(0) == 'p' || irr.at(0) == 'P'){
		sType = "pi";
		fValue = 3.14159;
	}
	else if(irr.at(0) == 's'){
		sType = "sqrt";
		for(int i = 5; i < irr.length(); i++){
			sqrtOf += irr.at(i);
		}
		//fValue = sqrt (strToD sqrtOf);
	}
	else if(irr.at(0) == ('0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9')){
		sType = "nrt";
		int i = 0;
		for(i = 0; 'r' != irr.at(i); i++){
			n = irr.at(i);
		}
		for(i += 3; i < irr.length(); i++){
			rootOf += irr.at(i);
		}
		//fValue = pow (strToD rootOf, (1/n));
	}
	else{
		cout<< "Error...not an irrational number" << endl;
	}
}

string Irrational::getType(){
	return sType;
}

string Irrational::toString(){
	return "aaa";
}

float Irrational::getValue(){
	return fValue;
}

Number Irrational::simplify(){
	Number * s = this;
	return s;
}
