#include "output.h"

bool display_list(P_Node head, bool R_L)
{
    if(head == NULL || head->Next == NULL)
    {
        printf("链表头节点异常!!!\n");
        return false;
    }
    
    P_Node tmp = NULL;

    if(R_L) //  判断需要往前（左）往后（右）
    {
        //使用下一个往右
        tmp = head->Next;
    }
    else
    {
        //使用上一个往左
        tmp = head->Prev;
    }

    while(tmp != head)  //  只要tmp等于头节点则表示到达了末尾（遍历结束）
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