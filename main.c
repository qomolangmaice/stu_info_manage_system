/*
 *     File Name: main.c
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.05.15 15:34:41
 */
#include "stu_info_manage.h"
#include "stu_info_manage.c"

void main()
{
 	struct stu_info_node stu_info_table[MAXSIZE]; 	/* student information table */
	int select_flag = 0;

	init_stu_info(stu_info_table);

	while(1)
	{
		display_manage_interface();
		printf("Please input operate selection: ");
		scanf("%d", &select_flag);

		if(select_flag == 0)
			return;

		switch(select_flag)
		{
			//case 1:
			//	add_stu_info(stu_info_table);
			// 	break;
			//case 2:
			//	display_stu_info(stu_info_table);
			//	break;
			//case 3:
			//	modify_stu_info(stu_info_table);
			//	break;
			//case 4:
			//	search_stu_info(stu_info_table);
			//	break;
			//case 5:
			//	delete_stu_info(stu_info_table);
			//	break;
			//case 6:
			//	save_stu_info(stu_info_table);
			//	break;
			default:
				printf("Your input is wrong, please input again.\n");
				break;
		}
	}
}
