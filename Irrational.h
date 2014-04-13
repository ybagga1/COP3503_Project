#ifndef IRRATIONAL_H_
#define IRRATIONAL_H_
#include <string>
#include "Number.h"
using namespace std;

class Irrational : public Number {
public:
	Irrational();
	Irrational(float z, string irr);
	Irrational(string irr);
	Number* simplify();
	string toString();
	string getType();
	float getValue();
	int getNum();
	int getDenom();
	string getType2();
	string getBase();
	string getLogOf();
private:
	string type;
	string base;
	string logOf;
	string rootOf;
	string n;
};

#endif /* IRRATIONAL_H_ */
