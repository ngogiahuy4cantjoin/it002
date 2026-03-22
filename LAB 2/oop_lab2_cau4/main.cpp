#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time t;

    cout << "Nhap gio phut giay:\n";
    t.Nhap();

    cout << "\nThoi gian vua nhap: ";
    t.Xuat();

    Time next = t.TinhCongThemMotGiay();

    cout << "\nSau khi cong 1 giay: ";
    next.Xuat();

    return 0;
}
