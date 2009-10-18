/*
 *
 * Professional Linux Programming - Retrieving an employee record
 *
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <db.h>

#include "emp.h"

int main()
{
   DBT key, data;
   DB *db; // DB handle
   int ret;
   struct employeeRecord emp;

   // Initialize our DB handle
   ret = db_create(&db, NULL, 0);
   if (ret != 0)
   {
      fprintf(stderr, "Failed to initialize the database handle: %s\n", db_strerror(ret));
      return 1;
   }

   // Open the existing DATABASE file in read-only mode. If it doesn't exist, report an error message.
   ret = db->open(db, NULL, DATABASE, NULL, DB_BTREE, DB_RDONLY, 0);
   if (ret != 0)
   {
      fprintf(stderr, "Failed to open database file %s: %s\n", DATABASE, db_strerror(ret));
      return 1;
   }

   while(1)
   {
      printf("Enter Employee ID: ");
      scanf("%d", &emp.empid);
      if (emp.empid == 0)
         break;

      memset(&key, 0, sizeof(DBT));
      memset(&data, 0, sizeof(DBT));
      key.data = &(emp.empid);
      key.size = sizeof(emp.empid);
      data.data = &emp;
      data.ulen = sizeof(emp);
      data.flags = DB_DBT_USERMEM;

      ret = db->get(db, NULL, &key, &data, 0);
      if (ret != 0)
      {
         printf("Employee ID does not exist\n");
      } else
      {
         printf("  Employee: %d - %s,%s\n", emp.empid, emp.lastname, emp.firstname);
         printf("  Salary: $%.2lf\n", emp.salary);
      }
   }

   db->close(db, 0);
   return 0;
}
