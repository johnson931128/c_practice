#include <iostream>
#include <chrono>
#include <thread> // 為了模擬延遲使用

using namespace std;

int main()
{
    // 使用 \n 的例子
    cout << "使用 \\n:" << endl;
    cout << "開始計算..." << "\n";              // 使用 \n 換行，但不會馬上刷新緩衝區
    this_thread::sleep_for(chrono::seconds(2)); // 模擬兩秒延遲
    cout << "計算完成。" << "\n";               // 這行會等到緩衝區滿或者程式結束才顯示

    // 使用 endl 的例子
    cout << "\n使用 endl:" << endl;
    cout << "開始計算..." << endl;              // 使用 endl 換行並刷新緩衝區，馬上顯示這行
    this_thread::sleep_for(chrono::seconds(2)); // 模擬兩秒延遲
    cout << "計算完成。" << endl;               // 這行也會馬上顯示

    return 0;
}
