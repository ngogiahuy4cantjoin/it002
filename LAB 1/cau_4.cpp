#include <iostream>

using namespace std;

/*
Hàm: laNamNhuan
Chức năng: Kiểm tra một năm có phải năm nhuận hay không
Đầu vào:
    - nam: số nguyên biểu diễn năm
Đầu ra:
    - true nếu là năm nhuận
    - false nếu không phải
*/
bool laNamNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/*
Hàm: soNgayTrongThang
Chức năng: Trả về số ngày trong một tháng cụ thể của một năm
Đầu vào:
    - thang: tháng (1–12)
    - nam: năm
Đầu ra:
    - Số ngày trong tháng
*/
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (laNamNhuan(nam))
                return 29;
            return 28;
        default:
            return 0;
    }
}
int main()
{
    int ngay, thang, nam;
    cin >> ngay >> thang >> nam;

        // Kiểm tra dữ liệu hợp lệ
    int maxNgay = soNgayTrongThang(thang, nam);
    if (thang < 1 || thang > 12 || ngay < 1 || ngay > maxNgay) {
        cout << "Ngay thang nam khong hop le";
        return 0;
    }

    // Tìm ngày kế tiếp
    ngay ++;
    if (ngay > maxNgay)
    {
        thang++;
        ngay = 1;
        if (thang > 12)
        {
            thang = 1;
            nam++;
        }
    }
    cout << ngay << "/"<<thang<<"/"<<nam;
    return 0;
}
