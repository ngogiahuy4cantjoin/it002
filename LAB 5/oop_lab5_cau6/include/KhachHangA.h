#ifndef KHACHHANGA_H
#define KHACHHANGA_H

#include "KhachHang.h"

class KhachHangA : public KhachHang {
public:
    KhachHangA();

    double TinhTienPhaiTra();
    void Xuat(ofstream&);
};

#endif
