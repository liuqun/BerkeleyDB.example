/*
 *
 * Professional Linux Programming - listing all employee records
 *
 */
#include <stdio.h>
#include <db.h>

#define DATABASE "employees.db"

int main()
{
   DBT key, data;
   DBC *cursor;
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

   ret = dbp->cursor(dbp, NULL, &cursor, 0);
   if (ret != 0)
   {
      perror("cursor: ");
      return 1;
   }

   memset(&key, 0, sizeof(DBT));
   memset(&data, 0, sizeof(DBT));
   data.data = &emp;
   data.size = sizeof(emp);
   data.flags = DB_DBT_USERMEM;

   while(ret = cursor->c_get(cursor, &key, &data, DB_NEXT) == 0)
   {
      printf("%d - %s,%s   $%.2lf\n", emp.empid, emp.lastname, emp.firstname, emp.salary);
   }

   cursor->c_close(cursor);
   dbp->close(dbp, 0);
   return 0;
}
