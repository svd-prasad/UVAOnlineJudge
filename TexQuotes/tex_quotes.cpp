#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
main()
{
   char *texstring,str[1024],*dQuote,b_quote[]="`",a_quote[]="'";
   int length,nQuotes,i,newlength,index=0;
   bool type_of_quote= false;
   gets(str);
   length=strlen(str);
   dQuote=strchr(str,'"');
   while (dQuote!=NULL)
	{
		
		nQuotes+=1;
		dQuote=strchr(dQuote+1,'"');
	}
	newlength=length+nQuotes;
	texstring=(char *)malloc(newlength*sizeof(char));
	for(i=0;i<=length-1;++i)
	{
		if(str[i]!='"')
		{
			texstring[index++]=str[i];
		}
		else
		{
			if(!type_of_quote)
			{
				strcpy(&texstring[index++],b_quote);
				strcpy(&texstring[index++],b_quote);
				type_of_quote=true;
				
			}
			else
			{
				strcpy(&texstring[index++],a_quote);
				strcpy(&texstring[index++],a_quote);
				type_of_quote=false;
			}
		}
	}
	texstring[newlength]=str[length];
	cout<<texstring;
	return 0; 
}