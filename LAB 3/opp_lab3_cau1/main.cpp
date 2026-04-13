/*
main:

INPUT:
- Nhập 3 điểm A, B, C
- Nhập dx, dy (tịnh tiến)
- Nhập góc quay (độ)
- Nhập hệ số phóng to
- Nhập hệ số thu nhỏ

OUTPUT:
- In tam giác ban đầu
- Loại, chu vi, diện tích
- Kết quả sau từng phép biến đổi (độc lập)

ALGORITHM:
1. Nhập tam giác tg
2. Gán goc = tg (lưu bản gốc)
3. Xuất thông tin ban đầu
4. Tịnh tiến trực tiếp trên tg
5. Reset tg = goc trước mỗi phép:
   - Quay
   - Phóng to
   - Thu nhỏ
*/
#include <iostream>
#include "cTamGiac.h"
using namespace std;

/*
INPUT:
- Nhập tọa độ (double)
- Nhập dx, dy
- Nhập góc (độ)
- Nhập hệ số k

OUTPUT:
- In kết quả đúng, không crash khi nhập sai

ALGORITHM:
- Dùng while + cin.fail() để kiểm tra input
- Nếu sai → clear + ignore → nhập lại
*/
// ===== HÀM NHẬP DOUBLE AN TOÀN =====
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
    cTamGiac goc, tg;

    cout << "Nhap tam giac:\n";

    // ===== NHẬP ĐIỂM A B C =====
    tg.Nhap();
    goc = tg;

    while (!tg.KiemTraHopLe()) {
    cout << "Tam giac khong hop le! Nhap lai:\n";
    tg.Nhap();
}
    cout << "\nTam giac ban dau: ";
    tg.Xuat();

    cout << "Loai: " << tg.KiemTraLoai() << endl;
    cout << "Chu vi: " << tg.TinhChuVi() << endl;
    cout << "Dien tich: " << tg.TinhDienTich() << endl;

    // ===== TỊNH TIẾN =====
    double dx, dy;
    cout << "\nNhap dx, dy: ";
    NhapSo(dx); NhapSo(dy);

    tg.TinhTien(dx, dy);
    cout << "Sau tinh tien: ";
    tg.Xuat();

    // ===== QUAY =====
    tg = goc;
    double gocDo;
    cout << "\nNhap goc quay (do): ";
    NhapSo(gocDo);

    tg.Quay(gocDo * 3.14159 / 180);
    cout << "Sau quay: ";
    tg.Xuat();

    // ===== PHONG TO =====
    tg = goc;
    double k;
    cout << "\nNhap he so phong to: ";
    NhapSo(k);

    tg.PhongTo(k);
    cout << "Sau phong to: ";
    tg.Xuat();

    // ===== THU NHO =====
    tg = goc;
    cout << "\nNhap he so thu nho: ";
    NhapSo(k);

    while (k == 0) {
        cout << "k khong duoc = 0, Nhap lai: ";
        NhapSo(k);
    }

    tg.ThuNho(k);
    cout << "Sau thu nho: ";
    tg.Xuat();

    return 0;
}
