#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    Date d;

    cout << "Nhap ngay thang nam:\n";
    d.Nhap();

    cout << "\nNgay vua nhap: ";
    d.Xuat();

    Date next = d.NgayThangNamTiepTheo();

    cout << "\nNgay tiep theo: ";
    next.Xuat();

    return 0;
}
