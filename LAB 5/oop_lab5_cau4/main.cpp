#include <iostream>
#include <iomanip>
#include "DanhSach.h"

using namespace std;

int main() {
    DanhSach ds;

    cout << fixed << setprecision(2);

    cout << "=== NHAP DANH SACH NHAN VIEN ===\n";
    ds.Nhap();

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    ds.Xuat();

    cout << "\n=== NHAN VIEN LUONG THAP HON TB ===\n";
    ds.XuatLuongThapHonTB();

    cout << "\n=== NHAN VIEN LUONG CAO NHAT ===\n";

    NhanVien* max = ds.NhanVienLuongMax();

    if (max)
        max->Xuat();
    else
        cout << "Khong co\n";

    cout << "\n=== NHAN VIEN LUONG THAP NHAT ===\n";

    NhanVien* min = ds.NhanVienLuongMin();

    if (min)
        min->Xuat();
    else
        cout << "Khong co\n";

    cout << "\n=== LAP TRINH VIEN LUONG CAO NHAT ===\n";

    NhanVien* ltv = ds.LapTrinhVienLuongMax();

    if (ltv)
        ltv->Xuat();
    else
        cout << "Khong co\n";

    cout << "\n=== KIEM CHUNG VIEN LUONG THAP NHAT ===\n";

    NhanVien* kcv = ds.KiemChungVienLuongMin();

    if (kcv)
        kcv->Xuat();
    else
        cout << "Khong co\n";

    return 0;
}
