#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CMatrix.h"
using namespace std;

/*
INPUT: so dong, so cot
OUTPUT: tao ma tran rong
*/
CMatrix::CMatrix(int d, int c) {
    dong = d;
    cot = c;
    a = NULL;

    if (dong > 0 && cot > 0)
        TaoMang();
}

/*
INPUT: none
OUTPUT: huy ma tran
*/
CMatrix::~CMatrix() {
    GiaiPhong();
}

/*
INPUT: kich thuoc
OUTPUT: cap phat bo nho
*/
void CMatrix::TaoMang() {
    a = new double*[dong];

    for (int i = 0; i < dong; i++)
        a[i] = new double[cot];
}

/*
INPUT: none
OUTPUT: thu hoi bo nho
*/
void CMatrix::GiaiPhong() {
    if (a != NULL) {
        for (int i = 0; i < dong; i++)
            delete[] a[i];

        delete[] a;
        a = NULL;
    }
}

/*
INPUT: ban phim
OUTPUT: ma tran hop le
*/
void CMatrix::Nhap() {
    cin >> *this;
}

/*
INPUT: ma tran
OUTPUT: in ra man hinh
*/
void CMatrix::Xuat() {
    cout << *this;
}

/*
INPUT: 2 ma tran
OUTPUT: tich 2 ma tran
*/
CMatrix CMatrix::operator * (const CMatrix& x) {
    CMatrix kq(dong, x.cot);

    for (int i = 0; i < dong; i++)
        for (int j = 0; j < x.cot; j++) {
            kq.a[i][j] = 0;

            for (int k = 0; k < cot; k++)
                kq.a[i][j] += a[i][k] * x.a[k][j];
        }

    return kq;
}

/*
INPUT: ma tran va vector
OUTPUT: tich ma tran vector
*/
vector<double> CMatrix::operator * (const vector<double>& v) {
    vector<double> kq(dong, 0);

    for (int i = 0; i < dong; i++)
        for (int j = 0; j < cot; j++)
            kq[i] += a[i][j] * v[j];

    return kq;
}

/*
INPUT: ma tran
OUTPUT: xuat ma tran
*/
ostream& operator << (ostream& out, const CMatrix& x) {
    for (int i = 0; i < x.dong; i++) {
        for (int j = 0; j < x.cot; j++)
            out << x.a[i][j] << "\t";

        out << endl;
    }

    return out;
}

/*
INPUT: ban phim
OUTPUT: nhap ma tran hop le
*/
istream& operator >> (istream& in, CMatrix& x) {
    string line;
    int d, c;
    char extra;

    while (true) {
        cout << "Nhap so dong: ";
        getline(in, line);
        stringstream ss(line);

        if (ss >> d && !(ss >> extra) && d > 0)
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap so cot: ";
        getline(in, line);
        stringstream ss(line);

        if (ss >> c && !(ss >> extra) && c > 0)
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    x.GiaiPhong();

    x.dong = d;
    x.cot = c;
    x.TaoMang();

    for (int i = 0; i < x.dong; i++)
        for (int j = 0; j < x.cot; j++) {
            double temp;

            while (true) {
                cout << "a[" << i << "][" << j << "] = ";
                getline(in, line);
                stringstream ss(line);

                if (ss >> temp && !(ss >> extra))
                    break;

                cout << "Nhap sai. Nhap lai.\n";
            }

            x.a[i][j] = temp;
        }

    return in;
}
