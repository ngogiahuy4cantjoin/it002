#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include "Diem.h"
#include <string>
using namespace std;

class cTamGiac {
private:
    Diem A, B, C;

public:
    void Nhap();
    void Xuat();

    void TinhCanh(double&, double&, double&);
    string KiemTraLoai();
    double TinhChuVi();
    double TinhDienTich();

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);

    bool KiemTraHopLe();
};

#endif
