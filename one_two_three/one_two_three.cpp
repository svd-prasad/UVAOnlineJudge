#include<iostream>
#include<cstring>
using namespace std;
int main()
{
		int i,testCases,length;
		std::string str;
		cin>>testCases;
		while(std::getline(std::cin,str))
		{
			length=str.size();
			if(length==5)
				cout<<"3"<<endl;
			if((str[0]=='o'&&str[1]=='n')||(str[1]=='n'&&str[2]=='e')||(str[0]=='o'&&str[2]=='e'))
				cout<<"1"<<endl;
			if((str[0]=='t'&&str[1]=='w')||(str[1]=='w'&&str[2]=='o')||(str[0]=='t'&&str[2]=='o'))
				cout<<"2"<<endl;
			
		}
return 0;
}