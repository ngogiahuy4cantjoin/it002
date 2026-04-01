#include <iostream>
#include "Time.h"
using namespace std;

/*
Hàm: main
Input:
- Người dùng nhập thời gian gồm: giờ, phút, giây

Output:
- In thời gian vừa nhập
- In thời gian sau khi cộng thêm 1 giây

Thuật toán:
- Tạo đối tượng Time t
- Nhập dữ liệu cho t
- Xuất thời gian ban đầu
- Gọi hàm TinhCongThemMotGiay() để tính thời gian mới
- Xuất kết quả
*/
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

