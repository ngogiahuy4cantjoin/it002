#include "KhachHangB.h"

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
KhachHangB::KhachHangB() : KhachHang() {
    soNamThanThiet = 0;
}

/*
INPUT: file
OUTPUT: thong tin khach hang B
*/
void KhachHangB::Nhap(ifstream& fin) {
    KhachHang::Nhap(fin);

    fin >> soNamThanThiet;

    fin.ignore();
}

/*
OUTPUT: phan tram khuyen mai
*/
double KhachHangB::TinhPhanTramKhuyenMai() {
    double km = soNamThanThiet * 0.05;

    if (km > 0.5)
        km = 0.5;

    return km;
}

/*
OUTPUT: so tien phai tra
*/
double KhachHangB::TinhTienPhaiTra() {
    double tienHang = soLuongHang * donGiaHang;

    tienHang = tienHang * (1 - TinhPhanTramKhuyenMai());

    return tienHang + tienHang * 0.1;
}

/*
OUTPUT: thong tin khach hang
*/
void KhachHangB::Xuat(ofstream& fout) {
    KhachHang::Xuat(fout);
}
