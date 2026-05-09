#ifndef DANHSACH_H
#define DANHSACH_H

#include "NhanVien.h"

class DanhSach {
private:
    NhanVien** DS;
    int soLuong;

public:
    DanhSach();
    ~DanhSach();

    void Nhap();
    void Xuat();

    double TongLuong();

    NhanVien* NVSanXuatLuongThapNhat();
    NhanVien* NVVanPhongLonTuoiNhat();
};

#endif
