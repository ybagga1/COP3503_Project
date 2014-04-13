#ifndef NUMBER_H_
#define NUMBER_H_
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Number {
public:
	virtual Number* simplify() = 0;
	virtual string toString() = 0;
	virtual string getType() = 0;
	virtual float getValue() = 0;
	virtual int getNum() = 0;
	virtual int getDenom() = 0;

protected:
	string sType;
	float fValue;

};

#endif /* NUMBER_H_ */
