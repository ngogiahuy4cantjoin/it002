#ifndef GDCANHO_H
#define GDCANHO_H

#include "GiaoDich.h"

class GiaoDichCanHo : public GiaoDich {
private:
    string maCan;
    int tang;
    double dienTich;

public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

#endif
