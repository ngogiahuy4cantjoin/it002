#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void Nhap();
    virtual void Xuat();

    virtual double TinhLuong() = 0;

    int LayTuoi();
};

#endif
