#include "Date.hpp"
#include "Student.hpp"
#include "Group.hpp"

#include <vector>
#include <iostream>
#include <fstream>

int main() {
    Group group;
    group.push(Student("Student1", 1, Date(1, 1, 2000), 3.0));
    group.push(Student("Student2", 2, Date(20, 10, 1995), 5.0));
    group.push(Student("Student3", 3, Date(28, 2, 1997), 6.0));
    group.push(Student("Student4", 4, Date(12, 7, 2004), 3.1));
    group.push(Student("Student5", 5, Date(9, 9, 2005), 2.0));

    auto result = group.get_student_with_highest_gpa();

    std::cout << "Finding student with highest gpa" << std::endl;
    if (result.has_value()) {
        result.value().print_self();
    } else {
        std::cout << "Group is empty" << std::endl;
    }

    std::cout << "\nPrinting students between 18 and 26 years old" << std::endl;
    std::cout << group << std::endl;

    std::ofstream os("students.txt");
    os << group;
}