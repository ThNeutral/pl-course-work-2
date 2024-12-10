#pragma once

#include <vector>
#include <optional>
#include "Student.hpp"

class Group {
private:
    std::vector<Student> students;
public:
    Group() {}

    void push(const Student& student) {
        this->students.push_back(student);
    }

    std::optional<Student> get_student_with_highest_gpa() {
        if (this->students.size() == 0) return std::nullopt;
        float max_gpa = -1;
        Student max_student;
        for (auto student : this->students) {
            if (student.get_gpa() > max_gpa) {
                max_gpa = student.get_gpa();
                max_student = student;
            }
        }
        return max_student;
    }

    friend std::ostream& operator<<(std::ostream& os, const Group& group) {
        if (group.students.size() == 0) {
            os << "Group is empty";
            return os;
        }    

        for (auto student : group.students) {
            int age = student.get_full_years();
            os << age << "\n";
            if (18 <= age && age <= 26) {
                os << student;
            }
        }

        return os;
    };

        friend std::ofstream& operator<<(std::ofstream& os, const Group& group) { 
        for (auto student : group.students) {
            os << student;
        }

        return os;
    };
};