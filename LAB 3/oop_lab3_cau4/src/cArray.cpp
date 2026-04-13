#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "cArray.h"
using namespace std;

/*
INPUT: size
OUTPUT: mảng ngẫu nhiên
ALGORITHM:
- cấp phát mảng
- random [-100,100]
*/
void cArray::TaoNgauNhien(int size) {
    n = size;
    a = new int[n];

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 201 - 100;
    }
}

/*
INPUT: nhập n và từng phần tử
OUTPUT: mảng hợp lệ
ALGORITHM:
- kiểm tra n > 0
- dùng stringstream tránh lỗi "1 a", "1 1"
*/
void cArray::Nhap() {
    string line;

    // ===== NHẬP N =====
    while (true) {
        cout << "Nhap so phan tu n: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && n > 0 && !(ss >> extra)) break;

        cout << "  Sai n. Nhap lai.\n";
    }

    a = new int[n];

    // ===== NHẬP MẢNG =====
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "a[" << i << "] = ";
            getline(cin, line);

            stringstream ss(line);
            char extra;

            if (ss >> a[i] && !(ss >> extra)) break;

            cout << "  Sai phan tu. Nhap lai.\n";
        }
    }
}

/*
INPUT: mảng
OUTPUT: in mảng
ALGORITHM: duyệt
*/
void cArray::Xuat() {
    cout << "Mang: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*
INPUT: x
OUTPUT: số lần xuất hiện
ALGORITHM: duyệt + đếm
*/
int cArray::DemSoLanXuatHien(int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) dem++;
    }
    return dem;
}

/*
INPUT: mảng
OUTPUT: true nếu tăng dần
ALGORITHM: a[i] <= a[i+1]
*/
bool cArray::KiemTraTangDan() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

/*
INPUT: mảng
OUTPUT: số lẻ nhỏ nhất (không có → -1)
ALGORITHM: duyệt
*/
int cArray::TimSoLeNhoNhat() {
    int min = 999999;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            if (!found || a[i] < min) {
                min = a[i];
                found = true;
            }
        }
    }

    return found ? min : -1;
}

/*
INPUT: số nguyên
OUTPUT: true nếu là số nguyên tố
ALGORITHM: chia thử
*/
bool cArray::KiemTraSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

/*
INPUT: mảng
OUTPUT: số nguyên tố lớn nhất (không có → -1)
ALGORITHM: duyệt + check prime
*/
int cArray::TimSoNguyenToLonNhat() {
    int max = -1;

    for (int i = 0; i < n; i++) {
        if (KiemTraSoNguyenTo(a[i]) && a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

/*
INPUT: mảng
OUTPUT: mảng tăng dần
ALGORITHM: bubble sort
*/
void cArray::SapXepTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

/*
INPUT: mảng
OUTPUT: mảng giảm dần
ALGORITHM: bubble sort
*/
void cArray::SapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

/*
INPUT: none
OUTPUT: giải phóng bộ nhớ
ALGORITHM: delete[]
*/
void cArray::GiaiPhong() {
    delete[] a;
}
