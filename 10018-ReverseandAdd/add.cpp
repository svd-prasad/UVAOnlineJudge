#include <iostream>
using namespace std;
unsigned long int reverse(unsigned long int num)
{
	unsigned long int rev = 0,n;
	while(num > 0)
	{
		n = num % 10;
		rev = rev * 10 + n;
		num /= 10;
	}
	return rev;
}
bool isPalilndrome(unsigned long int num)
{
	return (num == reverse(num))?true:false;
}
int main()
{
	unsigned long int num, temp;
	int lines, iter;
	cin>>lines;
	while(lines > 0)
	{
		cin>>num;
		temp = 0;
		iter = 0;
		while(num > 0)
		{
			temp = num + reverse(num);
			++iter;
			if(isPalilndrome(temp))
			{
				cout<<iter<<" "<<temp<<endl;
				break;
			}
			num = temp;
		}
		--lines;		
	}
	return 0;
}