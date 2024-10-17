#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data_Type;

//队列管理结构体的设计
typedef struct queue
{
    Data_Type * Enter;  // 队列的rukoudizh
    int size;           // 队列的大小
    int fornt;          // 队列的头部
    int rear;           // 队列的尾部
}Node, *P_Node;

P_Node queue_init(int queue_size)
{
    //申请管理结构体
    P_Node queue = calloc(1, sizeof(Node));

    //申请一个队列空间并把入口地址赋值给管理结构体中的入口成员
    queue->Enter = calloc(1, sizeof(Data_Type));

    //设置管理结构体中队列的大小
    queue->size = queue_size;

    //设置队头等于队尾，表示空队

    queue->fornt = queue->rear = 0;

    return queue;

}

bool add_2_queue(P_Node queue, Data_Type data)
{
    if(queue == NULL || queue->Enter == NULL || queue->fornt == (queue->rear + 1) % queue->size)
    {
        printf("队列异常， 队列为满！！！\n");
        return false;
    }

    //把数据存入到当前 队尾标记的下标位置
    *(queue->Enter + queue->rear) = data;

    //队尾往后挪一个（下标）
    queue->rear = (queue->rear + 1) % queue->size;

    return true;
}

Data_Type exit_queue(P_Node queue)
{
    if(queue->fornt == queue->rear)
    {
        printf("队列为空，没有任务！！！\n");
        return -1;
    }

    Data_Type tmp = *(queue->Enter + queue->fornt);

    queue->fornt = (queue->fornt + 1) % queue->size;

    return tmp;
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

int display_queue(P_Node queue)
{
    if(queue->fornt == queue->rear)
    {
        printf("队列为空，没有任务！！！\n");
        return -1;
    }

    int m = 1;
    for(int i = queue->fornt; i != queue->rear; i = (i+1) % queue->size)
    {
        printf("当前任务%d:%d\n", m++, *(queue->Enter + i));
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    P_Node queue = queue_init(5);
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
            add_2_queue(queue, data);
            break;
        
        case 2:
            tmp = exit_queue(queue);
            printf("出队的数据为:%d\n", tmp);
            break;

        case 3:
            display_queue(queue);
            break;

        default:
            break;
        }
    }

    free(queue->Enter);
    free(queue);

    return 0;
}
