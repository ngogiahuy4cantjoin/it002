#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
using namespace std;

class CVector {
private:
    int n;
    double* data;

public:
    // Constructor
    CVector(int = 0);

    // Copy constructor
    CVector(const CVector&);

    // Destructor
    ~CVector();

    // Thiet lap lai kich thuoc
    void ThietLap(int);

    // Nhap xuat thuong
    void Nhap();
    void Xuat();

    // Gan
    CVector& operator = (const CVector&);

    // Toan tu
    CVector operator + (const CVector&);
    CVector operator - (const CVector&);
    CVector operator * (double);

    // So sanh
    bool operator == (const CVector&);
    bool operator != (const CVector&);

    // Stream
    friend ostream& operator << (ostream&, const CVector&);
    friend istream& operator >> (istream&, CVector&);
};

#endif
