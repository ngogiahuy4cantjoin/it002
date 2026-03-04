#include <iostream>
#include <numeric>
#include <cstdlib>
using namespace std;

// bài tập 1

/*
Hàm: rutGonPhanSo
Chức năng: Rút gọn một phân số
Đầu vào:
    - tu: tử số (tham chiếu)
    - mau: mẫu số (tham chiếu)
Đầu ra:
    - Không trả về giá trị
    - Tử số và mẫu số được cập nhật sau khi rút gọn
*/
void rutGonPhanSo(int &tu, int &mau) {
    int ucln = gcd(abs(tu), abs(mau));
    tu /= ucln;
    mau /= ucln;

    // Chuẩn hoá: mẫu số luôn dương
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}


int main()
{
    int tu_1, mau_1, tu_2, mau_2;
    cin >> tu_1 >> mau_1;
    cin >> tu_2 >> mau_2;
     // Kiểm tra mẫu số hợp lệ
    if (mau_1 == 0 || mau_2 == 0)
    {
        cout << "Mau so phai khac 0";
        return 0;
    }
    // Rút gọn hai phân số
    rutGonPhanSo(tu_1, mau_1);
    rutGonPhanSo(tu_2, mau_2);
    cout << "Phan so 1: " << tu_1 << "/" << mau_1 << endl;
    cout << "Phan so 2: " << tu_2 << "/" << mau_2 << endl;

    // bài tập 2

    // So sánh hai phân số
    if (tu_1 * mau_2 > tu_2 * mau_1) {
        cout << "Phan so lon nhat la: " << tu_1 << "/" << mau_1 << endl;
    } else if (tu_1 * mau_2 < tu_2 * mau_1) {
        cout << "Phan so lon nhat la: " << tu_2 << "/" << mau_2 << endl;
    } else {
        cout << "Hai phan so bang nhau: "
             << tu_1 << "/" << mau_1 << endl;
    }

    // bài tập 3

    // ===== TÍNH TỔNG =====
    int tu_tong = tu_1 * mau_2 + tu_2 * mau_1;
    int mau_tong = mau_1 * mau_2;
    rutGonPhanSo(tu_tong, mau_tong);

    // ===== TÍNH HIỆU =====
    int tu_hieu = tu_1 * mau_2 - tu_2 * mau_1;
    int mau_hieu = mau_1 * mau_2;
    rutGonPhanSo(tu_hieu, mau_hieu);

    // ===== TÍNH TÍCH =====
    int tu_tich = tu_1 * tu_2;
    int mau_tich = mau_1 * mau_2;
    rutGonPhanSo(tu_tich, mau_tich);

    // ===== TÍNH THƯƠNG =====
    if (tu_2 == 0) {
        cout << "Khong the chia cho phan so co tu = 0";
        return 0;
    }
    int tu_thuong = tu_1 * mau_2;
    int mau_thuong = mau_1 * tu_2;
    rutGonPhanSo(tu_thuong, mau_thuong);

    // ===== XUẤT KẾT QUẢ =====
    cout << "Tong: " << tu_tong << "/" << mau_tong << endl;
    cout << "Hieu: " << tu_hieu << "/" << mau_hieu << endl;
    cout << "Tich: " << tu_tich << "/" << mau_tich << endl;
    cout << "Thuong: " << tu_thuong << "/" << mau_thuong << endl;


    return 0;
}
