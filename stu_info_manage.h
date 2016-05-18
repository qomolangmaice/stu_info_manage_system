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

int read_info_from_exist(struct stu_info_node info_table[]);
int init_stu_info(struct stu_info_node info_table[]);
void display_manage_interface(void); 

void update_stu_info(struct stu_info_node info_table[], int number);
void save_stu_info(struct stu_info_node *p_info_node);
int add_stu_info(struct stu_info_node info_table[], int number);

void display_all_stu_info(struct stu_info_node info_table[], int number);
void display_single_stu_info(struct stu_info_node info_table[], int index);

void modify_stu_info(struct stu_info_node info_table[], int number);

void search_stu_info(struct stu_info_node info_table[], int number);
void find_by_ID(struct stu_info_node info_table[], int number);




