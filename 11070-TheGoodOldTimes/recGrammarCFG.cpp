//E -> E + T | E - T | T   Preserves Left associativity
//T -> F * T | F / T | F   Preserves right associativity
//F -> (E) | n 
/*-------------Parser for all arithmetic expressions
float evalExpression()
    term_value = evalTerm();
    read_next();
    if "+" then
        read_next();
        return evalExpression() + term_value;         E -> E + T
    else if "-" then
        read_next();
        return evalExpression() - term_value;          E -> E - T
    else
        return term_value;                                       E -> T
 

float evalTerm()
    factor_value = evalFactor();
    read_next();
    if "*" then
        read_next();
        return evalFactor() * factor_value;              T -> T * F
    else if "/" then
        read_next();
        return evalFactor() / factor_value;               T -> T / F
    else
        return factor_value;                                     T -> F
float evalFactor()
    if number then
        return number;                                            F -> n
    else if ")" then
        read_next();
        number_value = evalExpression();
        if "(" then
            read_next();
            return number_value;                              F -> (E)
        else
            print "syntax error!";
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip> 
using namespace std;
double evalTerm();
double evalFactor();
double evalExpression();
double atof();
char *str = (char *)malloc(256*sizeof(char));
char *cur_ptr;
double evalExpression()
{
	double term_value;
    term_value = evalTerm();
	cout<<"termval="<<term_value<<endl;
    if(*cur_ptr == '+') 
	{
        cur_ptr--;
        return  evalExpression() +  term_value;        
	}
    else if(*cur_ptr == '-') 
	{
        cur_ptr--;
        return  evalExpression() -  term_value;          
	}
    else
        return term_value;                                     
} 

double evalTerm()
{
	double factor_value;
    factor_value = evalFactor();
    if(*cur_ptr == '*')
	{
		cur_ptr--;
		return  evalFactor() * factor_value;             // T -> T * F
	}
    else if (*cur_ptr == '/')
    {
		cur_ptr--;
        return  evalFactor() / factor_value ;              // T -> T / F
	}
    else
        return factor_value;                                    // T -> F
}
double evalFactor()
{
	double number_value;cout<<*cur_ptr;
	if(*cur_ptr >= '0' && *cur_ptr <= '9')
	{
	   	number_value = atof();	//F -> num
		cout<<"n="<<number_value<<endl;
		return number_value;
	}
	//else
		//return evalExpression();
}
double atof()
{
	double val, power;
	int  sign;
	//for (i = 0; isspace(cur_ptr[i]); i++) /* skip white space */
	//;
	sign = (*cur_ptr == '-') ? -1 : 1;
	if (*cur_ptr == '+' || *cur_ptr == '-')
		cur_ptr--;
	for (val = 0.0; *cur_ptr >= '0' && *cur_ptr <= '9'; cur_ptr--)
		val = 10.0 * val + (*cur_ptr - '0');
	if (*cur_ptr == '.')
		cur_ptr--;
	for (power = 1.0; *cur_ptr >= '0' && *cur_ptr <= '9'; cur_ptr--) {
		val = 10.0 * val + (*cur_ptr - '0');
		power *= 10;
	}
	return sign * val / power;
}
main()
{
	double f_val;
	while(gets(str))
	{
		f_val = evalExpression();
		cur_ptr = str+strlen(str)-1;
		cout<<cur_ptr;
		std::cout << std::setprecision(3) << std::fixed;
		cout<<f_val<<endl;
	}
	return 0;
}