#ifndef DANHSACH_H
#define DANHSACH_H

#include <vector>
#include "KhachHang.h"

class DanhSach {
private:
    vector<KhachHang*> DS;

    int x;
    int y;
    int z;

public:
    DanhSach();
    ~DanhSach();

    void DocFile(string);
    void XuatFile(string);

    double TongSoTienCongTyThuDuoc();
};

#endif
