#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
using namespace std;
struct lnode
{
	char key;
	struct lnode *link;
};
struct lnode * createNode(char c)
{
	struct lnode *newnode = (struct lnode *)malloc(sizeof(struct lnode));
	if(newnode != NULL)
	{
		newnode -> key = c;
		newnode -> link = NULL;
	}
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
/*void insertFront(struct lnode **head, struct lnode **tail, char c)
{
	struct lnode *curNode = createNode(c);
	if(*head == NULL)
	{
		*head = curNode;
		*tail = curNode;
	}
	else
	{
		curNode -> link = *head;
		(*head) = curNode;
	}
}*/
void insertEnd(struct lnode **head, struct lnode **tail, char c)
{
	struct lnode *curNode = createNode(c);
	if(*head == NULL)
	{
		*head = curNode;
		*tail = curNode;
	}
	else
	{
		(*tail) -> link = curNode;
		*tail = curNode;
	}
}
struct lnode *insertAfterLeft(struct lnode *left, char c)
{
	struct lnode *temp, *curNode = createNode(c);
	if(left == NULL)
		return curNode;
	else
	{
		temp = left -> link;
		left -> link = curNode;
		curNode -> link = temp;
	}
	return curNode;
}
void printList(struct lnode *head)
{
	while(head != NULL)
	{
		cout<<head -> key;
		head = head -> link;
	}
	cout<<endl;
}
int main()
{
	char c;
	struct lnode *listHead = NULL, *listTail = NULL, *returnNode = NULL, *dup_list_head, *temp;
	bool home_key_flag = false, end_key_flag = false, newlineflag = false;
	while((c = getchar()) != EOF)
	{
		if(c != '\n')
		{
			if(c == '[')
			{
				home_key_flag = true;
				dup_list_head = listHead;
				returnNode = NULL;
			}
			if(c == ']')
			{
				if(home_key_flag)
				{
					if(returnNode && returnNode -> link)
						returnNode -> link = dup_list_head;
					home_key_flag = false;
				}
				temp = listHead;
				while(temp && temp -> link)
					temp = temp -> link;
				listTail = temp;
			}
			if(isalpha(c) || c == '_')
			{
				if(home_key_flag)
				{
					if(returnNode == NULL)
					{
						returnNode = insertAfterLeft(returnNode, c);
						returnNode -> link = listHead;
						listHead = returnNode;
					}
					else
						returnNode = insertAfterLeft(returnNode, c);
				}
				else
					insertEnd(&listHead, &listTail, c);
			}
			
		}
		else
		{
			printList(listHead);
			newlineflag = true;
			deleteList(&listHead);
			home_key_flag = false;
			listHead = NULL;
			listTail = NULL;
			returnNode = NULL;
			
			
		}
	}
	printList(listHead);
	return 0;
}