#include <iostream>
#include <cmath>
#include "cTamGiac.h"
using namespace std;

/*
INPUT: nhập 3 điểm
OUTPUT: tam giác
ALGORITHM: gọi Nhap() của từng điểm
*/
void cTamGiac::Nhap() {
    // cin.ignore(); // clear buffer trước getline
    cout << "Nhap A(x y): "; A.Nhap();
    cout << "Nhap B(x y): "; B.Nhap();
    cout << "Nhap C(x y): "; C.Nhap();
}

/*
INPUT: tam giác
OUTPUT: in tọa độ
ALGORITHM: gọi Xuat()
*/
void cTamGiac::Xuat() {
    cout << "A"; A.Xuat();
    cout << " B"; B.Xuat();
    cout << " C"; C.Xuat();
    cout << endl;
}

/*
INPUT: tam giác
OUTPUT: true nếu hợp lệ, false nếu không
ALGORITHM:
- Dùng diện tích (shoelace)
- Nếu diện tích = 0 → thẳng hàng → không hợp lệ
*/
bool cTamGiac::KiemTraHopLe() {
    double Ax = A.GetX(), Ay = A.GetY();
    double Bx = B.GetX(), By = B.GetY();
    double Cx = C.GetX(), Cy = C.GetY();

    double area = Ax*(By - Cy) + Bx*(Cy - Ay) + Cx*(Ay - By);

    return area != 0;
}

/*
INPUT: 3 biến tham chiếu
OUTPUT: độ dài 3 cạnh
ALGORITHM: công thức khoảng cách
*/
void cTamGiac::TinhCanh(double &a, double &b, double &c) {
    double Ax = A.GetX(), Ay = A.GetY();
    double Bx = B.GetX(), By = B.GetY();
    double Cx = C.GetX(), Cy = C.GetY();

    a = sqrt(pow(Bx - Cx, 2) + pow(By - Cy, 2));
    b = sqrt(pow(Ax - Cx, 2) + pow(Ay - Cy, 2));
    c = sqrt(pow(Ax - Bx, 2) + pow(Ay - By, 2));
}

/*
INPUT: tam giác
OUTPUT: loại tam giác
ALGORITHM: so sánh cạnh
*/
string cTamGiac::KiemTraLoai() {
    double a, b, c;
    TinhCanh(a, b, c);

    if (a == b && b == c) return "Deu";

    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
        return "Vuong";

    if (a == b || b == c || a == c) return "Can";

    return "Thuong";
}

/*
INPUT: tam giác
OUTPUT: chu vi
ALGORITHM: tổng 3 cạnh
*/
double cTamGiac::TinhChuVi() {
    double a, b, c;
    TinhCanh(a, b, c);
    return a + b + c;
}

/*
INPUT: tam giác
OUTPUT: diện tích
ALGORITHM: công thức Heron
*/
double cTamGiac::TinhDienTich() {
    double a, b, c;
    TinhCanh(a, b, c);

    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/*
INPUT: dx, dy
OUTPUT: tam giác sau tịnh tiến
ALGORITHM: gọi TinhTien() cho từng điểm
*/
void cTamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void cTamGiac::Quay(double goc) {
    A.Quay(goc);
    B.Quay(goc);
    C.Quay(goc);
}

void cTamGiac::PhongTo(double k) {
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}

void cTamGiac::ThuNho(double k) {
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}
