#include "DanhSach.h"
#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"
#include <sstream>

using namespace std;

/*
OUTPUT: giai phong bo nho
*/
DanhSach::~DanhSach() {
    for (int i = 0; i < DS.size(); i++)
        delete DS[i];
}

/*
INPUT: ban phim
OUTPUT: danh sach sinh vien
*/
void DanhSach::Nhap() {
    string line;
    int n;

    while (true) {
        cout << "Nhap so luong sinh vien: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    for (int i = 0; i < n; i++) {
        int loai;

        while (true) {
            cout << "\nSinh vien " << i + 1;
            cout << " (1: Cao dang, 2: Dai hoc): ";

            getline(cin, line);

            stringstream ss(line);
            char extra;

            if (ss >> loai && !(ss >> extra) &&
                (loai == 1 || loai == 2))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        SinhVien* p;

        if (loai == 1)
            p = new SinhVienCaoDang();
        else
            p = new SinhVienDaiHoc();

        p->Nhap();

        DS.push_back(p);
    }
}

/*
OUTPUT: in danh sach
*/
void DanhSach::Xuat() {
    for (int i = 0; i < DS.size(); i++) {
        cout << "\n--- Sinh vien " << i + 1 << " ---\n";
        DS[i]->Xuat();
    }
}

/*
OUTPUT: danh sach du dieu kien tot nghiep
*/
void DanhSach::XuatDuDieuKienTotNghiep() {
    for (int i = 0; i < DS.size(); i++) {
        if (DS[i]->DuDieuKienTotNghiep()) {
            cout << "\n--- Sinh vien ---\n";
            DS[i]->Xuat();
        }
    }
}

/*
OUTPUT: danh sach khong du dieu kien tot nghiep
*/
void DanhSach::XuatKhongDuDieuKienTotNghiep() {
    for (int i = 0; i < DS.size(); i++) {
        if (!DS[i]->DuDieuKienTotNghiep()) {
            cout << "\n--- Sinh vien ---\n";
            DS[i]->Xuat();
        }
    }
}

/*
OUTPUT: sinh vien dai hoc diem TB cao nhat
*/
SinhVien* DanhSach::SVDaiHocDTBMax() {
    SinhVien* res = NULL;

    for (int i = 0; i < DS.size(); i++) {
        SinhVienDaiHoc* p = dynamic_cast<SinhVienDaiHoc*>(DS[i]);

        if (p) {
            if (res == NULL ||
                p->LayDiemTB() > res->LayDiemTB())
                res = p;
        }
    }

    return res;
}

/*
OUTPUT: sinh vien cao dang diem TB cao nhat
*/
SinhVien* DanhSach::SVCaoDangDTBMax() {
    SinhVien* res = NULL;

    for (int i = 0; i < DS.size(); i++) {
        SinhVienCaoDang* p = dynamic_cast<SinhVienCaoDang*>(DS[i]);

        if (p) {
            if (res == NULL ||
                p->LayDiemTB() > res->LayDiemTB())
                res = p;
        }
    }

    return res;
}
