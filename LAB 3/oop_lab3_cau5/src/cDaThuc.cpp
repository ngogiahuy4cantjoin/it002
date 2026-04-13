#include <iostream>
#include <sstream>
#include <cmath>
#include "cDaThuc.h"
using namespace std;

/*
INPUT: bậc n và hệ số
OUTPUT: đa thức hợp lệ
ALGORITHM:
- kiểm tra n >= 0
- dùng stringstream tránh lỗi nhập sai
- nhập hệ số từ bậc cao xuống
*/
void cDaThuc::Nhap() {
    string line;

    // ===== NHẬP BẬC =====
    while (true) {
        cout << "Nhap bac da thuc: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && n >= 0 && !(ss >> extra)) break;

        cout << "  Sai bac. Nhap lai.\n";
    }

    a = new double[n + 1];

    // ===== NHẬP HỆ SỐ =====
    for (int i = 0; i <= n; i++) {
        while (true) {
            cout << "He so bac " << (n - i) << ": ";
            getline(cin, line);

            stringstream ss(line);
            char extra;

            if (ss >> a[i] && !(ss >> extra)) break;

            cout << "  Sai he so. Nhap lai.\n";
        }
    }
}

/*
INPUT: đa thức
OUTPUT: in P(x)
ALGORITHM:
- duyệt hệ số
- bỏ hệ số = 0
*/
void cDaThuc::Xuat() {
    cout << "P(x) = ";
    bool first = true;

    for (int i = 0; i <= n; i++) {
        if (a[i] == 0) continue;

        int bac = n - i;

        if (!first && a[i] > 0) cout << "+ ";

        if (bac == 0)
            cout << a[i] << " ";
        else if (bac == 1)
            cout << a[i] << "x ";
        else
            cout << a[i] << "x^" << bac << " ";

        first = false;
    }

    if (first) cout << "0";

    cout << endl;
}

/*
INPUT: x
OUTPUT: P(x)
ALGORITHM:
- tính a[i] * x^(bậc)
*/
double cDaThuc::TinhGiaTri(double x) {
    double sum = 0;

    for (int i = 0; i <= n; i++) {
        sum += a[i] * pow(x, n - i);
    }

    return sum;
}

/*
INPUT: 2 đa thức
OUTPUT: đa thức tổng
ALGORITHM:
- chuẩn hóa cùng bậc
- cộng hệ số
*/
cDaThuc cDaThuc::CongDaThuc(const cDaThuc& other) {
    cDaThuc kq;

    int maxBac = max(n, other.n);
    kq.n = maxBac;
    kq.a = new double[maxBac + 1];

    for (int i = 0; i <= maxBac; i++) {
        double hs1 = (i >= maxBac - n) ? a[i - (maxBac - n)] : 0;
        double hs2 = (i >= maxBac - other.n) ? other.a[i - (maxBac - other.n)] : 0;

        kq.a[i] = hs1 + hs2;
    }

    return kq;
}

/*
INPUT: 2 đa thức
OUTPUT: đa thức hiệu
ALGORITHM:
- giống cộng nhưng trừ
*/
cDaThuc cDaThuc::TruDaThuc(const cDaThuc& other) {
    cDaThuc kq;

    int maxBac = max(n, other.n);
    kq.n = maxBac;
    kq.a = new double[maxBac + 1];

    for (int i = 0; i <= maxBac; i++) {
        double hs1 = (i >= maxBac - n) ? a[i - (maxBac - n)] : 0;
        double hs2 = (i >= maxBac - other.n) ? other.a[i - (maxBac - other.n)] : 0;

        kq.a[i] = hs1 - hs2;
    }

    return kq;
}

/*
INPUT: none
OUTPUT: giải phóng bộ nhớ
*/
void cDaThuc::GiaiPhong() {
    delete[] a;
}
