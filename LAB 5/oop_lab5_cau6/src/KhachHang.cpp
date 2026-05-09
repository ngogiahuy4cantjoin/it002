#include "KhachHang.h"

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
KhachHang::KhachHang() {
    tenKhachHang = "";
    soLuongHang = 0;
    donGiaHang = 0;
}

KhachHang::~KhachHang() {}

/*
INPUT: file
OUTPUT: thong tin khach hang
*/
void KhachHang::Nhap(ifstream& fin) {
    getline(fin, tenKhachHang);

    fin >> soLuongHang;
    fin >> donGiaHang;

    fin.ignore();
}

/*
OUTPUT: thong tin va so tien phai tra
*/
void KhachHang::Xuat(ofstream& fout) {
    fout << tenKhachHang << endl;
    fout << TinhTienPhaiTra() << endl;
}
