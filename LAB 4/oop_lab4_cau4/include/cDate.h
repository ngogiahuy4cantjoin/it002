#ifndef CDATE_H
#define CDATE_H

#include <iostream>
using namespace std;

class CDate {
private:
    int ngay;
    int thang;
    int nam;

public:
    // Constructor
    CDate(int = 1, int = 1, int = 2000);

    // Thiet lap
    void ThietLap(int, int, int);

    // Nhap xuat thuong
    void Nhap();
    void Xuat();

    // Ham ho tro
    bool NamNhuan(int);
    int SoNgayTrongThang(int, int);
    bool KiemTraHopLe(int, int, int);

    void Tang1Ngay();
    void Giam1Ngay();

    long long TongSoNgay() const;

    // Toan tu cong tru ngay
    CDate operator + (int);
    CDate operator - (int);

    // Khoang cach 2 ngay
    long long operator - (const CDate&);

    // Prefix
    CDate& operator ++ ();
    CDate& operator -- ();

    // Postfix
    CDate operator ++ (int);
    CDate operator -- (int);

    // Nhap xuat bang stream
    friend ostream& operator << (ostream&, const CDate&);
    friend istream& operator >> (istream&, CDate&);
};

#endif
