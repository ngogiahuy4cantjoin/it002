#include "DanhSach.h"
#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include <sstream>

/*
INPUT: -
OUTPUT: khoi tao danh sach rong
*/
DanhSach::DanhSach() {
    DS = NULL;
    soLuong = 0;
}

/*
INPUT: -
OUTPUT: giai phong bo nho
*/
DanhSach::~DanhSach() {
    for (int i = 0; i < soLuong; i++)
        delete DS[i];
    delete[] DS;
}

/*
INPUT: ban phim
OUTPUT: danh sach nhan vien
*/
void DanhSach::Nhap() {
    string line;
    int n;

    while (true) {
        cout << "Nhap so luong nhan vien: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && !(ss >> extra)) break;
        cout << "Nhap sai. Nhap lai.\n";
    }

    soLuong = n;
    DS = new NhanVien*[soLuong];

    for (int i = 0; i < soLuong; i++) {
        int loai;

        while (true) {
            cout << "\nNhan vien " << i + 1 << " (1: Van phong, 2: San xuat): ";
            getline(cin, line);

            stringstream ss(line);
            char extra;

            if (ss >> loai && !(ss >> extra) && (loai == 1 || loai == 2))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        if (loai == 1)
            DS[i] = new NhanVienVanPhong();
        else
            DS[i] = new NhanVienSanXuat();

        DS[i]->Nhap();
    }
}

/*
INPUT: danh sach
OUTPUT: in ra man hinh
*/
void DanhSach::Xuat() {
    for (int i = 0; i < soLuong; i++) {
        cout << "\n--- Nhan vien " << i + 1 << " ---\n";
        DS[i]->Xuat();
    }
}

/*
INPUT: danh sach
OUTPUT: tong luong
*/
double DanhSach::TongLuong() {
    double sum = 0;
    for (int i = 0; i < soLuong; i++)
        sum += DS[i]->TinhLuong();
    return sum;
}

/*
INPUT: danh sach
OUTPUT: NV san xuat luong thap nhat
*/
NhanVien* DanhSach::NVSanXuatLuongThapNhat() {
    NhanVien* res = NULL;

    for (int i = 0; i < soLuong; i++) {
        NhanVienSanXuat* p = dynamic_cast<NhanVienSanXuat*>(DS[i]);
        if (p != NULL) {
            if (res == NULL || p->TinhLuong() < res->TinhLuong())
                res = p;
        }
    }
    return res;
}

/*
INPUT: danh sach
OUTPUT: NV van phong tuoi cao nhat
*/
NhanVien* DanhSach::NVVanPhongLonTuoiNhat() {
    NhanVien* res = NULL;

    for (int i = 0; i < soLuong; i++) {
        NhanVienVanPhong* p = dynamic_cast<NhanVienVanPhong*>(DS[i]);
        if (p != NULL) {
            if (res == NULL || p->LayTuoi() > res->LayTuoi())
                res = p;
        }
    }
    return res;
}
