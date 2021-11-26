#include<iostream>
using namespace std;
/*
	ten: nguyen thi quynh quyen 
	mssv: 6151071091
	ngay sinh: 20/10/2002
	Email: 6151071091@st.utc2.edu.vn
	ham swap
*/
class Sach {
private:
    string ten;
    int trang;
public:
    Sach();
    void Nhap();
    void Xuat();
    string getten() {
        return ten;
    }
    int getTrang() {
        return trang;
    }
};
Sach::Sach() {
    ten = " ";
    trang = 0;
}
void Sach::Nhap() {
    fflush(stdin);
    cout << "Ten sach: ";
    getline(cin, ten);
    cout << "So trang: ";
    cin >> trang;
}
void Sach::Xuat() {
    cout << " Ten: " << ten << ", Trang: " << trang << endl;
}
void swap(Sach& a, Sach& b) {
    Sach temp;
    temp = a;
    a = b;
    b = temp;
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    sap xep nhanh , sap xep cuon sach theo chieu tang dan cua sach 
*/
void SapXepSach(Sach* a, int left, int right) {//quick sort
    Sach x = *(a + ((left + right) / 2));
    int i = left, j = right;
    do {
        while ((a + i)->getten() < x.getten())
            i++;
        while ((a + j)->getten() > x.getten())
            j--;
        if (i <= j) {
            swap(*(a + i), *(a + j));
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        SapXepSach(a, left, j);
    if (right > i)
        SapXepSach(a, i, right);
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    sap xep nhanh , sap xep cuon sach theo chieu giam  dan cua so trang 
*/
void SapXepTrang(Sach* a, int left, int right) {//quick sort
    Sach x = *(a + ((left + right) / 2));
    int i = left, j = right;
    do {
        while ((a + i)->getTrang() > x.getTrang())
            i++;
        while ((a + j)->getTrang() < x.getTrang())
            j--;
        if (i <= j) {
            swap(*(a + i), *(a + j));
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        SapXepTrang(a, left, j);
    if (right > i)
        SapXepTrang(a, i, right);
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    tim sach co ten x
*/
Sach TimSach(Sach* a, int n, string ten) {//binary search
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if ((a + mid)->getten() == ten)
            return a[mid];
        if ((a + mid)->getten() < ten)
            left = mid + 1;
        else
            right = mid - 1;
    }
    Sach s;
    return s;
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    Liệt kê các cuốn sách có số trang ít hơn p 
*/
void LietKe(Sach* a, int n, int p) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if ((a + i)->getTrang() < p) {
            (a + i)->Xuat();
            dem++;
        }
    }
    if (dem == 0) {
        cout << "Khong tim thay" << endl;
    }
}
/*
    ten: nguyen thi quynh quyen
    mssv: 6151071091
    ngay sinh: 20/10/2002
    Email: 6151071091@st.utc2.edu.vn
    hàm main 
*/
int main() {
    Sach* ds;
    int n;
    cout << "Nhap so sach: "; cin >> n;
    ds = new Sach[n];
    cout << endl << "Thong tin sach" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sach " << i + 1 << endl;
        (ds + i)->Nhap();
    }
    for (int i = 0; i < n; i++) {
        cout << "So: " << i + 1;
        (ds + i)->Xuat();
    }
    SapXepSach(ds, 0, n - 1);
    cout << endl << "Sap xep theo ten" << endl;
    for (int i = 0; i < n; i++) {
        cout << "So thu: " << i + 1;
        (ds + i)->Xuat();
    }
    SapXepTrang(ds, 0, n - 1);
    cout << endl << "Sap xep theo trang" << endl;
    for (int i = 0; i < n; i++) {
        cout << "So thu: " << i + 1;
        (ds + i)->Xuat();
    }
    string ten;
    cout << "Nhap ten sach can tim: ";
    fflush(stdin);
    getline(cin, ten);
    if (TimSach(ds, n, ten).getten() == " ") {
        cout << "Khong tim thay" << endl;
    }
    else TimSach(ds, n, ten).Xuat();
    int t;
    cout << "Nhap trang sach can thong ke: "; 
    cin >> t;
    LietKe(ds, n, t);
    delete[] ds;
    return 0;
}
