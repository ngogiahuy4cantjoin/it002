#ifndef SINHVIENCAODANG_H
#define SINHVIENCAODANG_H

#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTotNghiep;

public:
    void Nhap();
    void Xuat();

    bool DuDieuKienTotNghiep();
};

#endif
