#include <iostream>
#include <sstream>
#include "cDaThuc.h"
using namespace std;

/*
INPUT:
- 2 đa thức
- x

OUTPUT:
- giá trị đa thức
- tổng và hiệu

ALGORITHM:
1. Nhập
2. Xuất
3. Tính giá trị
4. Cộng & trừ
*/

void NhapSo(double &x) {
    string line;

    while (true) {
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> x && !(ss >> extra)) break;

        cout << "Nhap sai. Nhap lai: ";
    }
}

int main() {
    cDaThuc p1, p2;

    cout << "=== NHAP DA THUC 1 ===\n";
    p1.Nhap();

    cout << "\n=== NHAP DA THUC 2 ===\n";
    p2.Nhap();

    cout << "\n=== XUAT ===\n";
    p1.Xuat();
    p2.Xuat();

    // ===== TINH GIA TRI =====
    double x;
    cout << "\nNhap x: ";
    NhapSo(x);

    cout << "P1(x) = " << p1.TinhGiaTri(x) << endl;
    cout << "P2(x) = " << p2.TinhGiaTri(x) << endl;

    // ===== CONG =====
    cDaThuc tong = p1.CongDaThuc(p2);
    cout << "\nP1 + P2 = ";
    tong.Xuat();

    // ===== TRU =====
    cDaThuc hieu = p1.TruDaThuc(p2);
    cout << "P1 - P2 = ";
    hieu.Xuat();

    // ===== GIẢI PHÓNG =====
    p1.GiaiPhong();
    p2.GiaiPhong();
    tong.GiaiPhong();
    hieu.GiaiPhong();

    return 0;
}
