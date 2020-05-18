#ifndef STUDENT_H
#define STUDENT_H
#include "node.h"
#include "student.h"
#include <stdlib.h>
int max;
int maxid;
typedef struct student // 学生结构体定义
{
    int cid;       //学生学号定义
    char name[32]; //	学生姓名
    char pass[16]; //	学生密码
    int age;       //学生年龄
    int gmath;     ///	学生数学成绩
    int glang;     //	C语言成绩
    int gphil;     //	语文成绩
    int gsum;      //总分
    int order;     //	排序
    int classid;   //	班号
} stu_t;

/****************
功能：获取最大id数
参数：无 //
返回值：大于零表示获取成功，小于等于零表示插入失败
*************/
int getcid(void);

/****************
功能：从文件加载学生信息到结构体
参数：无
返回值：成功 返回生成的学生构体，失败则返回NULL
*************/
node_t *loadstu(void);
node_t *loadstus(void);
//
/****************
功能：从学生信息结构体保存到文件
参数：学生链表头节点
返回值：成功 返回0，失败则返回1
*************/
int savestuInfo(node_t **head);

/****************
功能：添加学生函数
参数：学生链表头节点
返回值：成功 返回生成的学生构体，失败则返回NULL
*************/
node_t *addstu(node_t *head);

node_t *findstu(node_t *head, int mode, stu_t stu);

/****************
功能：根据学号删除
参数：学生链表头节点 cid 为指定学号
返回值：成功 返回0，失败则返回1
*************/
int delstu_cid(node_t *head, int cid);

/****************
功能：销毁学生链表
参数：学生链表头节点
返回值：无返回值
*************/
void destory_list(node_t **head);

/*
获取学生节点
函数参数：head为已有所有学生链表，mode为查找方式 0 全部获取，1 按学号获取，2 按姓名获取，3 按班级获取
函数返回值：返回所查找到的新建的学生链表
函数流程： 
1、如果mode为0，返回所有学生链表
2、如果mode为1,调用node_find() 按学号从链表中查找学生，根据学号返回学生  并且返回
3、如果mode为2,调用node_find() 按姓名从链表中查找学生， 根据姓名返回学生插入到新链表中 并且返回
3、如果mode为3,调用node_find() 按班级从链表中查找学生， 根据班级返回学生插入到新链表中 并且返回
 */
node_t *getstu(node_t *head, int mode, void *data);

/*函数定义： int getstudata(node_t *getnode, int mode) 
参数：getnode为学生节点指针,mode为获取模式，
返回值：根据mode不同而返回不同结果
函数功能；按mode从学生节点中获取数据
函数流程：
1、switch(mode) //1.学号 2.学科总分 3.数学成绩 4.C语言成绩 5.语文成绩 
case 1: //1.获取学号 返回 getnode->data->id; 
case 2: //2.获取学科总分，计算得出，返回总分
case 3: // 3.获取数学成绩 ，返回数学成绩 
case 4: //4.获取C语言成绩，返回C语言成绩
case 5: //5.获取语文成绩，返回语文成绩
*/
int getstudata(node_t *getnode, int mode);

/*函数定义： int sortstu(node_t *head, int mode)
参数：head为学生链表头节点,mode为排序模式，
返回值：根据mode不同而返回不同结果
函数功能；排序学生链表
函数流程：
1、switch(mode) //1.学号 2.学科总分 3.数学成绩 4.C语言成绩 5.语文成绩 
case 1: //1.根据学号排序
case 2: //2.根据数学排序
case 3: // 3.根据语文排序 
case 4: //4.根据总分排序*/
int sortstu(node_t *head, int mode);

/*函数定义： int sortstu_t(node_t *head, int mode)
参数：head为学生链表头节点,mode为排序模式，
返回值：根据mode不同而返回不同结果
函数功能；排序学生链表 逆序
函数流程：
1、switch(mode) //1.学号 2.学科总分 3.数学成绩 4.C语言成绩 5.语文成绩 
case 1: //1.根据学号排序
case 2: //2.根据数学排序
case 3: // 3.根据语文排序 
case 4: //4.根据总分排序*/
int sortstu_t(node_t *head, int mode);

/****************
功能：显示所有学生信息
参数：head 为学生链表头节点 
返回值：无返回
*************/
void show_stu_all(node_t *head);

/****************
功能：显示单独学生信息
参数：data 为指定学生数据域 
返回值：无返回
*************/
void show_stu(void *data);

/****************
功能：比较学生学号函数
参数：data 为指定学生学号数据域指针
返回值：无返回
*************/
int cmp_stu_cid(void *data1, void *data2);

/****************
功能：比较学生名字函数
参数：data 为指定学生名字数据域指针
返回值：无返回
*************/
int cmp_stu_name(void *data1, void *data2);

/****************
功能：比较学生数学成绩函数
参数：data 为指定学生数学成绩数据域指针
返回值：无返回
*************/
int cmp_stu_gmath(void *data1, void *data2);

/****************
功能：比较学生C语言成绩函数
参数：data 为指定学生C语言成绩数据域指针
返回值：无返回
*************/
int cmp_stu_glang(void *data1, void *data2);

/****************
功能：比较学生语文成绩函数
参数：data 为指定学生语文成绩数据域指针
返回值：无返回
*************/
int cmp_stu_gphil(void *data1, void *data2);

/****************
功能：比较学生总分函数
参数：data 为指定学生总分数据域指针
返回值：无返回
*************/
int cmp_stu_sum(void *data1, void *data2);

/****************
功能：比较学生学号函数
参数：data 为指定学生学号数据域指针
返回值：无返回
*************/
int cmp_stu_classid(void *data1, void *data2);
#endif
