#include <iostream>
#include <iomanip>
#include "DanhSach.h"

using namespace std;

int main() {
    DanhSach ds;

    cout << fixed << setprecision(2);

    cout << "=== NHAP DANH SACH SINH VIEN ===\n";
    ds.Nhap();

    cout << "\n=== DANH SACH SINH VIEN ===\n";
    ds.Xuat();

    cout << "\n=== SINH VIEN DU DIEU KIEN TOT NGHIEP ===\n";
    ds.XuatDuDieuKienTotNghiep();

    cout << "\n=== SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    ds.XuatKhongDuDieuKienTotNghiep();

    cout << "\n=== SINH VIEN DAI HOC DTB CAO NHAT ===\n";

    SinhVien* dh = ds.SVDaiHocDTBMax();

    if (dh)
        dh->Xuat();
    else
        cout << "Khong co\n";

    cout << "\n=== SINH VIEN CAO DANG DTB CAO NHAT ===\n";

    SinhVien* cd = ds.SVCaoDangDTBMax();

    if (cd)
        cd->Xuat();
    else
        cout << "Khong co\n";

    return 0;
}
