// Nattawat  Ruensumrit //
// 66070503420 //
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} tree;

tree* Create_node(int node) // Create a node function //
{
    tree* newnode = (tree*)malloc(sizeof(tree));
    newnode->data = node;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(tree **root, int val) 
{
    if (*root == NULL) 
    {
        *root = Create_node(val); // recall to store a 1st value keep into create_node function //
    } else {
        if (val <= (*root)->data) {
            insert(&((*root)->left), val);
        } else {
            insert(&((*root)->right), val);
        }
    }
}

void INORDER(tree *root) 
{
    if(root == NULL) {
        return;
    }
    INORDER(root->left);
    printf("%d ", root->data);
    INORDER(root->right);
}

void PREORDER(tree *root) 
{
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    PREORDER(root->left);
    PREORDER(root->right);
}

void POSTORDER(tree *root) 
{
    if(root == NULL)
    {
        return;
    }
    POSTORDER(root->left);
    POSTORDER(root->right);
    printf("%d ", root->data);
}

void END(tree *root) 
{
    if (root != NULL) 
    {
        END(root->left);
        printf("%d ", root->data);
        END(root->right);
    }
}

int main() 
{
    char mode[10];
    int val;
    tree *binary_tree = NULL;

    while(1) {
        scanf("%s", mode);

        if(strcmp(mode, "INS") == 0) {
            scanf("%d", &val); // store val from main function //
            insert(&binary_tree, val);  // tranfer to store in INS //
        } else if(strcmp(mode, "INORDER") == 0) {
            INORDER(binary_tree);
            printf("\n");
        } else if(strcmp(mode, "PREORDER") == 0) {
            PREORDER(binary_tree);
            printf("\n");
        } else if(strcmp(mode, "POSTORDER") == 0) {
            POSTORDER(binary_tree);
            printf("\n");
        } else if(strcmp(mode, "END") == 0) {
            END(binary_tree);
            printf("\n");
            return 0;
        }
    }

    return 0;
}
