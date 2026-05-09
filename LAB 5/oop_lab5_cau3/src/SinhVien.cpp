#include "SinhVien.h"
#include <sstream>

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
SinhVien::SinhVien() {
    maSV = "";
    hoTen = "";
    diaChi = "";
    tongTinChi = 0;
    diemTB = 0;
}

SinhVien::~SinhVien() {}

/*
INPUT: ban phim
OUTPUT: thong tin hop le
*/
void SinhVien::Nhap() {
    string line;
    char extra;

    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    while (true) {
        cout << "Nhap tong so tin chi: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> tongTinChi && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap diem trung binh: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> diemTB && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void SinhVien::Xuat() {
    cout << "Ma SV: " << maSV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Tong tin chi: " << tongTinChi << endl;
    cout << "Diem trung binh: " << diemTB << endl;
}

/*
OUTPUT: diem trung binh
*/
double SinhVien::LayDiemTB() {
    return diemTB;
}
