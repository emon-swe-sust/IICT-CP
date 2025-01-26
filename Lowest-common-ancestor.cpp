#include <bits/stdc++.h>
using namespace std;

struct node {
    struct node *left, *right;
    int data;
};

node* newNode(int data) {
  node* newNode = new node();

  newNode->data = data;

  newNode->left = NULL;
  newNode->right = NULL;
  return (newNode);
}

node* lca(struct node *root, int n1, int n2) {

    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct node *leftLca = lca(root->left, n1, n2);
    struct node *rightLca = lca(root->right, n1, n2);

    if (leftLca && rightLca)
        return root;

    return leftLca ? leftLca : rightLca;
}

int main() {

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    struct node *ans = lca(root, 4, 5);
    if(ans == NULL){
        cout<<"No common ancestor found";
    }
    else{
        cout<<ans->data;
    }

    return 0;
}