#include "NhanVien.h"
#include <sstream>
#include <ctime>

using namespace std;

/*
INPUT: nam
OUTPUT: true neu la nam nhuan
ALGORITHM:
1. Neu chia het cho 400 -> true
2. Neu chia het cho 4 va khong chia het cho 100 -> true
3. Nguoc lai -> false
*/
bool LaNamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

/*
INPUT: ngay, thang, nam
OUTPUT: true neu ngay hop le
ALGORITHM:
1. Kiem tra thang [1,12], ngay >=1
2. Xac dinh so ngay trong thang
3. Neu thang 2 va nam nhuan -> toi da 29
4. So sanh ngay voi gioi han
*/
bool NgayHopLe(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;

    int ngayTrongThang[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (m == 2 && LaNamNhuan(y))
        return d <= 29;

    return d <= ngayTrongThang[m - 1];
}

/*
INPUT: -
OUTPUT: khoi tao nhan vien rong
*/
NhanVien::NhanVien() {
    hoTen = "";
    ngaySinh = "";
}

/*
INPUT: -
OUTPUT: huy nhan vien
*/
NhanVien::~NhanVien() {}

/*
INPUT: ban phim
OUTPUT: thong tin nhan vien hop le
ALGORITHM:
1. Nhap ho ten
2. Nhap ngay sinh dang dd/mm/yyyy
3. Tach chuoi bang stringstream
4. Kiem tra dinh dang va hop le
5. Sai thi nhap lai
*/
void NhanVien::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    string line;

    while (true) {
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, line);

        stringstream ss(line);
        string d, m, y;
        char extra;

        if (getline(ss, d, '/') &&
            getline(ss, m, '/') &&
            getline(ss, y)) {

            stringstream sd(d), sm(m), sy(y);
            int dd, mm, yy;

            if (sd >> dd && !(sd >> extra) &&
                sm >> mm && !(sm >> extra) &&
                sy >> yy && !(sy >> extra) &&
                NgayHopLe(dd, mm, yy)) {

                ngaySinh = line;
                break;
            }
        }

        cout << "Ngay khong hop le. Nhap lai.\n";
    }
}

/*
INPUT: thong tin nhan vien
OUTPUT: in ra man hinh
*/
void NhanVien::Xuat() {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
}

/*
INPUT: ngay sinh
OUTPUT: tuoi (theo nam)
ALGORITHM:
1. Tach nam tu chuoi ngay sinh
2. Lay nam hien tai
3. Tru nam sinh
*/
int NhanVien::LayTuoi() {
    stringstream ss(ngaySinh);
    string d, m, y;

    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    int ngay, thang, nam;
    stringstream(d) >> ngay;
    stringstream(m) >> thang;
    stringstream(y) >> nam;

    time_t t = time(0);
    tm hienTai = *localtime(&t);

    int namHienTai = hienTai.tm_year + 1900;
    int thangHienTai = hienTai.tm_mon + 1;
    int ngayHienTai = hienTai.tm_mday;

    int tuoi = namHienTai - nam;

    // Nếu chưa tới sinh nhật trong năm nay → giảm 1 tuổi
    if (thangHienTai < thang ||
       (thangHienTai == thang && ngayHienTai < ngay)) {
        tuoi--;
    }

    return tuoi;
}
