#ifndef NVSX_H
#define NVSX_H

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;
    double luongCanBan;

public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};

#endif
