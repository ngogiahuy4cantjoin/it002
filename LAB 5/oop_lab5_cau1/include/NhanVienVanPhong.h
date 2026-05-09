#ifndef NVVP_H
#define NVVP_H

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLam;

public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};

#endif
