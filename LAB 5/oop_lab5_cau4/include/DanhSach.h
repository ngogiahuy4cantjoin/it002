#ifndef DANHSACH_H
#define DANHSACH_H

#include <vector>
#include "NhanVien.h"

class DanhSach {
private:
    vector<NhanVien*> DS;

public:
    ~DanhSach();

    void Nhap();
    void Xuat();

    double LuongTrungBinh();

    void XuatLuongThapHonTB();

    NhanVien* NhanVienLuongMax();
    NhanVien* NhanVienLuongMin();

    NhanVien* LapTrinhVienLuongMax();
    NhanVien* KiemChungVienLuongMin();
};

#endif
