#include <iostream>
using namespace std;
int main()
{
	bool a, b, c;
	while(cin>>a>>b>>c)
	{
		if((a == 0 && b == 0 && c == 1) || (a == 1 && b == 1 && c == 0))
			cout<<"C";
		else if((a == 0 && b == 1 && c == 0) || (a == 1 && b == 0 && c == 1))
			cout<<"B";
		else if((a == 0 && b == 1 && c == 1) || (a == 1 && b == 0 && c == 0))
			cout<<"A";
		else
			cout<<"*";
		cout<<endl;
	}
	return 0;
}