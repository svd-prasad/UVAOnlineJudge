#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int main ()
{
  char str[1000000];
  char *pch;
  while(gets(str))
  {
	pch = strtok (str," ");
	while (pch != NULL)
	{
		printf("%s",strrev(pch));
		pch = strtok (NULL," ");
		if(pch)		//Dont output a space at the end of line--->Presentation error
			printf(" ");
	}
	printf("\n");
  }
  return 0;
}