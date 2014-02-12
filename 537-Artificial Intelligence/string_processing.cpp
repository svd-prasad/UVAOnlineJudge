#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;
#define m 0.001
#define k 1000
#define M 1000000
char *str = (char *)malloc(10000*sizeof(char));
int i;
double getRealNumber()
{
			int sign;
			double val, power;
			++i;
			sign = (str[i] == '-') ? -1 : 1;
			if (str[i] == '+' || str[i] == '-')
				str++;
			for (val = 0.0; str[i] >= '0' && str[i] <= '9'; i++)
				val = 10.0 * val + (str[i] - '0');
			if (str[i] == '.')
				i++;
			for (power = 1.0; str[i] >= '0' && str[i] <= '9'; i++) 
			{
				val = 10.0 * val + (str[i] - '0');
				power *= 10;
			}
			val = sign * val / power;
			if( str[i] == 'm' )
				val = val * m;
			if(str[i]  == 'k')
				val = val * k;
			if(str[i]  =='M')
				val = val * M;
			if(str[i]  == 'm' || str[i]  == 'k' || str[i]  =='M')
					++i;
	return val;
}
int main()
{
	int testCases, problem = 1, len;
	double u_value, p_value, i_value;
	bool UFLAG, IFLAG, PFLAG;
	UFLAG=false;
	PFLAG=false;
	IFLAG=false;
	cin>>testCases;
	gets(str);   //skip 
	while(testCases > 0)
	{
		gets(str);
		len=strlen(str);
		i=0;
		while(i<len)
		{
			if(str[i] == 'U' && str[++i] == '=' )
			{ 
				u_value=getRealNumber();
				if(str[i] == 'V')
				{
					UFLAG =true;
					++i;
				}
			}
			else if(str[i] == 'P' && str[++i] == '=')
			{
				p_value=getRealNumber();
				if(str[i] == 'W')
				{
					PFLAG =true;
					++i;
				}
			}
			else if(str[i] == 'I' && str[++i] == '=')
			{
				i_value=getRealNumber();
				if(str[i] == 'A')
				{
					IFLAG =true;
					++i;
				}
			}
			else
			{
				++i;
			}
		}
		std::cout << std::setprecision(2) << std::fixed;
		cout<<"Problem #"<<problem++<<endl;
		if(UFLAG && IFLAG)
			cout<<"P="<<u_value * i_value<<'W'<<endl<<endl;
		if(UFLAG && PFLAG )
		{
			if(u_value != 0 )
				cout<<"I="<<p_value / u_value<<'A'<<endl<<endl;
			else
				cout<<"I="<<u_value<<'A'<<endl<<endl;
		}
		if(IFLAG && PFLAG)
		{
			if(i_value != 0 )
				cout<<"U="<<p_value / i_value<<'V'<<endl<<endl; 
			else
				cout<<"U="<<i_value<<'V'<<endl<<endl;
		}
		UFLAG=false;
		PFLAG=false;
		IFLAG=false;
		i=0;
		--testCases;
	}
	return 0;
}