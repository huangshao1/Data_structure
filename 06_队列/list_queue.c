#include <stdio.h>
#include <stdlib.h>

typedef int Data_Type;

typedef struct queue
{
    Data_Type data;
    struct queue *prev, *next;
}Node, *P_Node;

P_Node node_new_init(Data_Type data)
{
    P_Node new = calloc(1, sizeof(Node));

    new->data = data;
    new->next = new->prev = new;

    return new;
}

Data_Type get_usr_input(char * msg)
{
    printf("%s\n", msg);

    Data_Type data;
    int ret_val = 0;

    while(1)
    {
        ret_val = scanf("%d", &data);
        if(ret_val != 1)
        {
            printf("你输入的数据有误！！！\n");
            while(getchar() != '\n');
            continue;
        }
        break;
    }

    return data;
}

int add_2_queue(P_Node head, Data_Type data)
{
    if(head == NULL)
    {
        printf("数据异常！！！\n");
        return -1;
    }

    P_Node new = node_new_init(data);

    new->next = head;
    new->prev = head->prev;

    head->prev->next = new;
    head->prev = new;

    return 0;
}

int exit_queue(P_Node head)
{
    if(head->next == head)
    {
        printf("当前队列为空\n");
        return -1;
    }

    P_Node tmp = head->next;

    printf("对头数据为：%d\n", tmp->data);

    head->next = tmp->next;
    tmp->next->prev = head;

    tmp->next = tmp->prev = NULL;

    free(tmp);
    tmp = NULL;

    return 0;
}

int display_queue(P_Node head)
{
    if(head->next == head)
    {
        printf("当前队列为空\n");
        return -1;
    }

    P_Node tmp = head->next;
    int m = 1;

    for ( ; tmp != head; tmp = tmp->next)
    {
        printf("任务%d:%d\n", m++, tmp->data);
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    P_Node head = node_new_init(0);
    Data_Type data;
    Data_Type tmp;
    while(1)
    {
        printf("****************************\n");
        printf("*********1、入队*************\n");
        printf("*********2、出队************\n");
        printf("*********3、显示*************\n");
        printf("****************************\n");
        Data_Type input = get_usr_input("请选择你的操作：");

        switch (input)
        {
        case 1:
            data = get_usr_input("请输入你的数据：");
            add_2_queue(head, data);
            break;
        
        case 2:
            tmp = exit_queue(head);
            printf("出队的数据为:%d\n", tmp);
            break;

        case 3:
            display_queue(head);
            break;

        default:
            break;
        }
    }
    return 0;
}
