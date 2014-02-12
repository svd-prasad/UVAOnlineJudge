#include<iostream>
#include<cstdlib>
#include <locale>         // std::locale, std::isdigit
#include <sstream>        // std::stringstream
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	std::locale loc;
	char *names[20],str[140],temp_name[20];
	int *greedy_money,i,no_of_names,index,sindex,iterForNames;
	while(gets(str))	
	{
		if (isdigit(str[0],loc))
			std::stringstream(str) >> no_of_names;
		gets(str);
		for(i=0;i<no_of_names;i++)
			names[i]=(char *)malloc(20*sizeof(char));
		greedy_money=(int *)malloc(no_of_names*sizeof(int));
		index=0;
		iterForNames=0;
		while(index<strlen(str))
		{
			sindex=0;
			while(index<strlen(str)&&str[index]!=' ')
			{
				temp_name[sindex]=str[index];
				sindex++;
				index++;
			}
			temp_name[sindex]='\0';
			strcpy(names[iterForNames],temp_name);
			iterForNames++;
			while(str[index]==' ')
				index++;
		}
		for(i=0;i<no_of_names;i++)
		{
			gets(str);
			
			
		}		
		for(i=0;i<no_of_names;i++)
			free(names[i]);
	}
	return 0;
}