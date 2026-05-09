#include "GiaoDichDat.h"
#include <sstream>

/*
INPUT: ban phim
OUTPUT: giao dich dat hop le
*/
void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();

    string line;
    char extra;

    while (true) {
        cout << "Nhap loai dat (A/B/C): ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> loaiDat && !(ss >> extra) &&
            (loaiDat == 'A' || loaiDat == 'B' || loaiDat == 'C'))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

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
void GiaoDichDat::Xuat() {
    GiaoDich::Xuat();
    cout << "Loai dat: " << loaiDat << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Thanh tien: " << ThanhTien() << endl;
}

/*
OUTPUT: thanh tien
*/
double GiaoDichDat::ThanhTien() {
    if (loaiDat == 'A')
        return dienTich * donGia * 1.5;
    return dienTich * donGia;
}
