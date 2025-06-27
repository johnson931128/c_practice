/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 */
struct Course {
  /* STUDENT TODO */ std::string title;
  /* STUDENT TODO */ std::string number_of_units;
  /* STUDENT TODO */ std::string quarter;
};

/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  /* (STUDENT TODO) Your code goes here... */
  // open file
  std::ifstream file(filename);
  // check if or not open file, for the nice habbit
  if (!file.is_open()){
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return;
  }

  // ignore header_line
  std::string header_line;
  std::getline(file, header_line);

  // read line by line
  std::string line;
  while(std::getline(file, line)){
    //use spilt to split it
    std::vector<std::string> tokens = split(line, ',');
    // one two three
    if (tokens.size() == 3){
      // build the Course object
      Course course;
      course.title = tokens[0];
      course.number_of_units = tokens[1];
      course.quarter = tokens[2];
      // send course to the vector
      courses.push_back(course);
    }
    else{
      // Error message
      std::cerr << "Warning: Skipping malformed line: " << line << std::endl;
    }
  }
}

/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  /* (STUDENT TODO) Your code goes here... */
  // use ofstream to open COURSES_OFFERED_PATH
  std::ofstream output_file(COURSES_OFFERED_PATH);
  // check if success or not
  if (!output_file.is_open()){
    std::cerr << "Error: Could not open file " << COURSES_OFFERED_PATH << std::endl;
    return;
  }

  // write in header_line
  output_file << "Title,Number of Units,Quarter\n";
  // create a vector to store no  offered course
  std::vector<Course> unoffered_courses;
  /*
  if course's quarter is null store in unoffered_courses
  else *write in* ouput_file
  */
  for (const Course& course : all_courses) {
    if (course.quarter != "null"){
      output_file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
    }else{
      unoffered_courses.push_back(course);
    }
  }

  // replace all_courses to unoddered_courses
  all_courses = unoffered_courses;
}

/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(const std::vector<Course>& unlisted_courses) {
  /* (STUDENT TODO) Your code goes here... */
  // open ouput_file by ofstream
  std::ofstream output_file(COURSES_NOT_OFFERED_PATH);
  // check success or not
  if (!output_file.is_open()){
    std::cerr << "Error: Could not open file " << COURSES_NOT_OFFERED_PATH << std::endl;
    return;
  }
  // first write in header_line
  output_file << "Title,Number of Units,Quarter\n";
  for (const Course& course : unlisted_courses){
    output_file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
  }
}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}