#include "input.h"

P_Node new_node_init(Data_Type data)
{
    //申请一个堆空间用来存放新节点
    P_Node new = calloc(1, sizeof(Node));
    if(new == NULL)
    {
        //标准出错文件              获得出错的原因信息
        fprintf(stderr, "出现异常:%s\n", strerror(errno));
        return NULL;
    }

    //新节点数据初始化
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

    //让新节点的前驱后继指针，分别指向头节点和头节点的后继节点
    new->Next = head->Next;
    new->Prev = head;

    //让头节点的后继节点的前驱指针，指向新节点
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

    //让新节点的前驱后继指针，分别指向头节点和头节点的前驱节点
    new->Next = head;
    new->Prev = head->Prev;

    //让头节点的前驱节点的后继指针，指向新节点
    head->Prev->Next = new;

    //让头节点的前驱指针指向新节点
    head->Prev = new;

    return true;
}

P_Node del_4_list(P_Node del)
{
    if(del == NULL)
    {
        printf("没找到节点！！！\n");
        return NULL;
    }

    //让删除节点的前后节点都不要指向删除节点，而是分别指向前/后节点
    del->Prev->Next = del->Next;
    del->Next->Prev = del->Prev;

    //让删除节点的前后指针指向字节
    del->Next = del->Prev = del;

    return del;
}

void double_list_mix(P_Node L1, P_Node L2)
{
    
    L2->Prev->Next = L1;
    L1->Prev->Next = L2->Next;

    L2->Next->Prev = L1->Prev;
    L1->Prev = L2->Prev;    

    L2->Next = L2->Prev = L2;
    
}
