#ifndef NODE_H
#define NODE_H
//双向循环链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SYSERR(x, option, y, k, z)                              \
	if ((x)option(y))                                           \
	{                                                           \
		printf("%s:%s:%d:%s", __FILE__, __func__, __LINE__, k); \
		return z;                                               \
	}

typedef struct node
{
	struct node *before; //前级指针
	void *data;			 //数据指针
	struct node *next;	 //后级指针
} node_t;

//初始化
node_t *node_init(void);
//头插
int node_inserh(node_t *head, void *data, int size);
//尾插
int node_insert(node_t *head, void *data, int size);

typedef void (*showfun_t)(void *);
//顺序显示
int node_hshow(node_t *head, showfun_t showfun);
//逆序显示
int node_tshow(node_t *head, showfun_t showfun);
//头删
int node_hdelete(node_t *head);
//尾删
int node_tdelete(node_t *head);
//查找
typedef int (*cmpfun_t)(void *, void *);
node_t *node_find(node_t *head, void *data, cmpfun_t cmpfun);
//修改
int node_update(node_t *head, void *olddata, void *newdata, int size, cmpfun_t cmpfun);

//查找删
int node_finddelete(node_t *head, void *olddata, cmpfun_t cmpfun);
int node_bubble_sort(node_t *head, cmpfun_t cmpfun);
//排序	冒泡排序	选择排序
int node_select_sort(node_t *head, cmpfun_t cmpfun);

//销毁
int node_destory(node_t **head);
#endif
