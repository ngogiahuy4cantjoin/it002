#ifndef CPHANSO_H
#define CPHANSO_H

#include <iostream>
using namespace std;

class cPhanSo {
private:
    int tu;
    int mau;

public:
    // Constructor
    cPhanSo(int = 0, int = 1);

    // Phuong thuc thiet lap duy nhat
    void ThietLap(int, int = 1);

    // Xu ly phan so
    void RutGon();
    int UCLN(int, int);

    // Nhap xuat thuong
    void Nhap();
    void Xuat();

    // Toan tu phan so
    cPhanSo operator + (const cPhanSo&);
    cPhanSo operator - (const cPhanSo&);
    cPhanSo operator * (const cPhanSo&);
    cPhanSo operator / (const cPhanSo&);

    // So sanh
    bool operator == (const cPhanSo&);
    bool operator > (const cPhanSo&);
    bool operator < (const cPhanSo&);

    // Nhap xuat bang stream
    friend ostream& operator << (ostream&, const cPhanSo&);
    friend istream& operator >> (istream&, cPhanSo&);
};

#endif
