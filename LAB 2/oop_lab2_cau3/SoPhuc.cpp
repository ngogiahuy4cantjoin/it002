#include <iostream>
#include <limits> // dùng để clear buffer
#include "SoPhuc.h"
using namespace std;

/*
Hàm: KiemTraSoNguyen
Input: chuỗi s
Output: true nếu là số nguyên hợp lệ, false nếu không
Thuật toán:
- Cho phép dấu '-' ở đầu
- Các ký tự còn lại phải là số
*/
bool KiemTraSoNguyen(string s)
{
    if (s.empty()) return false;

    int i = 0;
    if (s[0] == '-') i = 1;

    if (i == s.length()) return false; // chỉ có dấu '-'

    for (; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

/*
Hàm: Nhap
Input: nhập từ bàn phím (string)
Output: lưu vào iThuc, iAo (int)
Thuật toán:
- Dùng getline để đọc chuỗi
- Kiểm tra hợp lệ
- Nếu đúng → stoi
- Nếu sai → nhập lại
*/
void SoPhuc::Nhap()
{
    string s;

    // Nhập phần thực
    while (true)
    {
        cout << "Nhap phan thuc: ";
        getline(cin, s);

        if (KiemTraSoNguyen(s))
        {
            iThuc = stoi(s);
            break;
        }
        else
        {
            cout << "Loi: Chi duoc nhap so nguyen!\n";
        }
    }

    // Nhập phần ảo
    while (true)
    {
        cout << "Nhap phan ao: ";
        getline(cin, s);

        if (KiemTraSoNguyen(s))
        {
            iAo = stoi(s);
            break;
        }
        else
        {
            cout << "Loi: Chi duoc nhap so nguyen!\n";
        }
    }
}

/*
Hàm: Xuat
Input: số phức hiện tại
Output: in dạng a+bi hoặc a-bi
Algorithm:
- In phần thực
- Nếu phần ảo >=0 → in +bi
- Ngược lại in bi
*/
void SoPhuc::Xuat()
{
    cout << iThuc;
    if (iAo >= 0)
        cout << "+" << iAo << "i";
    else
        cout << iAo << "i";
}

/*
Hàm: Tong
Input: 1 số phức sp
Output: tổng 2 số phức
*/
SoPhuc SoPhuc::Tong(SoPhuc sp)
{
    SoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}

/*
Hàm: Hieu
Input: 1 số phức sp
Output: hiệu 2 số phức
*/
SoPhuc SoPhuc::Hieu(SoPhuc sp)
{
    SoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}

/*
Hàm: Tich
Input: 1 số phức sp
Output: tích 2 số phức
Algorithm:
(a+bi)(c+di) = (ac - bd) + (ad + bc)i
*/
SoPhuc SoPhuc::Tich(SoPhuc sp)
{
    SoPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}

/*
Hàm: Thuong
Input: 1 số phức sp
Output: thương 2 số phức
Algorithm:
- mẫu = c^2 + d^2
- nếu mẫu = 0 → báo lỗi
*/
SoPhuc SoPhuc::Thuong(SoPhuc sp)
{
    SoPhuc kq;
    int mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;

    if (mau == 0)
    {
        cout << "\nLoi: Khong the chia cho so phuc 0!";
        kq.iThuc = 0;
        kq.iAo = 0;
        return kq;
    }

    kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
    kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;

    return kq;
}

