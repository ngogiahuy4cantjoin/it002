#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "CMatrix.h"
using namespace std;

int main() {
    CMatrix A, B;

    cout << "=== NHAP MA TRAN A ===\n";
    cin >> A;

    cout << "\n=== NHAP MA TRAN B ===\n";
    cin >> B;

    cout << "\n=== MA TRAN A ===\n";
    cout << A;

    cout << "\n=== MA TRAN B ===\n";
    cout << B;

    cout << "\n=== TICH HAI MA TRAN ===\n";
    cout << A * B;

    int n;
    string line;
    char extra;

    while (true) {
        cout << "\nNhap so phan tu vector: ";
        getline(cin, line);
        stringstream ss(line);

        if (ss >> n && !(ss >> extra) && n > 0)
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }

    vector<double> v(n);

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "v[" << i << "] = ";
            getline(cin, line);
            stringstream ss(line);

            if (ss >> v[i] && !(ss >> extra))
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }
    }

    vector<double> kq = A * v;

    cout << "\n=== TICH MA TRAN A VOI VECTOR ===\n";

    for (int i = 0; i < kq.size(); i++)
        cout << kq[i] << " ";

    return 0;
}
