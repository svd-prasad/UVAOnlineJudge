#include<stdio.h>
long cyclelength(long m,long n)
{
	long clength,max=0,iter,iter1;
	for(iter=m;iter<=n;iter++)
	{
		iter1=iter;
		clength=1;
		while(iter1>1)
		{
			if(!(iter1%2))
			{
				iter1=iter1/2; 
				clength+=1;
			}
			else
			{
				iter1=(3*iter1+1);
				clength+=1;
			}
		}
		if(max<clength)
		{
			max=clength;
		}
		
	}
	
	return max;
}

main()
{
	long leftindex,rightindex,cl;
	while(scanf("%ld %ld",&leftindex,&rightindex)!=EOF)
	{
		if(leftindex<rightindex)
		{
			cl=cyclelength(leftindex,rightindex);
		}
		else
		{
			cl=cyclelength(rightindex,leftindex);
		}
		printf("%ld %ld %ld\n",leftindex,rightindex,cl);
	}
}