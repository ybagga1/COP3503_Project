#ifndef NUMBER_H_
#define NUMBER_H_
#include <string>
using namespace std;

class Number {
public:
	Number();
	virtual ~Number();
	virtual Number simplify();
	string type();
	float value();

private:
	string Type;
	float value;

};

#endif /* NUMBER_H_ */
