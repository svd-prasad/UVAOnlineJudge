#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;
struct lnode
{
	string keys;
	struct lnode *link;
};
struct lnode * createNode()
{
	struct lnode *newnode = (struct lnode *)malloc(sizeof(struct lnode));
	if(newnode != NULL)
		newnode -> link = NULL;
	return newnode;
}
void deleteList(struct lnode **head)
{
	struct lnode * temp;
	while(*head != NULL)
	{
		temp = (*head) -> link;
		free(*head);
		*head = temp;
	}
}
void insertCharToNode(struct lnode *node, char c)
{
	node -> keys = c;
}
void printList(struct lnode *head)
{
	while(head != NULL)
	{
		cout<<head -> keys;
		head = head -> link;
	}
	cout<<endl;
}
int main()
{
	char c;
	struct lnode *listHead = NULL;
	bool home_key_flag = false;
	while((c = getchar()) != EOF)
	{
		if(c != '\n')
		{
			if(c == '[')
			{
				home_key_flag = true;
				
			}
			if(c == ']')
			{
				if(home_key_flag)
				{
					home_key_flag = false;
				}
			}
			if(isalpha(c) || c == '_')
			{ cout<<c;
				listHead = (struct lnode *)malloc(sizeof(struct lnode));
				(listHead -> keys).append(c);
				//insertCharToNode(listHead, c);
			}
			
		}
		else
		{
			//printList(listHead);
			//deleteList(&listHead);
			home_key_flag = false;
			listHead = NULL;
		}
	}
	//printList(listHead);
	return 0;
}