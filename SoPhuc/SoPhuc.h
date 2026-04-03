#pragma once
#include <iostream>

class SoPhuc {
private:
    double iThuc;
    double iAo;

public:
    SoPhuc();
    SoPhuc(double thuc, double ao);

    void Nhap();
    void Xuat();

    SoPhuc Tong(SoPhuc sp2);
    SoPhuc Hieu(SoPhuc sp2);
    SoPhuc Tich(SoPhuc sp2);
    SoPhuc Thuong(SoPhuc sp2);
};
