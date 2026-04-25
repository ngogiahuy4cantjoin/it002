#include <iostream>
#include "cDaThuc.h"
using namespace std;

/*
INPUT:
- 2 da thuc
- gia tri x

OUTPUT:
- 2 da thuc
- tong
- hieu
- gia tri tai x

ALGORITHM:
1. Nhap 2 da thuc
2. Xuat
3. Tinh tong hieu
4. Tinh gia tri tai x
*/

int main() {
    cDaThuc p1, p2;
    double x;

    cout << "=== NHAP DA THUC 1 ===\n";
    cin >> p1;

    cout << "\n=== NHAP DA THUC 2 ===\n";
    cin >> p2;

    cout << "\n=== HAI DA THUC ===\n";
    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    cout << "\n=== PHEP TOAN ===\n";
    cout << "P1 + P2 = " << p1 + p2 << endl;
    cout << "P1 - P2 = " << p1 - p2 << endl;
    while (true) {
            cout << "\nNhap x = ";
    if (cin >> x)
        break;

    cout << "Nhap sai. Nhap lai.\n";
    cin.clear();
    cin.ignore(1000, '\n');
}
    cout << "P1(" << x << ") = " << p1.GiaTriTai(x) << endl;
    cout << "P2(" << x << ") = " << p2.GiaTriTai(x) << endl;

    return 0;
}
