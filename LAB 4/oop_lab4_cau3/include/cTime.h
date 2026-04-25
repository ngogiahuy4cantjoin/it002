#ifndef CTIME_H
#define CTIME_H

#include <iostream>
using namespace std;

class CTime {
private:
    int gio;
    int phut;
    int giay;

public:
    /*
    INPUT:
    - gio, phut, giay

    OUTPUT:
    - Tao doi tuong thoi gian

    ALGORITHM:
    1. Gan gia tri mac dinh = 0
    2. Chuan hoa lai thoi gian
    */
    CTime(int = 0, int = 0, int = 0);

    /*
    INPUT:
    - gio, phut, giay moi

    OUTPUT:
    - Cap nhat lai thoi gian

    ALGORITHM:
    1. Gan lai gia tri
    2. Chuan hoa
    */
    void ThietLap(int, int, int);

    /*
    INPUT:
    - Thoi gian hien tai

    OUTPUT:
    - Dua ve dang hop le
      0 <= gio < 24
      0 <= phut < 60
      0 <= giay < 60

    ALGORITHM:
    1. Quy doi tong so giay
    2. Dua tong giay ve 1 ngay
    3. Tach lai gio phut giay
    */
    void ChuanHoa();

    /*
    INPUT:
    - so giay can cong

    OUTPUT:
    - Thoi gian moi sau khi cong
    */
    CTime operator + (int);

    /*
    INPUT:
    - so giay can tru

    OUTPUT:
    - Thoi gian moi sau khi tru
    */
    CTime operator - (int);

    /*
    INPUT:
    - ++t

    OUTPUT:
    - Tang 1 giay, tra ve chinh no
    */
    CTime& operator ++ ();

    /*
    INPUT:
    - t++

    OUTPUT:
    - Tra ve gia tri cu, sau do tang 1 giay
    */
    CTime operator ++ (int);

    /*
    INPUT:
    - --t

    OUTPUT:
    - Giam 1 giay, tra ve chinh no
    */
    CTime& operator -- ();

    /*
    INPUT:
    - t--

    OUTPUT:
    - Tra ve gia tri cu, sau do giam 1 giay
    */
    CTime operator -- (int);

    /*
    INPUT:
    - doi tuong CTime

    OUTPUT:
    - In dang hh:mm:ss
    */
    friend ostream& operator << (ostream&, const CTime&);

    /*
    INPUT:
    - Ban phim

    OUTPUT:
    - Nhap gio phut giay hop le
    */
    friend istream& operator >> (istream&, CTime&);
};

#endif
