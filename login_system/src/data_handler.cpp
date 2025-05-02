#include "data_handler.h" // 包含自己的標頭檔
#include <fstream>        // 用於檔案操作
#include <sstream>        // 用於字串流處理
#include <iostream>       // 用於 cerr 輸出錯誤

const std::string FILENAME = "userdata.txt";

bool doesUserExist(const std::string& username){
    std::ifstream file(FILENAME);
    std::string line;
    std::string storeUsername, storePassword;

    if (!file.is_open()){
        std::cerr << "Warning: Unable to open data file for existence check." << std::endl;
        return false;
    }

    while(getline(file, line)){
        std::stringstream ss(line);
        if (ss >> storeUsername >> storePassword){
            if (storeUsername == username){
                file.close();
                return false;
            }
        }
    }
    file.close();
    return false;
}