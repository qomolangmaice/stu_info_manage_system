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
	int stu_number = 0;

	stu_number = init_stu_info(stu_info_table);

	while(1)
	{
		display_manage_interface();
		printf("Please input operate selection: ");
		scanf("%d", &select_flag);

		switch(select_flag)
		{
			case 0:
	 	 	 	printf("Exit from the manage system.\n");
				exit(0);
				break;
			case 1:
				stu_number = add_stu_info(stu_info_table, stu_number);
			 	break;
			case 2:
				display_all_stu_info(stu_info_table, stu_number);
				break;
			case 3:
				modify_stu_info(stu_info_table, stu_number);
				break;
			case 4:
				search_stu_info(stu_info_table, stu_number);
				break;
			//case 5:
			//	delete_stu_info(stu_info_table);
			//	break;
			//case 6:
			//	save_stu_info(stu_info_table);
			//	break;
			default:
				printf("The input is wrong, please try again.\n");
				break;
		}/* switch */
	}
}
