#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
main ()
{
  string line,tex_quote_string;
  int length,i;
  bool turn=true;
  while(std::getline (std::cin,line))
  {
	length=line.size();
	for(i=0;i<length;++i)
	{
			if(line[i]!='"')
			{
				tex_quote_string.append(line,i,1);
			}
			else
			{
				if(!turn)
				{
					tex_quote_string.append("''");
					turn=true;
				}
				else
				{
					tex_quote_string.append("``");
					turn=false;
				}
			}
	}
	tex_quote_string.append("\n");
  }
	cout<<tex_quote_string;
  return 0;
}