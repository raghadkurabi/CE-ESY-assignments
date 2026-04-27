#include <stdio.h>
#include <string.h>

#define SIZE 20 // جربي مرة أصغر من طول الاسم ومرة أكبر

typedef struct
{
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb)
{
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb)
{
    return cb->count == 0;
}

void write(CircularBuffer *cb, char data)
{
    if (isFull(cb))
    {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char read(CircularBuffer *cb)
{
    if (isEmpty(cb))
    {
        printf("Buffer Underflow\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

int main()
{
    CircularBuffer cb;
    init(&cb);

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY"); // إضافة النص المطلوب

    // كتابة كل حرف في المخزن
    for (int i = 0; i < strlen(name); i++)
    {
        write(&cb, name[i]);
    }

    // قراءة وطباعة حتى يفرغ المخزن
    printf("Output: ");
    while (!isEmpty(&cb))
    {
        char c = read(&cb);
        printf("%c", c);
    }
    printf("\n");

    return 0;
}