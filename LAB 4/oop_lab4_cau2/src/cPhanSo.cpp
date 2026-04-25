#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "cPhanSo.h"
using namespace std;

/*
INPUT: tu, mau
OUTPUT: tao phan so
ALGORITHM:
1. Neu mau = 0 thi gan = 1
2. Rut gon
*/
cPhanSo::cPhanSo(int t, int m) {
    tu = t;

    if (m == 0)
        mau = 1;
    else
        mau = m;

    RutGon();
}

/*
INPUT: tu, mau(mac dinh = 1)
OUTPUT: cap nhat phan so
ALGORITHM:
1. Neu mau = 0 thi gan = 1
2. Rut gon
*/
void cPhanSo::ThietLap(int t, int m) {
    tu = t;

    if (m == 0)
        mau = 1;
    else
        mau = m;

    RutGon();
}

/*
INPUT: a, b
OUTPUT: uoc chung lon nhat
*/
int cPhanSo::UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    if (a == 0)
        return 1;

    return a;
}

/*
INPUT: phan so
OUTPUT: phan so toi gian
ALGORITHM:
1. Chia ca tu va mau cho UCLN
2. Dua dau am len tu
*/
void cPhanSo::RutGon() {
    int uc = UCLN(tu, mau);

    tu /= uc;
    mau /= uc;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

/*
INPUT: ban phim
OUTPUT: phan so hop le
*/
void cPhanSo::Nhap() {
    cin >> *this;
}

/*
INPUT: phan so
OUTPUT: in ra man hinh
*/
void cPhanSo::Xuat() {
    cout << *this;
}

/*
INPUT: 2 phan so
OUTPUT: tong
*/
cPhanSo cPhanSo::operator + (const cPhanSo& x) {
    return cPhanSo(tu * x.mau + x.tu * mau, mau * x.mau);
}

/*
INPUT: 2 phan so
OUTPUT: hieu
*/
cPhanSo cPhanSo::operator - (const cPhanSo& x) {
    return cPhanSo(tu * x.mau - x.tu * mau, mau * x.mau);
}

/*
INPUT: 2 phan so
OUTPUT: tich
*/
cPhanSo cPhanSo::operator * (const cPhanSo& x) {
    return cPhanSo(tu * x.tu, mau * x.mau);
}

/*
INPUT: 2 phan so
OUTPUT: thuong
ALGORITHM:
1. Neu tu so cua x = 0 thi tra ve 0/1
*/
cPhanSo cPhanSo::operator / (const cPhanSo& x) {
    if (x.tu == 0)
        return cPhanSo(0, 1);

    return cPhanSo(tu * x.mau, mau * x.tu);
}

/*
INPUT: 2 phan so
OUTPUT: true neu bang nhau
*/
bool cPhanSo::operator == (const cPhanSo& x) {
    return (tu == x.tu && mau == x.mau);
}

/*
INPUT: 2 phan so
OUTPUT: true neu lon hon
*/
bool cPhanSo::operator > (const cPhanSo& x) {
    return (tu * x.mau > x.tu * mau);
}

/*
INPUT: 2 phan so
OUTPUT: true neu nho hon
*/
bool cPhanSo::operator < (const cPhanSo& x) {
    return (tu * x.mau < x.tu * mau);
}

/*
INPUT: phan so
OUTPUT: dang tu/mau
*/
ostream& operator << (ostream& out, const cPhanSo& x) {
    if (x.mau == 1)
        out << x.tu;
    else
        out << x.tu << "/" << x.mau;

    return out;
}

/*
INPUT: ban phim
OUTPUT: nhap hop le
ALGORITHM:
1. Nhap tu
2. Nhap mau
3. Mau khac 0
4. Sai thi nhap lai
*/
istream& operator >> (istream& in, cPhanSo& x) {
    string line;
    int t, m;

    while (true) {
        cout << "Nhap tu so: ";
        getline(in, line);

        stringstream ss(line);
        char extra;

        if (ss >> t && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap mau so: ";
        getline(in, line);

        stringstream ss(line);
        char extra;

        if (ss >> m && !(ss >> extra) && m != 0)
            break;

        cout << "Nhap sai. Mau so phai khac 0. Nhap lai.\n";
    }

    x.tu = t;
    x.mau = m;
    x.RutGon();

    return in;
}
