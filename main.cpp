/**
 *   Function Description：      循环队列
 *   Environment：               Code::Blocks 17.12
 *   Author:                     Malones
 *   Date:                       2020.12.30
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 20
typedef int Element;
typedef struct Queue{
    int size;
    int front_vex;
    int last_vex;
    Element data[MAX];
}Queue;

void show();   //操作界面
void init_queue( Queue* t);   //队列初始化
int empty( Queue* t);   //查询队列是否为空
int size_of_queue( Queue*t);   //返回队列中元素个数
void push( Queue *t, Element data_);   //往队列中插入数据
Element pop( Queue* t);   //得到队头元素

int main(){
    system("title 循环队列");   //cmd窗口名称
    int t;   //记录想要执行的操作
    int number;   //用于pop和push
    show();
    scanf("%d", &t);
    Queue myQueue;
    while( t){
        if( t == 1){   //init
            init_queue(&myQueue);
        }else if( t == 2){   //push
            if( size_of_queue( &myQueue) < 21){
                printf("请输入插入的数:\n");
                scanf("%d", &number);
                push( &myQueue, number);
            }else
                printf("队列已满, 无法插入");
        }else if( t == 3){   //pop
            if( empty( &myQueue))
                printf("队列为空");
            else{
                number = pop(&myQueue);
                printf("队头元素为: %d", number);
            }
        }
        Sleep(1000);
        system("cls");
        show();
        scanf("%d", &t);
    }
    return 0;
}

/** \brief 操作界面的显示
 */
void show(){
    printf("-------循环队列-------\n");
    printf("1.init\t\t2.push\n");
    printf("3.pop\t\t0.exit\n");
    printf("choose:");
}
/** \brief 队列初始化
 * \param t: 目标队列
 */
void init_queue( Queue* t){
    int i = 0;
    t->size = 0;
    t->front_vex = -1;
    t->last_vex = -1;
    for( i = 0; i < MAX; i++)
        t->data[i] = 0;
}

/** \brief 查询队列是否为空
 * \param t: 目标队列
 * \return 1: 空    0: 非空
 */
int empty( Queue* t){
    return t->size == 0;
}

/** \brief 返回队列中元素个数
 * \param t: 目标队列
 * \return 队列中元素个数
 */
int size_of_queue( Queue*t){
    return t->size;
}

/** \brief 往队列中插入数据
 * \param t: 插入的目标队列
 * \param data_: 待插入的数据
 */
void push( Queue *t, Element data_){
    t->size++;
    if( t->last_vex == 19)   //开始循环到队列数组首
        t->last_vex = -1;
    t->data[ ++t->last_vex] = data_;
}

/** \brief 得到队头元素
 * \param t: 目标队列
 * \return 队头元素的数据
 */
Element pop( Queue* t){
    t->size--;
    if( t->front_vex == 19)
        t->front_vex = -1;
    return t->data[ ++t->front_vex];
}
