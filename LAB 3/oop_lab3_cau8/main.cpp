#include <iostream>
#include <sstream>
#include "cNhanVienSX.h"
using namespace std;

/*
INPUT: n
OUTPUT: n hợp lệ
*/
void NhapSoNguyen(int &n) {
    string line;

    while (true) {
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && n > 0 && !(ss >> extra)) break;

        cout << "Nhap sai. Nhap lai: ";
    }
}

/*
INPUT: danh sách NV
OUTPUT: NV lương thấp nhất
*/
cNhanVienSX TimLuongThapNhat(cNhanVienSX ds[], int n) {
    cNhanVienSX min = ds[0];

    for (int i = 1; i < n; i++) {
        if (ds[i].TinhLuong() < min.TinhLuong())
            min = ds[i];
    }

    return min;
}

/*
INPUT: danh sách NV
OUTPUT: tổng lương
*/
double TinhTongLuong(cNhanVienSX ds[], int n) {
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += ds[i].TinhLuong();

    return sum;
}

/*
INPUT: danh sách NV
OUTPUT: NV lớn tuổi nhất
*/
cNhanVienSX TimTuoiLonNhat(cNhanVienSX ds[], int n) {
    cNhanVienSX max = ds[0];

    for (int i = 1; i < n; i++) {
        if (ds[i].LayTuoi() > max.LayTuoi())
            max = ds[i];
    }

    return max;
}

/*
INPUT: danh sách NV
OUTPUT: sắp xếp tăng theo lương
*/
void SapXepTangTheoLuong(cNhanVienSX ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

int main() {
    int n;

    cout << "Nhap so nhan vien: ";
    NhapSoNguyen(n);

    cNhanVienSX* ds = new cNhanVienSX[n];

    cout << "\n=== NHAP DANH SACH ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\n=== DANH SACH ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    // ===== LUONG THAP NHAT =====
    cout << "\nNhan vien luong thap nhat:\n";
    TimLuongThapNhat(ds, n).Xuat();

    // ===== TONG LUONG =====
    cout << "\nTong luong: " << TinhTongLuong(ds, n) << endl;

    // ===== TUOI CAO NHAT =====
    cout << "\nNhan vien tuoi cao nhat:\n";
    TimTuoiLonNhat(ds, n).Xuat();

    // ===== SAP XEP =====
    SapXepTangTheoLuong(ds, n);

    cout << "\n=== SAU SAP XEP ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    delete[] ds;

    return 0;
}
