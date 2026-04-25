#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class CMatrix {
private:
    int dong;
    int cot;
    double** a;

public:
    CMatrix(int = 0, int = 0);
    ~CMatrix();

    void TaoMang();
    void GiaiPhong();

    void Nhap();
    void Xuat();

    CMatrix operator * (const CMatrix&);
    vector<double> operator * (const vector<double>&);

    friend ostream& operator << (ostream&, const CMatrix&);
    friend istream& operator >> (istream&, CMatrix&);
};

#endif
