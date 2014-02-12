#include <stdio.h>
#include<stdlib.h>
long long int *array;
long long int max(long long int lindex,long long int rindex)
{
	long long int max=0,i;
	for(i=lindex;i<=rindex;i++)
	{
		if(max<array[i])
			max=array[i];
	}
	return max;
}
long long int cycle_length(long long int input_n)
{
	if(!array[input_n])
	{
		if(input_n == 1)
		{
			array[input_n]=1;
			return array[input_n];
		}
		else if(!(input_n%2))
		{
			array[input_n]=cycle_length(input_n>>1)+1;
			return array[input_n];
		}
		else
		{
			array[input_n]=cycle_length((3*input_n+1)>>1)+2;
			return array[input_n];
		}
			
	}
	else
	{
		return array[input_n];
	}	
}
void main()
{
	long long int i1,i,n,j,t,i2,j2;
	array = (long long int *)calloc(100000000, sizeof(long long int));
	for(i1=1;i1<=1000000;i1++)
		{
			array[i1]=cycle_length(i1);
		}
	while(scanf("%ld %ld",&i,&j)!=EOF)
	{ 
		if(i>j)
		{
			i2=j;j2=i;
		}
		else
		{
			i2=i;j2=j;
		}
		
		/*for(i1=i2;i1<=j2;i1++)
		{
			array[i1]=cycle_length(i1);
		}*/
		printf("%ld %ld %ld\n",i,j,max(i2,j2));
	}
	free(array);
}



