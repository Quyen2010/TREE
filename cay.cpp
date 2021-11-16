//Nguyễn Thị Quỳnh Quyên 6151071091
#include <iostream>
using namespace std;
typedef int Item;
struct Node {
    Item data;
    Node* left;
    Node* right;
};
class BinaryTree {
public:
    Node* root;

    BinaryTree();
    BinaryTree(Item v);
    Node* createNode(Item v);
    void insert(Node*& root, Item v);
    void preOrder(Node* root);
    Item search(Node* root, Item v);
};
BinaryTree::BinaryTree() {
    root = NULL;
}
BinaryTree::BinaryTree(Item v) {
    root = createNode(v);
}
Node* BinaryTree::createNode(Item v) {
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
void BinaryTree::insert(Node*& root, Item v) {
    if (root == NULL) {
        root = createNode(v);
    }
    else {
        if (v < root->data)
            insert(root->left, v);
        else if (v > root->data)
            insert(root->right, v);
    }
}
void BinaryTree::preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}
Item BinaryTree::search(Node* root, Item v) {
    if (root == NULL)
        return NULL;
    if (root->data == v)
        return root->data;
    Item q = search(root->left, v);
    if (q == NULL)
        q = search(root->right, v);
}
int main() {
    BinaryTree bt;
    bt.root = NULL;
    Item v[5];
    cout << "Enter Value: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        bt.insert(bt.root, v[i]);
    }
    bt.preOrder(bt.root);
    Item temp;
    cout << "\nEnter Value You Want To Find: ";
    cin >> temp;
    cout << "\nHere is this: " << bt.search(bt.root, temp);
}

