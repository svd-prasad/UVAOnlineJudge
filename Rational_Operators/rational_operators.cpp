#include<iostream>
using namespace std;
int main()
{
	int test_cases;
	long i,j;
	cin>>test_cases;
	while(test_cases>0)
	{
		cin>>i>>j;
		if(i>j){cout<<">"<<endl;}
		else if(i<j){cout<<"<"<<endl;}
		else{cout<<"="<<endl;}
		--test_cases;
	}
}