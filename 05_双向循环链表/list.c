#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

typedef int Data_Type;

typedef struct node
{
    Data_Type data;
    struct node *Prev;
    struct node *Next;
}Node, *P_Node;

P_Node new_node_init(Data_Type data)
{
    P_Node new = calloc(1, sizeof(Node));
    if(new == NULL)
    {
        fprintf(stderr, "出现异常:%s\n", strerror(errno));
        return NULL;
    }

    new->data = data;
    new->Next = new;
    new->Prev = new;

    return new;
}

bool add_2_list_head(P_Node head, P_Node new)
{
    if(head == NULL)
    {
        printf("数据异常！！！\n");
        return false;
    }

    new->Next = head->Next;
    new->Prev = head;
    head->Next->Prev = new;
    head->Next = new;

    return true;
}

bool display_list(P_Node head)
{
    if(head == NULL || head->Next == NULL)
    {
        printf("链表头节点异常!!!\n");
        return false;
    }

    P_Node tmp = head->Next;
    for( ; tmp !=head; tmp = tmp->Next)
    {
        printf("%d\n", tmp->data);
    }

    return true;
}

int main(int argc, char const *argv[])
{
    //初始化头节点
    P_Node head = new_node_init(0);

    for (int i = 0; i < 10; i++)
    {
        //创建新节点
        P_Node new = new_node_init(i);

        //添加新数据
        add_2_list_head(head, new);
    }

    //遍历显示链表
    display_list(head);

    return 0;
}
