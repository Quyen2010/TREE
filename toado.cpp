#include<iostream>
using namespace std;
struct Point {
    float x;
    float y;
};
void Nhap(Point* a) {
    cout << "Nhap x: "; 
    cin >> a->x;
    cout << "Nhap y: ";
    cin >> a->y;
}
void NhapDanhSach(Point* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "nhap diem thu: " << i + 1 << " la: " << endl;
        Nhap(a + i);
    }
}
void Xuat(Point* a) {
    cout << "(" << a->x << "," << a->y << ")" << "; ";
}
void XuatDanhSach(Point* a, int n) {
    for (int i = 0; i < n; i++) {
        Xuat(a + i);
    }
    cout << endl;
}
float do_dai(Point* a) {
    return sqrt(pow(a->x, 2) + pow(a->y, 2));
}
/*
    ten: nguyen thi quynh quyen 
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    Sắp xếp N điểm đó theo chiều tăng dần của khoảng cách từ điểm đó tới gốc tọa độ
*/
void swap(Point& a, Point& b) {
    Point temp;
    temp = a;
    a = b;
    b = temp;
}
void QuickSort(Point* a, int left, int right) {
    Point x = *(a + ((left + right) / 2));
    int i = left;
    int j = right;
    do {
        while (do_dai((a + i)) < do_dai(&x))
            i++;
        while (do_dai((a + j)) > do_dai(&x))
            j--;
        if (i <= j) {
            swap(*(a + i), *(a + j));
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
    Hãy tìm các điểm nằm trong hình tròn tâm O bán kính R 
*/
void find(Point* a, int n, int R) {
    cout << "Cac diem nam trong hinh tron tam O ban kinh R: " << endl;
    for (int i = 0; i < n; i++) {
        if (do_dai((a + i)) < R) Xuat(a + i);
    }
    cout << endl;
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    Hãy tìm các cặp điểm thỏa mãn điều kiện hai điểm nằm trên hai phía của trục hoành
*/
void find1(Point* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (((a + i)->x > 0 && (a + i)->y > 0) || ((a + i)->x < 0 && (a + i)->y>0)) {
            for (int j = i + 1; j < n; j++) {
                if (((a + j)->x > 0 && (a + j)->y > 0) || ((a + j)->x < 0 && (a + j)->y>0)) {
                    if ((a + i)->y == (a + j)->y) {
                        cout << endl;
                        Xuat((a + i));
                        Xuat((a + j));
                    }
                }
            }
        }
    }
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    Hãy tìm các điểm có khoảng cách tới gốc tọa độ bằng d
*/
void find2(Point* a, int n, int d) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (do_dai(a + i) == d) {
            Xuat(a + i);
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "khon tim thay ! vui long xem lai " << d << endl;
    }
}
int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    Point* a = new Point[n];
    NhapDanhSach(a, n);
    QuickSort(a, 0, n - 1);
    XuatDanhSach(a, n);
    float bk;
    cout << "Nhap ban kinh : ";
    cin >> bk;
    find(a, n, bk);
    cout << "cac cap diem nam tren hai phia truc hoanh la: ";
    find1(a, n);
    float d;
    cout << "nhap d: ";
    cin >> d;
    cout << "Cac diem co khoang cach bang goc toa do d: ";
    find2(a, n, d);
    delete[] a;
    return 0;
}
