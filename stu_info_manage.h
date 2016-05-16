/*
 *     File Name: stu_info_manage.h
 *     Description: 
 *     Author: iczelion
 *     Email: qomolangmaice@163.com 
 *     Created: 2016.05.15 15:34:17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 	 	/* isdigit(int) */

#define MAXSIZE 50 

struct stu_info_node{ 	/* student information node */
	int ID;
	char name[20];
	char sex[10];
	char specialty[80];
	int class;
};

void read_info_from_exist(struct stu_info_node info_table[]);
void init_stu_info(struct stu_info_node info_table[]);
void display_manage_interface(void); 

void save_stu_info(struct stu_info_node *p_info_node);
void add_stu_info(struct stu_info_node info_table[]);
void display_stu_info(struct stu_info_node info_table[]);



