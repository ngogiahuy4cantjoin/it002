#include <iostream>
#include <cmath>
#include <sstream>
#include "cDaGiac.h"
using namespace std;

/*
INPUT: số đỉnh n, danh sách điểm
OUTPUT: đa giác
ALGORITHM:
- kiểm tra n >= 3
- nhập từng điểm bằng Nhap() của Diem
*/
void cDaGiac::Nhap() {
    string line;

    // ===== NHẬP n =====
    while (true) {
        cout << "Nhap so dinh n (>=3): ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && !(ss >> extra) && n >= 3) break;

        cout << "  Sai n. Nhap lai.\n";
    }

    ds.clear();
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap diem " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

/*
INPUT: đa giác
OUTPUT: in các điểm
ALGORITHM: duyệt vector
*/
void cDaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1;
        ds[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

/*
INPUT: đa giác
OUTPUT: true nếu hợp lệ
ALGORITHM:
- kiểm tra diện tích != 0 (shoelace)
*/
bool cDaGiac::KiemTraHopLe() {
    double area = 0;

    for (int i = 0; i < n; i++) {
        double x1 = ds[i].GetX();
        double y1 = ds[i].GetY();
        double x2 = ds[(i + 1) % n].GetX();
        double y2 = ds[(i + 1) % n].GetY();

        area += (x1 * y2 - x2 * y1);
    }

    return fabs(area) > 1e-6;
}

/*
INPUT: đa giác
OUTPUT: chu vi
ALGORITHM:
- tổng khoảng cách giữa các điểm liên tiếp
*/
double cDaGiac::TinhChuVi() {
    double chuvi = 0;

    for (int i = 0; i < n; i++) {
        double x1 = ds[i].GetX();
        double y1 = ds[i].GetY();
        double x2 = ds[(i + 1) % n].GetX();
        double y2 = ds[(i + 1) % n].GetY();

        chuvi += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    return chuvi;
}

/*
INPUT: đa giác
OUTPUT: diện tích
ALGORITHM:
- công thức shoelace
*/
double cDaGiac::TinhDienTich() {
    double area = 0;

    for (int i = 0; i < n; i++) {
        double x1 = ds[i].GetX();
        double y1 = ds[i].GetY();
        double x2 = ds[(i + 1) % n].GetX();
        double y2 = ds[(i + 1) % n].GetY();

        area += (x1 * y2 - x2 * y1);
    }

    return fabs(area) / 2;
}

/*
INPUT: dx, dy
OUTPUT: đa giác sau tịnh tiến
ALGORITHM: gọi TinhTien() cho từng điểm
*/
void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        ds[i].TinhTien(dx, dy);
    }
}

/*
INPUT: góc radian
OUTPUT: đa giác sau quay
ALGORITHM: gọi Quay() cho từng điểm
*/
void cDaGiac::Quay(double goc) {
    for (int i = 0; i < n; i++) {
        ds[i].Quay(goc);
    }
}

void cDaGiac::PhongTo(double k) {
    for (int i = 0; i < n; i++) {
        ds[i].PhongTo(k);
    }
}

void cDaGiac::ThuNho(double k) {
    if (k != 0) { // FIX lỗi chia 0
        for (int i = 0; i < n; i++) {
            ds[i].ThuNho(k);
        }
    }
}
