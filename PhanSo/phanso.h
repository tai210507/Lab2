#pragma once
#include <iostream>

class PhanSo {
private:
    int iTu;
    int iMau;

    // Hàm phụ trợ tìm Ước chung lớn nhất để phục vụ cho việc rút gọn
    int UCLN(int a, int b);

public:
    PhanSo();

    void Nhap();
    void Xuat();
    void RutGon();
    PhanSo TinhTong(PhanSo &a);
    PhanSo TinhHieu(PhanSo &a);
    PhanSo TinhTich(PhanSo &a);
    PhanSo TinhThuong(PhanSo &a);
    int SoSanh(PhanSo &a);
};
