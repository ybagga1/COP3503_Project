#include 'Rational.h'

Rational:: Rational(){
numerator = 1;
denominator = 1;
type = "Rational";
value = 1;
}

Rational:: Rational(int numerator){
this->numerator = numerator;
this->denominator = 1;
type = "Rational";
value = numerator;
}

Rational:: Rational(int numerator, int denominator){
if(denominator == 0)
throw invalid_argument("Cannot divide by zero");

this->numerator = numerator;
this->denominator = denominator;

type = "Rational";
value = (float)numerator / (float)denominator;
}

int Rational:: getNum(){
return numerator;
}

int Rational:: getDenom(){
return denominator;
}

//if denominator = 1, return the numerator as a string
//else return "numerator '/' denominator"
string Rational:: toString(){
string number = "";
return number;

}
string Rational:: type()
{
return type;
}

float Rational:: value()
{
return value;
}

Rational Rational::simplify(Rational& r) {

int a= r.getNum();
int b = r.getDenom();
if (a < b) {
    for (int i = 2, i < b, i++) {
        if (a % i == 0 && b % i == 0) {
            a /= i;
            b /= i;
        }
    }
}
else {
    for (int i = 2, i < a, i++) {
        if (b % i == 0 && a % i == 0) {
            a /= i;
            b /= i;
        }
    }
}
Number fraction = new Number(a, b);
return fraction;
}
