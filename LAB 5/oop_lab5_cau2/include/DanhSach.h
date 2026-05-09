#ifndef DANHSACH_H
#define DANHSACH_H

#include <vector>
#include "GiaoDich.h"

class DanhSach {
private:
    vector<GiaoDich*> DS;

public:
    ~DanhSach();

    void Nhap();
    void Xuat();

    void DemTungLoai();
    double TBCanHo();
    GiaoDich* NhaPhoMax();
    void XuatThang12_2024();
};

#endif
