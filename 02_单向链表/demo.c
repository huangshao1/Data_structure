#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int Data_Type;

typedef struct demo
{
    Data_Type data;
    struct demo * Next;
}Node, *P_Node;

Node * new_node_init(Data_Type data)
{
    Node * new = calloc(1, sizeof(Node));
    if(new == NULL)
    {
        //通过标准出错来输出问题信息，并结合strerror来获得出错的原因
        fprintf(stderr, "申请内存失败，原因是：%s\n", strerror(errno));
        return NULL;
    }

    //让结构体中后继指针指向空
    new->Next = NULL;

    //初始化节点的数据
    new->data = data;

    return new;
}

Data_Type get_usr_input(char *msg)
{
    printf("%s\n", msg);

    Data_Type data;
    int ret_val = 0;

    while(1)
    {
        ret_val = scanf("%d", &data);
        if(ret_val != 1)
        {
            printf("你输入的数据有误！！\n请重新输入：\n");
            while(getchar() != '\n');   //清空输入缓冲区
            continue;
        }
        break;
    }

    return data;
}

Node * find_node(Node * head, Data_Type data)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node * tmp = head;

    while(tmp->Next != NULL)
    {
        if(tmp->Next->data > data)  //如果大于表示找到了合适位置
        {
            return tmp; //返回新节点应该放的位置的前一个节点
        }
        tmp = tmp->Next;    //如果不大于则遍历下一个
    }

    return tmp;
}

Data_Type display_list(Node * head)
{
    if(head == NULL)
    {
        return -1;
    }

    Node * tmp = head;

    while(tmp->Next != NULL)
    {
        printf("data:%d\n", tmp->Next->data);
        tmp = tmp->Next;    //如果不大于则遍历下一个
    }

    return 0;
}

Node * ins2_list(Node * head, Node * new)
{
    if(head == NULL || new == NULL)
    {
        return NULL;
    }

    Node * dest = NULL;

    if(head->Next == NULL)
    {
        //直接插入
        dest = head;
    }
    else
    {
        dest  = find_node(head, new->data);
    }

    //让新节点的后继指针等于dest的后继指针
    new->Next = dest->Next;

    //让dest的后继指针指向new
    dest->Next = new;

    return new;
}

int main(int argc, char const *argv[])
{
    //初始化
    Node * head = new_node_init(0);

    for (size_t i = 0; i < 5; i++)
    {
        //添加数据
        Data_Type data = get_usr_input("请输入一个新的数据进行插入：");

        //根据新的数据生成一个新节点
        Node * new = new_node_init(data);

        //把新节点插入到链表中
        ins2_list(head, new);
    }

    //遍历显示链表内容
    display_list(head);

    return 0;
}

