/*
 *     File Name: stu_info_manage.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.05.15 15:34:28
 */

void read_info_from_exist(struct stu_info_node info_table[])
{
	FILE *fp = NULL;
	int i = 0;
	fp = fopen("stu_info_table.dat", "rb");
	while(fread(&info_table[i], sizeof(struct stu_info_node), 1, fp))
		++i;
	fclose(fp);
	//return i;
}

/* 初始化学生信息表，检查是否存在学生信息表存储文件，若没有则创建. */
void init_stu_info(struct stu_info_node stu_info_table[])
{
	FILE *fp = NULL;
	char yes_or_no;
	int number = 0;

	/* 初始化学生信息表 */
	for(int i=0; i<MAXSIZE; ++i)
	{
		stu_info_table[i].ID = 0;
		stu_info_table[i].name[20] = '\0'; 
		stu_info_table[i].sex[10] = '\0';
		stu_info_table[i].specialty[30] = '\0'; 
		stu_info_table[i].class = 0;
	}

	/* 检查是否存在学生信息表存储文件，如果没有则创建. */
	if((fp = fopen("stu_info_table.dat", "rb")) == NULL)
	{
		printf("The info table is not exist. Do you want to create a new one? (y/n)\n");
		scanf("%c", &yes_or_no);
	 	if(yes_or_no == 'y' || yes_or_no == 'Y')
		{
			/* 创建一个新的学生信息表存储文件. */
			fp = fopen("stu_info_table.dat", "wb");
			fclose(fp);
		}
		else
			return;
	}
	else
		//number = read_info_from_exist(stu_info_table);
		/* 存在学生信息表存储文件，那么就从该文件中读取所有学生的信息. */
		read_info_from_exist(stu_info_table);
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












