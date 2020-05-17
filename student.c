#include "student.h"
#include <stdio.h>

int getcid()
{
    return maxid;
}

void show_stu(void *data)
{
    //    printf("学号：%d 姓名：%s 密码：%s 总分：%d ", ((stu_t *)(data))->cid, ((stu_t *)(data))->name, ((stu_t *)(data))->pass, ((stu_t *)(data))->gsum);
    //  printf("c语言成绩：%d 数学成绩：%d 语文成绩：%d 年龄：%d ", ((stu_t *)(data))->glang, ((stu_t *)(data))->gmath, ((stu_t *)(data))->gphil, ((stu_t *)(data))->age);
    //  printf("班级：%d \n ", ((stu_t *)(data))->classid);
    // printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
    printf("%d\t%s\t%s\t%d", ((stu_t *)(data))->cid, ((stu_t *)(data))->name, ((stu_t *)(data))->pass, ((stu_t *)(data))->gsum);
    printf("\t%-3d\t\t%d\t\t%d\t\t%d ", ((stu_t *)(data))->glang, ((stu_t *)(data))->gmath, ((stu_t *)(data))->gphil, ((stu_t *)(data))->age);
    printf("\t%d\n ", ((stu_t *)(data))->classid);
}

// printf("%d %s ,%s \n", ((stu_t *)data)->age, ((stu_t *)data)->name, ((stu_t *)data)->pass);

void show_stu_all(node_t *head) //显示所有学生 方便调试
{
    printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
    for (node_t *new = head->next; new != head; new = new->next)
    {
        show_stu(new->data);
        // printf("%d %s %s %d ", ((stu_t *)(new->data))->cid, ((stu_t *)(new->data))->name, ((stu_t *)(new->data))->pass, ((stu_t *)(new->data))->gsum);
        //printf("%d %d %d\n ", ((stu_t *)(new->data))->glang, ((stu_t *)(new->data))->gmath, ((stu_t *)(new->data))->gphil);
    }

    // printf("%d %s ,%s \n", ((stu_t *)data)->age, ((stu_t *)data)->name, ((stu_t *)data)->pass);
}

int cmp_stu_cid(void *data1, void *data2) //比较学生id
{
    return ((stu_t *)(data1))->cid - ((stu_t *)(data2))->cid;
}
int cmp_stu_gmath(void *data1, void *data2) //比较学生id
{
    return ((stu_t *)(data1))->gmath - ((stu_t *)(data2))->gmath;
}
int cmp_stu_glang(void *data1, void *data2) //比较学生id
{
    return ((stu_t *)(data1))->glang - ((stu_t *)(data2))->glang;
}
int cmp_stu_gphil(void *data1, void *data2) //比较学生id
{
    return ((stu_t *)(data1))->gphil - ((stu_t *)(data2))->gphil;
}
int cmp_stu_sum(void *data1, void *data2) //比较学生id
{
    return ((stu_t *)(data1))->gsum - ((stu_t *)(data2))->gsum;
}
int cmp_stu_classid(void *data1, void *data2) //比较学生id
{
    return ((stu_t *)(data1))->classid - ((stu_t *)(data2))->classid;
}

int cmp_stu_name(void *data1, void *data2)

{
    return strncmp((((stu_t *)(data1))->name), (((stu_t *)(data1))->name), sizeof((((stu_t *)(data1))->name)));
}

node_t *loadstu()
{
    node_t *head = node_init();
    FILE *fd = fopen("student.dat", "r");
    if (fd == NULL)
    {
        perror("fopen error");
        return NULL;
    }
    //int max = 0, maxid = 0;
    fscanf(fd, "%d %d", &max, &maxid);
    int cid, age, gmath, glang, gphil, gsum, order, classid;
    // char name[32], pass[16];
    //char buff[1024];
    stu_t *tmp = malloc(sizeof(stu_t));
    SYSERR(tmp, ==, NULL, "malloc error \n", NULL);
    for (int i = 0; i < max; i++)
    {
        fscanf(fd, "%d %s %s %d %d %d %d %d %d %d", &cid, tmp->name, tmp->pass, &age, &gmath, &glang, &gphil, &gsum, &order, &classid);
        // printf("%s", name);
        tmp->age = age;
        tmp->cid = cid;
        tmp->classid = classid;
        tmp->glang = glang;
        tmp->gmath = gmath;
        tmp->gphil = gphil;
        tmp->order = order;
        // tmp->gsum = gsum;
        tmp->gsum = glang + gmath + gphil;
        // strncpy(tmp->name, name, strlen(name));
        // scanf()
        //  strncpy(tmp->pass, pass, strlen(pass));
        node_inserh(head, tmp, sizeof(stu_t));
    }

   //show_stu_all(head);
    free(tmp);
    fclose(fd);
    return head;
}

int savestuInfo(node_t **head)
{
    FILE *fd = fopen("student.dat", "w");
    if (fd == NULL)
    {
        perror("fopen");
        return 1;
    }
    char tmpmax[5], tmpmaxid[5];
    sprintf(tmpmax, "%d", max);
    sprintf(tmpmaxid, "%d", maxid);
    strcat(tmpmax, " ");
    strcat(tmpmax, tmpmaxid);
    //printf("%s \n", tmpmax);
    fputs(tmpmax, fd);
    fputs("\n", fd);
    for (node_t *pcur = (*head)->next; pcur != (*head); pcur = pcur->next)
    {
        //    cid, name, pass, &age, &gmath, &glang, &gphil, &gsum, &order, &classid);

        fprintf(fd, "%d %s ", ((stu_t *)(pcur->data))->cid, ((stu_t *)(pcur->data))->name);
        fprintf(fd, "%s %d ", ((stu_t *)(pcur->data))->pass, ((stu_t *)(pcur->data))->age);
        fprintf(fd, "%d %d ", ((stu_t *)(pcur->data))->gmath, ((stu_t *)(pcur->data))->glang);
        fprintf(fd, "%d %d ", ((stu_t *)(pcur->data))->gphil, ((stu_t *)(pcur->data))->gsum);
        // fprintf(fd, "%d %d\n", ((stu_t *)(pcur->data))->order, ((stu_t *)(pcur->data))->classid);
        fprintf(fd, "%d %d\n", 0, ((stu_t *)(pcur->data))->classid);
        //    fwrite(((stu_t *)(pcur->data))->name, sizeof(((stu_t *)(pcur->data))->name), 1, fd);
    }
    // node_destory(head);
    fclose(fd);
    return 0;
}

node_t *stupwdcheck(node_t *head) //检查学生信息
{

    int cid = 0;
    char tmpcid[5];
    char pass[20];
    printf("\t\t\tinput cid please!\n");
    if (scanf(" %d", &cid) != 1)
    {
        printf("input error \n");
        stupwdcheck(head);
    }
    sprintf(tmpcid, "%d", cid);
    printf("\t\t\tinput passcode please!\n");

    if (scanf(" %s", pass) != 1)
    {
        printf("input error \n");
        stupwdcheck(head);
    }

    node_t *stu = node_find(head, tmpcid, cmp_stu_cid);
    if (stu == NULL)
    {
        printf("cant find cid \n");
        return NULL;
        // stupwdcheck(head);
    }
    if (strncmp((((stu_t *)(stu->data))->pass), pass, sizeof(((stu_t *)(stu->data))->pass)) != 0)
    {
        printf("passcode error ! \n");
        stupwdcheck(head);
    }

    return stu;
}

node_t *addstu(node_t *stulist) //插入学生信息
{

    int age, gmath, glang, gphil, classid;
    char name[32], pass[16], tmpmaxid[5];

    //输入信息
    printf("\t\t\tinput name please!\n");

    if (scanf(" %s", name) != 1)
    {
        printf("input error \n");
        return NULL;
    }
    printf("\t\t\tinput passcode please!\n");

    if (scanf(" %s", pass) != 1)
    {
        printf("input error \n");
        return NULL;
    }

    printf("\t\t\tinput age please!\n");
    if (scanf(" %d", &age) != 1)
    {
        printf("input error \n");
        return NULL;
    }
    printf("\t\t\tinput gmath please!\n");
    if (scanf(" %d", &gmath) != 1)
    {
        printf("input error \n");
        return NULL;
    }
    printf("\t\t\tinput glang please!\n");
    if (scanf(" %d", &glang) != 1)
    {
        printf("input error \n");
        return NULL;
    }
    printf("\t\t\tinput gphil please!\n");
    if (scanf(" %d", &gphil) != 1)
    {
        printf("input error \n");
        return NULL;
    }
    printf("\t\t\tinput classid please!\n");
    if (scanf(" %d", &classid) != 1)
    {
        printf("input error \n");
        return NULL;
    }
    //sprintf(tmpage, "%d", cid);
    maxid++;
    max++;
    sprintf(tmpmaxid, "%d", maxid);
    stu_t new;
    new.age = age;
    new.gmath = gmath;
    new.glang = glang;
    new.gphil = gphil;
    new.cid = maxid;
    new.gsum = gmath + glang + gphil;
    new.classid = classid;
    strncpy(new.name, name, sizeof(name));
    strncpy(new.pass, pass, sizeof(pass));

    node_inserh(stulist, &new, sizeof(new));
    //printf("%d", maxid);
    //show_stu_all(stulist);
    sortstu(stulist, 2);
    return node_find(stulist, &maxid, cmp_stu_cid);
}

int sortstu(node_t *head, int mode) //根据模式排序
                                    //1：根据学号  2：根据总分排序
{
    switch (mode)
    {
    case 1:
        node_bubble_sort(head, cmp_stu_cid);
        break;
    case 2:
        node_bubble_sort(head, cmp_stu_gmath);
        break;
    case 3:
        node_bubble_sort(head, cmp_stu_gphil);
        break;
    case 4:
        node_bubble_sort(head, cmp_stu_sum);
        break;

    default:
        break;
    }

    // show_stu_all(head);
    return 0;
}
int sortstu_t(node_t *head, int mode) //逆序排序
                                      //1：根据学号  2：根据总分排序
{
    switch (mode)
    {
    case 1:
        node_select_sort(head, cmp_stu_cid);
        break;
    case 2:
        node_select_sort(head, cmp_stu_gmath);
        break;
    case 3:
        node_select_sort(head, cmp_stu_gphil);
        break;
    case 4:
        node_select_sort(head, cmp_stu_sum);
        break;

    default:
        break;
    }

    // show_stu_all(head);
    return 0;
}
int delstu_cid(node_t *head, int cid) //根据学号删除
{

    if (node_finddelete(head, &cid, cmp_stu_cid) == 0)
    {
        printf("del id %d !\n", cid);
        max--;
        return 0;
    }
    else
    {
        printf("cant del cid:%d !\n", cid);
        return -1;
    }
}
void destory_list(node_t **head)
{
    node_destory(head);
}
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
node_t *getstu(node_t *head, int mode, void *data)
{
    node_t *new = node_init();
    node_t *newnew;
    if (mode == 0)
    {
        for (newnew = head->next; newnew != head; newnew = newnew->next)
            node_inserh(new, newnew->data, sizeof(stu_t));
        return new;
    }
    if (mode == 1)
    {
        node_t *find = node_find(head, data, cmp_stu_cid);

        return find;
    }
    if (mode == 2)
    {
        for (newnew = head->next; newnew != head; newnew = newnew->next)
        {
            //  if ((((stu_t *)(newnew->data))->classid - *(int *)data) == 0)
            if (strncmp(((stu_t *)(newnew->data))->name, (char *)data, sizeof(data)) == 0)
            {
                // node_inserh(new, newnew->data, sizeof(stu_t));
                node_inserh(new, newnew->data, sizeof(stu_t));
            }
            // printf("%s ", ((stu_t *)(newnew->data))->name);
            // printf("%d \n", *(int *)data);
        }
        return new;
    }
    if (mode == 3)
    {
        for (newnew = head->next; newnew != head; newnew = newnew->next)
        {
            if ((((stu_t *)(newnew->data))->classid - *(int *)data) == 0)
            {
                node_inserh(new, newnew->data, sizeof(stu_t));
            }
            // printf("%d ", ((stu_t *)(newnew->data))->classid);
            // printf("%d \n", *(int *)data);
        }

        return new;
    }

    //printf("input error \n");
    return NULL;
}
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
int getstudata(node_t *getnode, int mode)
{
    switch (mode)
    { //1.学号 2.学科总分 3.数学成绩 4.C语言成绩 5.语文成绩
    case 1:
        return ((stu_t *)getnode->data)->cid;
        //1.获取学号 返回 getnode->data->id;
    case 2:
        return ((stu_t *)getnode->data)->gsum = ((stu_t *)getnode->data)->gmath + ((stu_t *)getnode->data)->glang + ((stu_t *)getnode->data)->gphil;
        //2.获取学科总分，计算得出，返回总分
    case 3:
        return ((stu_t *)getnode->data)->gmath;
        // 3.获取数学成绩 ，返回数学成绩
    case 4:
        return ((stu_t *)getnode->data)->glang;
        //4.获取C语言成绩，返回C语言成绩
    case 5:
        return ((stu_t *)getnode->data)->cid;

    default:
        return -1; //5.获取语文成绩，返回语文成绩
    }
}

/*(九)函数定义： double sturank(node_t * head, int mode) 
参数：学生链表头结点head,node为获取的模式
返回值：
函数功能；根据不用mode值进行排序
函数流程：
1、如果mode为1调用blub_sort()按学生学号排序
2、如果mode为2调用blub_sort()按数学成绩排序
3、如果mode为3调用blub_sort()按C语言成绩排序
4、如果mode为4调用blub_sort()按语文成绩排序
5、如果mode为5调用blub_sort()按总分排序
*/
int sturank(node_t *head, int mode) //根据模式排序
                                    //1：根据学号  2：根据总分排序
{
    switch (mode)
    {
    case 1:
        node_bubble_sort(head, cmp_stu_cid);
        break;
    case 2:
        node_bubble_sort(head, cmp_stu_gmath);
        break;
    case 3:
        node_bubble_sort(head, cmp_stu_gphil);
        break;
    case 4:
        node_bubble_sort(head, cmp_stu_glang);
        break;
    case 5:
        node_bubble_sort(head, cmp_stu_sum);
        break;
    default:
        break;
    }

    show_stu_all(head);
    return 0;
}
/*(十)函数定义：void printnode_t(stu_t *stunode)
函数功能；显示学生节点信息*
参数：stunode为所要显示的学生结点指针
*/
void printnode_t(void *data)
{
    printf("%d %s %s %d ", ((stu_t *)(data))->cid, ((stu_t *)(data))->name, ((stu_t *)(data))->pass, ((stu_t *)(data))->gsum);
    printf("%d %d %d\n ", ((stu_t *)(data))->glang, ((stu_t *)(data))->gmath, ((stu_t *)(data))->gphil);
}
/*
根据mode 修改学生信息

*/
int updatestu(node_t *head, int mode, stu_t olddata, stu_t newdata)
{
    return 0;
}
