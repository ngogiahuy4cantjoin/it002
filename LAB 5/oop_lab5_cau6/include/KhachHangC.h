#ifndef KHACHHANGC_H
#define KHACHHANGC_H

#include "KhachHang.h"

class KhachHangC : public KhachHang {
public:
    KhachHangC();

    double TinhTienPhaiTra();
    void Xuat(ofstream&);
};

#endif
