#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	char c, str[256];
	int lines, count[26], i, max = 0;
	cin>>lines;
	gets(str);
	while(lines > 0)
	{
		gets(str);
		for(i = 0;i < 26; i++)
			count[i] = 0;
		for(i = 0;i < strlen(str);i++)
		{
			if(isalpha(str[i]))
			{ 
				c = tolower(str[i]);
				++count[int(c)-97];
			}
		}
		max = 0;
		for(i = 0;i < 26; i++)
			if(max < count[i])
				max = count[i];
		for(i = 0;i < 26; i++)
			if(count[i] == max)
				cout<<char(i+97);
		cout<<endl;
		--lines;
	}
	return 0;
}