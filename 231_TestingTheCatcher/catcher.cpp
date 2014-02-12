#include <iostream>
#include <climits>
#define MAX_INTEGER 32767
using namespace std;
int main()
{
	int i,s_index=0,interception_index,STEP,max_possibles,j,temp_max,count,test=0;//starting index Fixed
	int a[MAX_INTEGER];
	while(1)
	{	
		count=0;
		max_possibles=1;
		interception_index=0;
		cin>>a[count];
		if(a[count]==-1)
			break;
		else
		{
			while(1)
			{
				count+=1;
				cin>>a[count];
				if(a[count]==-1)
					break;
			}
			for(STEP=1;STEP<count;STEP++)
			{
				temp_max=1;	//Starting missile is always intercepted
				interception_index=0;
				for(j=STEP;j+1<=count&&count>1;j++)
				{
					if(a[interception_index]>=a[j])
					{
						interception_index=j;
						temp_max+=1;
					}
				}
				if(max_possibles<temp_max)
					max_possibles=temp_max;
			}
			cout<<"Test #"<<++test<<":"<<endl;
			cout<<"  maximum possible interceptions: "<<max_possibles<<endl;
		}
		cout<<endl;
	}
	return 0;
}