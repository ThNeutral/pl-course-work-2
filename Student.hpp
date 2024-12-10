#pragma once

#include "./Date.hpp"

#include <string>
#include <stdexcept>
#include <fstream>

class Student {
private:
    std::string name;
    int faculty_number;
    Date date_of_birth;
    float gpa;
public:
    Student() {
        set_name("");
        set_faculty_number(0);
        set_date_of_birth(Date());
        set_gpa(2.0);
    }
    Student(std::string name, int faculty_number, Date date_of_birth, float gpa) {
        set_name(name);
        set_faculty_number(faculty_number);
        set_date_of_birth(date_of_birth);
        set_gpa(gpa);
    }

    int get_full_years() {
        return Date().get_year_diff(this->date_of_birth);
    }

    std::string get_name() const {
        return name;
    }

    void set_name(const std::string& name) {
        this->name = name;
    }

    int get_faculty_number() const {
        return faculty_number;
    }

    void set_faculty_number(int faculty_number) {
        this->faculty_number = faculty_number;
    }

    Date get_date_of_birth() const {
        return date_of_birth;
    }

    void set_date_of_birth(const Date& date_of_birth) {
        this->date_of_birth = date_of_birth;
    }

    float get_gpa() const {
        return gpa;
    }

    void set_gpa(float gpa) {
        if (gpa >= 2.0f && gpa <= 6.0f) {
            this->gpa = gpa;
        } else {
            throw std::invalid_argument("GPA must be between 2.0 and 6.0.");
        }
    }

    void print_self() {
        std::cout << "Student {" << "\n\tName: " << this->name << "\n\tFaculty number: " << this->faculty_number 
        << "\n\tDate of birth: " << this->date_of_birth.to_string() << "\n\tGPA: " << this->gpa << "\n}" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "Student {" << "\n\tName: " << student.name << "\n\tFaculty number: " << student.faculty_number 
        << "\n\tDate of birth: " << student.date_of_birth.to_string() << "\n\tGPA: " << student.gpa << "\n}" << std::endl;
        return os;
    }

    friend std::ofstream& operator<<(std::ofstream& os, const Student& student) {
        os << student.name << "," << std::to_string(student.faculty_number) << "," << student.date_of_birth.to_string() 
        << "," << std::to_string(student.gpa) << ";\n";
        return os;
    }
};