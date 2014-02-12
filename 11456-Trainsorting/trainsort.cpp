#include <iostream>
#include <cstdlib>
using namespace std;
long int max(long int a,long int b)
{
	return (a>b)?a:b;
}
long int  * LIS(long int *cars, long int * lis, long int len)
{
	long int i, j;
	for(i = 0 ; i < len ; ++i)
		lis[i] = 1;
	for(i = len - 1 ; i >= 0 ; i--)
		for(j = i + 1 ; j < len ; j++)
			if(cars[i] < cars[j])
				lis[i] = max(lis[j] + 1 , lis[i]);
	return lis;
}
long int * LDS(long int *cars, long int * lds, long int len)
{
	long int i, j;
	for(i = 0 ; i < len ; ++i)
		lds[i] = 1;
	for(i = len - 1 ; i >= 0 ; i--)
		for(j = len - 1 ; j > i ; j--)
			if(cars[i] > cars[j] && lds[i] <= lds[j])
				lds[i] = max(lds[j] + 1 , lds[i]);
	return lds;
}
int main()
{
	long int testCases, no_of_cars, *cars, *lis, *lds, i , max;
	cin>>testCases;
	while(testCases > 0)
	{
		cin>>no_of_cars;
		cars = (long int *)malloc(no_of_cars * sizeof(long int));
		lis = (long int *)malloc(no_of_cars * sizeof(long int));
		lds = (long int *)malloc(no_of_cars * sizeof(long int));
		for(i = 0 ; i < no_of_cars ; ++i)
			cin>>cars[i];
		lis = LIS(cars, lis, no_of_cars);
		lds = LDS(cars, lds, no_of_cars);
		for(i = 0, max = 0 ; i < no_of_cars ; i++)
			if(lis[i] + lds[i] -1 > max)
				max = lis[i] + lds[i] - 1;
			cout<<max<<endl;
			
		free(cars);
		free(lis);
		free(lds);
		--testCases;
	}
	return 0;
}