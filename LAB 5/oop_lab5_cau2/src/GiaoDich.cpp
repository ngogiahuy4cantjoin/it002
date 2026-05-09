#include "GiaoDich.h"
#include <sstream>

using namespace std;

/*
INPUT: -
OUTPUT: khoi tao rong
*/
GiaoDich::GiaoDich() {
    maGD = "";
    ngayGD = "";
    donGia = 0;
}

GiaoDich::~GiaoDich() {}

/*
INPUT: nam
OUTPUT: true neu la nam nhuan
*/
bool LaNamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

/*
INPUT: ngay, thang, nam
OUTPUT: true neu ngay hop le
ALGORITHM:
1. Kiem tra thang [1,12], ngay >= 1
2. Xac dinh so ngay trong thang
3. Neu thang 2 va nam nhuan -> toi da 29
4. So sanh ngay voi gioi han
*/
bool NgayHopLe(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;

    int ngayTrongThang[] = {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };

    if (m == 2 && LaNamNhuan(y))
        return d <= 29;

    return d <= ngayTrongThang[m - 1];
}

/*
INPUT: ban phim
OUTPUT: thong tin hop le
*/
void GiaoDich::Nhap() {
    cout << "Nhap ma giao dich: ";
    getline(cin, maGD);

    string line;

    while (true) {
        cout << "Nhap ngay giao dich (dd/mm/yyyy): ";
        getline(cin, line);

        stringstream ss(line);
        string d, m, y;
        char extra;

        if (getline(ss, d, '/') &&
            getline(ss, m, '/') &&
            getline(ss, y)) {

            stringstream sd(d), sm(m), sy(y);
            int dd, mm, yy;

            if (sd >> dd && !(sd >> extra) &&
                sm >> mm && !(sm >> extra) &&
                sy >> yy && !(sy >> extra) &&
                NgayHopLe(dd, mm, yy)) {

                ngayGD = line;
                break;
            }
        }
        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap don gia: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> donGia && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
INPUT: -
OUTPUT: in thong tin
*/
void GiaoDich::Xuat() {
    cout << "Ma GD: " << maGD << endl;
    cout << "Ngay GD: " << ngayGD << endl;
    cout << "Don gia: " << donGia << endl;
}

/*
INPUT: ngayGD
OUTPUT: "mm/yyyy"
*/
string GiaoDich::LayThangNam() {
    stringstream ss(ngayGD);
    string d, m, y;

    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    return m + "/" + y;
}
