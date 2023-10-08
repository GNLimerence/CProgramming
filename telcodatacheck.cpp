#include <iostream>
#include <map>
using namespace std;
map<string, int> quantity, timeP;
//hàm kiểm tra số điện thoại 
bool check(string phoneNumber)
{
    //nếu số điện thoại không phải là 10 số
    if (phoneNumber.length() != 10)
        return false;
    //kiểm tra các chữ số có phải trong khoảng từ 0-9
    for (int i = 0; i < phoneNumber.length(); i++)
        if (!(phoneNumber[i] >= '0' && phoneNumber[i] <= '9'))
            return false;
    return true;
}
//hàm tính thời gian gọi
int count(string start, string end)
{
    int startTime = 3600 * ((start[0] - '0') * 10 + start[1] - '0') + 60 * ((start[3] - '0') * 10 + start[4] - '0') + ((start[6] - '0') * 10 + start[7] - '0');
    int endTime = 3600 * ((end[0] - '0') * 10 + end[1] - '0') + 60 * ((end[3] - '0') * 10 + end[4] - '0') + ((end[6] - '0') * 10 + end[7] - '0');
    return endTime - startTime;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string choice;
    int total = 0;
    int incorrect = 0;
    do
    {
        cin >> choice;
        if (choice == "#")
            continue;
        ++total;
        string from_num, to_num, date, from_time, to_time;
        cin >> from_num >> to_num >> date >> from_time >> to_time;
        //Nếu số sai tăng biến đếm số sai lên
        if (!check(from_num) || !check(to_num))
            ++incorrect;
        //tăng số cuộc gọi 
        quantity[from_num]++;
        //tính thời gian được nhập
        timeP[from_num] += count(from_time, to_time);
    } while (choice != "#"); //dừng lại khi gặp kí tự #

    do
    {
        cin >> choice;
        if (choice == "#")
            continue;
        if (choice == "?check_phone_number")
        {
            cout << !incorrect << endl;
        }
        else if (choice == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << quantity[phone] << endl;
        }
        else if (choice == "?number_total_calls")
            cout << total << endl;
        else if (choice == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timeP[phone] << endl;
        }
    } while (choice != "#");
    return 0;
}