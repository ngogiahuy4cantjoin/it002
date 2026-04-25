#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>
using namespace std;

class cDaThuc {
private:
    int bac;
    double* heSo;

public:
    cDaThuc(int = 0);
    cDaThuc(const cDaThuc&);
    ~cDaThuc();

    void Nhap();
    void Xuat();

    double GiaTriTai(double);

    cDaThuc& operator = (const cDaThuc&);
    cDaThuc operator + (const cDaThuc&);
    cDaThuc operator - (const cDaThuc&);

    friend ostream& operator << (ostream&, const cDaThuc&);
    friend istream& operator >> (istream&, cDaThuc&);
};

#endif
