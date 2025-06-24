#include <iostream>
#include <fstream>   // 用於 ifstream 和 ofstream
#include <string>    // 用於 string
#include <vector>    // 雖然不是核心，但包含進來無妨
#include <set>       // 核心容器，用於去重和排序

int main() {
    // --- 1. 設定檔名並開啟檔案串流 ---
    std::string source_filename = "email_list.txt";
    std::string dest_filename = "unique_emails.txt";

    std::ifstream source_file(source_filename);
    std::ofstream dest_file(dest_filename);

    // --- 2. 安全檢查 ---
    if (!source_file.is_open()) {
        std::cerr << "Error: Could not open source file '" << source_filename << "'" << std::endl;
        return 1;
    }
    if (!dest_file.is_open()) {
        std::cerr << "Error: Could not create destination file '" << dest_filename << "'" << std::endl;
        source_file.close(); // 退出前關閉已開啟的檔案
        return 1;
    }

    std::cout << "Reading from " << source_filename << "..." << std::endl;

    // --- 3. 核心處理：讀取檔案並存入 set ---
    std::set<std::string> unique_emails;
    std::string email;

    // 逐行從來源檔案讀取 email
    while (std::getline(source_file, email)) {
        // 如果讀取的行不是空的，就插入到 set 中
        if (!email.empty()) {
            unique_emails.insert(email);
        }
    }

    std::cout << "Processing complete. Found " << unique_emails.size() << " unique emails." << std::endl;

    // --- 4. 輸出結果：將 set 的內容寫入目標檔案 ---
    std::cout << "Writing sorted unique emails to " << dest_filename << "..." << std::endl;

    // 遍歷已排序和去重的 set
    for (const std::string& unique_email : unique_emails) {
        // 將每個 email 寫入目標檔案，並加上換行符
        dest_file << unique_email << '\n';
    }

    // --- 5. 清理工作 ---
    source_file.close();
    dest_file.close();

    std::cout << "Task finished successfully!" << std::endl;

    return 0;
}