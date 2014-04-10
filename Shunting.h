#ifndef SHUNTING_H_
#define SHUNTING_H_
#include 'Number.h'

class Shunting {
public:
	Shunting();
	//Actually does the calculations
	//Has to return a number because of the ans keyword
	//Calls parseTokens, then convertInput, then behaves like RPNtoDouble
	//Does this so the main isn't  cluttered like the one we saw
	Number evaluate(vector<string> tokens);
  
private:
	//Used to keep track of operators and their precedence
	map<> Operators(string op, int precedence);
	
	//Called by evaluate 1st
	//Parses input string into separate 
	//AKA getExpressionTokens
	vector<string> parseTokens(const string& input);
	
	//Called by evaluate 2nd
	//Rearranges the elements into PEMDAS
	//AKA infixToRPN
	bool convertInput(const vector<string>& input, const int& size, vector<string>& output);
	
	//Called by parseTokens then convertInput
	bool isParenthesis(const string str);
	
	//Called by all three methods
	bool isOperator(const string str);
	
	//Called only by convertInput
	bool isAssociative(const string str, int precedence);
	
	//Compares Operation order precedence
	//AKA cmpPrecedence
	int comparePrec(const string& token1, const string& token2 );
	
	//Converts decimals to fractions... Maybe.
	Rational toFraction(float f);
};

#endif /* SHUNTING_H_ */
