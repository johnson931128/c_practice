/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

// 輔助函式
/*
README 裡面提示我們可以寫一個輔助函式。這個函式接收一個全名 
(例如 "Bjarne Stroustrup")，然後回傳它的首字母縮寫 (例如 "BS"。這會讓我們的程式碼更乾淨。
*/
// 取得名字的首字母縮寫，例如 "Bjarne Stroustrup" -> "BS"
std::string get_initials(const std::string& name){
  if (name.empty()){
    // 如果名字是空的，回傳空字串
    return "";
  }

  std::string initials = "";
  initials += name[0]; // 加入第一個字母

  // 找到名字中的空格位置
  size_t space_pos = name.find(' ');
  // 如果有空格，且空格後還有字元
  if (space_pos != std::string::npos && space_pos + 1 < name.length()){
    initials += name[space_pos + 1]; // 加入空格後的第一個字母
  }
  return initials;
}

std::string kYourName = "Johnson Fan"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // 1.宣告一個set來儲存名子
  std::set<std::string> applicnats;
  // 2.宣告並嘗試打開檔案
  std::ifstream inputfile(filename);
  // 3.檢查是否打開成功
  if (!inputfile.is_open()){
    std::cerr << "There is a error for open file " << filename << std::endl; 
    return applicnats;
  }
  std::string name;
  while(std::getline(inputfile, name)){
    applicnats.insert(name);
  }

  inputfile.close();
  return applicnats;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  // 1.宣告回傳函式
  std::queue<const std::string*> matches;
  // 2.取得自己名字的首字母
  std::string your_initials = get_initials(name);
  // 3.遍歷整個student set
  for (const std::string& student_name : students){
  // 4.對比後加入queue
    if (get_initials(student_name) == your_initials){
      matches.push(&student_name);
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  // 選出queue中間的人!
  // 1.處理空queue的情況
  if (matches.empty()){
    return "I'm so lonely.";
  }
  // 2.實現演算法，選中間的人
  size_t middle_index = matches.size()/2;

  // 3.把前面的人pop出來 選第一個就是他
  for (int i = 0; i < middle_index; i++){
    matches.pop();
  }

  // 4.選擇頂端的人
  const std::string* match_ptr = matches.front();
  return *match_ptr;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
