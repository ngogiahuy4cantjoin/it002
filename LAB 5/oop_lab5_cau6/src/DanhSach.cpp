#include "DanhSach.h"
#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"

#include <fstream>
#include <iomanip>

using namespace std;

/*
OUTPUT: khoi tao
*/
DanhSach::DanhSach() {
    x = y = z = 0;
}

/*
OUTPUT: giai phong bo nho
*/
DanhSach::~DanhSach() {
    for (int i = 0; i < DS.size(); i++)
        delete DS[i];
}

/*
INPUT: ten file
OUTPUT: doc danh sach khach hang
*/
void DanhSach::DocFile(string tenFile) {
    ifstream fin(tenFile);

    fin >> x >> y >> z;
    fin.ignore();

    for (int i = 0; i < x; i++) {
        KhachHang* p = new KhachHangA();

        p->Nhap(fin);

        DS.push_back(p);
    }

    for (int i = 0; i < y; i++) {
        KhachHang* p = new KhachHangB();

        p->Nhap(fin);

        DS.push_back(p);
    }

    for (int i = 0; i < z; i++) {
        KhachHang* p = new KhachHangC();

        p->Nhap(fin);

        DS.push_back(p);
    }

    fin.close();
}

/*
OUTPUT: tong so tien cong ty thu duoc
*/
double DanhSach::TongSoTienCongTyThuDuoc() {
    double tong = 0;

    for (int i = 0; i < DS.size(); i++)
        tong += DS[i]->TinhTienPhaiTra();

    return tong;
}

/*
INPUT: ten file
OUTPUT: xuat ket qua
*/
void DanhSach::XuatFile(string tenFile) {
    ofstream fout(tenFile);

    fout << fixed << setprecision(2);

    fout << x << " " << y << " " << z << endl;

    for (int i = 0; i < DS.size(); i++)
        DS[i]->Xuat(fout);

    fout << TongSoTienCongTyThuDuoc();

    fout.close();
}
