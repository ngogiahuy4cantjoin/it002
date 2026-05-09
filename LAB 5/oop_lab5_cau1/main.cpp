#include <iostream>
#include "DanhSach.h"
#include <iomanip>
using namespace std;

/*
INPUT:
- Danh sach nhan vien (van phong + san xuat)

OUTPUT:
- Danh sach nhan vien
- Tong luong cong ty
- Nhan vien san xuat co luong thap nhat
- Nhan vien van phong co tuoi cao nhat

ALGORITHM:
1. Nhap danh sach
2. Xuat danh sach
3. Tinh tong luong
4. Tim NV san xuat luong thap nhat
5. Tim NV van phong tuoi cao nhat
*/

int main() {
    DanhSach ds;
    cout << fixed << setprecision(0);

    cout << "=== NHAP DANH SACH NHAN VIEN ===\n";
    ds.Nhap();

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    ds.Xuat();

    cout << "\n=== TONG LUONG CONG TY ===\n";
    cout << "Tong luong: " << ds.TongLuong() << endl;

    cout << "\n=== NV SAN XUAT LUONG THAP NHAT ===\n";
    NhanVien* nvsx = ds.NVSanXuatLuongThapNhat();
    if (nvsx != NULL)
        nvsx->Xuat();
    else
        cout << "Khong co nhan vien san xuat\n";

    cout << "\n=== NV VAN PHONG TUOI CAO NHAT ===\n";
    NhanVien* nvvp = ds.NVVanPhongLonTuoiNhat();
    if (nvvp != NULL)
        nvvp->Xuat();
    else
        cout << "Khong co nhan vien van phong\n";

    return 0;
}
