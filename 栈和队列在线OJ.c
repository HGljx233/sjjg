#include"Common.h"
//3、用栈实现队列[https://leetcode-cn.com/problems/implement-queue-using-stacks/]

//链栈
#define ElemType char
typedef struct LinkStackNode
{
    ElemType data;
    struct LinkStackNode* next;
}LinkStackNode;
typedef struct LinkStack
{
    LinkStackNode* head;
}LinkStack;

void LinkStackInit(LinkStack* pst);
void LinkStackPush(LinkStack* pst, ElemType v);
void LinkStackPop(LinkStack* pst);
ElemType LinkStackTop(LinkStack* pst);
void LinkStackShow(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);
bool LinkStackEmpty(LinkStack* pst);

void LinkStackInit(LinkStack* pst)
{
    pst->head = NULL;
}

void LinkStackPush(LinkStack* pst, ElemType v)
{
    LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
    assert(s != NULL);
    s->data = v;

    s->next = pst->head;
    pst->head = s;
}

void LinkStackPop(LinkStack* pst)
{
    LinkStackNode* p;
    if (pst->head == NULL)
        return;
    p = pst->head;
    pst->head = p->next;
    free(p);
}

ElemType LinkStackTop(LinkStack* pst)
{
    assert(pst->head != NULL);
    return pst->head->data;
}

void LinkStackShow(LinkStack* pst)
{
    LinkStackNode* p = pst->head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void LinkStackDestroy(LinkStack* pst)
{
    LinkStackNode* p = pst->head;
    while (p != NULL)
    {
        pst->head = p->next;
        free(p);
        p = pst->head;
    }
}

bool LinkStackEmpty(LinkStack* pst)
{
    return pst->head == NULL;
}
//////////////////////////////////////////////

typedef struct
{
    LinkStack st1;
    LinkStack st2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
    LinkStackInit(&(pq->st1));
    LinkStackInit(&(pq->st2));
    return pq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
    LinkStackPush(&(obj->st1), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
    if (LinkStackEmpty(&(obj->st2)))
    {
        while (!LinkStackEmpty(&(obj->st1)))
        {
            LinkStackPush(&(obj->st2), LinkStackTop(&(obj->st1)));
            LinkStackPop(&(obj->st1));
        }
    }
    int val = LinkStackTop(&(obj->st2));
    LinkStackPop(&(obj->st2));
    return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
    if (LinkStackEmpty(&(obj->st2)))
    {
        while (!LinkStackEmpty(&(obj->st1)))
        {
            LinkStackPush(&(obj->st2), LinkStackTop(&(obj->st1)));
            LinkStackPop(&(obj->st1));
        }
    }
    return LinkStackTop(&(obj->st2));
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
    return LinkStackEmpty(&(obj->st1)) && LinkStackEmpty(&(obj->st2));
}

void myQueueFree(MyQueue* obj)
{
    LinkStackDestroy(&(obj->st1));
    LinkStackDestroy(&(obj->st2));
    free(obj);
}



//4、设计循环队列[https://leetcode-cn.com/problems/design-circular-queue/]
typedef struct
{
    int* base;
    int capacity;
    int front;
    int rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    pcq->capacity = k;
    pcq->base = (int*)malloc(sizeof(int) * (pcq->capacity + 1));
    pcq->front = pcq->rear = 0;
    return pcq;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->rear + 1) % (obj->capacity + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj))
        return false;

    obj->base[obj->rear] = value;
    obj->rear = (obj->rear + 1) % (obj->capacity + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front = (obj->front + 1) % (obj->capacity + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->base[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->base[(obj->rear - 1 + obj->capacity + 1) % (obj->capacity + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->base);
    obj->base = NULL;
    obj->front = obj->rear = 0;
    free(obj);
}
//用队列实现栈
#define ElemType int
typedef struct LinkQueueNode
{
    ElemType data;
    struct LinkQueueNode* link;
}LinkQueueNode;

typedef struct LinkQueue
{
    LinkQueueNode* front;
    LinkQueueNode* rear;
}LinkQueue;

void LinkQueueInit(LinkQueue* pq);
void LinkQueuePush(LinkQueue* pq, ElemType v);
void LinkQueuePop(LinkQueue* pq);
ElemType LinkQueueFront(LinkQueue* pq);
ElemType LinkQueueBack(LinkQueue* pq);
void LinkQueueShow(LinkQueue* pq);
bool LinkQueueEmpty(LinkQueue* pq);
void LinkQueueDestroy(LinkQueue* pq);

void LinkQueueInit(LinkQueue* pq)
{
    pq->front = pq->rear = NULL;
}
void LinkQueuePush(LinkQueue* pq, ElemType v)
{
    LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    assert(s != NULL);
    s->data = v;
    s->link = NULL;

    if (pq->front == NULL)
        pq->front = pq->rear = s;
    else
    {
        pq->rear->link = s;
        pq->rear = s;
    }
}
void LinkQueuePop(LinkQueue* pq)
{
    LinkQueueNode* p;
    if (pq->front == NULL)
        return;
    p = pq->front;
    pq->front = p->link;
    free(p);
}

ElemType LinkQueueFront(LinkQueue* pq)
{
    assert(pq->front != NULL);
    return pq->front->data;
}
ElemType LinkQueueBack(LinkQueue* pq)
{
    assert(pq->front != NULL);
    return pq->rear->data;
}
void LinkQueueShow(LinkQueue* pq)
{
    LinkQueueNode* p = pq->front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

bool LinkQueueEmpty(LinkQueue* pq)
{
    return pq->front == NULL;
}

void LinkQueueDestroy(LinkQueue* pq)
{
    while (pq->front != NULL)
    {
        LinkQueueNode* p = pq->front;
        pq->front = p->link;
        free(p);
    }
    pq->front = pq->rear = NULL;
}

////////////////////////////////////////////////////////////
typedef struct
{
    LinkQueue q1;
    LinkQueue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    LinkQueueInit(&(pst->q1));
    LinkQueueInit(&(pst->q2));
    return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
    LinkQueue* pnoempty;
    if (!LinkQueueEmpty(&(obj->q1)))
        pnoempty = &(obj->q1);
    else
        pnoempty = &(obj->q2);
    LinkQueuePush(pnoempty, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
    LinkQueue* pnoempty, * pempty;
    if (!LinkQueueEmpty(&(obj->q1)))
    {
        pnoempty = &(obj->q1);
        pempty = &(obj->q2);
    }
    else
    {
        pnoempty = &(obj->q2);
        pempty = &(obj->q1);
    }

    int val;
    while (!LinkQueueEmpty(pnoempty))
    {
        val = LinkQueueFront(pnoempty);
        LinkQueuePop(pnoempty);

        if (LinkQueueEmpty(pnoempty))
            break;

        LinkQueuePush(pempty, val);
    }
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
    LinkQueue* pnoempty, * pempty;
    if (!LinkQueueEmpty(&(obj->q1)))
    {
        pnoempty = &(obj->q1);
        pempty = &(obj->q2);
    }
    else
    {
        pnoempty = &(obj->q2);
        pempty = &(obj->q1);
    }

    int val;
    while (!LinkQueueEmpty(pnoempty))
    {
        val = LinkQueueFront(pnoempty);
        LinkQueuePop(pnoempty);
        LinkQueuePush(pempty, val);
    }
    return val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
    return LinkQueueEmpty(&(obj->q1)) && LinkQueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj)
{
    LinkQueueDestroy(&(obj->q1));
    LinkQueueDestroy(&(obj->q2));
    free(obj);
}


//括号匹配问题
typedef char STDatatype;
typedef struct Stack
{
    STDatatype* a;
    int top;        // 栈顶
    int capacity;
}ST;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
int StackSize(ST* ps);
STDatatype StackTop(ST* ps);
void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0; // -1
    ps->capacity = 0;
}


void StackDestroy(ST* ps)
{
    assert(ps);
    if (ps->a)
    {
        free(ps->a);
    }
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}


void StackPush(ST* ps, STDatatype x)
{
    assert(ps);


    // 检查空间够不够，不够就增容
    if (ps->top == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDatatype* tmp = realloc(ps->a, sizeof(STDatatype) * newcapacity);
        if (tmp == NULL)
        {
            printf("rellaoc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }


    ps->a[ps->top] = x;
    ps->top++;
}


void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));


    --ps->top;
}


bool StackEmpty(ST* ps)
{
    assert(ps);


    return ps->top == 0;
}


int StackSize(ST* ps)
{
    assert(ps);


    return ps->top;
}


STDatatype StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));


    return ps->a[ps->top - 1];
}


bool isValid(char* s) {
    ST st;
    StackInit(&st);
    bool match = true;
    while (*s)
    {
        if (*s == '[' || *s == '(' || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        else
        {
            if (StackEmpty(&st))
            {
                match = false;
                break;
            }


            char ch = StackTop(&st);
            StackPop(&st);
            if ((*s == ']' && ch != '[')
                || (*s == '}' && ch != '{')
                || (*s == ')' && ch != '('))
            {
                match = false;
                break;
            }
            else
            {
                ++s;
            }
        }
    }


    if (match == true)
    {
        match = StackEmpty(&st);
    }


    StackDestroy(&st);

    return match;
}

bool isValid(char* s) {
    if (*s == NULL || *s == '\0')
        return true;
    int len = strlen(s);
    char* st = (char*)malloc(sizeof(char) * len);
    int top = 0;
    while (*s) {
        if (*s == '{' || *s == '[' || *s == '(')
            st[top++] = *s;
        else
        {
            if (top == 0)
                return false;
            char top_val = st[top - 1];
            if ((*s == '}' && top_val != '{') ||
                (*s == ']' && top_val != '[') ||
                (*s == ')' && top_val != '('))
            {
                return false;

            } top--;
        }
        s++;
    }
    if (top == 0)
        return true;
    return false;
}