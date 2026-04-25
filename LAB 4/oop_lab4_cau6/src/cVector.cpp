#include <iostream>
#include <sstream>
#include <string>
#include "CVector.h"
using namespace std;

/*
INPUT: so chieu
OUTPUT: tao vector
*/
CVector::CVector(int size) {
    n = size;

    if (n > 0)
        data = new double[n];
    else
        data = NULL;

    for (int i = 0; i < n; i++)
        data[i] = 0;
}

/*
INPUT: vector khac
OUTPUT: sao chep
*/
CVector::CVector(const CVector& x) {
    n = x.n;

    if (n > 0)
        data = new double[n];
    else
        data = NULL;

    for (int i = 0; i < n; i++)
        data[i] = x.data[i];
}

/*
OUTPUT: huy bo nho
*/
CVector::~CVector() {
    delete[] data;
}

/*
INPUT: kich thuoc moi
OUTPUT: cap nhat vector
*/
void CVector::ThietLap(int size) {
    delete[] data;

    n = size;

    if (n > 0)
        data = new double[n];
    else
        data = NULL;

    for (int i = 0; i < n; i++)
        data[i] = 0;
}

/*
INPUT: ban phim
OUTPUT: vector hop le
*/
void CVector::Nhap() {
    cin >> *this;
}

/*
INPUT: vector
OUTPUT: xuat vector
*/
void CVector::Xuat() {
    cout << *this;
}

/*
INPUT: vector khac
OUTPUT: gan
*/
CVector& CVector::operator = (const CVector& x) {
    if (this == &x)
        return *this;

    delete[] data;

    n = x.n;

    if (n > 0)
        data = new double[n];
    else
        data = NULL;

    for (int i = 0; i < n; i++)
        data[i] = x.data[i];

    return *this;
}

/*
INPUT: 2 vector
OUTPUT: tong
*/
CVector CVector::operator + (const CVector& x) {
    if (n != x.n)
        return CVector();

    CVector temp(n);

    for (int i = 0; i < n; i++)
        temp.data[i] = data[i] + x.data[i];

    return temp;
}

/*
INPUT: 2 vector
OUTPUT: hieu
*/
CVector CVector::operator - (const CVector& x) {
    if (n != x.n)
        return CVector();

    CVector temp(n);

    for (int i = 0; i < n; i++)
        temp.data[i] = data[i] - x.data[i];

    return temp;
}

/*
INPUT: vector va so thuc
OUTPUT: nhan scalar
*/
CVector CVector::operator * (double k) {
    CVector temp(n);

    for (int i = 0; i < n; i++)
        temp.data[i] = data[i] * k;

    return temp;
}

/*
INPUT: 2 vector
OUTPUT: true neu bang nhau
*/
bool CVector::operator == (const CVector& x) {
    if (n != x.n)
        return false;

    for (int i = 0; i < n; i++)
        if (data[i] != x.data[i])
            return false;

    return true;
}

/*
INPUT: 2 vector
OUTPUT: true neu khac nhau
*/
bool CVector::operator != (const CVector& x) {
    return !(*this == x);
}

/*
INPUT: vector
OUTPUT: dang (a1, a2, ...)
*/
ostream& operator << (ostream& out, const CVector& x) {
    out << "(";

    for (int i = 0; i < x.n; i++) {
        out << x.data[i];

        if (i != x.n - 1)
            out << ", ";
    }

    out << ")";

    return out;
}

/*
INPUT: ban phim
OUTPUT: nhap hop le
*/
istream& operator >> (istream& in, CVector& x) {
    string line;
    int size;
    char extra;

    while (true) {
        cout << "Nhap so chieu: ";
        getline(in, line);

        stringstream ss(line);

        if (ss >> size && !(ss >> extra) && size > 0)
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    x.ThietLap(size);

    for (int i = 0; i < x.n; i++) {
        double value;

        while (true) {
            cout << "Nhap thanh phan thu " << i + 1 << ": ";
            getline(in, line);

            stringstream ss(line);

            if (ss >> value && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        x.data[i] = value;
    }

    return in;
}
