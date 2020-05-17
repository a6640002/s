#include "teacher.h"
node_t *loadtch()
{
    FILE *fd = fopen("teacher.dat", "r");
    SYSERR(fd, ==, NULL, "cant open data \n", NULL);
    fscanf(fd, "%d %d", &tch_max, &tch_maxid);
    node_t *new = node_init();
    tch_t *tmp = malloc(sizeof(tch_t));
    SYSERR(tmp, ==, NULL, "malloc error \n", NULL);
    for (int i = 0; i < tch_max; i++)
    {
        fscanf(fd, "%d %s %s %d", &(tmp->tid), tmp->name, tmp->pass, &(tmp->classid));
        node_inserh(new, tmp, sizeof(tch_t));
    }
    free(tmp);
    fclose(fd);
    return new;
}

void showall_tch(node_t *head)
{

    node_t *pcur = NULL;
    for (pcur = head->next; pcur != head; pcur = pcur->next)
    {
        printf("%d %s ", ((tch_t *)(pcur->data))->tid, ((tch_t *)(pcur->data))->name);
        printf("%s %d \n", ((tch_t *)(pcur->data))->pass, ((tch_t *)(pcur->data))->classid);
    }
}

int savetch(node_t *head)
{
    FILE *fd = fopen("teacher.dat", "w");
    SYSERR(fd, ==, NULL, "error fopen \n", -1);
    fprintf(fd, "%d %d\n", tch_max, tch_maxid);
    node_t *pcur = NULL;
    for (pcur = head->next; pcur != head; pcur = pcur->next)
    {
        fprintf(fd, "%d %s ", ((tch_t *)(pcur->data))->tid, ((tch_t *)(pcur->data))->name);
        fprintf(fd, "%s %d \n", ((tch_t *)(pcur->data))->pass, ((tch_t *)(pcur->data))->classid);
    }
    fclose(fd);
    return 0;
}

int addtch(node_t *head, tch_t tch)
{
    tch_max++;
    node_inserh(head, &tch, sizeof(tch_t));
    return 0;
}

node_t *FindTch(node_t *head, char *name)
{
    return 0;
}
/*删除教师  
返回值 ：成功时为0；失败为-1
1.mode 为1时 根据教师序号删除
2.mode 为2时 根据教师名字删除
2.mode 为3时 根据班级删除
*/
int deltch(node_t *head, int mode, tch_t tch)
{
    switch (mode)
    {
    case 1:
        if (node_finddelete(head, &tch, cmp_tch_tid) != 0)
        {
            printf("delete error");
            return -1;
        }
        tch_max--;
        return 0;
    case 2:
        if (node_finddelete(head, &tch, cmp_tch_name) != 0)
        {
            printf("delete error");
            return -1;
        }
        tch_max--;
        return 0;
    case 3:
        if (node_finddelete(head, &tch, cmp_tch_classid) != 0)
        {
            printf("delete error");
            return -1;
        }
        tch_max--;
        return 0;

    default:
        return -1;
    }
}
//修改教师信息
int updatetch(node_t *head,int mode,tch_t oldtch,tch_t newtch)
{
return 0;
}

int cmp_tch_tid(void *data1, void *data2) //比较教师工号函数
{
    return ((tch_t *)(data1))->tid - ((tch_t *)(data2))->tid;
}
int cmp_tch_name(void *data1, void *data2) //	比较教师的名字
{
    return strncmp(((tch_t *)(data1))->name, ((tch_t *)(data2))->name, sizeof(((tch_t *)(data1))->name));
    // return strncmp(((tch_t *)(data1))->name, ((tch_t *)(data2))->name, sizeof(((tch_t *)(data1))->name));
}
int cmp_tch_classid(void *data1, void *data2) //比较教师的班号
{
    return ((tch_t *)(data1))->classid - ((tch_t *)(data2))->classid;
}
