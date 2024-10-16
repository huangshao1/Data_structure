#include <stdio.h>
#include <stdlib.h>

typedef int Data_Type;

//节点设计
typedef struct list
{
    Data_Type Num;  //数据
    struct list *Next;  //后继指针
}List, *P_list;

//初始化
P_list init_new_node(Data_Type data)
{
    P_list new = calloc(1, sizeof(List));
    new->Num = data;
    new->Next = new;

    return new;
}

int list_add_2_tail(P_list head, P_list new)
{
    if(head == NULL || new == NULL)
    {
        printf("数据异常！！！\n");
        return -1;
    }

    P_list tmp = head;
    for( ; tmp->Next != head; tmp = tmp->Next);

    new->Next = tmp->Next;
    tmp->Next = new;

    return 0;
}

void display_list(P_list head)
{
    if(head == NULL || head->Next == head)
    {
        printf("数据可能异常！！！\n");
        return ;
    }

    P_list tmp = head->Next;
    for( ; tmp != head; tmp = tmp->Next)
    {
        printf("%d\n", tmp->Num);
    }

    // printf("%d\n", tmp->Num);

    return ;
}

int main(int argc, char const *argv[])
{
    P_list head = init_new_node(0);

    for (int i = 0; i < 10; i++)
    {
        //创建新节点
        P_list new = init_new_node(i);

        //插入新节点
        list_add_2_tail(head, new);
    }
    
    display_list(head);

    return 0;
}
