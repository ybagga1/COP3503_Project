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
//typedef map <string, pair< int,int> > operatorMap;

}
typedef map <string, pair< int,int> > operatorMap;
const operatorMap:: value_type assocs[] =
    {  operatorMap :: value_type( "+", make_pair<int,int>( 0, 0 )),
       operatorMap:: value_type( "-", make_pair<int,int>( 0, 0 )),
       operatorMap:: value_type( "*", make_pair<int,int>( 5, 0 )),
       operatorMap:: value_type( "/", make_pair<int,int>( 5, 0 )),
       operatorMap:: value_type( "^", make_pair<int,int>( 5, 1 ))
       };

const operatorMap opmap(assocs, assocs + sizeof(assocs)/sizeof(assocs[0]));

bool Shunting::isParenthesis(const string& str)
{
    return str == "(" || str == ")";
}

bool Shunting:: isOperator(const string& str)
{
    return str == "+" || str == "-" || str == "*" || str == "/" || str == "^";
}
bool Shunting::isAssociative(const string& str, int precedence)
{
	const pair<int,int> p = opmap.find(str)->second;
    if (p.second == 0) {
        return false;
    }
    else
        return true;
     // if(tkn == "+" || tkn == "-" || tkn == "/" || tkn == "*") return true;
     //else return false;
}

int Shunting:: comparePrec(const string& firsttoken, const string& secondtoken ) {
 const :: pair<int,int> p1 = opmap.find(firsttoken) -> second;
 const :: pair<int,int> p2 = opmap.find(secondtoken) -> second;

    return p1.first - p2.first;
}

vector<string> Shunting::parseTokens(const string& input) {
	////cout << "ParseTokens(" << input << ")" << endl;
    vector<string> tokens;
    string str = "";
    for ( int i = 0; i <= (int) input.length(); ++i)   {
        const string token(1, input [i]);

        if (isParenthesis(token) || isOperator(token))
        {
        	//cout << "Parenthesis? " << isParenthesis(token) << " isOperator(token)" << isOperator(token) << endl;
            if (!str.empty())
            {
            	//cout << "Parenthesis? " << isParenthesis(token) << " isOperator(token)" << isOperator(token) << endl;
            	//cout << "!str.empty() tokens.push_back(" << str << ")" << endl;
                 tokens.push_back(str ) ;
            }
            str = "";
            //cout << "tokens.push_back(" << token << ")" << endl;
            tokens.push_back(token);
        }
        else {
            if (!token.empty() && token != " ")
            {
            	//cout << "str.append(" << token << ")" << endl;
                str.append( token );
            }
            else
            {
                if (str != "")
                {
                	//cout << "tokens.push_back(" << str << ")" << endl;
                    tokens.push_back(str);
                    str = "";
                    //cout << "str = " << str << endl;
                }
			}
            if(i == input.length() && str != "")
            	tokens.push_back(str);
		 }
    }


    //cout << "tokens= ";
    for(int i = 0; i < tokens.size(); i++)
    {
    	//cout << tokens[i] << ", ";
    }
    //cout << "\nstr= " << str;
    return tokens;
    }

bool Shunting::convertInput(const vector<string>& input, const int& size, vector<string>& outputVec) {
    //cout << "ConvertInput size= " << size << endl;
	bool success = true;
    list <string> output;
    stack<string> opstack;
     for ( int i = 0; i < size; i++ )
    {
        const string token = input[ i ];
        if(token == " ")
        	break;
        //cout << "token = " << token << endl;
        if ( isOperator(token)) {
            const string operator1 = token;
            //cout << "operator1 = " << token << endl;
             if (!opstack.empty())
            {
                string operator2 = opstack.top();
                //cout << "operator2 = " << token << endl;
                while (isOperator( operator2 ) &&
                        ((isAssociative(operator1, 1) &&  comparePrec(operator1, operator2) == 0 ) ||
                        ( comparePrec( operator1, operator2 ) <= 0 )))
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
        //cout << "TokenStack = " << TokenStack;
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
Number* Shunting:: evaluate(string input)
{
	//cout << "Evaluate(" << input << ")" << endl;
	Operations* o = new Operations();
	vector<string> tokens = parseTokens(input);
	vector<string> converted;
	stack<Number*> nums;
	if(convertInput(tokens, tokens.size(), converted))
	{
		cout << "converted= ";
		for(int i = 0; i < converted.size(); i++)
		{
			cout << converted[i] << ", ";
		}
		for ( int i = 0; i < (int) tokens.size(); i++ )
		{
			// If the token is a value push it onto the stack
			if ( !isOperator(tokens[i]) )
			{
				cout << "!Op tokens[i]= " << tokens[i] << endl;
				try
				{
					cout << "nums.push " << tokens[i] << endl;
					nums.push(toNumber(tokens[i]));
				}
				catch(int e)
				{
					throw invalid_argument("Invalid expression input, please adhere to input standards.");
				}
			}
			else
			{
				cout << "Op tokens[i]= " << tokens[i] << endl;
				Number* result;

				// Token is an operator: pop top two entries
				Number* n2 = nums.top();
				nums.pop();
				cout << "n2 = " << n2->toString();
				cout << "nums.empty()"<< nums.empty() << endl;
				if (!nums.empty() )
				{
					Number* n1 = nums.top();
					nums.pop();

					cout << ", n1 = " << n1->toString();
					//Get the result
					if(tokens[i] == "+") {
						result = o->add(n1, n2);
						cout << "result= " << result->toString() << endl;
					}
					else if(tokens[i] == "-")
						result = o->subtract(n1, n2);
					else if(tokens[i] == "*")
						result = o->multiply(n1, n2);
					else if(tokens[i] == "/")
						result = o->divide(n1, n2);
					else if(tokens[i] == "^")
						result = o->exponentiate(n1, n2);
					else
						throw invalid_argument("Invalid expression input, please adhere to input standards.");
				}
				else
				{
					if ( tokens[i] == "-" )
						result = o->multiply(n2, new Rational(-1));
					else
						result = n2;
				}

				// Push result onto stack
				nums.push(result);
				cout << "pushed result = " << result->toString() << endl;
			}
		}
	}

	else
	{
		throw invalid_argument("Mismatched parenthesis");
	}

	string token = tokens[tokens.size() - 1];
	if(isOperator(token) )
	{
		Number* result;
		Number* n2 = nums.top();
		nums.pop();
		cout << "n2 = " << n2->toString();
		cout << "nums.empty()"<< nums.empty() << endl;
		if (!nums.empty() )
		{
			Number* n1 = nums.top();
			nums.pop();

			cout << ", n1 = " << n1->toString();
			//Get the result
			if(token == "+") {
				result = o->add(n1, n2);
				cout << "result= " << result->toString() << endl;
			}
			else if(token == "-")
				result = o->subtract(n1, n2);
			else if(token == "*")
				result = o->multiply(n1, n2);
			else if(token == "/")
				result = o->divide(n1, n2);
			else if(token == "^")
				result = o->exponentiate(n1, n2);
			else
				throw invalid_argument("Invalid expression input, please adhere to input standards.");
		}
		else
		{
			if ( token == "-" )
				result = o->multiply(n2, new Rational(-1));
			else
				result = n2;
		}
	}

	cout << "nums.top() = " << nums.top()->toString() << endl;
	return nums.top();
}
Number* Shunting:: toNumber(string str){
	Number* ans;
	if((str.at(0) == 'l')  || (str.at(0) == 'e') || (str.at(0) == 'p') || (str.at(0) == 's'))
	{
		ans = new Irrational(str);
	}
	else
	{
		for(int i = 1; i < (int)str.size(); i++)
		{
			if(str.at(i) == '/')
			{
				char *a=new char[str.size()+1];
				a[str.substr(i-1).size()]=0;
				memcpy(a,str.c_str(),str.substr(i-1).size());

				char *b=new char[str.size()+1];
				b[str.substr(i+1).size()]=0;
				memcpy(b,str.c_str(),str.substr(i+1).size());
				ans = new Rational(atoi(a), atoi(b));
			}
			else if(str.at(i) == 'r')
			{
				ans = new Irrational(str);
			}
		}
	}

	char *c=new char[str.size()+1];
	c[str.size()]=0;
	memcpy(c,str.c_str(),str.size());
	ans = new Rational(atoi(c));
	//cout << "created number = " << ans->toString() << endl;
	return ans;
}
