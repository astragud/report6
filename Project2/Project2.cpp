#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element
{
    int data;
};

struct element* stack;
int top = -1;
int size = 10;

void push(int data)
{
    if (top >= size - 1)
    {
        size += 10;
        struct element* temp_stack = (struct element*)realloc(stack, size * sizeof(struct element));
        if (temp_stack != NULL)
        {
            stack = temp_stack;
        }
        if (stack == NULL)
        {
            printf("Memory reallocation error.\n");
            return;
        }
        else
        {}
    }
    top++;
    stack[top].data = data;
}

int pop()
{
    int data;
    if (top < 0)
    {
        printf("Stack underflow.\n");
        return -1;
    }
    data = stack[top].data;
    top--;
    return data;
}

int main()
{
    int i, data = 0, rand_num;
    srand(time(NULL));
    stack = (struct element*)malloc(size * sizeof(struct element));

    for (i = 0; i < 10; i++)
    {
        rand_num = rand() % 100 + 1;
        printf("Random number generated: %d\n", rand_num);

        if (rand_num % 2 == 0)
        {
            printf("Pushing %d to the stack.\n", rand_num);
            push(rand_num);
        }

        else
        {
            printf("Popping %d from the stack.\n", pop());
        }
    }

    free(stack);
    return 0;
}