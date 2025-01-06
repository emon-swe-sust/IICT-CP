#include<bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

node* newNode(int data) {
  node* newNode = new node();

  newNode->data = data;

  newNode->left = NULL;
  newNode->right = NULL;
  return (newNode);
}

// Insert a node in level order
node* InsertNode(node* root, int data)
{
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = newNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = newNode(data);
            return root;
        }
    }
}


// Traverse Preorder
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traverse Inorder
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

int main() {
  struct node *root = newNode(1);   
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(11);
  root->right->left = newNode(6);
  root->right->left->right = newNode(13);
  root->right->right = newNode(7);
  root->right->right->left = newNode(14);

  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);

  root = InsertNode(root, 15);
  cout << "\nInorder traversing After inserting a node: ";
  traverseInOrder(root);

}
