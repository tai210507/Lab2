#include "GioPhutGiay.h"
#include <iomanip> // Thư viện hỗ trợ định dạng in ấn (setw, setfill)
using namespace std;

void GioPhutGiay::Nhap() {

    cout << "  Nhap gio: "; cin >> iGio;
    cout << "  Nhap phut: "; cin >> iPhut;
    cout << "  Nhap giay: "; cin >> iGiay;
}

void GioPhutGiay::Xuat() {
    // Sử dụng setfill('0') và setw(2) để luôn in ra 2 chữ số
    cout << setfill('0') << setw(2) << iGio << ":"
         << setfill('0') << setw(2) << iPhut << ":"
         << setfill('0') << setw(2) << iGiay;
}

void GioPhutGiay::TongCongThemMotGiay() {
    iGiay++; // Cộng thêm 1 giây

    // Xử lý tràn giây
    if (iGiay >= 60) {
        iGiay = 0;
        iPhut++;

        // Xử lý tràn phút
        if (iPhut >= 60) {
            iPhut = 0;
            iGio++;

            // Xử lý tràn giờ (Qua ngày mới)
            if (iGio >= 24) {
                iGio = 0;
            }
        }
    }
}
