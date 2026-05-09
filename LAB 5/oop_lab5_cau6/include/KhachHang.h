#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class KhachHang {
protected:
    string tenKhachHang;
    int soLuongHang;
    double donGiaHang;

public:
    KhachHang();
    virtual ~KhachHang();

    virtual void Nhap(ifstream&);
    virtual void Xuat(ofstream&);

    virtual double TinhTienPhaiTra() = 0;
};

#endif
