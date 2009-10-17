/*
 *
 * Professional Linux Programming - removing an employee record
 *
 */
#include <stdio.h>
#include <db.h>

#define DATABASE "employees.db"

int main()
{
   DBT key;
   DB *dbp;
   int ret;
   struct data_struct {
      int empid;
      char lastname[50];
      char firstname[50];
      float salary;
   } emp;

   ret = db_create(&dbp, NULL, 0);
   if (ret != 0)
   {
      perror("create");
      return 1;
   }

   ret = dbp->open(dbp, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0);
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

      memset(&key, 0, sizeof(DBT));
      key.data = &(emp.empid);
      key.size = sizeof(emp.empid);

      ret = dbp->del(dbp, NULL, &key, 0);
      if (ret != 0)
      {
         printf("Employee ID does not exist\n");
      } else
      {
         printf("  Employee %d deleted.\n", emp.empid);
      }
   }

   dbp->close(dbp, 0);
   return 0;
}
