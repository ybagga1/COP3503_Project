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
	virtual string getType();
	virtual float getValue();
	virtual int getNum();
	virtual int getDenom();

protected:
	string sType;
	float fValue;

};

#endif /* NUMBER_H_ */
