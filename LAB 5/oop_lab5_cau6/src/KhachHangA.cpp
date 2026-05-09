#include "KhachHangA.h"

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
KhachHangA::KhachHangA() : KhachHang() {}

/*
OUTPUT: so tien phai tra
*/
double KhachHangA::TinhTienPhaiTra() {
    double tienHang = soLuongHang * donGiaHang;

    return tienHang + tienHang * 0.1;
}

/*
OUTPUT: thong tin khach hang
*/
void KhachHangA::Xuat(ofstream& fout) {
    KhachHang::Xuat(fout);
}
