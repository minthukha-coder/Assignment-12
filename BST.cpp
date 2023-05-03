//
// Created by User on 02/05/2023.
//

#include"stdio.h"
#include"stdlib.h"

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int newData){
    struct Node * new_node = new Node();
    new_node->data = newData;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node * insertNode(struct Node * root,int start,int end) {
    if (start > end) {
        return NULL;
    }

        int mid = (start + end) / 2;
        root = createNode(mid);
        root->left = insertNode(root->left, start, mid - 1);
        root->right = insertNode(root->right, mid + 1, end);
        return root;

    }


void inorderTranversal(struct Node * root) {
    if (root == NULL) {
        return;
    }

    inorderTranversal(root->left);
    printf("%d ", root->data);

    inorderTranversal(root->right);

}

int sizeOfTree(struct Node * root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + sizeOfTree(root->left)+sizeOfTree(root->right);
    }
}

int main(){
    struct Node * root = NULL;
    root = insertNode(root,1,1000);
    inorderTranversal(root);
    printf("\n");
    int size = sizeOfTree(root);
    printf("Size of Tree %d\b",size);



    return 0;
}
