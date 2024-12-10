#pragma once

#include <chrono>
#include <stdexcept>
#include <iostream>
#include <string>

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() {
        std::time_t current_time = std::time(nullptr);
        std::tm* local_time = std::localtime(&current_time);

        set_day(local_time->tm_mday);
        set_month(local_time->tm_mon + 1);
        set_year(local_time->tm_year + 1900);  
    }

    Date(int day, int month, int year ) {
        set_day(day);
        set_month(month);
        set_year(year);
    }

    int get_year_diff(const Date& other) const {
        int day_diff = this->get_day() - other.get_day();
        int month_diff = this->get_month() - other.get_month();
        int year_diff = this->get_year() - other.get_year();
        
        if ((month_diff < 0) || (month_diff == 0 && day_diff < 0)) {
            year_diff -= 1;
        }

        return year_diff; 
    }

    int get_day() const {
        return this->day;
    }

    void set_day(int day) {
        if (day >= 1 && day <= 31) {
            this->day = day;
        } else {
            throw std::invalid_argument("Day must be between 1 and 31");
        }
    }

    int get_month() const {
        return this->month;
    }

    void set_month(int month) {
        if (month >= 1 && month <= 12) {
            this->month = month;
        } else {
            throw std::invalid_argument("Month should be between 1 and 12");
        }
    }

    int get_year() const {
        return this->year;
    }

    void set_year(int year) {
        this->year = year;
    }

    void print_self() const {
        std::cout << "Date: " << year << "-" << month << "-" << day << std::endl;
    }

    std::string to_string() const {
        return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
    }
};