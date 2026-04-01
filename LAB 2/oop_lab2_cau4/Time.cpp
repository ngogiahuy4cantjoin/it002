#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

/*
Hàm: KiemTraSoNguyen
Input: chuỗi s
Output: true nếu là số nguyên hợp lệ
*/
bool KiemTraSoNguyen(string s)
{
    if (s.empty()) return false;

    int i = 0;
    if (s[0] == '-') i = 1;

    if (i == s.length()) return false;

    for (; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

/*
Hàm: Nhap
Input:
- Người dùng nhập giờ, phút, giây (string)

Output:
- Lưu vào iGio, iPhut, iGiay hợp lệ

Thuật toán:
- Nhập từng thành phần bằng getline
- Kiểm tra là số nguyên
- Kiểm tra trong khoảng hợp lệ
- Sai → nhập lại
*/
void Time::Nhap()
{
    string s;

    // Nhập giờ
    while (true)
    {
        cout << "Nhap gio (0-23): ";
        getline(cin, s);

        if (KiemTraSoNguyen(s))
        {
            int temp = stoi(s);
            if (temp >= 0 && temp <= 23)
            {
                iGio = temp;
                break;
            }
        }
        cout << "Loi: Gio phai tu 0 den 23!\n";
    }

    // Nhập phút
    while (true)
    {
        cout << "Nhap phut (0-59): ";
        getline(cin, s);

        if (KiemTraSoNguyen(s))
        {
            int temp = stoi(s);
            if (temp >= 0 && temp <= 59)
            {
                iPhut = temp;
                break;
            }
        }
        cout << "Loi: Phut phai tu 0 den 59!\n";
    }

    // Nhập giây
    while (true)
    {
        cout << "Nhap giay (0-59): ";
        getline(cin, s);

        if (KiemTraSoNguyen(s))
        {
            int temp = stoi(s);
            if (temp >= 0 && temp <= 59)
            {
                iGiay = temp;
                break;
            }
        }
        cout << "Loi: Giay phai tu 0 den 59!\n";
    }
}

/*
Hàm: Xuat
Input: thời gian hiện tại
Output: in dạng hh:mm:ss
Thuật toán:
- In giờ:phút:giây
*/
void Time::Xuat()
{
    cout << iGio << ":" << iPhut << ":" << iGiay;
}

/*
Hàm: TinhCongThemMotGiay
Input: thời gian hiện tại
Output: thời gian sau khi cộng 1 giây
Thuật toán:
- Tăng giây
- Nếu >=60 → reset giây, tăng phút
- Nếu phút >=60 → reset phút, tăng giờ
- Nếu giờ >=24 → reset về 0
*/
Time Time::TinhCongThemMotGiay()
{
    Time next = *this;

    next.iGiay++;

    if (next.iGiay >= 60)
    {
        next.iGiay = 0;
        next.iPhut++;

        if (next.iPhut >= 60)
        {
            next.iPhut = 0;
            next.iGio++;

            if (next.iGio >= 24)
            {
                next.iGio = 0;
            }
        }
    }

    return next;
}

