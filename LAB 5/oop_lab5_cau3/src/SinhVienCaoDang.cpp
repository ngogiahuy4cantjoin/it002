#include "SinhVienCaoDang.h"
#include <sstream>

using namespace std;

/*
INPUT: ban phim
OUTPUT: sinh vien cao dang hop le
*/
void SinhVienCaoDang::Nhap() {
    SinhVien::Nhap();

    string line;
    char extra;

    while (true) {
        cout << "Nhap diem thi tot nghiep: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> diemThiTotNghiep && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void SinhVienCaoDang::Xuat() {
    SinhVien::Xuat();
    cout << "Diem thi tot nghiep: " << diemThiTotNghiep << endl;

    if (DuDieuKienTotNghiep())
        cout << "Ket qua: Du dieu kien tot nghiep\n";
    else
        cout << "Ket qua: Khong du dieu kien tot nghiep\n";
}

/*
OUTPUT: true neu du dieu kien tot nghiep
*/
bool SinhVienCaoDang::DuDieuKienTotNghiep() {
    return tongTinChi >= 120 &&
           diemTB >= 5 &&
           diemThiTotNghiep >= 5;
}
