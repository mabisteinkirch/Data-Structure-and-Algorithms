/*Given a pointer to the root of a binary tree, you need to print the level order traversal of this tree. 
In level-order traversal, nodes are visited level by level from left to right.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

int getHeight(struct node* root) {
    
    int hl, hr;

    if (!root)
        return 0; //tree height empty

    hl = getHeight(root->left);
    hr = getHeight(root->right);

    if (hl<hr)
        return (hr+1);
 
    else 
        return (hl+1);

}

void level(struct node *root,int h){
      if(!root)
          return ;
      if(h==1)
          printf("%d ", root->data);
      level(root->left,h-1);
      level(root->right,h-1);
    
  }

void levelOrder( struct node *root) {
int n=getHeight(root);
    for(int i=1;i<=n;i++){
        level(root,i);
        
    }
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	levelOrder(root);
    return 0;
}
