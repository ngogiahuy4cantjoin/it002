#include <iostream>
#include "cDaThuc.h"
#include <sstream>
using namespace std;

/*
INPUT: bac da thuc
OUTPUT: tao da thuc rong
ALGORITHM:
1. Gan bac
2. Cap phat mang he so
3. Gan tat ca bang 0
*/
cDaThuc::cDaThuc(int n) {
    bac = n;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++)
        heSo[i] = 0;
}

/*
INPUT: 1 da thuc
OUTPUT: tao ban sao
*/
cDaThuc::cDaThuc(const cDaThuc& x) {
    bac = x.bac;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++)
        heSo[i] = x.heSo[i];
}

/*
INPUT: khong co
OUTPUT: giai phong bo nho
*/
cDaThuc::~cDaThuc() {
    delete[] heSo;
}

/*
INPUT: ban phim
OUTPUT: da thuc hop le
*/
void cDaThuc::Nhap() {
    cin >> *this;
}

/*
INPUT: da thuc
OUTPUT: xuat ra man hinh
*/
void cDaThuc::Xuat() {
    cout << *this;
}

/*
INPUT: x
OUTPUT: gia tri da thuc tai x
ALGORITHM:
1. Tinh tong ai*x^i
*/
double cDaThuc::GiaTriTai(double x) {
    double tong = 0;
    double mu = 1;

    for (int i = 0; i <= bac; i++) {
        tong += heSo[i] * mu;
        mu *= x;
    }

    return tong;
}

/*
INPUT: 2 da thuc
OUTPUT: gan da thuc
*/
cDaThuc& cDaThuc::operator = (const cDaThuc& x) {
    if (this == &x)
        return *this;

    delete[] heSo;

    bac = x.bac;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++)
        heSo[i] = x.heSo[i];

    return *this;
}

/*
INPUT: 2 da thuc
OUTPUT: tong 2 da thuc
*/
cDaThuc cDaThuc::operator + (const cDaThuc& x) {
    int maxBac = (bac > x.bac) ? bac : x.bac;
    cDaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= x.bac) ? x.heSo[i] : 0;
        kq.heSo[i] = a + b;
    }

    return kq;
}

/*
INPUT: 2 da thuc
OUTPUT: hieu 2 da thuc
*/
cDaThuc cDaThuc::operator - (const cDaThuc& x) {
    int maxBac = (bac > x.bac) ? bac : x.bac;
    cDaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= x.bac) ? x.heSo[i] : 0;
        kq.heSo[i] = a - b;
    }

    return kq;
}

/*
INPUT: da thuc
OUTPUT: dang hien thi thong thuong
*/
ostream& operator << (ostream& out, const cDaThuc& x) {
    for (int i = x.bac; i >= 0; i--) {
        if (x.heSo[i] != 0) {
            if (i != x.bac && x.heSo[i] > 0)
                out << " + ";

            if (i != x.bac && x.heSo[i] < 0)
                out << " - ";

            if (i == x.bac)
                out << x.heSo[i];
            else
                out << (x.heSo[i] > 0 ? x.heSo[i] : -x.heSo[i]);

            if (i > 0)
                out << "x";

            if (i > 1)
                out << "^" << i;
        }
    }

    return out;
}

/*
INPUT: ban phim
OUTPUT: nhap hop le
ALGORITHM:
1. Nhap bac >= 0
2. Nhap he so tu a0 den an
*/
istream& operator >> (istream& in, cDaThuc& x) {
    string line;
    char extra;

while (true) {
    cout << "Nhap bac da thuc: ";
    getline(in, line);

    if (line.empty()) {
        cout << "Nhap sai. Nhap lai.\n";
        continue;
    }

    stringstream ss(line);

    if (ss >> x.bac && !(ss >> extra) && x.bac >= 0)
        break;

    cout << "Nhap sai. Nhap lai.\n";
}

    delete[] x.heSo;
    x.heSo = new double[x.bac + 1];

    for (int i = 0; i <= x.bac; i++) {
        while (true) {
            cout << "Nhap he so bac " << i << ": ";
            getline(in, line);

            stringstream ss(line);

            if (ss >> x.heSo[i] && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }
    }

    return in;
}
