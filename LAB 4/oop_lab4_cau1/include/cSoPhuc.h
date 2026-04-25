#ifndef CSOPHUC_H
#define CSOPHUC_H

#include <iostream>
using namespace std;

class cSoPhuc {
private:
    double thuc;
    double ao;

public:
    // Constructor
    cSoPhuc(double = 0, double = 0);

    // Phuong thuc thiet lap duy nhat
    void ThietLap(double, double = 0);

    // Nhap xuat thuong
    void Nhap();
    void Xuat();

    // Toan tu so phuc
    cSoPhuc operator + (const cSoPhuc&);
    cSoPhuc operator - (const cSoPhuc&);
    cSoPhuc operator * (const cSoPhuc&);
    cSoPhuc operator / (const cSoPhuc&);

    // So sanh
    bool operator == (const cSoPhuc&);
    bool operator != (const cSoPhuc&);

    // Nhap xuat bang stream
    friend ostream& operator << (ostream&, const cSoPhuc&);
    friend istream& operator >> (istream&, cSoPhuc&);
};

#endif
