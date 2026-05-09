#include "GiaoDichNhaPho.h"
#include <sstream>

/*
INPUT: ban phim
OUTPUT: giao dich nha pho hop le
*/
void GiaoDichNhaPho::Nhap() {
    GiaoDich::Nhap();

    string line;
    char extra;

    while (true) {
        cout << "Nhap loai nha (cao cap / thuong): ";
        getline(cin, loaiNha);

        if (loaiNha == "cao cap" || loaiNha == "thuong")
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    while (true) {
        cout << "Nhap dien tich: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> dienTich && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void GiaoDichNhaPho::Xuat() {
    GiaoDich::Xuat();
    cout << "Loai nha: " << loaiNha << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Thanh tien: " << ThanhTien() << endl;
}

/*
OUTPUT: thanh tien
*/
double GiaoDichNhaPho::ThanhTien() {
    if (loaiNha == "thuong")
        return dienTich * donGia * 0.9;
    return dienTich * donGia;
}
