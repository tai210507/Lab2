#pragma once
#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

    bool LaNamNhuan(int nam);
    int SoNgayTrongThang(int thang, int nam);

public:
    void Nhap();
    void Xuat();
    void NgayThangNamTiepTheo();
};
