#pragma once
#define DATABASE "employees.db"

typedef struct {
    int empid;
    char lastname[50];
    char firstname[50];
    float salary;
} employee_record_t;
