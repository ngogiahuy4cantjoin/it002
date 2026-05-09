#ifndef SINHVIENDAIHOC_H
#define SINHVIENDAIHOC_H

#include "SinhVien.h"

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void Nhap();
    void Xuat();

    bool DuDieuKienTotNghiep();
};

#endif
