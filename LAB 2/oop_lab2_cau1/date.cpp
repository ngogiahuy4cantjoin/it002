#include "date.h"
#include <iostream>
#include <limits> // xử lý lỗi nhập
using namespace std;

/*
INPUT: nam (int)
OUTPUT: true nếu là năm nhuận, false nếu không
ALGORITHM:
- chia hết 400 → nhuận
- chia hết 4 nhưng không chia hết 100 → nhuận
*/
bool LaNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/*
INPUT: thang, nam
OUTPUT: số ngày trong tháng
ALGORITHM:
- dùng switch
- tháng 2 xét năm nhuận
*/
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

/*
INPUT: ngay, thang, nam
OUTPUT: true nếu hợp lệ
ALGORITHM:
- kiểm tra tháng (1→12)
- kiểm tra ngày theo tháng
*/
bool KiemTraHopLe(int ngay, int thang, int nam)
{
    if (nam < 1) return false;
    if (thang < 1 || thang > 12) return false;

    int maxDay = SoNgayTrongThang(thang, nam);
    return (ngay >= 1 && ngay <= maxDay);
}

/*
INPUT: nhập từ bàn phím
OUTPUT: số nguyên hợp lệ
ALGORITHM:
- nhập
- nếu fail → clear + ignore → nhập lại
*/
int NhapSo()
{
    int x;
    while (true)
    {
        cin >> x;
        if (!cin.fail()) return x;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ">> Du lieu KHONG hop le! Nhap lai: ";
    }
}

/*
INPUT: nhập ngày tháng năm
OUTPUT: gán giá trị hợp lệ cho object
ALGORITHM:
- dùng NhapSo() để tránh nhập chữ
- kiểm tra hợp lệ → sai thì nhập lại
*/
void Date::Nhap()
{
    do
    {
        cout << "Nhap ngay: ";
        iNgay = NhapSo();

        cout << "Nhap thang: ";
        iThang = NhapSo();

        cout << "Nhap nam: ";
        iNam = NhapSo();

        if (!KiemTraHopLe(iNgay, iThang, iNam))
        {
            cout << ">> Ngay thang nam KHONG hop le! Nhap lai!\n";
        }

    } while (!KiemTraHopLe(iNgay, iThang, iNam));
}

/*
INPUT: không
OUTPUT: in dd/mm/yyyy
ALGORITHM:
- in trực tiếp
*/
void Date::Xuat()
{
    cout << iNgay << "/" << iThang << "/" << iNam;
}

/*
INPUT: object hiện tại
OUTPUT: ngày kế tiếp
ALGORITHM:
- copy object
- tăng ngày
- xử lý tràn tháng, năm
*/
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

