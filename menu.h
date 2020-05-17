#ifndef MENU_H
#define MENU_H
#include "node.h"
#include "comm.h"
//#include "teacher.h"
#include "student.h"
#include <stdlib.h>
#include <unistd.h>
/****************
功能：程序主界面
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int login_menu(node_t *stulist, node_t *tchlist);

/****************
功能：管理员操作菜单
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int admin_menu(node_t *stulist, node_t *tchlist);

/****************
功能：管理员登陆界面
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int welcomeadmin_menu(node_t *stulist, node_t *tchlist);

/****************
功能：教师登陆界面
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int welcometch_menu(node_t *stulist, node_t *tchlist);

/****************
功能：学生操作菜单
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int stu_menu(node_t *stulist, stu_t *stup);

/****************
功能： 学生登陆界面
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int welcomestu_menu(node_t *stulist);

/****************
功能： 管理员修改函数
参数：node_t *find 指定学生节点; int op  选择操作模式;
返回值：成功 返回0，失败则返回1

函数流程：
1、switch(op) 
case 1: //1.修改学生姓名
case 2: //2.修改学生密码
case 3: // 3.修改学生年龄 
case 4: //4.修改学生数学成绩
case 5: //5.修改C语言成绩
case 6: //6.修改语文成绩
case 7: //7.修改学号
case 8: //8.修改排序
case 9: //9.修改班号
case 0: // 推出

*************/
int modify_by_admin(node_t *find, int op);
//
/****************
功能：管理员搜索函数
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int search_by_admin(node_t *stulist, node_t *tchlist);
/****************
功能：管理员排序函数
参数：学生链表头节点 老师链表头节点
返回值：成功 返回0，失败则返回1
*************/
int srot_by_admin(node_t *stulist, node_t *tchlist);
#endif
