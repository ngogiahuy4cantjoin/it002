#include <iostream>
#include <sstream>
#include "cArray.h"
using namespace std;

/*
INPUT:
- mảng
- x

OUTPUT:
- kết quả xử lý mảng

ALGORITHM:
1. Nhập
2. Xuất
3. Đếm x
4. Kiểm tra tăng dần
5. Tìm số lẻ nhỏ nhất
6. Tìm số nguyên tố lớn nhất
7. Sắp xếp
*/

void NhapSo(int &x) {
    string line;

    while (true) {
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> x && !(ss >> extra)) break;

        cout << "Nhap sai. Nhap lai: ";
    }
}

int main() {
    cArray arr;

    cout << "=== NHAP MANG ===\n";
    arr.Nhap();

    cout << "\n=== XUAT ===\n";
    arr.Xuat();

    // ===== DEM X =====
    int x;
    cout << "\nNhap x can dem: ";
    NhapSo(x);

    cout << "So lan xuat hien: " << arr.DemSoLanXuatHien(x) << endl;

    // ===== KIEM TRA =====
    cout << "Tang dan? " << (arr.KiemTraTangDan() ? "Yes" : "No") << endl;

    // ===== MIN LE =====
    int minLe = arr.TimSoLeNhoNhat();
    if (minLe == -1)
        cout << "Khong co so le\n";
    else
        cout << "So le nho nhat: " << minLe << endl;

    // ===== PRIME MAX =====
    int maxPrime = arr.TimSoNguyenToLonNhat();
    if (maxPrime == -1)
        cout << "Khong co so nguyen to\n";
    else
        cout << "So nguyen to lon nhat: " << maxPrime << endl;

    // ===== SORT =====
    arr.SapXepTangDan();
    cout << "\nTang dan: ";
    arr.Xuat();

    arr.SapXepGiamDan();
    cout << "Giam dan: ";
    arr.Xuat();

    arr.GiaiPhong();

    return 0;
}
