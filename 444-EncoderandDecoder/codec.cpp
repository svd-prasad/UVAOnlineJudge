#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
int trailing_zeros(int num)
{
	int digits = 0;
	while(num > 0)
	{
		++digits;
		num = num / 10;
	}
	return digits;
}
int reverse_number(int num)
{
	int rev = 0 ,n;
	while(num > 0)
	{
		n = num % 10;
		rev = rev * 10 + n;
		num = num / 10;
	}
	return rev;
}
void decode(char * str , int len)
{
	while(len >= 0)
	{
		cout<<setw(trailing_zeros(int(str[len]))) << setfill('0');  //MOST IMP BUG
		cout<<reverse_number(int(str[len]));
		--len;
	}
	cout<<endl;
}
void encode(char *str, int len)
{
	int num, i, j, k;
	while(len >= 0)
	{
		if(str[len] == '1')
		{
			i = len;
			j = len - 1;
			k = len - 2;
			num = (str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0') * 1;
			len -= 3;
		}
		else
		{
			i = len;
			j = len -1;
			num = (str[i] - '0') * 10 + (str[j] - '0') * 1;
			len -= 2;
		}
		cout<<char(num);
	}
	cout<<endl;
}
int main()
{
	char *str = (char *)malloc(255*sizeof(char));
	int asc_value, len;
	while(gets(str))
	{
		len = strlen(str);
		if(len > 0)
		{
			if(str[len-1] - '0' >= 0 &&  str[len-1] - '0' <= 9 )
				encode(str ,len-1);
			else
				decode(str , len-1);
		}
		else
			cout<<endl;
	}
	return 0;
}