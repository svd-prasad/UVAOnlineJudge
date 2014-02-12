#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char c;
	while((c=getchar())!=EOF)
	{	
		if(c!='\n')
			cout<<char(c-7);
		else
			cout<<"\n";
	}
	return 0;
}