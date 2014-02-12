#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char c;
	while((c = getchar()) != EOF)
	{
			if(c == 'A' || c == 'B' || c == 'C' )
				cout<<"2";
			else if(c == 'D' || c == 'E' || c == 'F' )
				cout<<"3";
			else if(c == 'G' || c == 'H' || c == 'I' )
				cout<<"4";
			else if(c == 'J' || c == 'K' || c == 'L' )
				cout<<"5";
			else if(c == 'M' || c == 'N' || c == 'O' )
				cout<<"6";
			else if(c == 'P' || c == 'Q' || c == 'R' || c == 'S' )
				cout<<"7";
			else if(c == 'T' || c == 'U' || c == 'V' )
				cout<<"8";
			else if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z' )
				cout<<"9";
			else
				cout<<c;
	}
	return 0;
}