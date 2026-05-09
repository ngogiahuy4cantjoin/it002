#include "DanhSach.h"
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichCanHo.h"
#include <sstream>

/*
OUTPUT: giai phong bo nho
*/
DanhSach::~DanhSach() {
    for (int i = 0; i < DS.size(); i++)
        delete DS[i];
}

/*
INPUT: ban phim
OUTPUT: danh sach giao dich
*/
void DanhSach::Nhap() {
    string line;
    int n;

    while (true) {
        cout << "Nhap so luong giao dich: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> n && !(ss >> extra)) break;
        cout << "Nhap sai. Nhap lai.\n";
    }

    for (int i = 0; i < n; i++) {
        int loai;

        while (true) {
            cout << "\nGiao dich " << i + 1 << " (1: Dat, 2: Nha pho, 3: Can ho): ";
            getline(cin, line);

            stringstream ss(line);
            char extra;

            if (ss >> loai && !(ss >> extra) && loai >= 1 && loai <= 3)
                break;

            cout << "Nhap sai. Nhap lai.\n";
        }

        GiaoDich* p;

        if (loai == 1) p = new GiaoDichDat();
        else if (loai == 2) p = new GiaoDichNhaPho();
        else p = new GiaoDichCanHo();

        p->Nhap();
        DS.push_back(p);
    }
}

/*
OUTPUT: in danh sach
*/
void DanhSach::Xuat() {
    for (int i = 0; i < DS.size(); i++) {
        cout << "\n--- Giao dich " << i + 1 << " ---\n";
        DS[i]->Xuat();
    }
}

/*
OUTPUT: dem tung loai
*/
void DanhSach::DemTungLoai() {
    int dat = 0, nha = 0, can = 0;

    for (int i = 0; i < DS.size(); i++) {
        if (dynamic_cast<GiaoDichDat*>(DS[i])) dat++;
        else if (dynamic_cast<GiaoDichNhaPho*>(DS[i])) nha++;
        else if (dynamic_cast<GiaoDichCanHo*>(DS[i])) can++;
    }

    cout << "Dat: " << dat << endl;
    cout << "Nha pho: " << nha << endl;
    cout << "Can ho: " << can << endl;
}

/*
OUTPUT: trung binh can ho
*/
double DanhSach::TBCanHo() {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < DS.size(); i++) {
        GiaoDichCanHo* p = dynamic_cast<GiaoDichCanHo*>(DS[i]);
        if (p) {
            sum += p->ThanhTien();
            count++;
        }
    }

    if (count == 0) return 0;
    return sum / count;
}

/*
OUTPUT: nha pho max
*/
GiaoDich* DanhSach::NhaPhoMax() {
    GiaoDich* res = NULL;

    for (int i = 0; i < DS.size(); i++) {
        GiaoDichNhaPho* p = dynamic_cast<GiaoDichNhaPho*>(DS[i]);
        if (p) {
            if (res == NULL || p->ThanhTien() > res->ThanhTien())
                res = p;
        }
    }
    return res;
}

/*
OUTPUT: giao dich thang 12/2024
*/
void DanhSach::XuatThang12_2024() {
    for (int i = 0; i < DS.size(); i++) {
        if (DS[i]->LayThangNam() == "12/2024") {
            cout << "\n--- Giao dich ---\n";
            DS[i]->Xuat();
        }
    }
}
