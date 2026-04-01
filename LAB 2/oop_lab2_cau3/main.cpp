#include <iostream>
#include "SoPhuc.h"
using namespace std;

/*
Hàm main
Input: nhập 2 số phức A, B
Output: in A, B và các phép toán (tổng, hiệu, tích, thương)
Algorithm:
- Nhập A, B
- Xuất A, B
- Tính 4 phép toán
- Xuất kết quả
*/
int main()
{
    SoPhuc a, b;

    cout << "Nhap so phuc A:\n";
    a.Nhap();

    cout << "Nhap so phuc B:\n";
    b.Nhap();

    cout << "\nSo phuc A: ";
    a.Xuat();

    cout << "\nSo phuc B: ";
    b.Xuat();

    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);
    SoPhuc thuong = a.Thuong(b);

    cout << "\n\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    cout << "\nThuong: ";
    thuong.Xuat();

    return 0;
}

