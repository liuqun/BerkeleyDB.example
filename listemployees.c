/*
 *
 * Professional Linux Programming - listing all employee records
 *
 */
#include <stdio.h>
#include <db.h>
#include "employee_record.h"

int main()
{
    DBT key, data;
    DBC *cursor;
    DB *dbp;
    int err;
    employee_record_t emp;

    err = db_create(&dbp, NULL, 0);
    if (err)
    {
        perror("db_create(): ");
    }
    else
    {
        err = dbp->open(dbp, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0);
        if (err)
        {
            perror("dbp->open(): ");
        }
        else
        {
            err = dbp->cursor(dbp, NULL, &cursor, 0);
            if (err)
            {
                perror("dbp->cursor(): ");
            }
            else
            {
                memset(&key, 0, sizeof(DBT));
                memset(&data, 0, sizeof(DBT));
                data.data = &emp;
                data.size = sizeof(emp);
                data.flags = DB_DBT_USERMEM;

                while (!(err = cursor->c_get(cursor, &key, &data, DB_NEXT)))
                {
                    printf("%d - %s,%s   $%.2lf\n", emp.empid, emp.lastname, emp.firstname, emp.salary);
                }

                cursor->c_close(cursor);
            }

            dbp->close(dbp, 0);
        }
    }
    return err;
}
