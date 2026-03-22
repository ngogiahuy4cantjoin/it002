#include "date.h"
#include <iostream>
using namespace std;
// kiểm tra năm nhuận
bool LaNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

// số ngày trong tháng
int SoNgayTrongThang(int thang, int nam)
{
    switch (thang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return LaNamNhuan(nam) ? 29 : 28;
        default:
            return 0;
    }
}

void Date::Nhap()
{
    cout << "Nhap ngay: ";
    cin >> iNgay;
    cout << "Nhap thang: ";
    cin >> iThang;
    cout << "Nhap nam: ";
    cin >> iNam;
}

void Date::Xuat()
{
    cout << iNgay << "/" << iThang << "/" << iNam;
}

Date Date::NgayThangNamTiepTheo()
{
    Date next = *this;

    next.iNgay++;

    if (next.iNgay > SoNgayTrongThang(next.iThang, next.iNam))
    {
        next.iNgay = 1;
        next.iThang++;

        if (next.iThang > 12)
        {
            next.iThang = 1;
            next.iNam++;
        }
    }

    return next;
}
