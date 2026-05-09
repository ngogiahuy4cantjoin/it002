#ifndef DANHSACH_H
#define DANHSACH_H

#include <vector>
#include "SinhVien.h"

class DanhSach {
private:
    vector<SinhVien*> DS;

public:
    ~DanhSach();

    void Nhap();
    void Xuat();

    void XuatDuDieuKienTotNghiep();
    void XuatKhongDuDieuKienTotNghiep();

    SinhVien* SVDaiHocDTBMax();
    SinhVien* SVCaoDangDTBMax();
};

#endif
