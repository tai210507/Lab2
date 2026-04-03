#include <iostream>
#include "GioPhutGiay.h"

using namespace std;

int main() {
    GioPhutGiay time;

    // Nhập thời gian
    time.Nhap();

    // In ra thời gian ban đầu
    cout << "\n=> Thoi gian ban dau: ";
    time.Xuat();
    cout << endl;

    // Cộng thêm 1 giây
    time.TongCongThemMotGiay();

    // In ra kết quả
    cout << "=> Sau khi cong 1s:   ";
    time.Xuat();
    cout << "\n-------------------------------------------" << endl;

    return 0;
}
