#include "KhachHangC.h"

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
KhachHangC::KhachHangC() : KhachHang() {}

/*
OUTPUT: so tien phai tra
*/
double KhachHangC::TinhTienPhaiTra() {
    double tienHang = soLuongHang * donGiaHang * 0.5;

    return tienHang + tienHang * 0.1;
}

/*
OUTPUT: thong tin khach hang
*/
void KhachHangC::Xuat(ofstream& fout) {
    KhachHang::Xuat(fout);
}
