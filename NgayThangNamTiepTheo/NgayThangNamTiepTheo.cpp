#include "NgayThangNamTiepTheo.h"
using namespace std;

// Kiểm tra năm nhuận
bool NgayThangNam::LaNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

// Lấy số ngày tối đa của tháng hiện tại
int NgayThangNam::SoNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return LaNamNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}

void NgayThangNam::Nhap() {
    cout << "Nhap ngay: "; cin >> iNgay;
    cout << "Nhap thang: "; cin >> iThang;
    cout << "Nhap nam: "; cin >> iNam;
}

void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam;
}

void NgayThangNam::NgayThangNamTiepTheo() {
    int maxNgay = SoNgayTrongThang(iThang, iNam);

    if (iNgay < maxNgay) {
        // Nếu chưa đến ngày cuối tháng thì chỉ việc tăng ngày
        iNgay++;
    } else {
        // Nếu là ngày cuối tháng, reset ngày về 1
        iNgay = 1;
        if (iThang < 12) {
            // Chưa đến tháng 12 thì tăng tháng
            iThang++;
        } else {
            // Tháng 12 thì reset tháng về 1 và tăng năm
            iThang = 1;
            iNam++;
        }
    }
}
