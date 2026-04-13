#ifndef DIEM_H
#define DIEM_H

class Diem {
private:
    double x, y;

public:
    void Nhap();
    void Xuat();

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);

    double GetX();
    double GetY();
    void Set(double, double);
};

#endif
