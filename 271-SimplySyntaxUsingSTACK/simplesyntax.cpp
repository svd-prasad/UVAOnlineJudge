#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct stack
{
	char c;
	struct stack *next;
};
void push(struct stack **top , char c1)
{
	struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
	if(newnode)
	{
		newnode -> c = c1;
		newnode -> next = *top; 
	}
	*top = newnode;
}
void pop(struct stack **top)  //No need to return popped element
{
	(*top) = (*top) -> next;
}
int isStackEmpty(struct stack *top)
{
	return (top == NULL)?1:0;
}
int stacksize(struct stack * top)
{
	int i=0;
	while(!isStackEmpty(top))
	{
		pop(&top);
		++i;
	}
	return i;
}

int main()
{
	struct stack *top = NULL;
	char *str = (char *)malloc(260*sizeof(char));
	int len, i;
	bool FLAG = false;
	while(gets(str))
	{	
		if(FLAG)
			cout<<endl;
		FLAG = true;
		len = strlen(str);
		for(i = len-1;i>=0;i--)
		{
			if(str[i] >= 'p' && str[i] <= 'z') 
				push(&top , str[i]);
			else if(str[i] == 'N')
			{
				if(stacksize(top) >= 1)
				{
					pop(&top);
					push(&top , str[i]);
				}
				else
				{
					cout<<"NO";
					break;		//Stack is empty and Ns syntax is not found
				}
			}
			else if(str[i] == 'C' || str[i] == 'D' || str[i] == 'E' || str[i] == 'I')
			{
				if(!isStackEmpty(top))
				{
					
					if(stacksize(top) >= 2)
					{
						pop(&top);
						pop(&top);
						push(&top , str[i]);
					}
					else
					{
						cout<<"NO";
						break;		//Stack is empty and Ns syntax is not found
					}
				}
			}
			else
			{
				cout<<"NO";
				break;
			}
		}  //FOR END
		if(i == -1 && stacksize(top) == 1)
				cout<<"YES";
		if(i== -1 && stacksize(top) != 1)
				cout<<"NO";
		top = NULL; //Making stack empty*/
	}// WHILE END
	//cout<<endl;
	return 0;
}