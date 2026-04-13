#include <iostream>
#include <sstream>
#include <ctime>
#include <cctype>
#include "cNhanVienSX.h"
using namespace std;

/*
INPUT: năm
OUTPUT: true nếu năm nhuận
*/
bool LaNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

/*
INPUT: ngày tháng năm
OUTPUT: true nếu hợp lệ
*/
bool NgayHopLe(int d, int m, int y) {
    if (y <= 0 || m < 1 || m > 12 || d < 1) return false;

    int ngayTrongThang[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (LaNamNhuan(y)) ngayTrongThang[1] = 29;

    if (d > ngayTrongThang[m - 1]) return false;

    return true;
}

/*
INPUT: thông tin nhân viên
OUTPUT: dữ liệu hợp lệ
*/
void cNhanVienSX::Nhap() {
    string line;

    // ===== MA NV =====
    cout << "Ma NV: ";
    getline(cin, maNV);

    // ===== HO TEN =====
    while (true) {
        cout << "Ho ten: ";
        getline(cin, hoTen);

        bool hopLe = true;

        for (char c : hoTen) {
            if (!isalpha(c) && c != ' ') {
                hopLe = false;
                break;
            }
        }

        if (hopLe && hoTen.length() > 0) break;

        cout << "  Sai ho ten. Nhap lai.\n";
    }

    // ===== NGAY SINH =====
    while (true) {
        cout << "Ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);

        int d, m, y;
        char c1, c2;

        stringstream ss(ngaySinh);

        if (ss >> d >> c1 >> m >> c2 >> y &&
            c1 == '/' && c2 == '/' &&
            NgayHopLe(d, m, y)) {
            break;
        }

        cout << "  Sai ngay sinh. Nhap lai.\n";
    }

    // ===== SO SAN PHAM =====
    while (true) {
        cout << "So san pham: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> soSanPham && soSanPham >= 0 && !(ss >> extra)) break;

        cout << "  Sai. Nhap lai.\n";
    }

    // ===== DON GIA =====
    while (true) {
        cout << "Don gia: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> donGia && donGia >= 0 && !(ss >> extra)) break;

        cout << "  Sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thông tin nhân viên
*/
void cNhanVienSX::Xuat() {
    cout << maNV << " | "
         << hoTen << " | "
         << ngaySinh << " | "
         << soSanPham << " | "
         << donGia << " | "
         << "Luong: " << TinhLuong()
         << endl;
}

/*
OUTPUT: lương
*/
double cNhanVienSX::TinhLuong() {
    return soSanPham * donGia;
}

/*
OUTPUT: tuổi
*/
int cNhanVienSX::LayTuoi() {
    int d, m, y;
    char c;

    stringstream ss(ngaySinh);
    ss >> d >> c >> m >> c >> y;

    time_t t = time(0);
    tm* now = localtime(&t);

    int namHienTai = now->tm_year + 1900;

    return namHienTai - y;
}

// ===== GET =====
string cNhanVienSX::getMaNV() { return maNV; }
string cNhanVienSX::getHoTen() { return hoTen; }
string cNhanVienSX::getNgaySinh() { return ngaySinh; }
int cNhanVienSX::getSoSanPham() { return soSanPham; }
double cNhanVienSX::getDonGia() { return donGia; }

// ===== SET =====
void cNhanVienSX::setMaNV(string x) { maNV = x; }
void cNhanVienSX::setHoTen(string x) { hoTen = x; }
void cNhanVienSX::setNgaySinh(string x) { ngaySinh = x; }
void cNhanVienSX::setSoSanPham(int x) { soSanPham = x; }
void cNhanVienSX::setDonGia(double x) { donGia = x; }
