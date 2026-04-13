#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <string>
using namespace std;

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    string ngaySinh;   // dạng dd/mm/yyyy
    int soSanPham;
    double donGia;

public:
    // ===== NHAP XUAT =====
    void Nhap();
    void Xuat();

    // ===== XU LY =====
    double TinhLuong();
    int LayTuoi();

    // ===== GET =====
    string getMaNV();
    string getHoTen();
    string getNgaySinh();
    int getSoSanPham();
    double getDonGia();

    // ===== SET =====
    void setMaNV(string);
    void setHoTen(string);
    void setNgaySinh(string);
    void setSoSanPham(int);
    void setDonGia(double);
};

#endif
