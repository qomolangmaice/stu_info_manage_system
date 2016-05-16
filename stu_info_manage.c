/*
 *     File Name: stu_info_manage.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.05.15 15:34:28
 */

/* 读取已存在文件中学生学籍信息 */
void read_info_from_exist(struct stu_info_node info_table[])
{
	FILE *fp = NULL;
	int i = 0;

	/* 以二进制形式读取文件信息 */
	fp = fopen("stu_info_table.dat", "rb");
	while(fread(&info_table[i], sizeof(struct stu_info_node), 1, fp))
		++i;

	/* 以文本形式读取文件信息 */
	//if((fp = fopen("stu_info_node.dat", "r")) != NULL)
	//	fscanf(fp, "%d\t%s\t%s\t%s\t%d", p_info_node->ID,
	//									 p_info_node->name,
	//									 p_info_node->sex,
	//									 p_info_node->specialty,
	//									 p_info_node->class);

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

/* 保存学生学籍信息到文件中 */
void save_stu_info(struct stu_info_node *p_info_node)
{
	FILE *fp = NULL;

	/* 以二进制形式追加信息到文件中 */
	//fp = fopen("stu_info_table.dat", "ab+");
	/* 以二进制形式将数据写入到文件中 */
	//fwrite(p_info_node, sizeof(struct stu_info_node), 1, fp);
	
	/* 以文本形式追加信息到文件中 */
	fp = fopen("stu_info_table.dat", "a+");
	/* 以文本形式将数据写入到文件中 */
	fprintf(fp, "%d %s %s %s %d", p_info_node->ID,
			 	 	 	 	 	 p_info_node->name,
								 p_info_node->sex,
								 p_info_node->specialty,
								 p_info_node->class);
	//printf("%d\t%s\t%s\t%s\t%d\n", p_info_node->ID,
	//		 	 	 	 	 	 p_info_node->name,
	//							 p_info_node->sex,
	//							 p_info_node->specialty,
	//							 p_info_node->class);
	
	fclose(fp);
}

/* 添加学生学籍信息,并保存信息到文件中 */
void add_stu_info(struct stu_info_node info_table[])
{
	int i = 0;

	while(1)
	{
		printf("Please input the student's ID: ");
		scanf("%d", &info_table[i].ID);
		printf("Please input the student's name: ");
		scanf("%s", info_table[i].name);
		printf("Please input the student's sex: ");
		scanf("%s", info_table[i].sex);
		printf("Please input the student's specialty: ");
		scanf("%s", info_table[i].specialty);
		printf("Please input the student's class: ");
		scanf("%d", &info_table[i].class);

		save_stu_info(&info_table[i]);
		++i;

		getchar();
		printf("Continue or not ? (y/n) ");
		if(getchar() == 'n')
			break;
	}
	printf("Add student information on success.\n");
}

/* 显示学生学籍信息 */
void display_stu_info(struct stu_info_node info_table[])
{
	FILE *fp = NULL;
	printf("%s\t%s\t%s\t%s\t%s\n", "ID", "name", "sex", "specialty", "class");
	printf("---------------------------------------------\n");
	fp = fopen("stu_info_table.dat", "r");
	for(int i=0; i<5; ++i)
	{
		fscanf(fp, "%d %s %s %s %d\n", &info_table[i].ID,
									   &info_table[i].name[20],
									   &info_table[i].sex[10],
									   &info_table[i].specialty[80],
									   &info_table[i].class);
		printf("%d\t%s\t%s\t%s\t%d\n", info_table[i].ID,
									   info_table[i].name[20],
									   info_table[i].sex[10],
									   info_table[i].specialty[80],
									   info_table[i].class);
	}
	fclose(fp);
}









