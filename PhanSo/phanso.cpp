#include "PhanSo.h"
#include <cmath>
using namespace std;


PhanSo::PhanSo() {
    iTu = 0;
    iMau = 1;
}

// Tìm UCLN
int PhanSo::UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return (a == 0) ? 1 : a;
}

// Hàm rút gọn phân số
void PhanSo::RutGon() {
    if (iTu == 0) {
        iMau = 1;
        return;
    }
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;

    // Đảm bảo dấu trừ luôn nằm ở tử số nếu có
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

void PhanSo::Nhap() {
    cout << "  Nhap tu so: "; cin >> iTu;
    do {
        cout << "  Nhap mau so (khac 0): "; cin >> iMau;
        if (iMau == 0) cout << "  => Mau so phai khac 0. Vui long nhap lai!\n";
    } while (iMau == 0);
    RutGon(); // Nhập xong rút gọn luôn
}

void PhanSo::Xuat() {
    if (iTu == 0) {
        cout << "0";
    } else if (iMau == 1) {
        cout << iTu; // Nếu mẫu là 1 thì chỉ in tử số (số nguyên)
    } else {
        cout << iTu << "/" << iMau;
    }
}

// (a/b) + (c/d) = (ad + bc) / bd
PhanSo PhanSo::TinhTong(PhanSo &a) {
    PhanSo kq;
    kq.iTu = this->iTu * a.iMau + a.iTu * this->iMau;
    kq.iMau = this->iMau * a.iMau;
    kq.RutGon();
    return kq;
}

// (a/b) - (c/d) = (ad - bc) / bd
PhanSo PhanSo::TinhHieu(PhanSo &a) {
    PhanSo kq;
    kq.iTu = this->iTu * a.iMau - a.iTu * this->iMau;
    kq.iMau = this->iMau * a.iMau;
    kq.RutGon();
    return kq;
}

// (a/b) * (c/d) = (ac) / (bd)
PhanSo PhanSo::TinhTich(PhanSo &a) {
    PhanSo kq;
    kq.iTu = this->iTu * a.iTu;
    kq.iMau = this->iMau * a.iMau;
    kq.RutGon();
    return kq;
}

// (a/b) / (c/d) = (ad) / (bc)
PhanSo PhanSo::TinhThuong(PhanSo &a) {
    PhanSo kq;
    if (a.iTu == 0) {
        cout << "\n[Loi] Khong the chia cho phan so 0! Tra ve phan so 0/1." << endl;
        kq.iTu = 0;
        kq.iMau = 1;
        return kq;
    }
    kq.iTu = this->iTu * a.iMau;
    kq.iMau = this->iMau * a.iTu;
    kq.RutGon();
    return kq;
}

// So sánh: Quy đồng (a*d và b*c) rồi so sánh tử
int PhanSo::SoSanh(PhanSo &a) {
    int val1 = this->iTu * a.iMau;
    int val2 = a.iTu * this->iMau;

    if (val1 > val2) return 1;       // Phân số hiện tại lớn hơn
    else if (val1 < val2) return -1; // Phân số hiện tại nhỏ hơn
    return 0;                        // Bằng nhau
}
