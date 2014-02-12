#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
#define NO_OF_CHARS 256
char word[10000], anagram[10000];
/* Function to copy strings */
char *strcpy(char *dest, const char *src)
{
  unsigned i;
  for (i=0; src[i] != '\0'; ++i)
    dest[i] = src[i];
  dest[i] = '\0';
  return dest;
}
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */

 /*void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
     cout<<a;
   else
   {
        for (j = i; j <= n; j++)
       {
		  swap((a+i), (a+j));
          permute(a, i+1, n);
		  swap((a+i), (a+j)); //backtrack
       }
   }
}*/
struct stack
{
	char c;
	struct stack *next;
};
void push(struct stack **top , char c1)
{
	struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
	if(newnode)
	{
		newnode -> c = c1;
		newnode -> next = *top; 
	}
	*top = newnode;
}

int isStackEmpty(struct stack *top)
{
	return (top == NULL)?1:0;
}

char pop(struct stack **top)  //No need to return popped element
{
	char popc;
	if(!isStackEmpty(*top))
	{
		popc = (*top) -> c;
		(*top) = (*top) -> next;
	}
	return popc;
}
void printResult(const char *str)
{
	unsigned long int len, i;
	len = strlen(str);
	for(i = 0 ; i < len ; ++i)
		cout<<str[i]<<" ";
	cout<<endl;
}
void check_dyck_for_anagram(const char * s)
{
	unsigned long long int len, ires = 0 ,i, wordi = 0;
	struct stack *top = NULL;
	char * res = new char[strlen(anagram) + 1];
	char tempchar;
	len = strlen(s);
	for(i = 0 , wordi = 0; i < len; ++i)
	{
		if(s[i] == 'i')
			push(&top, word[wordi++]);
		if(s[i] == 'o')
		{
			tempchar = pop(&top);
			if(tempchar != anagram[ires])
				return;
			else
				res[ires] = tempchar;
			++ires;
		}
	}
	res[ires] = '\0';
	if(!strcmp(res,anagram))
		printResult(s);
}
 /* Function to print Dyck words(t no initial segment of the string has more o's than i's) of i & o
   This function takes three parameters:
   1. String
   2. i count 
   3. o count */
void dyck_permute(const char * s, unsigned long long int icount, unsigned long long int ocount)
{
	char * s1;
	if(icount == 0 && ocount == 0)
		check_dyck_for_anagram(s);
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
/* function to check whether two strings are anagram of each other */
bool isAnagram(const char *str1, const char *str2)
{
    // Create two count arrays and initialize all values as 0
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i;
 
    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
 
    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
    if (str1[i] || str2[i])
      return false;
 
    // Compare count arrays
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i])
            return false;
 
    return true;
}
/* Driver program to test above functions */
int main()
{
   char dyck[]="";
   long len, anagLen;
   while(gets(word))
   {
		len = strlen(word);
		gets(anagram);
		anagLen = strlen(anagram);
		cout<<"["<<endl;
		if(len == anagLen && isAnagram(word, anagram))
			dyck_permute(dyck, len, 0);
		cout<<"]"<<endl;
		strcpy(dyck,"");
   }
   return 0;
}






















