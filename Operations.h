#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include "Number.h"
class Operations {
public:
	Operations();
	~Operations();
	Number add(Number a, Number b);
	Number subtract(Number a, Number b);
	Number multiply(Number a, Number b);
	Number divide(Number a, Number b);
	Number exponentiate(Number a, Number b);
	Number logbase(Number a, Number b);
	Number nthroot(Number a, Number b);
	Number simplifyAns(Number a, Number b);
};

#endif /* OPERATIONS_H_ */
