#include <iostream>
#include "Time.h"
using namespace std;

void Time::Nhap() {
    cout << "Nhap gio: ";
    cin >> iGio;
    cout << "Nhap phut: ";
    cin >> iPhut;
    cout << "Nhap giay: ";
    cin >> iGiay;
}

void Time::Xuat() {
    cout << iGio << ":" << iPhut << ":" << iGiay;
}

Time Time::TinhCongThemMotGiay() {
    Time next = *this;

    next.iGiay++;

    if (next.iGiay >= 60)
    {
        next.iGiay = 0;
        next.iPhut++;

        if (next.iPhut >= 60)
        {
            next.iPhut = 0;
            next.iGio++;

            if (next.iGio >= 24)
            {
                next.iGio = 0;
            }
        }
    }

    return next;
}
