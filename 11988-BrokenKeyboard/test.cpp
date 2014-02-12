#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
struct node
{
	std::vector<char> myvector;
	struct node *link;
}n;
int main()
{	
	//struct node *n = (struct node *)malloc(sizeof(struct node));
	(n.myvector).push_back('a');
	(n.myvector).push_back('a');
	(n.myvector).push_back('a');
	(n.myvector).push_back('a');
	//n->link = NULL;
	cout<<"size"<<int(n.myvector.size())<<endl;
	return 0;
}
