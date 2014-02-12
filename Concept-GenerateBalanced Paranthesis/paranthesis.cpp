#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
void dyck_permute(const char * s, unsigned long long int icount, unsigned long long int ocount)
{
	char * s1;
	if(icount == 0 && ocount == 0)
		cout<<s<<endl;
	if(icount > 0)
	{
		string str = s;
		str.append("i");
		s1 = new char[str.length() + 1];
		strcpy(s1, str.c_str());
		dyck_permute(s1, icount - 1, ocount + 1);
	}
	if(ocount > 0)
	{
		string str = s;
		str.append("o");
		s1 = new char[str.length() + 1];
		strcpy(s1, str.c_str());
		dyck_permute(s1, icount , ocount - 1);
	}
}
int main()
{
	unsigned long long num;
	char s[2] = "";
	cin>>num;
	dyck_permute(s, num, 0);
	return 0;
}