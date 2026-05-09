#include "SinhVienDaiHoc.h"
#include <sstream>

using namespace std;

/*
INPUT: ban phim
OUTPUT: sinh vien dai hoc hop le
*/
void SinhVienDaiHoc::Nhap() {
    SinhVien::Nhap();

    string line;
    char extra;

    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);

    while (true) {
        cout << "Nhap diem luan van: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> diemLuanVan && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void SinhVienDaiHoc::Xuat() {
    SinhVien::Xuat();
    cout << "Ten luan van: " << tenLuanVan << endl;
    cout << "Diem luan van: " << diemLuanVan << endl;

    if (DuDieuKienTotNghiep())
        cout << "Ket qua: Du dieu kien tot nghiep\n";
    else
        cout << "Ket qua: Khong du dieu kien tot nghiep\n";
}

/*
OUTPUT: true neu du dieu kien tot nghiep
*/
bool SinhVienDaiHoc::DuDieuKienTotNghiep() {
    return tongTinChi >= 170 &&
           diemTB >= 5 &&
           diemLuanVan >= 5;
}
