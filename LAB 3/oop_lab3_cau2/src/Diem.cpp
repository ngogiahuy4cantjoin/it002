#include <iostream>
#include <cmath>
#include "Diem.h"
#include <iomanip>
#include <sstream>
using namespace std;

/*
INPUT: nhập x, y
OUTPUT: gán tọa độ điểm
ALGORITHM: nhập trực tiếp từ bàn phím
*/
void Diem::Nhap() {
    string line;

    // ===== NHẬP X =====
    while (true) {
        cout << "\nNhap x: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> x && !(ss >> extra)) {
            break; // hợp lệ
        }

        cout << "  Sai x. Nhap lai.\n";
    }

    // ===== NHẬP Y =====
    while (true) {
        cout << "Nhap y: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> y && !(ss >> extra)) {
            break; // hợp lệ
        }

        cout << "  Sai y. Nhap lai.\n";
    }
}

/*
INPUT: điểm
OUTPUT: in dạng (x, y)
ALGORITHM: dùng cout
*/
void Diem::Xuat() {
    cout << "(" << x << "," << y << ")";
}

/*
INPUT: dx, dy
OUTPUT: điểm sau tịnh tiến
ALGORITHM: x += dx, y += dy
*/
void Diem::TinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

/*
INPUT: góc (radian)
OUTPUT: điểm sau quay quanh gốc O
ALGORITHM:
x' = x*cos - y*sin
y' = x*sin + y*cos
*/
void Diem::Quay(double goc) {
    double newX = x * cos(goc) - y * sin(goc);
    double newY = x * sin(goc) + y * cos(goc);
    if (fabs(newX) < 1e-6) newX = 0;
    if (fabs(newY) < 1e-6) newY = 0;
    x = newX;
    y = newY;
}

/*
INPUT: k
OUTPUT: điểm sau phóng to
ALGORITHM: nhân tọa độ với k
*/
void Diem::PhongTo(double k) {
    x *= k;
    y *= k;
}

/*
INPUT: k
OUTPUT: điểm sau thu nhỏ
ALGORITHM: chia tọa độ cho k (k != 0)
*/
void Diem::ThuNho(double k) {
    if (k != 0) {
        x /= k;
        y /= k;
    }
}

double Diem::GetX() { return x; }
double Diem::GetY() { return y; }

void Diem::Set(double a, double b) {
    x = a; y = b;
}
