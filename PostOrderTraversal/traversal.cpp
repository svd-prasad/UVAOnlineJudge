#include <iostream>
#include <cstdlib>
using namespace std;
struct tNode
{
	int data;
	struct tNode* left;
	struct tNode* right;
};
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
   given data and NULL left and right pointers. */
typedef struct tNode node;

void insert(node ** tree, node * item) {
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->data<(*tree)->data)
      insert(&(*tree)->left, item);
   else if(item->data>(*tree)->data)
      insert(&(*tree)->right, item);
}

void printout(node * tree) {
   if(tree->left) printout(tree->left);
   cout<<tree->data<<endl;
   if(tree->right) printout(tree->right);
}

struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}
  
/* Stack Functions */
struct stack
{
	struct tNode* node;
	struct stack* link;
};
void push(struct stack** top ,struct tNode* node)
{
	struct stack *stacknode = (struct stack *)malloc(sizeof(struct stack));
	stacknode -> node = node;
	stacknode -> link = NULL;
	if(*top == NULL)
		*top = stacknode;
	else
	{
		stacknode -> link = *top;
		*top = stacknode;
	}
}
bool isStackEmpty(struct stack *top)
{	
	return((top != NULL)?0:1);
}
struct tNode* pop(struct stack** top)
{
	struct tNode* retVal;
	if(!isStackEmpty(*top))
	{
		retVal = (*top) -> node;
		*top = (*top) -> link;
	}
	return retVal;
}
struct tNode* top(struct stack* top)
{
	struct tNode* retVal;
	if(!isStackEmpty(top))
		return((top) -> node);
}
void PostOrderTraversal(struct tNode* root)
{
	struct stack* s_top = NULL;
	struct tNode* tnode;
	while(1)
	{
		while(root)
		{
			push(&s_top, root);
			//cout<<root -> data<<endl;
			root = root -> left;
		}
		if(isStackEmpty(s_top))
			break;
		root = pop(&s_top);
		cout<<root -> data<<endl;
		root = root -> right;
		if(root == NULL)
			continue;
	}
}
void recPostOrderTraversal(struct tNode* root)
{
	if(root)
	{
		recPostOrderTraversal(root->left);
		cout<<root -> data<<endl;
		recPostOrderTraversal(root->right);
	}
}
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  
  node * curr, * root;
   int i;

   root = NULL;

   for(i=16;i<=20;i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->data = i;
      insert(&root, curr);
   }
   for(i=11;i<=15;i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->data = i;
      insert(&root, curr);
   }

  //printout(root);
  PostOrderTraversal(root);
 
  return 0;
}