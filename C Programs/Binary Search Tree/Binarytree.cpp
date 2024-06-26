#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data; //node will store some data
  struct node *right_child; // right child
  struct node *left_child; // left child
}*root=NULL;

//function to create a node
struct node* new_node(int x) {
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left_child = NULL;
  temp -> right_child = NULL;

  return temp;
}

// searching operation
struct node* search(struct node * root, int x) {
  if (root == NULL || root -> data == x) //if root->data is x then the element is found
    return root;
  else if (x > root -> data) // x is greater, so we will search the right subtree
    return search(root -> right_child, x);
  else //x is smaller than the data, so we will search the left subtree
    return search(root -> left_child, x);
}

// insertion
struct node* insert(struct node * root, int x) {
  //searching for the place to insert
  if (x > root -> data) // x is greater. Should be inserted to the right
    root -> right_child = insert(root -> right_child, x);
  else // x is smaller and should be inserted to left
    root -> left_child = insert(root -> left_child, x);
  
}

//function to find the minimum value in a node
struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root -> left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root -> left_child); // left most element will be minimum
  return root;
}

// deletion
struct node* del(struct node * root, int x) {
  //searching for the item to be deld
  if (root == NULL)
    return NULL;
  if (x > root -> data)
    root -> right_child = del(root -> right_child, x);
  else if (x < root -> data)
    root -> left_child = del(root -> left_child, x);
  else {
    //No Child node
    if (root -> left_child == NULL && root -> right_child == NULL) {
      free(root);
      return NULL;
    }

    //One Child node
    else if (root -> left_child == NULL || root -> right_child == NULL) {
      struct node *temp;
      if (root -> left_child == NULL)
        temp = root -> right_child;
      else
        temp = root -> left_child;
      free(root);
      return temp;
    }

    //Two Children
    else {
      struct node *temp = find_minimum(root -> right_child);
      root -> data = temp -> data;
      root -> right_child = del(root -> right_child, temp -> data);
    }
  }
  return root;
}

// inorder Traversal
struct node* inorder(struct node *root) {
  if (root != NULL) // checking if the root is not null
  {
    inorder(root -> left_child); // traversing left child
    printf(" %d ", root -> data); // printing data at root
    inorder(root -> right_child); // traversing right child
  }
}

int main() 
{
	int choice,n,data,i;
	while(1)
	{
		printf("\n press 1 for insert");
		printf("\n press 2 for delete");
		printf("\n press 3 for traverse in order");
		printf("\n enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n enter the no of elements you want to enter in the binary tree: ");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("\n enter the data: ");
						scanf("%d",&data);
						insert(root,data);
					}
					break;
			case 2:	printf("\n enter the elemnt to delete: ");
					scanf("%d",&data);
					del(root,data);
					break;
			case 3:	inorder(root);
					break;
			default:	printf("\n wrong choice!!");
		}
	}
	


  return 0;
}


