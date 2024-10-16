#include <stdio.h>
#include <stdlib.h>

typedef int Data_Type;
#define DATA_SIZE 10
//设计一个管理结构
typedef struct data{
    Data_Type * Data_Enter;     //堆空间的入口地址
    int Size;                   //数据总量
    int Last;                   //当前的使用量
}Data, *P_Data;

Data * init_data()
{
    P_Data ptr = calloc(1, sizeof(Data));
    //申请堆空间来作为顺序表的存储空间
    ptr->Data_Enter = calloc(DATA_SIZE, sizeof(Data_Type));
    ptr->Size = DATA_SIZE;   //设置顺序表的大小为10
    ptr->Last = 0;   //设置当前使用量为0

    return ptr;
}

int ins_data(Data * Ctrl, Data_Type new_data)
{
    //判断管理结构体指针是否为空
    //当前管理结构体中现有数据是否已满
    if(Ctrl == NULL || Ctrl->Last == Ctrl->Size)
    {
        printf("当前内存已满！！！\n");
        return 0;
    }

    int tmp = 0;
    if(!(Ctrl->Last == 0))
    {
        for (int i = 0; i < Ctrl->Last; i++)
        {
            if(new_data <= Ctrl->Data_Enter[i])
            {
                tmp = i;
                for (int j = Ctrl->Last; j >= i; j--)
                {
                    Ctrl->Data_Enter[j] = Ctrl->Data_Enter[j-1];
                }
                //把数据存放到顺序表的内存中
                Ctrl->Data_Enter[tmp] = new_data;
                //让顺序表的当前下表往后移动
                Ctrl->Last++;
                return Ctrl->Last;
            }
        }
    }
    //把数据存放到顺序表的内存中
    Ctrl->Data_Enter[Ctrl->Last] = new_data;
    //让顺序表的当前下表往后移动
    Ctrl->Last++;

    return Ctrl->Last;
}

int displayer_data(Data* Ctrl)
{
    //判断管理结构体指针是否为空
    //当前管理结构体中现有数据是否已满
    if(Ctrl == NULL || Ctrl->Last == 0)
    {
        printf("当前顺序表为空！！！\n");
        return Ctrl->Last;
    }

    for (size_t i = 0; i < Ctrl->Last; i++)
    {
        printf("data:%d\n", *(Ctrl->Data_Enter+i));
    }
    
    return Ctrl->Last;
}

int main(int argc, char const *argv[])
{
    //初始化
    P_Data Ctrl = init_data();    //定义一个结构体指针，大小为8字节（64位系统）
    init_data(&Ctrl);    //传递的参数为指针的地址
    printf("Data_Enter:%p, Size:%d, Last:%d\n", Ctrl->Data_Enter, Ctrl->Size, Ctrl->Last);

    for (size_t i = 0; i < 10; i++)
    {
        //创建数据
        printf("请输入需要插入的数据：\n");
        Data_Type new_data;
        scanf("%d", &new_data);
        while(getchar()!='\n');

        //插入数据
        if(!ins_data(Ctrl, new_data))
        {
            break;
        }
    }
    
    //显示数据
    displayer_data(Ctrl);
    return 0;
}
