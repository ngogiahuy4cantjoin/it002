#include <iostream>
#include <cmath>   // dùng abs
#include <limits>  // xử lý nhập lỗi
#include "PhanSo.h"
using namespace std;

/*
INPUT: a, b
OUTPUT: UCLN(a, b)
ALGORITHM:
- dùng Euclid (đệ quy)
*/
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return UCLN(b, a % b);
}

/*
INPUT: từ bàn phím
OUTPUT: số nguyên hợp lệ
ALGORITHM:
- nhập
- nếu sai → clear + ignore → nhập lại
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
INPUT: nhập tử và mẫu
OUTPUT: gán giá trị hợp lệ
ALGORITHM:
- nhập tử
- nhập mẫu ≠ 0
*/
void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    iTu = NhapSo();

    do {
        cout << "Nhap mau (khac 0): ";
        iMau = NhapSo();

        if (iMau == 0)
            cout << ">> Mau phai khac 0!\n";

    } while (iMau == 0);
}

/*
INPUT: không
OUTPUT: in phân số
*/
void PhanSo::Xuat() {
    cout << iTu << "/" << iMau;
}

/*
INPUT: phân số hiện tại
OUTPUT: phân số rút gọn
ALGORITHM:
- chia cả tử và mẫu cho UCLN
- đưa dấu về tử
*/
void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);

    iTu /= ucln;
    iMau /= ucln;

    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/*
INPUT: ps
OUTPUT: tổng 2 phân số
*/
PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
INPUT: ps
OUTPUT: hiệu
*/
PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
INPUT: ps
OUTPUT: tích
*/
PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
INPUT: ps
OUTPUT: thương
ALGORITHM:
- nhân với nghịch đảo
- nếu tử ps = 0 → không hợp lệ
*/
PhanSo PhanSo::Thuong(PhanSo ps) {
    PhanSo kq;

    if (ps.iTu == 0) {
        cout << " >> Khong the chia cho 0!\n";
        kq.iTu = 0;
        kq.iMau = 1;
        return kq;
    }

    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}

/*
INPUT: ps
OUTPUT: 1, 0, -1
ALGORITHM:
- so sánh chéo
*/
int PhanSo::SoSanh(PhanSo ps) {
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right) return 1;
    if (left == right) return 0;
    return -1;
}

