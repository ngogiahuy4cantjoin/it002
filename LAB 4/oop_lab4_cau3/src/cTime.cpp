#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "CTime.h"
using namespace std;

/*
INPUT:
- gio, phut, giay

OUTPUT:
- Tao doi tuong thoi gian

ALGORITHM:
1. Gan gia tri
2. Chuan hoa
*/
CTime::CTime(int h, int p, int s) {
    gio = h;
    phut = p;
    giay = s;
    ChuanHoa();
}

/*
INPUT:
- gio, phut, giay moi

OUTPUT:
- Cap nhat lai thoi gian

ALGORITHM:
1. Gan lai gia tri
2. Chuan hoa
*/
void CTime::ThietLap(int h, int p, int s) {
    gio = h;
    phut = p;
    giay = s;
    ChuanHoa();
}

/*
INPUT:
- Thoi gian hien tai

OUTPUT:
- Dua ve dang hop le

ALGORITHM:
1. Quy doi tong giay
2. Dua ve khoang 0 -> 86399
3. Tach lai gio phut giay
*/
void CTime::ChuanHoa() {
    int tong = gio * 3600 + phut * 60 + giay;

    tong %= 86400;

    if (tong < 0)
        tong += 86400;

    gio = tong / 3600;
    tong %= 3600;

    phut = tong / 60;
    giay = tong % 60;
}

/*
INPUT:
- so giay can cong

OUTPUT:
- thoi gian moi
*/
CTime CTime::operator + (int x) {
    CTime temp(gio, phut, giay + x);
    return temp;
}

/*
INPUT:
- so giay can tru

OUTPUT:
- thoi gian moi
*/
CTime CTime::operator - (int x) {
    CTime temp(gio, phut, giay - x);
    return temp;
}

/*
INPUT:
- ++t

OUTPUT:
- tang 1 giay
*/
CTime& CTime::operator ++ () {
    giay++;
    ChuanHoa();
    return *this;
}

/*
INPUT:
- t++

OUTPUT:
- gia tri cu roi tang 1 giay
*/
CTime CTime::operator ++ (int) {
    CTime temp = *this;
    giay++;
    ChuanHoa();
    return temp;
}

/*
INPUT:
- --t

OUTPUT:
- giam 1 giay
*/
CTime& CTime::operator -- () {
    giay--;
    ChuanHoa();
    return *this;
}

/*
INPUT:
- t--

OUTPUT:
- gia tri cu roi giam 1 giay
*/
CTime CTime::operator -- (int) {
    CTime temp = *this;
    giay--;
    ChuanHoa();
    return temp;
}

/*
INPUT:
- doi tuong thoi gian

OUTPUT:
- hh:mm:ss
*/
ostream& operator << (ostream& out, const CTime& t) {
    out << setw(2) << setfill('0') << t.gio << ":";
    out << setw(2) << setfill('0') << t.phut << ":";
    out << setw(2) << setfill('0') << t.giay;
    return out;
}

/*
INPUT:
- ban phim

OUTPUT:
- nhap hop le

ALGORITHM:
1. Nhap gio
2. Nhap phut
3. Nhap giay
4. Neu sai thi nhap lai
*/
istream& operator >> (istream& in, CTime& t) {
    string line;
    int h, p, s;
    char extra;

    while (true) {
        cout << "Nhap gio: ";
        getline(in, line);

        stringstream ss(line);

        if (ss >> h && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap phut: ";
        getline(in, line);

        stringstream ss(line);

        if (ss >> p && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap giay: ";
        getline(in, line);

        stringstream ss(line);

        if (ss >> s && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    t.ThietLap(h, p, s);
    return in;
}
