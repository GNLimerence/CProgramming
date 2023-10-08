#include <iostream>
#include <cmath>
using namespace std;

int n; 
int M[30][1000000]; 
int A[1000000]; 

// Hàm để tiền xử lý và xây dựng mảng M để thực hiện các truy vấn tìm giá trị nhỏ nhất trong khoảng
void preprocessing()
{
    // Khởi tạo M với giá trị -1
    for (int j = 0; (1 << j) <= n; j++)
    {
        for (int i = 0; i < n; i++)
            M[j][i] = -1;
    }

    // Khởi tạo M cho trường hợp cơ bản (kích thước khoảng 1)
    for (int i = 0; i < n; i++)
        M[0][i] = i;

    // Xây dựng M cho các khoảng lớn hơn bằng cách sử dụng quy hoạch động
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            // So sánh các phần tử trong hai nửa của khoảng
            if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]])
            {
                M[j][i] = M[j - 1][i]; // Lưu chỉ số của phần tử nhỏ nhất
            }
            else
            {
                M[j][i] = M[j - 1][i + (1 << (j - 1))]; // Lưu chỉ số của phần tử nhỏ nhất
            }
        }
    }
}

// Hàm để thực hiện truy vấn tìm giá trị nhỏ nhất trong khoảng trên mảng A
int rmq(int i, int j)
{
    int k = log2(j - i + 1); // Tính lũy thừa 2 cho kích thước khoảng
    int p2k = (1 << k); // Tính 2^k

    // So sánh các phần tử nhỏ nhất trong hai nửa của khoảng
    if (A[M[k][i]] <= A[M[k][j - p2k + 1]])
    {
        return M[k][i]; // Trả về chỉ số của phần tử nhỏ nhất
    }
    else
    {
        return M[k][j - p2k + 1]; // Trả về chỉ số của phần tử nhỏ nhất
    }
}

int main()
{
    cin >> n; // Đọc số phần tử trong mảng

    for (int i = 0; i < n; i++)
    {
        cin >> A[i]; // Đọc các phần tử của mảng A
    }

    preprocessing(); // Xây dựng mảng M để thực hiện các truy vấn tìm giá trị nhỏ nhất trong khoảng

    int ans = 0;
    int m;
    cin >> m; // Đọc số lượng truy vấn tìm giá trị nhỏ nhất

    // Thực hiện các truy vấn tìm giá trị nhỏ nhất và tích lũy các giá trị nhỏ nhất
    for (int i = 0; i < m; i++)
    {
        int I, J;
        cin >> I >> J; // Đọc chỉ số trái và phải của khoảng
        ans += A[rmq(I, J)]; // Cập nhật kết quả bằng cách cộng thêm giá trị nhỏ nhất trong khoảng
    }

    cout << ans; // In ra kết quả cuối cùng
    cout << endl;
    return 0;
}
