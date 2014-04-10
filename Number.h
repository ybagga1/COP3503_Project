#ifndef NUMBER_H_
#define NUMBER_H_
#include <string>
#include<stdexcept>
using namespace std;

class Number {
public:
	virtual Number simplify() = 0;
	virtual String toString() = 0;
	virtual string type() = 0;
	virtual float value() = 0;

private:
	string type;
	float value;

};

#endif /* NUMBER_H_ */
