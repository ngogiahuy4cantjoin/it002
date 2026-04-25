#include <iostream>
#include <iomanip>
#include "CDate.h"
using namespace std;

/*
INPUT:
- Ngay gui tien
- So tien gui
- Lai suat nam (%)
- Ngay rut tien

OUTPUT:
- Ngay gui
- Ngay rut
- So ngay gui
- Tien lai
- Tong tien nhan

ALGORITHM:
1. Nhap ngay gui
2. Nhap ngay rut
3. Nhap tien gui va lai suat
4. Tinh so ngay gui
5. Tinh lai don theo ngay
6. Test cac toan tu CDate
*/

int main() {
    CDate ngayGui, ngayRut;

    cout << "=== NHAP NGAY GUI TIEN ===\n";
    cin >> ngayGui;

    cout << "\n=== NHAP NGAY RUT TIEN ===\n";
    cin >> ngayRut;

    double tienGui, laiSuat;

    cout << "\nNhap so tien gui: ";
    cin >> tienGui;

    cout << "Nhap lai suat nam (%): ";
    cin >> laiSuat;

    long long soNgay = ngayRut - ngayGui;

    double tienLai = tienGui * (laiSuat / 100) * soNgay / 365.0;
    double tongTien = tienGui + tienLai;

    cout << fixed << setprecision(2);

    cout << "\n===== KET QUA =====\n";
    cout << "Ngay gui: " << ngayGui << endl;
    cout << "Ngay rut: " << ngayRut << endl;
    cout << "So ngay gui: " << soNgay << endl;
    cout << "Tien lai: " << tienLai << endl;
    cout << "Tong tien nhan: " << tongTien << endl;

    cout << "\n===== TEST TOAN TU =====\n";

    CDate a = ngayGui;

    cout << "a = " << a << endl;
    cout << "a + 10 = " << a + 10 << endl;
    cout << "a - 10 = " << a - 10 << endl;

    cout << "++a = " << ++a << endl;
    cout << "a++ = " << a++ << endl;
    cout << "Sau a++ : " << a << endl;

    cout << "--a = " << --a << endl;
    cout << "a-- = " << a-- << endl;
    cout << "Sau a-- : " << a << endl;

    return 0;
}
