#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
int main()
{
	int testCases,no_of_stores,minDistance,maxDistance,*position,i,j;
	cin>>testCases;
	for(j=1;j<=testCases;j++)
	{
		minDistance=INT_MAX;
		maxDistance=INT_MIN;
		cin>>no_of_stores;
		position=(int *)malloc(no_of_stores*sizeof(int));
		for(i=0;i<=no_of_stores-1;++i)
		{
			cin>>position[i];
		}
		for(i=0;i<=no_of_stores-1;++i)
		{
			if(minDistance>position[i])
				minDistance=position[i];
			if(maxDistance<position[i])
				maxDistance=position[i];
		}
		cout<<2*(maxDistance-minDistance)<<endl;
		free(position);
	}
	return 0;
}