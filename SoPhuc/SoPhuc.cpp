#include "SoPhuc.h"
#include <cmath>
using namespace std;

SoPhuc::SoPhuc() {
    iThuc = 0;
    iAo = 0;
}

SoPhuc::SoPhuc(double thuc, double ao) {
    iThuc = thuc;
    iAo = ao;
}

void SoPhuc::Nhap() {
    cout << "  Nhap phan thuc: "; cin >> iThuc;
    cout << "  Nhap phan ao: "; cin >> iAo;
}

// Xử lý in ấn cho giống với định dạng toán học
void SoPhuc::Xuat() {
    if (iThuc == 0 && iAo == 0) {
        cout << "0";
    } else if (iThuc == 0) {
        cout << iAo << "i";
    } else if (iAo == 0) {
        cout << iThuc;
    } else {
        cout << iThuc << (iAo > 0 ? " + " : " - ") << abs(iAo) << "i";
    }
}

// (a + bi) + (c + di) = (a + c) + (b + d)i
SoPhuc SoPhuc::Tong(SoPhuc sp2) {
    SoPhuc kq;
    kq.iThuc = this->iThuc + sp2.iThuc;
    kq.iAo = this->iAo + sp2.iAo;
    return kq;
}

// (a + bi) - (c + di) = (a - c) + (b - d)i
SoPhuc SoPhuc::Hieu(SoPhuc sp2) {
    SoPhuc kq;
    kq.iThuc = this->iThuc - sp2.iThuc;
    kq.iAo = this->iAo - sp2.iAo;
    return kq;
}

// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::Tich(SoPhuc sp2) {
    SoPhuc kq;
    kq.iThuc = (this->iThuc * sp2.iThuc) - (this->iAo * sp2.iAo);
    kq.iAo = (this->iThuc * sp2.iAo) + (this->iAo * sp2.iThuc);
    return kq;
}

// Phép chia số phức
SoPhuc SoPhuc::Thuong(SoPhuc sp2) {
    SoPhuc kq;
    double mauChung = (sp2.iThuc * sp2.iThuc) + (sp2.iAo * sp2.iAo);

    if (mauChung == 0) {
        cout << " [Loi chia cho 0] " << endl; // Không thể chia cho số phức 0
        return kq;
    }

    kq.iThuc = (this->iThuc * sp2.iThuc + this->iAo * sp2.iAo) / mauChung;
    kq.iAo = (this->iAo * sp2.iThuc - this->iThuc * sp2.iAo) / mauChung;
    return kq;
}
