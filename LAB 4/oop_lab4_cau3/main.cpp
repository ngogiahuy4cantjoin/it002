#include <iostream>
#include <windows.h>
#include "CTime.h"
using namespace std;

/*
INPUT:
- 1 thoi diem
- so giay cong tru

OUTPUT:
- Ket qua cac phep toan
- Dong ho goc tren ben phai

ALGORITHM:
1. Nhap thoi gian
2. In thoi gian
3. Test +, -, ++, --
4. Chay dong ho
*/

int main() {
    CTime t;
    int x;

    cout << "=== NHAP THOI GIAN ===\n";
    cin >> t;

    cout << "\nThoi gian vua nhap: " << t << endl;

    cout << "\nNhap so giay can cong/tru: ";
    cin >> x;

    cout << "\n=== CAC PHEP TOAN ===\n";
    cout << "t + " << x << " = " << t + x << endl;
    cout << "t - " << x << " = " << t - x << endl;

    cout << "\nPrefix ++t = " << ++t << endl;
    cout << "Sau prefix, t = " << t << endl;

    cout << "\nPostfix t++ = " << t++ << endl;
    cout << "Sau postfix, t = " << t << endl;

    cout << "\nPrefix --t = " << --t << endl;
    cout << "Sau prefix, t = " << t << endl;

    cout << "\nPostfix t-- = " << t-- << endl;
    cout << "Sau postfix, t = " << t << endl;

    cout << "\n=== DONG HO (10 GIAY) ===\n";

    for (int i = 0; i <= 10; i++) {
        cout << "\r\t\t\t\t\t" << t;
        cout.flush(); // Ep cout hien thi ngay lap tuc ra man hinh

        t++;
        // Sleep(1000);
    }

    cout << endl;

    return 0;
}
