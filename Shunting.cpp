#include "Shunting.h"
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <list>
#include <stack>
#include <vector>

using namespace std;
Shunting::Shunting() {
 // map<> Operators(string op, int precedence);
 //typedef map <string, pair<int,int> > OperatorMap;

}

typedef map <string, pair< int,int> > operatorMap;
 const operatorMap value_type assocs[] =
    {  operatorMap value_type( "+", make_pair<int,int>( 0, 0 )),
       operatorMap value_type( "-", make_pair<int,int>( 0, 0 )),
       operatorMap value_type( "*", make_pair<int,int>( 5, 0 )),
       operatorMap value_type( "/", make_pair<int,int>( 5, 0 )),
       operatorMap value_type( "^", make_pair<int,int>( 5, 1 ))
       };

// const OperatorMap opmap(assocs, assocs + sizeof(assocs)/sizeof(assocs[0]));

bool Shunting::isParenthesis(const string& str)
{
    return str == "(" || str == ")";
}

bool Shunting:: isOperator(const string& str)
{
    return str == "+" || str == "-" || str == "*" || str == "/" || str == "^";
    else return false;
}
bool Shunting::isAssociative(const string str, int precedence)
{
	const pair<int,int> p = peratormap.find(str)->second;
    if (p.second == 0) {
        return false;
    }
    else
        return true;
     // if(tkn == "+" || tkn == "-" || tkn == "/" || tkn == "*") return true;
     //else return false;
}

int Shunting:: comparePrec(const string& firsttoken, const string& secondtoken ) {
 const pair<int,int> p1 = operatorMap.find(firsttoken)->first;
 const pair<int,int> p2 = operatorMap.find(secondtoken)->first;

    return p1.first - p2.first;
}

vector<string> Shunting::parseTokens(const string& input) {
    vector<string> tokens;
    string str = "";
    for ( int i = 0; i < (int) input.length(); ++i)   {
        const string token(1, input [i]);

        if (isParenthesis(token) || isOperator(token))
        {
            if (!str.empty())
            {
                 tokens.push_back(str ) ;
            }
            str = "";
            tokens.push_back(token);
        }
        else {
            if (!token.empty() && token != " ")
            {
                str.append( token );
            }
            else
            {
                if (str != "")
                {
                    tokens.push_back(str);
                    str = "";
                }
                }
             }
    }
    return tokens;
    }

bool Shunting::convertInput(const vector<string>& input, const int& size, vector<string>& outputVec) {
    bool success = true;
    list <string> output;
    stack<string> opstack;
     for ( int i = 0; i < size; i++ )
    {
        const string token = input[ i ];
        if ( isOperator(token)) {
            const string operator1 = token;
             if (!opstack.empty())
            {
                string operator2 = opstack.top();
                while (isOperator( operator2 ) &&
                        ((isAssociative(operator1, 1) &&  comparePrec(operator1, operator2) == 0 ) ||
                        ( comparePrec( operator1, operator2 ) < 0 )))
                {
                    opstack.pop();
                    output.push_back(operator2);

                    if (!opstack.empty())
                        operator2 = opstack.top();
                    else
                        break;
                }
            }
             opstack.push(operator1);
        }
        else if ( token == "(")
        {
            opstack.push( token );
        }
         else if ( token == ")" )
        {
            string firstToken  = opstack.top();
            while (firstToken != "(")
            {
                output.push_back(firstToken);
                opstack.pop();

                if (opstack.empty() ) break;
                firstToken = opstack.top();
            }
            if (!opstack.empty())opstack.pop();

            if ( firstToken != "(" )
            {
                return false;
            }
        }
        else
        {
            output.push_back( token );
        }
    }
    while (!opstack.empty())
    {
        const string TokenStack = opstack.top();

        if ( isParenthesis(TokenStack ))
        {
            return false;
        }
        output.push_back( TokenStack );
        opstack.pop();
    }

    outputVec.assign(output.begin(),output.end() );

    return success;
}

//Actually does the calculations
//Has to return a number because of the ans keyword
//Calls parseTokens, then convertInput, then behaves like RPNtoDouble
//Does this so the main isn't  cluttered like the one we saw
Number Shunting:: evaluate(string input)
{
	vector<string> tokens = parseTokens(input);
	vector<string> converted;
	if(convertInput(tokens, tokens.size(), converted))
	{
		stack<string> nums;
		for ( int i = 0; i < (int) tokens.size(); ++i )
		{
			// If the token is a value push it onto the stack
			if ( !isOperator(tokens[i]) )
			{
				try
				{
					nums.push(toNumber(tokens[i]));
				}
				catch
				{
					throw invalid_argument("Invalid expression input, please adhere to input standards.");
				}
			}
			else
			{
				Number result;

				// Token is an operator: pop top two entries
				const Number n2 = nums.top();
				nums.pop();

				if (!nums.empty() )
				{
					const Number n1 = nums.top();
					nums.pop();

					//Get the result
					result = tokens[i] == "+" ? add(n1, n2) :
							 tokens[i] == "-" ? subtract(n1, n2) :
							 tokens[i] == "/" ? diviide(n1, n2) :
							 tokens[i] == "*" ? multiply(n1, n2) :
							 tokens[i] == "^" ? exponentiate(n1, n2) :
							 throw invalid_argument("Invalid expression input, please adhere to input standards.");
				}
				else
				{
					if ( tokens[i] == "-" )
						result = multiply(n2, new Rational(-1));
					else
						result = n2;
				}


				// Push result onto stack
				nums.push(result);
			}
		}

    return nums.top();
}

Number Shunting:: toNumber(string str){
	if(str.charAt(0) == 'l'  || str.charAt(0) == 'e' || str.charAt(0) == 'p' str.charAt(0) == 's')
	{
		return new Irrational(str);
	}
	else
	{
		for(int i = 1; i < str.length(); i++)
		{
			if(str.charAt(i) == '/')
			{
				return new Rational(atoi(str.substring(i - 1)), atoi(str.substring(i+ 1)));
			}
			else if(str.charAt(i) == 'r')
			{
				return new Irrational(str);
			}
		}
	}
	return new Rational(atoi(str));
}
