#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() {
    PhanSo ps1, ps2;

    cout << "\n[Nhap Phan So 1]" << endl;
    ps1.Nhap();

    cout << "\n[Nhap Phan So 2]" << endl;
    ps2.Nhap();

    cout << "\n--------------------------------------" << endl;
    cout << "Phan so 1 (da rut gon): "; ps1.Xuat(); cout << endl;
    cout << "Phan so 2 (da rut gon): "; ps2.Xuat(); cout << endl;
    cout << "--------------------------------------" << endl;

    // Tính toán
    PhanSo tong = ps1.TinhTong(ps2);
    PhanSo hieu = ps1.TinhHieu(ps2);
    PhanSo tich = ps1.TinhTich(ps2);
    PhanSo thuong = ps1.TinhThuong(ps2);

    // Xuất kết quả các phép tính
    cout << "+ Tong 2 phan so: "; tong.Xuat(); cout << endl;
    cout << "+ Hieu 2 phan so: "; hieu.Xuat(); cout << endl;
    cout << "+ Tich 2 phan so: "; tich.Xuat(); cout << endl;
    cout << "+ Thuong 2 phan so: "; thuong.Xuat(); cout << endl;

    // So sánh
    int ketQuaSoSanh = ps1.SoSanh(ps2);
    cout << "+ Ket qua so sanh: ";
    if (ketQuaSoSanh == 1) {
        cout << "Phan so 1 LON HON Phan so 2" << endl;
    } else if (ketQuaSoSanh == -1) {
        cout << "Phan so 1 NHO HON Phan so 2" << endl;
    } else {
        cout << "Phan so 1 BANG Phan so 2" << endl;
    }

    return 0;
}
