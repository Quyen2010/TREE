#include<iostream>
using namespace std;
// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
struct Node {
    int data;
    Node* pNext;
};
struct singleList {
    Node* pHead;
    Node* pTail;
};
void Initialize(singleList& list) {
    list.pHead = list.pTail = NULL;
}
Node* CreateNode(int d) {
    Node* pNode = new Node;
    if (pNode != NULL) {
        pNode->data = d;
        pNode->pNext = NULL;
    }
    else {
        cout << "Cap phat bo nho that bai";
    }
    return pNode;
}
void PrintList(singleList list) {
    Node* pTmp = list.pHead;
    if (pTmp == NULL) {
        cout << "Danh sach rong";
        return;
    }
    while (pTmp != NULL) {
        cout << pTmp->data << " ";
        pTmp = pTmp->pNext;
    }
}
void InsertLast(singleList& list, int d) {
    Node* pNode = CreateNode(d);
    if (list.pHead == NULL) {
        list.pHead = list.pTail = pNode;
    }
    else {
        Node* pTmp = list.pHead;
        while (pTmp->pNext != NULL) {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNode;
    }
}
// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(singleList& list)
{
    int swapped, i;
    Node* lptr = NULL;
    if (list.pHead == NULL)
        return;
    do {
        swapped = 0;
        Node* ptr1 = list.pHead;
        while (ptr1->pNext != lptr) {
            if (ptr1->data > ptr1->pNext->data) {
                swap(ptr1->data, ptr1->pNext->data);
                swapped = 1;
            }
            ptr1 = ptr1->pNext;
        }
        lptr = ptr1;
    } while (swapped);
}
// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
void insertionSort(singleList& list) {
    Node* p = list.pHead;
    Node* cur = list.pHead->pNext;
    Node* prev = list.pHead;
    if (p == NULL || p->pNext == NULL) {
        return;
    }
    while (cur != NULL) {
        if (prev->data <= cur->data) {
            cur = cur->pNext;
            prev = prev->pNext;
        }
        else {
            if (list.pHead->data > cur->data) {
                prev->pNext = cur->pNext;
                cur->pNext = list.pHead;
                list.pHead = cur;
            }
            else {
                p = list.pHead;
                while (p->pNext != NULL && p->pNext->data < cur->data) {
                    p = p->pNext;
                }
                prev->pNext = cur->pNext;
                cur->pNext = p->pNext;
                p->pNext = cur;
            }
        }
        cur = prev->pNext;
    }
}
// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
void selectionSort(singleList& list) {
    Node* temp = list.pHead;
    while (temp != NULL) {
        Node* min = temp;
        Node* k = temp->pNext;
        while (k != NULL) {
            if (min->data > k->data)
                min = k;

            k = k->pNext;
        }
        swap(temp->data, min->data);
        temp = temp->pNext;
    }
}
// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;
    Node* newHead = NULL, * newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->pNext != pivot)	tmp = tmp->pNext;
        tmp->pNext = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->pNext = pivot;
    }
    pivot->pNext = quickSortRecur(pivot->pNext, newEnd);
    return newHead;
}
// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
void quickSort(singleList& list) {
    Node** headRef = &list.pHead;
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

// ten: nguyen thi quynh quyen
// MSSV: 6151071091
// Ngay sinh: 20/10/2002
// Email: 6151071091@st.utc2.edu.vn
int main() {
    singleList list;
    Initialize(list);
    InsertLast(list, 11);
    InsertLast(list, 8);
    InsertLast(list, 5);
    InsertLast(list, 2);
    InsertLast(list, 4);
    PrintList(list);
    int d;
    cout << endl << "Nhap du lieu can tim: ";
    cin >> d;
    Node* pSearch = linearSearch(list, d);
    if (pSearch != NULL) {
        cout << "Tim thay tim kiem tuyen tinh " << d;
    }
    else {
        cout << "Khong tim thay tim kiem tuyen tinh " << d;
    }
    cout << endl << "Sau khi sap xep: ";
    quickSort(list);
    PrintList(list);
    FreeMemory(list);
    return 0;
}
