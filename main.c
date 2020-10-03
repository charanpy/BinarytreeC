#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *left,*right;
};

struct node* create(){
        int x;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data(enter -1 for no node) ");
        scanf("%d",&x);
        if(x==-1){
                return 0;
        }
        newnode->data=x;
        printf("enter left child of %d",x);
        newnode->left=create();
        printf("enter right child of %d",x);
        newnode->right=create();
        return newnode;
}

void preorder(struct node* root){
        if(root == 0){
                return;
        }
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
}


void postorder(struct node* root){
        if(root == 0){
                return;
        }
        
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
}


void inorder(struct node* root){
        if(root == 0){
                return;
        }
        
        inorder(root->left);
         printf("%d",root->data);
        inorder(root->right);
       
}



int main(){
        struct node *root;
        root=create();
        printf("preorder is");
        preorder(root);
        postorder(root);
        inorder(root);
        return 0;
}