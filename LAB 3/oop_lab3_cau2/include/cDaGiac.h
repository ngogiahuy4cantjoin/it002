#ifndef CDAGIAC_H
#define CDAGIAC_H

#include "Diem.h"
#include <vector>
using namespace std;

class cDaGiac {
private:
    vector<Diem> ds; // danh sách điểm
    int n;           // số đỉnh

public:
    void Nhap();
    void Xuat();

    bool KiemTraHopLe();
    double TinhChuVi();
    double TinhDienTich();

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);
};

#endif
