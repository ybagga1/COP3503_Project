#include 'Shunting.h'
using namespace std;

//Declare hashmap of operators and link their precedence
Shunting:: Shunting()
{
	map<> Operators(string op, int precedence);
}


// Test if string is a parenthesis  
//Called by parseTokens then convertInput  
bool Shunting:: isParenthesis( const string& str)          
{          
    return str == "(" || str == ")";        
}        
  
// Test if str is an operator  
//Called by all three methods        
bool Shunting:: isOperator( const string& str)          
{          
    return str == "+" || str == "-" || str == "*" || str == "/" || str == "^";        
}  

//Called only by convertInput
bool Shunting::isAssociative(const string str, int precedence)
{
	return true;
}

//Compares Operation order precedence
//AKA cmpPrecedence
int Shunting::comparePrec( const string& token1, const string& token2 )
{
	return 0;
}

//Parses input string into separate elements
vector<string> Shunting::parseTokens(const string& input)
{
	return input;
}

//Rearranges the elements into PEMDAS
bool Shunting::convertInput(const vector<string>& input, const int& size, vector<string>& output)
{
	return true;
}

//Actually does the calculations
//Has to return a number because of the ans keyword
//Calls parseTokens, then convertInput, then behaves like RPNtoDouble
//Does this so the main isn't  cluttered like the one we saw
Number Shunting:: evaluate(string input)
{
	vector<string> tokens = getExpressionTokens(input);
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
	
	
	
