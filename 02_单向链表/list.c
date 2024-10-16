#include <stdio.h>
#include <stdlib.h>

typedef int Data_Type;

//节点设计
typedef struct list
{
    Data_Type Num;  //数据
    struct list *Next;  //后继指针
}List, *P_list;

P_list init_new_node(Data_Type new_data)
{
    //申请一个头节点
    List *head = calloc(1, sizeof(List));

    head->Num = new_data;
    head->Next = NULL;  //初始化后继指针指向空

    return head;
}

int add_2_list_tail(P_list head, P_list new_node)
{
    if(head == NULL)
    {
        printf("链表头异常！！\n");
        return -1;
    }

    //遍历找到链表的末尾
    P_list tmp;
    // while(tmp->Next != NULL)
    // {
    //     tmp = tmp->Next;
    // }

    for(tmp = head; tmp->Next != NULL; tmp = tmp->Next);

    //1 让新节点的后继指针指向头节点的后继节点
    new_node->Next = tmp->Next;

    //2 让头节点的后继指针指向新节点
    tmp->Next = new_node;

    return 0;
}

int add_2_list_head(P_list head, P_list new_node)
{
    if(head == NULL)
    {
        printf("链表头异常！！\n");
        return -1;
    }

    //1 让新节点的后继指针指向头节点的后继节点
    new_node->Next = head->Next;

    //2 让头节点的后继指针指向新节点
    head->Next = new_node;

    return 0;
}

List * list_4_each(List * head, Data_Type * Num)
{
    if(head->Next == NULL)
    {
        printf("该表为空！！\n");
        return NULL;
    }

    List* tmp = head; //把头节点的Next

    while(tmp->Next != NULL)
    {
        if(Num == NULL)
        {
            printf("data:%d\n", tmp->Next->Num);
        }
        else
        {
            if(tmp->Next->Num == *Num)
            {
                return tmp;
            }
        }
        tmp = tmp->Next;
    }

    return NULL;
}

List * del_4_list(List * head, Data_Type del_num)
{
    if(head->Next == NULL)
    {
        printf("该表已空!!\n");
        return NULL;
    }

    //遍历查找需要移除的节点
    List * tmp = list_4_each(head, &del_num);
    List * del = tmp->Next;

    //把找到的节点从链表中剔除
    tmp->Next = del->Next;  //让需要删除删除节点的前一个节点的后继指针指向需要删除节点的后继指针
    del->Next = NULL;   //让del的next不要再指向链表

    return del;
}

void move_node(List * head, Data_Type move_data, Data_Type move_tag)
{
    //找到需要移动的数据并把它从链表中剔除
    List* move_node = del_4_list(head, move_data);

    //找到目标位置
    List * tag_node = list_4_each(head, &move_tag);

    //把剔除的数据插入到目标位置
    add_2_list_head(tag_node->Next, move_node);

}

int main(int argc, char const *argv[])
{
    //初始化链表头
    List * head = init_new_node(0);

    for (int i = 1; i < 11; i++)
    {
        List* new_node = init_new_node(i);
        //插入数据
        add_2_list_tail(head, new_node);

    }

    //从链表中剔除节点
    List * del = del_4_list(head, 10);
    printf("%p:%d\n", del, del->Num);
    free(del);
    del = NULL;

    //显示链表
    list_4_each(head, NULL);

    //移动数据
    move_node(head, 2, 6);    //把数据移动到数据6的后面
    
    list_4_each(head, NULL);

    return 0;
}
