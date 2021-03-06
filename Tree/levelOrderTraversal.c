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

    //if empty
		
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

//The height of a tree, or depth of a tree, is the maximum level of your children

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
        //then print the elements
        printf("%d ", root->data);

    //visits the children of the left with height less than h
    level(root->left,h-1);
    //then visits the children of the right with height less than h
    level(root->right,h-1);

    //returns to main function 
    
}

void levelOrder( struct node *root) {

    //First step: calculates the height of the tree
    int n=getHeight(root);

    // travels nodes from height = 1 (i=1)
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
