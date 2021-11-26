#include<iostream>
using namespace std;
/*
	ten: nguyen thi quynh quyen 
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	ham swap
*/
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
/*
	ten: nguyen thi quynh quyen
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	sap xep noi bot 
*/
void BubbleSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
/*
	ten: nguyen thi quynh quyen
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	sap xep chon
*/
void SelectionSort(int* a, int n) {
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
	sap xep chen
*/
void InsertionSort(int* a, int n) {
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
/*
	ten: nguyen thi quynh quyen
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	sap xep nhanh
*/
void QuickSort(int* a, int left, int right) {
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
	tim kiem tuyen tinh
*/
int linearSearch(int* a, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key)
			return i;
	}
	return -1;
}
/*
	ten: nguyen thi quynh quyen
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	tim kiem nhi phan 
*/
int binarySearch(int* a, int n, int key) {
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
/*
	ten: nguyen thi quynh quyen
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	ham main 
*/
int main() {
	int* A;
	int n = 10;
	A = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << linearSearch(A, n, 7) << endl;
	QuickSort(A, 0, n - 1);
	BubbleSort(A, n);
	InsertionSort(A, n);
	SelectionSort(A, n);
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << binarySearch(A, n, 5) << endl;
	delete[] A;
	return 0;
}
