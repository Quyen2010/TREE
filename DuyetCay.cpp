#include <iostream>
using namespace std;

typedef int Item;
struct Node {
    Item data;
    Node* left;
    Node* right;
};
class BST {
public:
    Node* root;

    BST();
    BST(Item v);
    Node* createNode(Item v);
    bool isEmpty();
    Node* insert(Node* root, Item v);
    Item leftMostValue(Node* root);
    Node* remove(Node*& root, int v);
    void preOrder(Node* root);

};

BST::BST() {
    root = NULL;
}

BST::BST(Item v) {
    root = createNode(v);
}

bool BST::isEmpty() {
    return (root == NULL);
}

Node* BST::createNode(Item v) {
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
/*
    ho te: Nguyen Thi Quynh Quyen
    MSSV: 6151071091
    Ngay Sinh: 20/10/2002
    Email: 6151071091
   3.	Duyệt cây theo thứ tự trước, thứ tự giữa, và thứ tự sau.
*/
Node* BST::insert(Node* root, Item v) {
    if (isEmpty()) {
        root = createNode(v);
        return root;
    }
    else {
        if (v < root->data)
            insert(root->left, v);
        else if (v > root->data)
            insert(root->right, v);
    }
}

Item BST::leftMostValue(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

Node* BST::remove(Node*& root, int v) {
    if (isEmpty())
        return root;
    if (v < root->data)
        root->left = remove(root->left, v);
    else if (v > root->data)
        root->right = remove(root->right, v);
    else {
        if (root->left == NULL) {
            Node* newRoot = root->right;
            delete root;
            return newRoot;
        }
        if (root->right == NULL) {
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }
        root->data = leftMostValue(root->right);
        root->right = remove(root->right, root->data);
    }
    return root;
}
/*
    ho te: Nguyen Thi Quynh Quyen
    MSSV: 6151071091
    Ngay Sinh: 20/10/2002
    Email: 6151071091
   3.	Duyệt cây theo thứ tự trước, thứ tự giữa, và thứ tự sau.
*/
void BST::preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
    BST bst;
    bst.root = NULL;
    Item v[5];
    cout << "Enter Value: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        bst.insert(bst.root, v[i]);
    }
    for (int i = 0; i < 5; i++) {
        bst.preOrder(bst.root);
    }
}
