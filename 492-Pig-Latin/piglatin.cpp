#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;
int main()
{
	char c, consonent;
	while((c = getchar()) != EOF)
	{
		if(isalpha(c))
		{
			if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
			{
				cout<<c;
				while(isalpha(c=getchar()))
				{
					cout<<c;
				}
				cout<<"ay"<<c;
				
			}
			else
			{
				consonent = c;
				while(isalpha(c=getchar()))
				{
					cout<<c;
				}
				cout<<consonent<<"ay"<<c;
			}
		}
		else
			cout<<c;
	}
	return 0;
}