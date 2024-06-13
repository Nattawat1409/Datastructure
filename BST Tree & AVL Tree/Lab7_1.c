// Nattawat Ruensumrit //
// 66070503420 //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

int height(node *root);
int balance_factor(node *root);
bool is_balance(node *root);
void right_rotation(node **root);
void left_rotation(node **root);
void insert(node **root, int val);
void delete(node **root, int val);
void print_preorder(node *root);
void deallocate(node *root);

int main() 
{
    node *root = NULL; // define the initial root before allocate //
    char mode[100];
    while (true) 
    {
        scanf("%s", mode);
        if (strcmp(mode, "INSERT") == 0) 
        {
            int val;
            char text;
            do {
                scanf("%d%c", &val, &text);
                insert(&root, val);
            } while (text != '\n');              // whenever if text == \n // It's will be false out from condition //
        } else if (strcmp(mode, "DELETE") == 0) 
        {
            int val;
            char text;
            do {
                scanf("%d%c", &val, &text);
                delete(&root, val);
            } while (text != '\n');
        } else if (strcmp(mode, "PRINT") == 0) {
            if (root == NULL) 
            {
                puts("Tree is empty.");
                continue;
            }
            print_preorder(root);
            puts("");
        } else if (strcmp(mode, "EXIT") == 0) {
            break;
        } else {
            puts("Invalid command.");
        }
    }

    deallocate(root);
    return 0;
}

int height(node *root)  // to update and checking the height of tree //
{
    if (root == NULL) 
    {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height) 
    {
        return left_height + 1;
    }
    return right_height + 1;
}
int balance_factor(node *root)  //checking and update to return balance factor value //
{
    if (root == NULL) 
    {
        return 0;
    }

    return height(root->left) - height(root->right);
}

bool is_balance(node *root)  //checking if it balance //
{
    int balance = balance_factor(root);
    return balance >= -1 && balance <= 1;
}

void print_preorder(node *root) 
{
    if (root == NULL) 
    {
        return;
    }
    printf("%d ", root->val);
    print_preorder(root->left);
    print_preorder(root->right);
}

void insert(node **root, int val)  //for insert function to insert the value till input the other command // 
{
    if (*root == NULL) 
    {
        node *new_root = (node *)malloc(sizeof(node)); // allocate memories //
        new_root->val = val;
        new_root->left = NULL;
        new_root->right = NULL;
        *root = new_root;
    } else {
        if (val < (*root)->val) 
        {
            insert(&(*root)->left, val); //insert left node if less then root node value //
        } else if (val > (*root)->val) 
        {
            insert(&(*root)->right, val); //insert right node if greater then root node value //
        }
    }

    int checking_bF = balance_factor(*root);
    if (checking_bF > 1 && val < (*root)->left->val) 
    {
        right_rotation(root);
        return;
    }

    if (checking_bF < -1 && val > (*root)->right->val) 
    {
        left_rotation(root);
        return;
    }

    if (checking_bF > 1 && val > (*root)->left->val) 
    {
        left_rotation(&(*root)->left);
        right_rotation(root);
        return;
    }

    if (checking_bF < -1 && val < (*root)->right->val) 
    {
        right_rotation(&(*root)->right);
        left_rotation(root);
        return;
    }
}

void right_rotation(node **root) 
{

    node *new_root = (*root)->left;
    node *t2 = new_root->right;

    new_root->right = *root;
    (*root)->left = t2;
    *root = new_root;

}

void left_rotation(node **root) 
{
    node *new_root = (*root)->right;
    node *t2 = new_root->left;

    new_root->left = *root;
    (*root)->right = t2;
    *root = new_root;
}

void delete(node **root, int val) 
{
    if (*root == NULL) {
        puts("Node not found.");
        return;
    }
    node *ptr = *root;

    if (val < ptr->val) {
        delete (&ptr->left, val);
    } else if (val > ptr->val) {
        delete (&ptr->right, val);
    } else if (ptr->left != NULL && ptr->right != NULL) 
    {
        node *cur = (*root)->right;
        while (cur->left != NULL) 
        {
            cur = cur->left;
        }
        (*root)->val = cur->val;
        delete (&(*root)->right, cur->val);
    } else {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            *root = NULL;
        } else if (ptr->left != NULL) {
            *root = ptr->left;
        } else {
            *root = ptr->right;
        }
    }

    int check_balance = balance_factor(*root);
    if (check_balance > 1 && balance_factor((*root)->left) >= 0) 
    {
        right_rotation(root);
        return;
    }

    if (check_balance < -1 && balance_factor((*root)->right) <= 0) 
    {
        left_rotation(root);
        return;
    }

    if (check_balance > 1 && balance_factor((*root)->left) < 0) 
    {
        left_rotation(&(*root)->left);
        right_rotation(root);
        return;
    }

    if (check_balance < -1 && balance_factor((*root)->right) > 0) 
    {
        right_rotation(&(*root)->right);
        left_rotation(root);
        return;
    }
}

void deallocate(node *root)  // free memories // 
{
    if (root == NULL) 
    {
        return;
    }

    deallocate(root->left); // free memory from left node // 
    deallocate(root->right); //free memory from right node // 
    free(root);
}