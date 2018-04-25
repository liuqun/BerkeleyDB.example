# BerkeleyDB.example

## `employee_record.h`
```
typedef struct {
   int empid;
   char lastname[50];
   char firstname[50];
   float salary;
} employee_record_t;
```

## 4个样例程序
- newemployee.c
- delemployee.c
- listemployees.c: 列出所有雇员详细信息
- getemployee.c

## 缺少:
- editemployee.c
