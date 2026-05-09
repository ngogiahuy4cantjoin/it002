#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    SinhVien();
    virtual ~SinhVien();

    virtual void Nhap();
    virtual void Xuat();

    virtual bool DuDieuKienTotNghiep() = 0;

    double LayDiemTB();
};

#endif
