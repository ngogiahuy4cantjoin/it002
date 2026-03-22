#ifndef DATE_H
#define DATE_H


class Date
{
    public:
    void Nhap();
    void Xuat();
    Date NgayThangNamTiepTheo();


    private:
    int iNgay;
    int iThang;
    int iNam;

};

#endif // DATE_H
