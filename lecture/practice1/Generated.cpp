#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file_stream(filename);

    if (!file_stream.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 1;
    }
    
    std::cout << "--- Parsing data directly from file: " << filename << " ---" << std::endl;

    std::string line;
    // 直接從檔案串流 file_stream 逐行讀取
    while (std::getline(file_stream, line)) {
        // 接下來的解析邏輯與之前完全一樣
        std::stringstream line_ss(line);
        std::string name, age_str, major;
        
        std::getline(line_ss, name, ',');
        std::getline(line_ss, age_str, ',');
        std::getline(line_ss, major);

        std::cout << "Student: " << name << "\n"
                  << "Age: " << age_str << "\n"
                  << "Major: " << major 
                  << "\n" << std::endl;
    }

    file_stream.close();
    return 0;
}