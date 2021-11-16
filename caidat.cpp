#include <iostream>
using namespace std;
/*
    ho te: Nguyen Thi Quynh Quyen
    MSSV: 6151071091
    Ngay Sinh: 20/10/2002
    Email: 6151071091
    1.	Cài đặt cấu trúc dữ liệu 
    cây nhị phân với các thao tác đã được học trên lớp.
*/
typedef int Item;
struct Node {
    Item data;
    Node* left;
    Node* right;
};
class Tree {
    Node* root;

    BST();
    BST(Item v);
    Node* createNode(Item v);
    bool isEmpty();
    void preOrder(Node* root);
    void postOrder(Node* root);
    void inOrder(Node* root);
    void deleteTree(Node*& root);
    Node* search(Node* p, Item v);
    Node* insert(Node* root, Item v);
    Item remove(Node* p);
    Node* minValueNode(Node* p);
    Item leftMostValue(Node* root)
};

Tree::Tree() {
    root = NULL;
}

Tree::Tree(Item v) {
    root = createNode(v);
}

bool Tree::isEmpty() {
    return (root == NULL);
}
/*
    ho ten: Nguyen Thi Quynh Quyen
    MSSV: 6151071091
    Ngay Sinh: 20/10/2002
    Email: 6151071091
    2.	Tạo một cây nhị phân gồm n nút, mỗi nút lưu một phần tử của một mảng số nguyên cho trước. 
*/
Node* Tree::createNode(Item v) {
    Node* p = new Node;
    p->data = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* Tree::insert(Node* root, Item v) {
    if (root == NULL) {
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

void Tree::preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::postOrder(Node* root) {
    if (root != NULL) {
        PostOder(root->left);
        PostOder(root->right);
        cout << root->data;
    }
}

void Tree::inOrder(Node* root) {
    if (root != NULL) {
        PostOder(root->left);
        cout << root->data;
        PostOder(root->right);
    }
}


Node* Tree::minValueNode(Node* p) {
    Node* current = p;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Item Tree::leftMostValue(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

Node* Tree::remove(Node* root, int v) {
    if (root == NULL)
        return root;
    if (v < root->data)
        root->left = remove(root->left, v);
    else if (v > root->data)
        root->right = remove(root->right, v);
    else
    {
        if (root->left == NULL)
        {
            Node* newRoot = root->right;
            delete root;
            return newRoot;
        }
        if (root->left == NULL)
        {
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }
        root = LeftMostValue(root->right);
        root->right = remove(root->right, v);
    }
    return root;
}
Node* Tree::search(Node* root, Item v) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == v) {
        return root;
    }

    else if (v < root->data)
        Search(root->left, v);
    else if (v > root)
        Search(root->right, v);
    return root;
}



