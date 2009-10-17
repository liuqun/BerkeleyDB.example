/*
 *
 * Professional Linux Programming - Adding a new employee record
 *
 */
#include <stdio.h>
#include <string.h>
#include <db.h>

#include "emp.h"

int main()
{
   DBT key, data;
   DB *db;
   int ret;
   struct employeeRecord emp;

   ret = db_create(&db, NULL, 0);
   if (ret != 0)
   {
      perror("create");
      return 1;
   }

   ret = db->open(db, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0);
   if (ret != 0)
   {
      perror("open: ");
      return 1;
   }

   while(1)
   {
      printf("Enter Employee ID: ");
      scanf("%d", &emp.empid);
      if (emp.empid == 0)
         break;
      printf("Enter Last name: ");
      scanf("%s", &emp.lastname);
      printf("Enter First name: ");
      scanf("%s", &emp.firstname);
      printf("Enter Salary: ");
      scanf("%f", &emp.salary);

      memset(&key, 0, sizeof(DBT));
      memset(&data, 0, sizeof(DBT));

      key.data = &(emp.empid);
      key.size = sizeof(emp.empid);
      data.data = &emp;
      data.size = sizeof(emp);

      ret = db->put(db, NULL, &key, &data, DB_NOOVERWRITE);
      if (ret != 0)
      {
         printf("Employee ID exists\n");
      }
   }

   db->close(db, 0);
   return 0;
}
