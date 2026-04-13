#ifndef CARRAY_H
#define CARRAY_H

class cArray {
private:
    int* a;
    int n;

public:
    void Nhap();
    void Xuat();
    void TaoNgauNhien(int);

    int DemSoLanXuatHien(int);
    bool KiemTraTangDan();

    int TimSoLeNhoNhat();
    int TimSoNguyenToLonNhat();

    void SapXepTangDan();
    void SapXepGiamDan();

    bool KiemTraSoNguyenTo(int);

    void GiaiPhong();
};

#endif
