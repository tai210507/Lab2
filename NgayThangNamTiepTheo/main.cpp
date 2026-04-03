#include <iostream>
#include "NgayThangNamTiepTheo.h"

using namespace std;

int main() {
    NgayThangNam date;

    // Yêu cầu người dùng nhập ngày, tháng, năm
    date.Nhap();

    // In ra ngày vừa nhập
    cout << "\n=> Ngay ban dau: ";
    date.Xuat();
    cout << endl;

    // Tính toán ngày tiếp theo
    date.NgayThangNamTiepTheo();

    // In ra kết quả
    cout << "=> Ngay tiep theo: ";
    date.Xuat();
    cout << endl;

    return 0;
}
