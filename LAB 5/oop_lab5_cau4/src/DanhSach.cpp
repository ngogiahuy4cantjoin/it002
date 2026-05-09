#include "DanhSach.h"
#include "LapTrinhVien.h"
#include "KiemChungVien.h"
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

        if (ss >> n && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    for (int i = 0; i < n; i++) {
        int loai;

        while (true) {
            cout << "\nNhan vien " << i + 1;
            cout << " (1: Lap trinh vien, 2: Kiem chung vien): ";

            getline(cin, line);

            stringstream ss(line);
            char extra;

            if (ss >> loai && !(ss >> extra) &&
                (loai == 1 || loai == 2))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        NhanVien* p;

        if (loai == 1)
            p = new LapTrinhVien();
        else
            p = new KiemChungVien();

        p->Nhap();

        DS.push_back(p);
    }
}

/*
OUTPUT: in danh sach
*/
void DanhSach::Xuat() {
    for (int i = 0; i < DS.size(); i++) {
        cout << "\n--- Nhan vien " << i + 1 << " ---\n";
        DS[i]->Xuat();
    }
}

/*
OUTPUT: luong trung binh
*/
double DanhSach::LuongTrungBinh() {
    double tong = 0;

    for (int i = 0; i < DS.size(); i++)
        tong += DS[i]->LayLuong();

    if (DS.size() == 0)
        return 0;

    return tong / DS.size();
}

/*
OUTPUT: nhan vien luong thap hon trung binh
*/
void DanhSach::XuatLuongThapHonTB() {
    double tb = LuongTrungBinh();

    for (int i = 0; i < DS.size(); i++) {
        if (DS[i]->LayLuong() < tb) {
            cout << "\n--- Nhan vien ---\n";
            DS[i]->Xuat();
        }
    }
}

/*
OUTPUT: nhan vien luong cao nhat
*/
NhanVien* DanhSach::NhanVienLuongMax() {
    if (DS.size() == 0)
        return NULL;

    NhanVien* res = DS[0];

    for (int i = 1; i < DS.size(); i++) {
        if (DS[i]->LayLuong() > res->LayLuong())
            res = DS[i];
    }

    return res;
}

/*
OUTPUT: nhan vien luong thap nhat
*/
NhanVien* DanhSach::NhanVienLuongMin() {
    if (DS.size() == 0)
        return NULL;

    NhanVien* res = DS[0];

    for (int i = 1; i < DS.size(); i++) {
        if (DS[i]->LayLuong() < res->LayLuong())
            res = DS[i];
    }

    return res;
}

/*
OUTPUT: lap trinh vien luong cao nhat
*/
NhanVien* DanhSach::LapTrinhVienLuongMax() {
    NhanVien* res = NULL;

    for (int i = 0; i < DS.size(); i++) {
        LapTrinhVien* p =
            dynamic_cast<LapTrinhVien*>(DS[i]);

        if (p) {
            if (res == NULL ||
                p->LayLuong() > res->LayLuong())
                res = p;
        }
    }

    return res;
}

/*
OUTPUT: kiem chung vien luong thap nhat
*/
NhanVien* DanhSach::KiemChungVienLuongMin() {
    NhanVien* res = NULL;

    for (int i = 0; i < DS.size(); i++) {
        KiemChungVien* p =
            dynamic_cast<KiemChungVien*>(DS[i]);

        if (p) {
            if (res == NULL ||
                p->LayLuong() < res->LayLuong())
                res = p;
        }
    }

    return res;
}
