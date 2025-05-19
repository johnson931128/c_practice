#include <bits/stdc++.h>
using namespace std;
#include <iomanip> // 為了使用 setprecision

int main()
{
    int select, student_no = 0, num = 0;
    float Msum = 0, Esum = 0;

    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *next;
    };

    // 不需要 typedef，因為 C++ 支援直接使用 struct 名稱
    student *ptr;
    student *head;
    student *new_data;

    head = new student();
    head->next = NULL;
    ptr = head;

    do
    {
        cout << "(1) create (2) exit =>" << "\n";
        cin >> select;
        if (select != 2)
        {
            cout << "Name Number Math Eng :" << endl;
            new_data = new student();
            cin >> new_data->name >> new_data->no >> new_data->Math >> new_data->Eng; // 修正：去掉指標符號 '&'
            ptr->next = new_data;
            new_data->next = NULL;
            ptr = ptr->next;
            num++;
        }
    } while (select != 2);

    ptr = head->next;
    cout << "\n";
    while (ptr != NULL)
    {
        cout << "Name : " << ptr->name << " Number : " << ptr->no << " Math : " << ptr->Math << " Eng : " << ptr->Eng << endl;
        Msum += ptr->Math;
        Esum += ptr->Eng;
        student_no++;
        ptr = ptr->next;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << fixed << setprecision(2); // 設置輸出格式為小數點後兩位
    cout << "Average of Math is : " << (Msum / student_no) << " Average of English : " << (Esum / student_no) << endl;

    return 0;
}
