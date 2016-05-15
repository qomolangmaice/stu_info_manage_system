/*
 *     File Name: stu_info_manage.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.05.15 15:34:28
 */

/* 初始化学生信息表，检查是否存在学生信息表存储文件，若没有则创建. */
void init_stu_info(struct stu_info_node stu_info_table[])
{
	for(int i=0; i<MAXSIZE; ++i)
	{
		stu_info_table[i].ID = 0;
		stu_info_table[i].name[20] = ""; 
		stu_info_table[i].sex[10] = "";
		stu_info_table[i].specialty[30] = ""; 
		stu_info_table[i].class = 0;
	}
}

/* 显示学生信息管理界面 */
void display_manage_interface(void)
{
	printf("*************************************************************\n");
	printf("************  Student Information Manage System  ************\n");
 	printf("*   [1] add student info        [2] display student info    *\n");
 	printf("*   [3] modify student info     [4] search  student info    *\n"); 
 	printf("*   [5] delete student info     [5] save    student info    *\n"); 
 	printf("*   [0] exit                                                *\n"); 
	printf("*************************************************************\n");
}












