/*
Chương trình: Tính điểm trung bình của một học sinh
Đầu vào:
    - Ho ten
    - Diem Toan
    - Diem Van
Đầu ra:
    - Diem trung binh
*/
#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
    string hoTen;
    float diemToan;
    float diemVan;
};

/*
Hàm: tinhDiemTrungBinh
Chức năng: Tính điểm trung bình của học sinh
Đầu vào:
    - hs: một biến kiểu HocSinh
Đầu ra:
    - Điểm trung bình
*/
float tinhDiemTrungBinh(HocSinh hs) {
    return (hs.diemToan + hs.diemVan) / 2;
}

int main()
{
    HocSinh hs;

    cout << "Nhap ho ten: ";
    getline(cin, hs.hoTen);

    cout << "Nhap diem Toan: ";
    cin >> hs.diemToan;
    cout << "Nhap diem Van: ";
    cin >> hs.diemVan;

    cout << "Ho ten: " << hs.hoTen << endl;
    cout << "Diem trung binh: " << tinhDiemTrungBinh(hs);

    return 0;
}
