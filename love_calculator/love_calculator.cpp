#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::isalpha
#include <cstdio>
#include <cstdlib>
#include <iomanip>        //setprecision
using namespace std;
int sumOfDigits(int num)
{
	int sum=0,turn=0,tsum;
    while(num>0)
	{
		sum+=(num%10);
		num=num/10;
		if(num<=0 && sum>9)
		{
			num=sum;
			sum=0;
			turn=1;
		}
		if(sum<=9 && !turn && num<0)
			break;
		
	}
	return sum;
}


int main()
{
  std::locale loc;
  char str1[30],str2[30];
  int nameone,nametwo,i,count,alphabetsum1,alphabetsum2;
  double percentage;
  while(gets(str1))
  {
	gets(str2);
			i=0;
			nameone=0;
			alphabetsum1=0;
			while(str1[i])
				{
					if (std::isalpha(*(str1+i),loc))
						nameone+=tolower(*(str1+i))-96;
					i++;
				}
			alphabetsum1=sumOfDigits(nameone);
			i=0;
			nametwo=0;
			alphabetsum2=0;
			while(str2[i])
				{
					if (std::isalpha(*(str2+i),loc))
						nametwo+=tolower(*(str2+i))-96;
					i++;
				}
			alphabetsum2=sumOfDigits(nametwo);
			percentage=(double(min(alphabetsum1,alphabetsum2))/double(max(alphabetsum1,alphabetsum2)))*100;
			cout<<fixed<<std::setprecision(2)<<showpoint<<percentage<<" %"<<endl;
	}
	
  return 0;
}