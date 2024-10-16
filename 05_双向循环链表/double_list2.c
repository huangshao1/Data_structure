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

bool add_2_list_tail(P_Node head, P_Node new)
{
    if(head == NULL || new == NULL)
    {
        printf("数据异常！！！\n");
        return false;
    }

    new->Next = head;
    new->Prev = head->Prev;

    head->Prev->Next = new;
    head->Prev = new;

    return true;
}

bool display_list(P_Node head, bool R_L)
{
    if(head == NULL || head->Next == NULL)
    {
        printf("链表头节点异常!!!\n");
        return false;
    }
    
    P_Node tmp = NULL;

    if(R_L)
    {
        tmp = head->Next;
    }
    else
    {
        tmp = head->Prev;
    }

    while(tmp != head)
    {
        if(R_L)
        {
            //向下遍历
            printf("%p:%d\n", tmp, tmp->data);
            tmp = tmp->Next;
        }
        else
        {
            //向上遍历
            printf("%p:%d\n", tmp, tmp->data);
            tmp = tmp->Prev;
        }
    }

    // P_Node tmp = head->Next;
    // for( ; tmp !=head; tmp = tmp->Next)
    // {
    //     printf("%d\n", tmp->data);
    // }

    return true;
}

P_Node find_4_list(P_Node head, Data_Type data)
{
    if(head == NULL || head->Next == NULL)
    {
        printf("链表头节点异常!!!\n");
        return NULL;
    }

    P_Node tmp = head->Next;
    for( ; tmp !=head; tmp = tmp->Next)
    {
        if(tmp->data == data)
        {
            return tmp;
        }
    }

    return NULL;
}

P_Node del_4_list(P_Node del)
{
    if(del == NULL)
    {
        printf("没找到节点！！！\n");
        return NULL;
    }

    del->Prev->Next = del->Next;
    del->Next->Prev = del->Prev;
    del->Next = del->Prev = del;

    return del;
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
        add_2_list_tail(head, new);
    }
    
    //查找节点
    P_Node find =  find_4_list(head, 5);
    if(find == NULL)
    {
        printf("查找失败，没有数据！！！\n");
        return -1;
    }

    // display_list(head, true);

    // //删除节点
    // P_Node del = del_4_list(find);
    // printf("%p:%d\n", del, del->data);

    // //寻找一个目标位置
    // P_Node dest =  find_4_list(head, 8);

    // //移动节点
    // add_2_list_head(dest, del);

    //遍历显示链表
    display_list(head, true);

    return 0;
}
