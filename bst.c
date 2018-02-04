/*
 * Takes integer input and builds
 * a binary search tree then applies preorder, 
 * inorder, and postorder traversal functions
 *
 * author: It was a group effort
*/
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//Traverses the tree and places the new node in the
//correct place
static void place_node(TreeNode* root, TreeNode* newNode){
    //Go to the left
    if(newNode->data < newNode->data){
        
        //Empty node
        if(root->left != NULL){
            root->left = newNode;
        }else{
            place_node(root->left, newNode);
        }
    //Go to the right
    }else if(newNode->data > root->data){
        
        //Empty node
        if(root->right == NULL){
            root->right = newNode;
        }else{
            place_node(root->right, newNode);
        }

    }//end if
}

//Checks if there are duplicates in
//the input
static int duplicates(const int elements[], const int count, const int current){
 
    for(int i = 0; i < count; i++){
        if(elements[current] == elements[i] && current != i){
            return 1;
        }
    }//for

    return 0;

}

//Takes in a list of integers and
//builds a tree in the correct order
void build_tree(TreeNode** root, const int elements[], const int count){
    (*root)->data = elements[0];\

    for(int i = 1; i < count; i++){
        
        //Check for duplicate value
        if(duplicates(elements, count, i) != 0){
            continue;
        }

        //initialize new node
        TreeNode *newNode = malloc(sizeof(TreeNode));
        newNode->data = elements[i];
        newNode->left = NULL;
        newNode->right = NULL;

        place_node(*root, newNode);
        
        //nextNode = add_tree(nextNode, elements[i]);
        }
}

//Recursive function to traverse in a
//preorder, inorder, or postorder fashion
void traverse(const TreeNode* root, const TraversalType type){
	
	if(root == NULL){
		return;
	}
	
    switch(type){
        case(PREORDER):
			printf("%d\n", root->data);
                        traverse(root->left, PREORDER);
			traverse(root->right, PREORDER);
            break;
        case(INORDER):
			traverse(root->left, INORDER);
			printf("%d\n", root->data);
			traverse(root->right, INORDER);
            break;
        case(POSTORDER):
			traverse(root->left, POSTORDER);
			traverse(root->right, POSTORDER);
			printf("%d\n", root->data);
            break;
    }
}

//Frees all allocated nodes
void cleanup_tree(TreeNode* root){

    if(root == NULL)
        return;

    cleanup_tree(root->left);
    cleanup_tree(root->right);
}


int main(int argc, char argv[]){

    //John, is this how I do arguments in C? Why can't we use Python?
    if(argc < 2){
        //bad arguments
        printf("usage: ./bst size\n\tsize - number of elements in the tree\n");
        return 1;
    }

    int count = atoi(argv[1]);
    int values[count];

    //Initialize root node
    TreeNode *rootNode = malloc(sizeof(TreeNode));
	rootNode->data = -1;
	rootNode->left = NULL;
	rootNode->right = NULL;

    printf("Enter %d integer values to place in tree:\n", count);
 
    for(int i = 0; i < count; i++){
        scanf("%d", &values[i]);
    }

    printf("Input values:\n");
    for(int i = 1; i < count; i++){
        printf("%d\n", values[i]);
    }
    
    //Not sure if working
    build_tree(&rootNode, values, count); 

    printf("Inorder:\n");
    traverse(rootNode, PREORDER)

    printf("Preorder:\n");
    traverse(rootNode, INORDER)

    printf("Postorder:\n");
    traverse(rootNode, POSTORDER)

    cleanup_tree(rootNode);

    return 0;
}
