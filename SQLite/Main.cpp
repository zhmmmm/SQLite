#include <iostream>
#include "sqlite3.h"
#include <string.h>
using namespace std;


void print_row(int n_values, char** values)
{
	for (int i = 0; i < n_values; ++i)
		printf("%10s", values[i]);
	printf("\n");
}

int print_result(void* data, int n_columns, char** column_values, char** column_names)
{
	static int column_names_printed = 0;
	if (column_names_printed++ == 0)
		print_row(n_columns, column_names);
	print_row(n_columns, column_values);
	return 0;
}

int main(int argc, char * argv[])
{

	sqlite3 *db = NULL;
	char *errMsg = NULL;
	int rc = sqlite3_open("test.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		getchar();
		return 0;
	}
	else
		printf("open test.db successfully!\n");

	rc = sqlite3_exec(db, "select * from students;", print_result, NULL, &errMsg);

	//rc = sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
	//rc = sqlite3_exec(db, "CREATE TABLE students(number varchar(10), name varchar(10), "
	//	"sex varchar(6), age varchar(2));", NULL, NULL, NULL);
	//rc = sqlite3_exec(db, "INSERT INTO students VALUES('00001','Mary','female','15');"
	//	"INSERT INTO students VALUES('00002', 'John', 'male', '16');",
	//	NULL, NULL, &errMsg);
	//rc = sqlite3_exec(db, "SELECT students.* FROM students WHERE sex='female';",
	//	print_result, NULL, &errMsg);
	//rc = sqlite3_exec(db, "SELECT students.* FROM students WHERE sex='male';",
	//	print_result, NULL, &errMsg);
	//rc = sqlite3_exec(db, "COMMIT TRANSACTION;", NULL, NULL, NULL);

	printf("error code: %d\n", rc);
	printf("error message: %s\n", errMsg);

	sqlite3_close(db);

	getchar();
	return 0;
}
//��������������������������������
//��Ȩ����������ΪCSDN������û�п�����������ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/mycwq/java/article/details/15503293