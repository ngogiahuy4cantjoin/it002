#include <iostream>
#include <sstream>
#include <cmath>
#include "cSoPhuc.h"
using namespace std;

/*
INPUT: phan thuc, phan ao
OUTPUT: tao so phuc
ALGORITHM:
1. Gan gia tri mac dinh
*/
cSoPhuc::cSoPhuc(double t, double a) {
    thuc = t;
    ao = a;
}

/*
INPUT: phan thuc, phan ao (mac dinh = 0)
OUTPUT: cap nhat so phuc
ALGORITHM:
1. Gan lai gia tri
*/
void cSoPhuc::ThietLap(double t, double a) {
    thuc = t;
    ao = a;
}

/*
INPUT: ban phim
OUTPUT: so phuc hop le
ALGORITHM:
1. Nhap phan thuc
2. Nhap phan ao
3. Kiem tra dung dinh dang
*/
void cSoPhuc::Nhap() {
    cin >> *this;
}

/*
INPUT: so phuc
OUTPUT: in ra man hinh
ALGORITHM:
1. Goi operator <<
*/
void cSoPhuc::Xuat() {
    cout << *this;
}

/*
INPUT: 2 so phuc
OUTPUT: tong
ALGORITHM:
(a+bi) + (c+di) = (a+c) + (b+d)i
*/
cSoPhuc cSoPhuc::operator + (const cSoPhuc& x) {
    return cSoPhuc(thuc + x.thuc, ao + x.ao);
}

/*
INPUT: 2 so phuc
OUTPUT: hieu
ALGORITHM:
(a+bi) - (c+di) = (a-c) + (b-d)i
*/
cSoPhuc cSoPhuc::operator - (const cSoPhuc& x) {
    return cSoPhuc(thuc - x.thuc, ao - x.ao);
}

/*
INPUT: 2 so phuc
OUTPUT: tich
ALGORITHM:
(a+bi)(c+di) = (ac-bd) + (ad+bc)i
*/
cSoPhuc cSoPhuc::operator * (const cSoPhuc& x) {
    double t = thuc * x.thuc - ao * x.ao;
    double a = thuc * x.ao + ao * x.thuc;
    return cSoPhuc(t, a);
}

/*
INPUT: 2 so phuc
OUTPUT: thuong
ALGORITHM:
[(a+bi)/(c+di)]
mau = c^2 + d^2
*/
cSoPhuc cSoPhuc::operator / (const cSoPhuc& x) {
    double mau = x.thuc * x.thuc + x.ao * x.ao;

    if (mau == 0)
        return cSoPhuc(0, 0);

    double t = (thuc * x.thuc + ao * x.ao) / mau;
    double a = (ao * x.thuc - thuc * x.ao) / mau;

    return cSoPhuc(t, a);
}

/*
INPUT: 2 so phuc
OUTPUT: true neu bang nhau
*/
bool cSoPhuc::operator == (const cSoPhuc& x) {
    return (thuc == x.thuc && ao == x.ao);
}

/*
INPUT: 2 so phuc
OUTPUT: true neu khac nhau
*/
bool cSoPhuc::operator != (const cSoPhuc& x) {
    return !(*this == x);
}

/*
INPUT: so phuc
OUTPUT: dang a+bi
*/
ostream& operator << (ostream& out, const cSoPhuc& x) {
    out << x.thuc;

    if (x.ao >= 0)
        out << " + " << x.ao << "i";
    else
        out << " - " << -x.ao << "i";

    return out;
}

/*
INPUT: ban phim
OUTPUT: nhap hop le
ALGORITHM:
1. Nhap thuc
2. Nhap ao
3. Sai thi nhap lai
*/
istream& operator >> (istream& in, cSoPhuc& x) {
    string line;
    double t, a;

    while (true) {
        cout << "Nhap phan thuc: ";
        getline(in, line);

        stringstream ss(line);
        char extra;

        if (ss >> t && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap phan ao: ";
        getline(in, line);

        stringstream ss(line);
        char extra;

        if (ss >> a && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    x.thuc = t;
    x.ao = a;

    return in;
}
