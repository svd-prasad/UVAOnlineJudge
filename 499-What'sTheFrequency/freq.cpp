//BUG   check for count>0 ----if alphabets exists then only print
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int max_value(std::map<char,int> mymap)
{
	int max=0;
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		if(it->second > max)
			max =it->second;
	return max;
}
int main ()
{
  char c;
  int count;
  std::map<char,int> mymap;
  std::map<char,int>::iterator it_find;
  while((c=getchar())!=EOF)
  {
	if(isalpha(c))
	{
		it_find=mymap.find(c);
		if(it_find->second)
			(it_find->second)++;
		else
			mymap.insert ( std::pair<char,int>(c,1) );
	}
	if(c=='\n')
	{
		count=max_value(mymap);
		if(count>0)
		{
			for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				if(it->second == count)
					cout<<it->first;
			cout<<" "<<count;
			cout<<endl;
		}
		mymap.clear();
	}
  }
  count=max_value(mymap);
  if(count>0)
  {
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			if(it->second == count)
				cout<<it->first;
	cout<<" "<<count;
  }
  return 0;
}

