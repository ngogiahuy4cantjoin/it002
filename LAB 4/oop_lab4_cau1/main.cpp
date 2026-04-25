#include <iostream>
#include "cSoPhuc.h"
using namespace std;

/*
INPUT:
- 2 so phuc

OUTPUT:
- Tong
- Hieu
- Tich
- Thuong
- So sanh

ALGORITHM:
1. Nhap z1, z2
2. Tinh cac phep toan
3. In ket qua
4. Test so thuc nhu so phuc dac biet
*/

int main() {
    cSoPhuc z1, z2;

    cout << "=== NHAP SO PHUC THU NHAT ===\n";
    cin >> z1;

    cout << "\n=== NHAP SO PHUC THU HAI ===\n";
    cin >> z2;

    cout << "\n=== HAI SO PHUC ===\n";
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cout << "\n=== CAC PHEP TOAN ===\n";
    cout << "z1 + z2 = " << z1 + z2 << endl;
    cout << "z1 - z2 = " << z1 - z2 << endl;
    cout << "z1 * z2 = " << z1 * z2 << endl;
    cout << "z1 / z2 = " << z1 / z2 << endl;

    cout << "\n=== SO SANH ===\n";
    cout << "z1 == z2 : " << (z1 == z2 ? "True" : "False") << endl;
    cout << "z1 != z2 : " << (z1 != z2 ? "True" : "False") << endl;

    cout << "\n=== SO THUC NHU SO PHUC DAC BIET ===\n";
    cSoPhuc z3;
    z3.ThietLap(5); // 5 + 0i
    cout << "z3 = " << z3 << endl;

    return 0;
}
