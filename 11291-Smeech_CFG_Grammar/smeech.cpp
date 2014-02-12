//how to read a floating point number
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip> 
using namespace std;
char *str = (char *)malloc(256*sizeof(char));
double atof()
{
	double val, power;
	int  sign;
	//for (i = 0; isspace(str[i]); i++) /* skip white space */
	//;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	for (val = 0.0; *str >= '0' && *str <= '9'; str++)
		val = 10.0 * val + (*str - '0');
	if (*str == '.')
		str++;
	for (power = 1.0; *str >= '0' && *str <= '9'; str++) {
		val = 10.0 * val + (*str - '0');
		power *= 10;
	}
	return sign * val / power;
}
double evalRec()
{
	int i;
	double prob = 0, exp1 = 0 , exp2 = 0, val ,num=0;
	if(*str == '(')
	{
		str++;
		prob = atof();
		if(prob >=0)
		{
			exp1 = evalRec();
			exp2 = evalRec();	
			val = prob * (exp1 + exp2) + (1 - prob) * (exp1 - exp2);
			if(*str == ')')
			{
				str++;
				return val;
			}
		}
	}
	else if(*str == ' ')
	{
		str++;
		return  evalRec();  //Skip space and call evalRec
	}
	else
	{
		num = atof();
		return num;
	}
}

int main()
{
	double eval;
	while(gets(str))
	{
		if(str[0] == '(' && str[1] == ')')
			break;
		else
		{
			eval = evalRec();
			std::cout << std::setprecision(2) << std::fixed;
			cout<<eval<<endl;
		}
	}
	return 0;
}
