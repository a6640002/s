#include "node.h"

node_t *node_init(void)
{
	node_t *head = malloc(sizeof(node_t));
	SYSERR(head, ==, NULL, "head is NULL", NULL);
	head->before = head->next = head;
	head->data = NULL;
	return head;
}

int node_inserh(node_t *head, void *data, int size)
{
	SYSERR(head, ==, NULL, "head is NULL\n", -1);
	SYSERR(data, ==, NULL, "data is NULL\n", -2); //插入 会报错
	SYSERR(size, <, 1, "size must >=1\n", -3);
	node_t *p = malloc(sizeof(node_t));
	SYSERR(p, ==, NULL, "malloc err", -4);
	p->data = malloc(size);
	if (p->data == NULL)
	{
		free(p);
		printf("malloc err\n");
		return -4;
	}
	memcpy(p->data, data, size);
	p->before = head;
	p->next = head->next;

	head->next->before = p;
	head->next = p;

	return 0;
}

int node_insert(node_t *head, void *data, int size)
{
	SYSERR(head, ==, NULL, "head is NULL", -1);
	SYSERR(data, ==, NULL, "data is NULL", -2);
	SYSERR(size, <, 1, "size must >=1", -3);
	node_t *p = malloc(sizeof(node_t));
	SYSERR(p, ==, NULL, "malloc err", -4);
	p->data = malloc(size);
	if (p->data == NULL)
	{
		free(p);
		printf("malloc err\n");
		return -4;
	}
	memcpy(p->data, data, size);
	p->next = head;
	p->before = head->before;

	head->before->next = p;
	head->before = p;

	return 0;
}
int node_hdelete(node_t *head)
{
	SYSERR(head, ==, NULL, "head isNULL", -1);
	SYSERR(head->next, ==, head, "head is empty", -2);

	node_t *p = head->next;
	p->next->before = head;
	head->next = p->next;

	free(p->data);
	free(p);
	p = NULL;
	return 0;
}

int node_tdelete(node_t *head)
{
	SYSERR(head, ==, NULL, "head isNULL", -1);
	SYSERR(head->next, ==, head, "head is empty", -2);

	node_t *p = head->before;
	p->before->next = head;
	head->before = p->before;

	free(p->data);
	free(p);
	p = NULL;
	return 0;
}

node_t *node_find(node_t *head, void *data, cmpfun_t cmpfun)
{
	SYSERR(head, ==, NULL, "head isNULL", NULL);
	SYSERR(head->next, ==, head, "head is empty", NULL);
	SYSERR(data, ==, NULL, "data is NULL", NULL);

	node_t *p = head->next;
	while ((p != head) && (p->data != NULL))
	{
		if (!cmpfun(data, p->data))
			return p;
		p = p->next;
	}
	printf("not find\n");
	return NULL;
}

int node_update(node_t *head, void *olddata, void *newdata, int size, cmpfun_t cmpfun)
{
	SYSERR(head, ==, NULL, "head isNULL", -1);
	SYSERR(head->next, ==, head, "head is empty", -2);
	SYSERR(olddata, ==, NULL, "olddata is NULL", -3);
	SYSERR(newdata, ==, NULL, "newdata is NULL", -3);
	node_t *p = node_find(head, olddata, cmpfun);
	SYSERR(p, ==, NULL, "not find", -4);
	memcpy(p->data, newdata, size);
	return 0;
}
int node_finddelete(node_t *head, void *olddata, cmpfun_t cmpfun)
{
	SYSERR(head, ==, NULL, "head isNULL", -1);
	SYSERR(head->next, ==, head, "head is empty", -2);
	SYSERR(olddata, ==, NULL, "olddata is NULL", -3);
	node_t *p = node_find(head, olddata, cmpfun);
	SYSERR(p, ==, NULL, "not find", -4);

	p->next->before = p->before;
	p->before->next = p->next;
	free(p->data);
	free(p);
	return 0;
}
int node_hshow(node_t *head, showfun_t showfun) //顺序显示
{
	SYSERR(head, ==, NULL, "head is NULL", -1);
	node_t *p = head->next;
	while (p != head)
	{
		showfun(p->data);
		p = p->next;
	}
	return 0;
}
int node_tshow(node_t *head, showfun_t showfun) //逆序显示
{
	SYSERR(head, ==, NULL, "head is NULL", -1);
	node_t *p = head->before;
	while (p != head)
	{
		showfun(p->data);
		p = p->before;
	}
	return 0;
}
int node_bubble_sort(node_t *head, cmpfun_t cmpfun)
{
	SYSERR(head, ==, NULL, "head is NULL", -1);
	SYSERR(head->next, ==, NULL, "head is empty", -2);
	node_t *i, *j, *end;
	int flag = 0;
	void *temp;
	for (i = head->next, end = head; i->next != head; i = i->next, end = end->before)
	{
		flag = 0;
		for (j = head->next; j->next != end; j = j->next)
		{
			if (cmpfun(j->data, j->next->data) > 0)
			{
				flag = 1;
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
		if (!flag)
			break;
	}
	return 0;
}

int node_select_sort(node_t *head, cmpfun_t cmpfun)
{
	SYSERR(head, ==, NULL, "head is NULL", -1);
	SYSERR(head->next, ==, NULL, "head is empty", -2);

	node_t *i, *j, *min;
	void *temp;
	for (i = head->next; i->next != head; i = i->next)
	{
		min = i;
		for (j = i->next; j != head; j = j->next)
		{
			if (cmpfun(min->data, j->data) < 0)
				min = j;
		}
		if (min != i)
		{
			temp = min->data;
			min->data = i->data;
			i->data = temp;
		}
	}
	return 0;
}

int node_destory(node_t **head)
{
	SYSERR(*head, ==, NULL, "head is NULL", -1);
	node_t *p = (*head)->next, *q;
	while (p != *head)
	{
		q = p;
		free(q->data);
		free(q);
		p = p->next;
	}
	free(*head);
	*head = NULL;
	return 0;
}
