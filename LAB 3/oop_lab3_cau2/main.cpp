#include <iostream>
#include "cDaGiac.h"
using namespace std;

/*
Hàm nhập số double an toàn
*/
void NhapSo(double &x) {
    while (true) {
        cin >> x;

        if (cin.fail()) {
            cout << "Nhap sai. Vui long nhap lai: ";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    }
}

int main() {
    cDaGiac goc, dg;

    cout << "Nhap da giac:\n";
    dg.Nhap();
    goc = dg;

    while (!dg.KiemTraHopLe()) {
        cout << "Da giac khong hop le! Nhap lai:\n";
        dg.Nhap();
    }

    cout << "\nDa giac ban dau:\n";
    dg.Xuat();

    cout << "Chu vi: " << dg.TinhChuVi() << endl;
    cout << "Dien tich: " << dg.TinhDienTich() << endl;

    // ===== TỊNH TIẾN =====
    double dx, dy;
    cout << "\nNhap dx, dy: ";
    NhapSo(dx); NhapSo(dy);

    dg.TinhTien(dx, dy);
    cout << "Sau tinh tien:\n";
    dg.Xuat();

    // ===== QUAY =====
    dg = goc;
    double gocDo;
    cout << "\nNhap goc quay (do): ";
    NhapSo(gocDo);

    dg.Quay(gocDo * 3.14159 / 180);
    cout << "Sau quay:\n";
    dg.Xuat();

    // ===== PHONG TO =====
    dg = goc;
    double k;
    cout << "\nNhap he so phong to: ";
    NhapSo(k);

    dg.PhongTo(k);
    cout << "Sau phong to:\n";
    dg.Xuat();

    // ===== THU NHO =====
    dg = goc;
    cout << "\nNhap he so thu nho: ";
    NhapSo(k);

    while (k == 0) { // FIX lỗi chia 0
        cout << "k khong duoc = 0, nhap lai: ";
        NhapSo(k);
    }

    dg.ThuNho(k);
    cout << "Sau thu nho:\n";
    dg.Xuat();

    return 0;
}
