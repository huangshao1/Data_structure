#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book
{
    char Name[32];
    float Price;
    int Num;
}Data_Type;

//节点设计
typedef struct stack
{
    Data_Type Book;
    struct stack *Next;
}Node, *P_Node;

P_Node init_new_node(Data_Type * data)
{
    P_Node new = calloc(1, sizeof(Node));   
    if(data != NULL)    //判断是否不是头节点初始化，则初始化节点的数据域
    {
        //初始化书名
        strncpy(new->Book.Name, data->Name, 32);
        new->Book.Num = data->Num;
        new->Book.Price = data->Price;
    }
    new->Next = NULL;

    return new;
}

int push_stack(Node * stack, Node * new)
{
    if(stack == NULL || new == NULL)
    {
        return -1;
    }

    Node * tmp = stack;
    new->Next = tmp->Next;
    tmp->Next = new;

    return 0;
}

Node * pop_stack(Node * stack)
{
    if(stack->Next == NULL)
    {
        printf("该栈为空！！\n");
        return NULL;
    }

    Node * tmp = stack->Next;
    stack->Next = tmp->Next;
    tmp->Next = NULL;

    return tmp;
}

int main(int argc, char const *argv[])
{
    Node * stack = init_new_node(NULL);

    Data_Type data;
    Node * new = NULL;

    for (int i = 0; i < 5; i++)
    {
        sprintf(data.Name, "语文 %d", i);
        data.Num = i;
        data.Price = 34.23;

        //创建新节点
        new = init_new_node(&data);

        //入栈
        push_stack(stack, new);
        printf("Name:%s\tNum:%d\tPrice:%f\n", new->Book.Name, new->Book.Num, new->Book.Price);
    }
    
    for (int i = 0; i < 6; i++)
    {
        //出栈
        Node * node = pop_stack(stack);

        if(node == NULL)
        {
            break;
        }
        printf("Name:%s\tNum:%d\tPrice:%f\n", node->Book.Name, node->Book.Num, node->Book.Price);
        free(node);
    }


    return 0;
}
