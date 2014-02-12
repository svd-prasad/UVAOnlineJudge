/* itoa example */
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int binary(int n)
{
   int s,c=0;
   while(n!=0)
   {
      s=n%2;
      n=n/2;
      if(s==1)
      c++;
   }
   return c;
}
int hex_to_binary(int c)
{
	switch(c)
	{
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		case 4:
			return 1;
			break;
		case 5:
			return 2;
			break;
		case 6:
			return 2;
			break;
		case 7:
			return 3;
			break;
		case 8:
			return 1;
			break;
		case 9:
			return 2;
			break;
	}
}
int getb2(int num)
{
	int b2 = 0, index;
	while(num>0)
	{
		b2 += hex_to_binary(num % 10);
		num /=10;
	}
	return b2;
}
int main ()
{
  int i, lines, num;
  cin>>lines;
  for(i=1;i<=lines;i++)
  {
	cin>>num;
	cout<<binary(num)<<" "<<getb2(num)<<endl;	
  }
  return 0;
}