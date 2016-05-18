/*
 *     File Name: stu_info_manage.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.05.15 15:34:28
 */

/* 读取已存在文件中学生学籍信息,并返回学生个数 */
int read_info_from_exist(struct stu_info_node info_table[])
{
	FILE *fp = NULL;
	int i = 0;

	/* 以二进制形式读取文件信息 */
	fp = fopen("stu_info_table.dat", "rb");
	while(fread(&info_table[i], sizeof(struct stu_info_node), 1, fp))
		i++;

	/* 以文本形式读取文件信息 */
	//if((fp = fopen("stu_info_node.dat", "r")) != NULL)
	//	fscanf(fp, "%d\t%s\t%s\t%s\t%d", p_info_node->ID,
	//									 p_info_node->name,
	//									 p_info_node->sex,
	//									 p_info_node->specialty,
	//									 p_info_node->class);

	fclose(fp);
	return i;
}

/* 
 * 初始化学生信息表;
 * 检查是否存在学生信息表存储文件，如果不存在则创建信息存储文件;
 * 如果存在学生信息存储文件，读取已存在文件并返回学生个数 
 */
int init_stu_info(struct stu_info_node stu_info_table[])
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
			return 0;
	}
	else 	/* 存在学生信息表存储文件，那么就从该文件中读取所有学生的信息. */
		number = read_info_from_exist(stu_info_table);
	/* 返回学生个数 */
	return number;
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

/* 保存单个学生学籍信息到文件中 */
void save_stu_info(struct stu_info_node *p_info_node)
{
	FILE *fp = NULL;

	/* 以二进制形式追加信息到文件中 */
	fp = fopen("stu_info_table.dat", "ab+");
	/* 以二进制形式将数据写入到文件中 */
	fwrite(p_info_node, sizeof(struct stu_info_node), 1, fp);
	
	/* 以文本形式追加信息到文件中 */
	//fp = fopen("stu_info_table.dat", "a+");
	/* 以文本形式将数据写入到文件中 */
	//fprintf(fp, "%d %s %s %s %d", p_info_node->ID,
	//		 	 	 	 	 	 p_info_node->name,
	//							 p_info_node->sex,
	//							 p_info_node->specialty,
	//							 p_info_node->class);
	fclose(fp);
}

/* 更新学生学籍信息 */
void update_stu_info(struct stu_info_node info_table[], int number)
{
	FILE *fp = NULL;
	fp = fopen("stu_info_table.dat", "wb");
	for(int i=0; i<number; ++i)
		fwrite(&info_table[i], sizeof(struct stu_info_node), 1, fp);
	fclose(fp);
}

/* 添加学生学籍信息,并保存信息到文件中, 并且返回最新学生个数 */
int add_stu_info(struct stu_info_node info_table[], int number)
{
	while(1)
	{
		printf("Please input the student's ID: ");
		scanf("%d", &info_table[number].ID);
		printf("Please input the student's name: ");
		scanf("%s", info_table[number].name);
		printf("Please input the student's sex: ");
		scanf("%s", info_table[number].sex);
		printf("Please input the student's specialty: ");
		scanf("%s", info_table[number].specialty);
		printf("Please input the student's class: ");
		scanf("%d", &info_table[number].class);

		save_stu_info(&info_table[number]);
		++number;

		getchar();
		printf("Continue input or not ? (y/n) ");
		if(getchar() == 'n')
			break;
	}
	printf("Add student information on success.\n");
	return number;
}

/* 显示所有学生学籍信息 */
void display_all_stu_info(struct stu_info_node info_table[], int number)
{
	printf("----------------------------------------------\n");
	printf(" %s\t%s\t%s\t%s\t%s\n", "ID", "name", "sex", "specialty", "class");
	printf("----------------------------------------------\n");
	for(int i=0; i<number; i++)
	{
		printf(" %d\t%s\t%s\t%s\t\t%d\n", info_table[i].ID, 
				 	 	 	 	 	 	  info_table[i].name, 
										  info_table[i].sex, 
										  info_table[i].specialty, 
										  info_table[i].class);
	}
	printf("\n");
}

/* 显示单个学生学籍信息 */
void display_single_stu_info(struct stu_info_node info_table[], int index)
{
	printf("----------------------------------------------\n");
	printf(" %s\t%s\t%s\t%s\t%s\n", "ID", "name", "sex", "specialty", "class");
	printf("----------------------------------------------\n");
	printf(" %d\t%s\t%s\t%s\t\t%d\n", info_table[index].ID, 
			 	 	 	 	 	 	  info_table[index].name, 
									  info_table[index].sex, 
									  info_table[index].specialty, 
									  info_table[index].class);
	printf("\n");
}

/* 修改学生学籍信息 */
void modify_stu_info(struct stu_info_node info_table[], int number)
{
	FILE *fp = NULL;
	char name[20];
	int change_index = 0;

	printf("Please input the name that you want to modify: ");
	scanf("%s", name);

	/* 找到需要修改的学生名字 */
	for(int i=0; i<number; ++i)
	{
		if(strcmp(name, info_table[i].name) == 0)
		{
			change_index = i; 	/* 保存学生信息表中要修改的下标 */
			break;
		}
	}

	display_single_stu_info(info_table, change_index);
	//printf("----------------------------------------------\n");
	//printf(" %s\t%s\t%s\t%s\t%s\n", "ID", "name", "sex", "specialty", "class");
	//printf("----------------------------------------------\n");
	//printf(" %d\t%s\t%s\t%s\t\t%d\n", info_table[change_index].ID, 
	//		 	 	 	 	 	 	  info_table[change_index].name, 
	//								  info_table[change_index].sex, 
	//								  info_table[change_index].specialty, 
	//								  info_table[change_index].class);
	printf("Please input the new info of the student: \n");
 	printf("Student's new ID: ");
	scanf("%d", &info_table[change_index].ID);
 	printf("Student's new name: ");
	scanf("%s", info_table[change_index].name);
 	printf("Student's new sex: ");
	scanf("%s", info_table[change_index].sex);
 	printf("Student's new specialty: ");
	scanf("%s", info_table[change_index].specialty);
 	printf("Student's class: ");
	scanf("%d", &info_table[change_index].class);

	/* 信息修改后重新更新文件里面的数据，保持数据一致性 */
	update_stu_info(info_table, number);
	printf("Modified on success.\n");
}

void search_stu_info(struct stu_info_node info_table[], int number)
{
	int select = 0;;
	while(1)
	{
		printf(" (1) search by ID \n");
		printf(" (2) search by name \n");                  	
		scanf("%d", &select);                              	
		switch(select)                                     	
		{                                                  	
			case 1:                                        	
				find_by_ID(info_table, number);          	
				break;                                     	
			//case 2:                                        	
			//	find_by_name(info_table, number);        	
			//	break;                                     	
			default:                                       	
				printf("The input is wrong. Try again.\n");	
				break;                                     	
		}                                                  	

		getchar();
		printf("Continue input or not ? (y/n) ");
		if(getchar() == 'n')
			break;
 	}
}

void find_by_ID(struct stu_info_node info_table[], int number)
{
	int id;
	printf("Please input the search ID: \n");
	scanf("%d", &id);

	for(int i=0; i<number; ++i)
	{
		if(id == info_table[i].ID)
	 	 	display_single_stu_info(info_table, i);
	}
}






