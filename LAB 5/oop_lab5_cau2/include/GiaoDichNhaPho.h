#ifndef GDNHAPHO_H
#define GDNHAPHO_H

#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha;
    string diaChi;
    double dienTich;

public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

#endif
