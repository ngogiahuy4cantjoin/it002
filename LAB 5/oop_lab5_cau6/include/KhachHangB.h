#ifndef KHACHHANGB_H
#define KHACHHANGB_H

#include "KhachHang.h"

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;

public:
    KhachHangB();

    void Nhap(ifstream&);

    double TinhPhanTramKhuyenMai();
    double TinhTienPhaiTra();

    void Xuat(ofstream&);
};

#endif
