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

#define MAXSIZE 50 

struct stu_info_node{ 	/* student information node */
	int ID;
	char name[20];
	char sex[10];
	char specialty[30];
	int class;
};

void display_manage_interface(void); 
void init_stu_info(struct stu_info_node info_table[]);



