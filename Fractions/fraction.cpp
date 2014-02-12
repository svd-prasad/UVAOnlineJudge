#include <iostream>
using namespace std;
int main()
{
	int k,x,y,i,temp,out,count=1;
	while(1)
	{
		cin>>k;
		if(k>0)
		{
			temp=2*k;
			for(i=2;i<=(temp-1);i++)
			{ 
				if(i==k || i<k)
					continue;
				if(i>k)
				{
					y=(k*i)%(i-k);
					out=(k*i)/(i-k);
				}
				if(!y)
					count++;
			}
			cout<<count<<endl;
			for(i=2;i<=(temp-1);i++)
			{ 
				if(i==k || i<k)
					continue;
				if(i>k)
				{
					y=(k*i)%(i-k);
					out=(k*i)/(i-k);
				}
				if(!y)
					cout<<"1/"<<k<<" = "<<"1/"<<out<<" + "<<"1/"<<i<<endl;
			}
			cout<<"1/"<<k<<" = "<<"1/"<<temp<<" + "<<"1/"<<temp<<endl;
			k=-1;
			count=1;
		}
		else
			break;
	}
return 0;
}