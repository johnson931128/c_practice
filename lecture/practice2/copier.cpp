#include <iostream>
#include <fstream>
#include <string>

int main(){
    // 定義目標檔案名稱&開啟
    std::string source_filename = "source.txt";
    std::string dest_filename = "destination.txt";

    // 輸入
    std::ifstream source_file(source_filename);
    // 輸出
    std::ofstream dest_file(dest_filename);

   // 檢查來源檔案
    if (!source_file.is_open()) {
        std::cerr << "Error: Could not open source file '" << source_filename << "'" << std::endl;
        return 1; // 返回一個非零值表示程式出錯
    }

    if (!dest_file.is_open()) {
        std::cerr << "Error: Could not open dsetination file '" << dest_filename << "'" << std::endl;
        return 1; // 返回一個非零值表示程式出錯
    }

    std::cout << "Strating to copy from " << source_filename << " to " << dest_filename << "..." <<std::endl;
    std::string line;

    while(std::getline(source_file, line)){
        dest_file << line << "\n";
    }

    std::cout <<"File copy successful" <<std::endl;

    source_file.close();
    dest_file.close();

    std::cout << "File closed." <<std::endl;
    return 0;
}