#include <iostream>
#include <sstream>
#include "CVector.h"
using namespace std;

/*
INPUT:
- 2 vector
- 1 so thuc

OUTPUT:
- Tong
- Hieu
- Nhan scalar
- So sanh
*/

int main() {
    CVector v1, v2;
    double k;

    cout << "=== NHAP VECTOR 1 ===\n";
    cin >> v1;

    cout << "\n=== NHAP VECTOR 2 ===\n";
    cin >> v2;

    string line;
    char extra;
    while (true) {
            cout << "\nNhap so thuc k: ";
            getline(cin, line);
            stringstream ss(line);

            if (ss >> k && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
}

    cout << "\n=== HAI VECTOR ===\n";
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "\n=== CAC PHEP TOAN ===\n";
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    cout << "v1 * k = " << v1 * k << endl;
    cout << "v2 * k = " << v2 * k << endl;

    cout << "\n=== SO SANH ===\n";
    cout << "v1 == v2 : " << (v1 == v2 ? "True" : "False") << endl;
    cout << "v1 != v2 : " << (v1 != v2 ? "True" : "False") << endl;

    return 0;
}
