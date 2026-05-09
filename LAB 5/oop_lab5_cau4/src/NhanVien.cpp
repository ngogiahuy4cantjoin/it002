#include "NhanVien.h"
#include <sstream>

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
NhanVien::NhanVien() {
    maNV = "";
    hoTen = "";
    tuoi = 0;
    soDienThoai = "";
    email = "";
    luongCoBan = 0;
}

NhanVien::~NhanVien() {}

/*
INPUT: ban phim
OUTPUT: thong tin hop le
*/
void NhanVien::Nhap() {
    string line;
    char extra;

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    while (true) {
        cout << "Nhap tuoi: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> tuoi && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    cout << "Nhap so dien thoai: ";
    getline(cin, soDienThoai);

    cout << "Nhap email: ";
    getline(cin, email);

    while (true) {
        cout << "Nhap luong co ban: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> luongCoBan && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void NhanVien::Xuat() {
    cout << "Ma nhan vien: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << soDienThoai << endl;
    cout << "Email: " << email << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Luong: " << TinhLuong() << endl;
}

/*
OUTPUT: luong nhan vien
*/
double NhanVien::LayLuong() {
    return TinhLuong();
}
