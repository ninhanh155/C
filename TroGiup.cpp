#include <string>
#include <stdio.h>
#include <iostream>  // gọi các thư viện chuẩn của c++
#include <vector>
using namespace std;
int nhap_ID(string &x) 
{//hàm định dạng số nguyên
    int kt;
    do {
        kt = 1;
        fflush(stdin);
        getline(cin, x);
        for (int i = 0; i < x.length(); i++) {
            if ((int)x[i] < 48 || (int)x[i] > 57) {
                kt = 0;
                cout << "->Lỗi! Nhập lại\n" ;
                cout << "- Nhập ID công việc: ";
                break;
            }
        }
    } while (kt == 0 || x == "\0");
    int v = atoi(x.c_str());
    return v;
}
double nhap_trong_so(string &x) 
{//hàm định dạng số thực
    int  kt;
    do {
        kt = 1;
        fflush(stdin);
        getline(cin, x);
        for (double i = 0; i < x.length(); i++) {
            if ((double)x[i] < 48 || (double)x[i] > 57) {  // trong mã ASKII 1 = 48 ; 0 = 57
                kt = 0;
                cout << "->Lỗi! Nhập lại\n";
                cout << "- Nhập trọng số công việc: ";
                break;
            }
        }
    } while (kt == 0 || x == "\0");
    double v = atof(x.c_str());// thay thế x = v
    return v;
}
int Menu(string &x) {  // hàm định dạng số nguyên
    int kt;
    do {
        kt = 1;
        fflush(stdin);
        getline(cin, x);
        for (int i = 0; i < x.length(); i++) {
            if ((int)x[i] < 48 || (int)x[i] > 57) {
                kt = 0;
                cout << "->Lỗi! Nhập lại" << endl;
                cout << "Nhập lựa chọn: ";
                break;
            }
        }
    } while (kt == 0 || x == "\0");
    int v = atoi(x.c_str());
    return v;
}
int Deline(string &x) {  // hàm định dạng số nguyên
    int kt;
    do {
        kt = 1;
        fflush(stdin);
        getline(cin, x);
        for (int i = 0; i < x.length(); i++) {
            if ((int)x[i] < 48 || (int)x[i] > 57) {
                kt = 0;
                cout << "->Lỗi! Nhập lại" << endl;
                cout << "Nhập Deline: ";
                break;
            }
        }
    } while (kt == 0 || x == "\0");
    int v = atoi(x.c_str());
    return v;
}
int sl(string &x) {  // hàm định dạng số nguyên
    int kt;
    do {
        kt = 1;
        fflush(stdin);
        getline(cin, x);
        for (int i = 0; i < x.length(); i++) {
            if ((int)x[i] < 48 || (int)x[i] > 57) {
                kt = 0;
                cout << "->Lỗi! Nhập lại" << endl;
                cout << "Nhập số lượng công việc: ";
                break;
            }
        }
    } while (kt == 0 || x == "\0");
    int v = atoi(x.c_str());
    return v;
}
int nameExsist(const vector<CongViec> &DSCongViec, string ten) 
{
    for (int i = 0; i < DSCongViec.size(); i++) 
    {// duyệt vòng lặp for . sử dụng hàm compare để so sánh 
        if (ten.compare(DSCongViec[i].ten) == 0) 
        {// nếu trùng vs tên đã có trong danh sách thì trả về vị trí
            return i;
        }
    }// ngược lại trả về gtri ban đầu đã gán 
    return -1;
}

int idExsist(vector<CongViec> &DSCongViec, int id) {
    for (int i = 0; i < DSCongViec.size(); i++) {
        if (DSCongViec[i].id == id) {
            return i;
        }
    }
    return -1;
}