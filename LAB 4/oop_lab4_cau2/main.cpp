#include <iostream>
#include "cPhanSo.h"
using namespace std;

/*
INPUT:
- 2 phan so

OUTPUT:
- Tong
- Hieu
- Tich
- Thuong
- So sanh

ALGORITHM:
1. Nhap ps1, ps2
2. Tinh cac phep toan
3. In ket qua
4. Test so nguyen nhu phan so dac biet
*/

int main() {
    cPhanSo ps1, ps2;

    cout << "=== NHAP PHAN SO THU NHAT ===\n";
    cin >> ps1;

    cout << "\n=== NHAP PHAN SO THU HAI ===\n";
    cin >> ps2;

    cout << "\n=== HAI PHAN SO ===\n";
    cout << "ps1 = " << ps1 << endl;
    cout << "ps2 = " << ps2 << endl;

    cout << "\n=== CAC PHEP TOAN ===\n";
    cout << "ps1 + ps2 = " << ps1 + ps2 << endl;
    cout << "ps1 - ps2 = " << ps1 - ps2 << endl;
    cout << "ps1 * ps2 = " << ps1 * ps2 << endl;
    cout << "ps1 / ps2 = " << ps1 / ps2 << endl;

    cout << "\n=== SO SANH ===\n";
    cout << "ps1 == ps2 : " << (ps1 == ps2 ? "True" : "False") << endl;
    cout << "ps1 > ps2  : " << (ps1 > ps2 ? "True" : "False") << endl;
    cout << "ps1 < ps2  : " << (ps1 < ps2 ? "True" : "False") << endl;

    cout << "\n=== SO NGUYEN NHU PHAN SO DAC BIET ===\n";
    cPhanSo ps3;
    ps3.ThietLap(5);   // 5/1
    cout << "ps3 = " << ps3 << endl;

    return 0;
}
