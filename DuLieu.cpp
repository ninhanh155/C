#include <algorithm>
#include <string>
#include <vector>
// vì nó thể tự động tăng kích thước nên cho mỗi giá trị mới
using namespace std;

/* Cấu trúc dữ liệu */
struct CongViec {//gán giá trị
    int id ;             // id công việc
    string ten;         // tên công việc
    double trongso;     // trọng số đánh giá mức độ quan trọng của công việc
    bool hoanthanh;  // kiểm tra xem công việc hoàn thành chưa
    // biến phái sinh
    string hoanthanh_text ;  // kiểm tra đúng sai
    int Deline;
};
