// Gọi các thư viện vào ra chuẩn của C++
#include <stdio.h>
#include <iostream>
// Thư viện riêng cho hệ điều hành Windows
#include <windows.h>

// Các hàm chức năng
#include "QuanLy.cpp"

// Sử dụng không gian tên miền thư viện chuẩn
using namespace std;

int main() {
    string k;
    SetConsoleOutputCP(CP_UTF8);  // bật tiếng Việt
    vector<CongViec> DSCongViec;  // Khởi tạo biến cục bộ
    int menu;
    cout << "+-----------------------------------------------------------------------------------------------------------------------------------+\n";
    cout << "|         QUẢN LÝ CÔNG VIỆC NGƯỜI DÙNG                                                                                              |\n";  // tiêu đề
    while(true){
       
            cout << "+-----------------------------------------------------------------------------------------------------------------------------------+\n";
            cout << "| 1.Thêm | 2.Sửa | 3.Xoá | 4.Sắp Xếp | 5.Thống Kê | 6.Phân Loại | 7.Tìm Kiếm | 8.Ghi File | 9.Đọc file | 10.Xóa màn hình |  0.Thoát |\n";  // menu tính năng
            cout << "+-----------------------------------------------------------------------------------------------------------------------------------+\n";
            cout << "+>Nhập lựa chọn: ";
            menu = Menu(k);

            switch (menu) {
                case 1:
                    hamThem(DSCongViec);
                    break;
                case 2:
                    suaTheoYeuCau(DSCongViec);
                    break;
                case 3:
                    hamXoa(DSCongViec);
                    break;
                case 4:
                    hamSapXep(DSCongViec);
                    break;

                case 5:
                    hamThongKe(DSCongViec);
                    break;

                case 6:
                    hamPhanLoai(DSCongViec);
                    break;
                case 7:
                    hamTimKiem(DSCongViec);
                    break;
                case 8:
                    Ghi_file(DSCongViec);
                    break;
                case 9:
                    DOC_file(DSCongViec);
                    break;
                case 10:
                    system("cls");
                    break;
                case 0:
                    cout << "Tạm biệt!\n";
                    return 0;
                default:
                    cout << "Không có lựa chọn! Nhập lại theo Menu.\n";
        }
    }
}
