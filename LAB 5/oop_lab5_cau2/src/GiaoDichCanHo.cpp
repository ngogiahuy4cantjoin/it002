#include "GiaoDichCanHo.h"
#include <sstream>

/*
INPUT: ban phim
OUTPUT: giao dich can ho hop le
*/
void GiaoDichCanHo::Nhap() {
    GiaoDich::Nhap();

    string line;
    char extra;

    cout << "Nhap ma can: ";
    getline(cin, maCan);

    while (true) {
        cout << "Nhap tang: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> tang && !(ss >> extra))
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
void GiaoDichCanHo::Xuat() {
    GiaoDich::Xuat();
    cout << "Ma can: " << maCan << endl;
    cout << "Tang: " << tang << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Thanh tien: " << ThanhTien() << endl;
}

/*
OUTPUT: thanh tien
*/
double GiaoDichCanHo::ThanhTien() {
    if (tang == 1)
        return dienTich * donGia * 2;
    if (tang >= 15)
        return dienTich * donGia * 1.2;
    return dienTich * donGia;
}
