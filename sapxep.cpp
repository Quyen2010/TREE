#include<iostream>
using namespace std;
/*
	ten: nguyen thi quynh quyen 
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	ham hoan doi, sap xep noi bot , sap xep chon 
*/
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minV = a[i], pMin = i;
		for (int j = i + 1; j < n; j++) {
			if (minV > a[j]) {
				minV = a[j];
				pMin = j;
			}
		}
		if (i != pMin) {
			swap(a[i], a[pMin]);
		}
	}
}
/*
	ten: nguyen thi quynh quyen 
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	sap xep chen , sap xep nhanh 
*/
void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void QuickSort(int a[], int left, int right) {
	int x = a[(left + right) / 2];
	int i = left, j = right;
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	if (left < j)
		QuickSort(a, left, j);
	if (right > i)
		QuickSort(a, i, right);
}
/*
	ten: nguyen thi quynh quyen 
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	tim kiem tuyen tinh , tim kiem nhi phan
*/
int linearSearch(int a[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key)
			return i;
	}
	return -1;
}
int binarySearch(int a[], int n, int key) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == key)
			return mid;
		if (a[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int main() {
	int A[100] = { 2,5,6,8,9,7,1,4,0,2 };
	cout << linearSearch(A, 10, 8) << endl;
	BubbleSort(A, 10);
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << binarySearch(A, 10, 3) << endl;
	return 0;
}
