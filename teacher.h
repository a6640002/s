#ifndef TEACHER_H
#define TEACHER_H
#include "node.h"
int tch_max;
int tch_maxid;
typedef struct teacher //教师结构体定义
{
    int tid;
    char name[32];
    char pass[16];
    int classid; //班级号
} tch_t;

int gettid(void );                                                      //获取教师编号函数
node_t *loadtch(void );                                                 //加载教师函数
int savetch(node_t *head);                                         //保存教师函数
int addtch(node_t *head, tch_t tch);                               //添加教师函数
int deltch(node_t *head, int mode, tch_t tch);                     //删除教师函数
int updatetch(node_t *head, int mode, tch_t oldtch, tch_t newtch); //修改教师函数
node_t *findtch(node_t *head, int mode, tch_t tch);                //查找教师函数
int sorttch(node_t *head, int mode);                               //	排序教师函数
node_t *FindTch(node_t *head, char *name);                         //根据名字查找
int updatetch(node_t *head, int mode, tch_t oldtch, tch_t newtch); // 修改教师信息
void show_tch(void *data);                                         //	显示教师函数
void showall_tch(node_t *head);                                    //显示所有教师信息
int cmp_tch_tid(void *data1, void *data2);                         //比较教师工号函数
int cmp_tch_name(void *data1, void *data2);                        //	比较教师的名字
int cmp_tch_classid(void *data1, void *data2);                     //比较教师的班号

#endif
