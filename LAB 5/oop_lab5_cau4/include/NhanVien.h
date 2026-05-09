#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    double luongCoBan;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void Nhap();
    virtual void Xuat();

    virtual double TinhLuong() = 0;

    double LayLuong();
};

#endif
