#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc {
private:
    double* a; // hệ số
    int n;     // bậc

public:
    void Nhap();
    void Xuat();

    double TinhGiaTri(double);

    cDaThuc CongDaThuc(const cDaThuc&);
    cDaThuc TruDaThuc(const cDaThuc&);

    void GiaiPhong();
};

#endif
