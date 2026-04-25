#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "CDate.h"
using namespace std;

/*
INPUT: ngay, thang, nam
OUTPUT: tao ngay thang nam
ALGORITHM:
1. Gan gia tri
2. Neu sai thi gan mac dinh
*/
CDate::CDate(int d, int m, int y) {
    if (KiemTraHopLe(d, m, y)) {
        ngay = d;
        thang = m;
        nam = y;
    }
    else {
        ngay = 1;
        thang = 1;
        nam = 2000;
    }
}

/*
INPUT: ngay, thang, nam
OUTPUT: cap nhat ngay moi
ALGORITHM:
1. Neu hop le thi gan lai
*/
void CDate::ThietLap(int d, int m, int y) {
    if (KiemTraHopLe(d, m, y)) {
        ngay = d;
        thang = m;
        nam = y;
    }
}

/*
INPUT: nam
OUTPUT: true neu nam nhuan
*/
bool CDate::NamNhuan(int y) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

/*
INPUT: thang, nam
OUTPUT: so ngay trong thang
*/
int CDate::SoNgayTrongThang(int m, int y) {
    if (m == 1 || m == 3 || m == 5 || m == 7 ||
        m == 8 || m == 10 || m == 12)
        return 31;

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;

    if (m == 2) {
        if (NamNhuan(y))
            return 29;
        return 28;
    }

    return 0;
}

/*
INPUT: ngay, thang, nam
OUTPUT: true neu hop le
*/
bool CDate::KiemTraHopLe(int d, int m, int y) {
    if (y <= 0) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > SoNgayTrongThang(m, y)) return false;
    return true;
}

/*
INPUT: khong
OUTPUT: tang 1 ngay
*/
void CDate::Tang1Ngay() {
    ngay++;

    if (ngay > SoNgayTrongThang(thang, nam)) {
        ngay = 1;
        thang++;

        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
}

/*
INPUT: khong
OUTPUT: giam 1 ngay
*/
void CDate::Giam1Ngay() {
    ngay--;

    if (ngay == 0) {
        thang--;

        if (thang == 0) {
            thang = 12;
            nam--;
        }

        ngay = SoNgayTrongThang(thang, nam);
    }
}

/*
INPUT: ban phim
OUTPUT: ngay hop le
*/
void CDate::Nhap() {
    cin >> *this;
}

/*
INPUT: ngay hien tai
OUTPUT: xuat ra man hinh
*/
void CDate::Xuat() {
    cout << *this;
}

/*
INPUT: ngay hien tai
OUTPUT: tong so ngay tu moc 01/01/0001
*/
long long CDate::TongSoNgay() const {
    long long tong = 0;

    for (int y = 1; y < nam; y++) {
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            tong += 366;
        else
            tong += 365;
    }

    for (int m = 1; m < thang; m++) {
        if (m == 1 || m == 3 || m == 5 || m == 7 ||
            m == 8 || m == 10 || m == 12)
            tong += 31;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            tong += 30;
        else {
            if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
                tong += 29;
            else
                tong += 28;
        }
    }

    tong += ngay;
    return tong;
}

/*
INPUT: so ngay cong them
OUTPUT: ngay moi
*/
CDate CDate::operator + (int x) {
    CDate temp = *this;

    for (int i = 1; i <= x; i++)
        temp.Tang1Ngay();

    return temp;
}

/*
INPUT: so ngay tru bot
OUTPUT: ngay moi
*/
CDate CDate::operator - (int x) {
    CDate temp = *this;

    for (int i = 1; i <= x; i++)
        temp.Giam1Ngay();

    return temp;
}

/*
INPUT: 2 ngay
OUTPUT: khoang cach giua 2 ngay
*/
long long CDate::operator - (const CDate& x) {
    return llabs(TongSoNgay() - x.TongSoNgay());
}

/*
INPUT: ++a
OUTPUT: tang truoc roi tra ve
*/
CDate& CDate::operator ++ () {
    Tang1Ngay();
    return *this;
}

/*
INPUT: a++
OUTPUT: tra ve cu roi moi tang
*/
CDate CDate::operator ++ (int) {
    CDate temp = *this;
    Tang1Ngay();
    return temp;
}

/*
INPUT: --a
OUTPUT: giam truoc roi tra ve
*/
CDate& CDate::operator -- () {
    Giam1Ngay();
    return *this;
}

/*
INPUT: a--
OUTPUT: tra ve cu roi moi giam
*/
CDate CDate::operator -- (int) {
    CDate temp = *this;
    Giam1Ngay();
    return temp;
}

/*
INPUT: ngay
OUTPUT: dd/mm/yyyy
*/
ostream& operator << (ostream& out, const CDate& x) {
    out << setw(2) << setfill('0') << x.ngay << "/";
    out << setw(2) << setfill('0') << x.thang << "/";
    out << setw(4) << setfill('0') << x.nam;
    return out;
}

/*
INPUT: ban phim
OUTPUT: nhap ngay hop le
ALGORITHM:
1. Nhap ngay
2. Nhap thang
3. Nhap nam
4. Sai thi nhap lai
*/
istream& operator >> (istream& in, CDate& x) {
    string line;
    int d, m, y;
    char extra;

    while (true) {

        while (true) {
            cout << "Nhap ngay: ";
            getline(in, line);
            stringstream ss(line);

            if (ss >> d && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        while (true) {
            cout << "Nhap thang: ";
            getline(in, line);
            stringstream ss(line);

            if (ss >> m && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        while (true) {
            cout << "Nhap nam: ";
            getline(in, line);
            stringstream ss(line);

            if (ss >> y && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        if (x.KiemTraHopLe(d, m, y))
            break;

        cout << "Ngay thang nam khong hop le. Nhap lai tu dau.\n";
    }

    x.ngay = d;
    x.thang = m;
    x.nam = y;

    return in;
}
