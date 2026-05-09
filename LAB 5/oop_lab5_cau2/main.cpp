#include <iostream>
#include "DanhSach.h"
#include <iomanip>

using namespace std;

int main() {
    DanhSach ds;
    cout << fixed << setprecision(0);

    cout << "=== NHAP DANH SACH GIAO DICH ===\n";
    ds.Nhap();

    cout << "\n=== DANH SACH GIAO DICH ===\n";
    ds.Xuat();

    cout << "\n=== SO LUONG TUNG LOAI ===\n";
    ds.DemTungLoai();

    cout << "\n=== TRUNG BINH CAN HO ===\n";
    cout << ds.TBCanHo() << endl;

    cout << "\n=== NHA PHO CO TRI GIA CAO NHAT ===\n";
    GiaoDich* p = ds.NhaPhoMax();
    if (p) p->Xuat();
    else cout << "Khong co\n";

    cout << "\n=== GIAO DICH THANG 12/2024 ===\n";
    ds.XuatThang12_2024();

    return 0;
}
