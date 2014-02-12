#include <string.h>
#include <iostream>
#include <map>	//ordered  map
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <locale>         // std::locale, std::isdigit
#include <sstream>        // std::stringstream
using namespace std;

int main()
{
	map<string, int> names;	//map<string,int> produes sorted names not by order arrived
	map<string,int>::iterator ii;//i1 is the iterator for map names
    std::locale loc;
	char name[20],*presentation_names[20];
	int i,no_of_names,amount_spent_on_gifts,no_of_persons,amount_given,amount_left,in;
	cin>>no_of_names;
	while(1)		//No of members in the group
	{
		for(i=0;i<no_of_names;i++)
			presentation_names[i]=(char *)malloc(20*sizeof(char));
		for(i=0;i<no_of_names;i++)	//Initialization of map to 0
		{
			cin>>name;
			strcpy(presentation_names[i],name);
			names[name]=0;	
		}
		for(i=0;i<no_of_names;i++)
		{
			cin>>name>>amount_spent_on_gifts>>no_of_persons;
			 if(no_of_persons!=0) names[name]-=no_of_persons*(amount_spent_on_gifts/no_of_persons);
            
            for(int j=0;j<no_of_persons;j++){
                cin>>name;
                names[name]+=amount_spent_on_gifts/no_of_persons;
				}
			/*if(amount_spent_on_gifts>0)
			{
				amount_left=amount_spent_on_gifts%no_of_persons;
				amount_given=amount_spent_on_gifts/no_of_persons;
				names[name]=names[name]+amount_left-amount_spent_on_gifts;
				for(in=1;in<=no_of_persons;in++)
				{
					cin>>name;
					names[name]+=amount_given;
				}
			}
			else
			{
				for(in=1;in<=no_of_persons;in++)
				{
					cin>>name;
					//names[name]+=0;
				}
			}*/
		}
		for(i=0;i<no_of_names;i++)
		{
			cout<<presentation_names[i]<<' '<<names[presentation_names[i]]<<endl;
		}
		/*Clearing of map and presentation names for next group*/
		for(ii=names.begin(); ii!=names.end(); ++ii)//Sample for printing the map
		{
			names.erase(ii);
		}
		for(i=0;i<no_of_names;i++)
			free(presentation_names[i]);
		if(cin>>no_of_names)
			cout<<endl;
		else
			break;
	}
	return 0;
}
