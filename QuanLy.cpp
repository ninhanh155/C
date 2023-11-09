// gọi các thư viện chuẩn của c++
#include <stdio.h>
#include <iostream>  
#include <iomanip>
#include<string.h> 
 
#include <fstream>// dÙnG Đọc file
#include <vector>
// không gian hàm chức năg
#include "DuLieu.cpp"
#include "TroGiup.cpp"

void hamHienCot() {
    cout << "+-----------------------------------------------------------------------------------------------+\n";
    cout << "| STT |   ID  |      Tên công việc     |      Trọng số      |   Deline   | Trạng thái công việc |\n";
    cout << "+-----------------------------------------------------------------------------------------------+\n";
}

void hamHienDong(int stt, CongViec congviec) {
    cout << "| " << setw(3) << stt;
    cout << " | " << setw(5) << congviec.id << " | ";         
    cout << setw(22) << congviec.ten.c_str() << " | ";       
    cout << setw(18) << congviec.trongso << " | "; 
    cout << setw(6) << congviec.Deline << " (h) |";
    if(congviec.hoanthanh == 1)
    {
        cout << setw(25) << "Đã hoàn thành"<<" | ";
    }
    else
    {
        cout << setw(24) << "Chưa hoàn thành"<<" | ";
    }
    
    cout << "\n+-----------------------------------------------------------------------------------------------+\n";
}

void hamHienBang(const vector<CongViec> &DSCongViec) {
    hamHienCot();
    for (int i = 0; i < DSCongViec.size(); i++) {
        hamHienDong(i + 1, DSCongViec[i]);
    }
}

void hamThem(vector<CongViec> &DSCongViec) {
    CongViec congviec;
    string k;
    int n;
    do {
        cout << "- Nhập số lượng công việc: ";
        n = sl(k);
        if (n > 999 || n <= 0) {
            cout << "-> Lỗi! Nhập lại................\n";
        }
    } while (n > 999 || n <= 0);
    for (int i = 0; i < n;i++)
    {
        do {
            cout << "- Nhập ID công việc: ";
            congviec.id = nhap_ID(k);
            if ((idExsist(DSCongViec, congviec.id) != -1) || congviec.id > 999) {
                cout << "-> Lỗi! Nhập lại................\n";
            }
        } while ((idExsist(DSCongViec, congviec.id) != -1) || congviec.id > 999);

        do {
            cout << "- Tên công việc: ";
            getline(cin, congviec.ten);
            if (nameExsist(DSCongViec, congviec.ten) != -1)
            {
                cout << "-> Lỗi! Nhập lại.................\n";
            }
        } while (nameExsist(DSCongViec, congviec.ten) != -1);
        
        do
        {
            cout << "- Nhập trọng số công việc: ";
            congviec.trongso = nhap_trong_so(k);
            if(congviec.trongso > 1000000)
            {
                cout<<"-> Lỗi! Nhập lại........\n";
            }
        } while (congviec.trongso > 1000000);

        do {
                cout << "- Nhập Deline: ";
                congviec.Deline = Deline(k);
                if (congviec.Deline > 999) {
                    cout << "-> Lỗi! Nhập lại................\n";
                }
        } while (congviec.Deline > 999);

        string option;
        do {
            cout << "- Công việc đã hoàn thành chưa?(1/0): ";
            cin >> option;
        } while (option != "1" && option != "0");

        congviec.hoanthanh = option == "1";

        congviec.hoanthanh_text = congviec.hoanthanh ? "Đã hoàn thành" : "Chưa hoàn thành";
        DSCongViec.push_back(congviec);  // hàm đẩy phần tử mới thêm vào sau phần tử cũ
        
    }cout << "\n\t=> Thêm công việc thành công!\n";
        hamHienBang(DSCongViec);
    
}

void suaTheoYeuCau(vector<CongViec> &DSCongViec) { // sửa công việc theo ID
    int ID;
    CongViec congviec;
    hamHienBang(DSCongViec);
    string k;// thay thế x
        cout << "- Nhập ID công việc: ";
        ID = nhap_ID(k);

    int index = idExsist(DSCongViec, ID);// vị trí cv = biến ktra id cv xem có trùng vs công việc đã có sẵn
    if (index == -1) // ktra xem biến đã đc khỏi tạo chưa
    {// nếu index = -1 thì biến chưa đc khỏi tạo
        cout << "=> Công việc có id " << ID << " không tồn tại\n";
        return;
    }

    string name;

    do 
    {
        cout << "- Tên công việc: ";
        getline(cin, name);
        //hàm Kiểm tra trùng lặp tên công việc chạy đến khi tên công việc 0 trùng với tên đã có
        if (nameExsist(DSCongViec, congviec.ten) != -1) {
            cout << "-> Lỗi! Nhập lại........\n";
        }
    } while (nameExsist(DSCongViec, name) != -1);

    DSCongViec[index].ten = name;// cập nhật tên công việc sau sửa

    do {
        cout << "- Nhập trọng số công việc: ";
        DSCongViec[index].trongso = nhap_trong_so(k);
        if (DSCongViec[index].trongso > 1000000)
        {
            cout << "-> Lỗi! Nhập lại........\n";
        }
    } while (DSCongViec[index].trongso > 1000000);
    do {
            cout << "- Nhập Deline: ";
            DSCongViec[index].Deline = Deline(k);
            if (DSCongViec[index].Deline > 999) {
                cout << "-> Lỗi! Nhập lại................\n";
            }
    } while (DSCongViec[index].Deline > 999);

    string option;
    do 
    {
        cout << "- Công việc đã hoàn thành chưa?(1/0): ";
        cin >> option;
    } while (option != "1" && option != "0");

    DSCongViec[index].hoanthanh = option == "1";

    DSCongViec[index].hoanthanh_text = DSCongViec[index].hoanthanh ? "Đã hoàn thành" : "Chưa hoàn thành";

   
    hamHienBang(DSCongViec);
    cout << "\n\t=> Cập nhật thông tin cho công việc thành công\n";
}

void hamXoa(vector<CongViec> &DSCongViec) { // xóa công việc theo ID
    hamHienBang(DSCongViec);  // Hiển thị lại bảng trước khi xoá
    int ID;
    string k;
        cout << "- Nhập ID công việc: ";
        ID = nhap_ID(k);

    if (idExsist(DSCongViec, ID) == -1)  // kiểm tra id có trùng vs ID cần xóa 0
    {// nếu k có thì 
        cout << "\n=> Công việc có id " << ID << " không tồn tại\n";
       
    }
    else
    {// ngược lại
    //  duyệt vòng lặp for, sử dụng con trỏ của vecter trỏ đến phần tử đầu tiên và tiếp tục tăng nên cho đến phần tử cuối
          for (vector<CongViec>:: iterator it = DSCongViec.begin(); it != DSCongViec.end(); it++) 
            if (it->id == ID) // gọi it(iterator)
            {// nếu trùng vs id cần xóa thì dùng 
                DSCongViec.erase(it);
                break;
                // hàm xóa phần tử tùy ý theo vị trí  
            }

        hamHienBang(DSCongViec);
        cout << "\n\t=> Công việc có id " << ID << " đã được xóa thành công\n";
    }
    
     
}

void hamSapXep(vector<CongViec> &DSCongViec) 
{// sắp xếp giảm dần theo trọng số
    int kt = 0;
    // sắp xếp theo kiểu interchange sort
    for (int i = 0; i < DSCongViec.size(); i++) {
        for (int j = i + 1; j < DSCongViec.size(); j++) {
            if (DSCongViec[i].trongso < DSCongViec[j].trongso) {
                
                CongViec temp = DSCongViec[i];
                DSCongViec[i] = DSCongViec[j];
                DSCongViec[j] = temp;
                kt = 1;
            }
        }
    }
    
    if(kt == 0)
    {
        cout << "\n=> Số lượng công việc không đủ để sắp xếp\n";
    }
    else
    {
        cout << "-> Danh sách công việc sau khi sắp xếp\n";
        hamHienBang(DSCongViec);
        cout << "\n=>Sắp xếp công việc thành công!\n";
    }
}
void hamMax(vector<CongViec> & DSCongViec) { // thống kê theo trọng số max
    // hàm kiểm tra trọng số lớn nhất
    // trọng số , vị trí & biến kiểm tra công việc đã làm
    double MaxFinished;
    bool CheckFinished = 0;
    int vt, vt1;
    // công việc chưa làm
    double MaxUnfinished;
    bool CheckUnfinished = 0;
    // duyệt vòng lặp for
    for (int i = 0; i < DSCongViec.size(); i++)
        if (DSCongViec[i].hoanthanh) {
            MaxFinished = DSCongViec[i].trongso;
            CheckFinished = 1;
            vt = i;
            break;
        }
    for (int i = 0; i < DSCongViec.size(); i++)
        if (!DSCongViec[i].hoanthanh) {
            MaxUnfinished = DSCongViec[i].trongso;
            CheckUnfinished = 1;
            vt1 = i;
            break;
        }
    cout << "- Công việc có trọng số max: \n";
    if (!CheckFinished) {
        cout << "\t+,Đã hoàn thành: Không có\n";
    } else {
        for (int i = vt; i < DSCongViec.size(); i++) {
            if (DSCongViec[i].hoanthanh) {
                if (DSCongViec[i].trongso >= MaxFinished) {
                    MaxFinished = DSCongViec[i].trongso;
                }
            }
        }
        cout << "\t+,Đã hoàn thành: " << MaxFinished << "\n";
    }
    if (!CheckUnfinished)
        cout << "\t+,Chưa hoàn thành: Không có\n";
    else {
        for (int i = vt1; i < DSCongViec.size(); i++) {
            if (!DSCongViec[i].hoanthanh) {
                if (DSCongViec[i].trongso >= MaxUnfinished) {
                    MaxUnfinished = DSCongViec[i].trongso;
                }
            }
        }
        cout << "\t+,Chưa hoàn thành: " << MaxUnfinished << "\n";
    }
}
void hamMin(vector<CongViec> & DSCongViec) { // thống kê theo trọng số min
    double MinFinised;
    bool CheckFinished = 0;
    int vt, vt1;
    // gọi trọng số ,vị trí & kiểm tra công việc chưa làm
    double MinUnfinished;
    bool CheckUnfinished = 0;
    // duyệt vòng lặp for
    for (int i = 0; i < DSCongViec.size(); i++)
        if (DSCongViec[i].hoanthanh) {
            MinFinised = DSCongViec[i].trongso;
            CheckFinished = 1;
            vt = i;
            break;
        }
    for (int i = 0; i < DSCongViec.size(); i++)
        if (!DSCongViec[i].hoanthanh) {
            MinUnfinished = DSCongViec[i].trongso;
            CheckUnfinished = 1;
            vt1 = i;
            break;
        }
    cout << "- Công việc có trọng số max: \n";
    if (!CheckFinished) {
        cout << "\t+,Đã hoàn thành: Không có\n";
    } else {
        for (int i = vt; i < DSCongViec.size(); i++) {
            if (DSCongViec[i].hoanthanh) {
                if (DSCongViec[i].trongso <= MinFinised) {
                    MinFinised = DSCongViec[i].trongso;
                }
            }
        }
        cout << "\t+,Đã hoàn thành: " << MinFinised << "\n";
    }
    if (!CheckUnfinished)
        cout << "\t+,Chưa hoàn thành: Không có\n";
    else {
        for (int i = vt1; i < DSCongViec.size(); i++) {
            if (!DSCongViec[i].hoanthanh) {
                if (DSCongViec[i].trongso <= MinUnfinished) {
                    MinUnfinished = DSCongViec[i].trongso;
                }
            }
        }
        cout << "\t+,Chưa hoàn thành: " << MinUnfinished << "\n";
    }
}

void hamThongKe(vector<CongViec> & DSCongViec) { // danh sách thống kê
    hamHienBang(DSCongViec);
    int luachon;
    string k;
    do {
        cout << "\n+---------------------------------------------+\n";
        cout << "| 1.Trọng số Max | 2. Trọng số Min | 0. Thoát |\n";
        cout << "+---------------------------------------------+\n";
        cout << " Nhập lựa chọn: ";

        luachon = Menu(k);
        switch (luachon) {
            case 1:
                hamMax(DSCongViec);
                break;
            case 2:
                hamMin(DSCongViec);
                break;
            case 0:
                break;
        }
    } while (luachon != 0);
}
void hamPhanLoai(vector<CongViec> & DSCongViec) {// theo trọng số
    hamHienBang(DSCongViec);
    int Dem = 0;
    int d = 0;
    for (int i = 0; i < DSCongViec.size(); i++) {
        if (DSCongViec[i].hoanthanh) {
            Dem++;
        } 
        else {
            d++;
        }
    }
    cout << "- Tổng số công việc: " << Dem + d << endl;

    if (Dem > 0) {
        hamHienCot();
        for (int i = 0; i < DSCongViec.size(); i++) {
            if(DSCongViec[i].hoanthanh)
                hamHienDong(i + 1, DSCongViec[i]);
        }
        cout << "\n- Tổng số công việc đã hoàn thành: " << Dem << endl;
    }
    else{
        cout << "\n=> Không có công việc nào đã hoàn thành\n";
    }
    
    if (d > 0) {
        hamHienCot();
        for (int i = 0; i < DSCongViec.size(); i++) {
            if (DSCongViec[i].hoanthanh == 0)
                hamHienDong(i + 1, DSCongViec[i]);
        }
        cout << "\n- Tổng số công việc chưa hoàn thành: " << d << endl;
    } else {
        cout << "\n=> Không có công việc nào chưa hoàn thành\n";
    }
}
void TimID(vector<CongViec> & DSCongViec) { // tìm kiếm theo ID
    fflush(stdin);
    int ID;
    string k;
    cout << "- Nhập ID công việc: ";
    ID = nhap_ID(k);
    int dem = 0;

    for (int i = 0; i < DSCongViec.size(); i++) {
        if (DSCongViec[i].id == ID) {
            hamHienCot();
            hamHienDong(i + 1, DSCongViec[i]);
            dem++;
        }
    }

    if (dem > 0)
        cout << "\n=> Công việc có id: " << ID << " đã tìm thấy\n";
    else
        cout << "\n=> Không tìm thấy id công việc cần tìm \n";
}
void TrangThai(vector<CongViec> & DSCongViec) {// tìm kiếm theo trạng thái công việc
    int trangthai;
    int dem = 0;
    do{
        cout << "- Trạng thái công việc?(1/0): ";
        cin >> trangthai;
        if (trangthai != 1 && trangthai != 0)
        {
            cout << "\t=> Không có trạng thái công việc cần tìm! Yêu cầu nhập lại.\n";
        }
    } while (trangthai != 1 && trangthai != 0);
    if(trangthai == 1)
    {
        for (int i = 0; i < DSCongViec.size(); i++) {
            if(DSCongViec[i].hoanthanh == true) 
            {
                dem++;
            }
        }
    
        if(dem > 0)
        {
            hamHienCot();
            for (int i = 0; i < DSCongViec.size(); i++) {
                if (DSCongViec[i].hoanthanh == true) {
                    hamHienDong(i + 1, DSCongViec[i]);
                }
            }
            cout << "\n=> Công việc đã hoàn thành đã tìm thấy\n";

        }
        else
        {
            cout << "\n=> Không có công việc nào đã hoàn thành\n";
        }
    }
    
    else{int d = 0;
        for (int i = 0; i < DSCongViec.size(); i++) {
            if (DSCongViec[i].hoanthanh == false) {
                d++;
            }
        }
    
        if (d > 0) {
            hamHienCot();
            for (int i = 0; i < DSCongViec.size(); i++) {
                if (DSCongViec[i].hoanthanh == false) {
                    hamHienDong(i + 1, DSCongViec[i]);
                }
            }
            cout << "\n=> Công việc chưa hoàn thành đã tìm thấy\n";

        } else {
            cout << "\n=> Không có công việc nào chưa hoàn thành\n";
        }
    }
}
void Ten(vector<CongViec> &DSCongViec) { // tìm kiếm theo tên
    fflush(stdin);
    string Ten;
    cout << "nhập tên công việc cần tìm: ";
    cin >> Ten;
    int dem = 0;
    for (int i = 0; i < DSCongViec.size(); i++) {
        
        if (DSCongViec[i].ten == Ten) {
            hamHienCot();
            hamHienDong(i + 1, DSCongViec[i]);
            dem++;
        }
    }

    if (dem > 0)
        cout << "\n=> Công việc có tên " << Ten << " đã tìm thấy\n";
    else
        cout << "\n=> Không tìm thấy tên công việc này \n";
}
void hamTimKiem(vector<CongViec> &DSCongViec) { // danh sách tính năng tìm kiếm
    int luachon;
    string k;
    do {
        cout << "\n+----------------------------------------------------+\n";
        cout << "| 1.ID | 2. Trạng Thái Công việc | 3. Tên | 0. Thoát |\n";
        cout << "+----------------------------------------------------+\n";
        cout << " Nhập lựa chọn: ";

        luachon = Menu(k);
        switch (luachon) {
            case 1:
                TimID(DSCongViec);
                break;
            case 2:
                TrangThai(DSCongViec);
                break;
            case 3:
                Ten(DSCongViec);
                break;
            case 0:
                break;
        }
    } while (luachon != 0);
}

void Ghi_file(vector<CongViec> & DSCongViec) { // ghi lại file
    // mở file
    ofstream write("data.txt");  // write = cout

    for (int i = 0; i < DSCongViec.size(); i++) {
        write << "ID công việc: " << DSCongViec[i].id << "\n";
        write << "Tên công việc: " << DSCongViec[i].ten << "\n";
        write << "Trọng số công việc: " << DSCongViec[i].trongso << "\n";
        write << "Deline: " << DSCongViec[i].Deline << "\n";
        write << "Trạng thái công việc: " << DSCongViec[i].hoanthanh << "\n";
    }
    cout << "=> Ghi File thành công. . . . . . \n";
    write.close();  // đóng file
}
void DOC_file(vector<CongViec> & DSCongViec) { // mở file có sẵn
    ifstream file;                          // goi file để đọc
    file.open("./data.txt", ios_base::in);  // địa chỉ lưu file ,

    if (file.fail() == true)  // kta xem file tồn tại
    {
        cout << "=> File không tồn tại\n";
        return;
    }
    CongViec tam;  // biến tự định nghĩa lưu tạm
    int i = 0;
    int luu;
    while (file.eof() != true)  // nếu file 0 rỗng
    {
        string k;               // dùng k để lưu chuỗi trước dấu :
        getline(file, k, ':');  // gọi file , lưu ở k , đọc đến dấu :
        file >> luu;            // đọc đằng sau dấu :

        tam.id = luu;  // id = gtri đã đọc sau :

        getline(file, k, ':');

        getline(file, k);  // lưu chuỗi sau :

        tam.ten = k;

        getline(file, k, ':');
        file >> luu;

        tam.trongso = luu;

        bool h;
        // kiểm tra mức độ hoàn thành
        getline(file, k, ':');
        file >> h;

        tam.hoanthanh = h;

        getline(file, k, ':');  // gọi file , lưu ở k , đọc đến dấu :
        file >> luu;            // đọc đằng sau dấu :

        tam.Deline = luu;  // deline = gtri đã đọc sau :

        DSCongViec.push_back(tam);  // đẩy vào ds công việc
    }
    cout << "=> Đọc File Thành Công..........\n";
}