#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Process: Each process has a name and has an execution time.
 *          We keep track of how long the process still needs
 *          to run on the processor. "remaining_time" is the
 *          remaining execution time of the process.
 */
typedef struct
{
    char *name;
    int starting_time;
    int remaining_time;
} Process;
/*
 *
 */
typedef struct Node
{
    Process data;
    struct Node* next;
} Node;
/*
 *
 */
typedef struct
{
    /* TODO: ADD YOUR CODE HERE */
} Queue;
/*
 *
 */
Queue* init()
{
    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
int isEmpty(Queue *q)
{
    /* TODO: ADD YOUR CODE HERE */

}
/*
 *
 */
Process dequeue(Queue *q)
{
    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
void enqueue(Queue *q, Process x)
{
    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
void destroy(Queue *q)
{
    /* TODO: ADD YOUR CODE HERE */
}
/*
 * RoundRobin Scheduling
 */
void RoundRobin(char* filename)
{
    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
int main()
{
    char filename[261];
    puts("Enter file name or Ctrl+Z to exit:");
    puts("----------------------------------");
    while(fgets(filename, 260, stdin) != NULL)
    {
        filename[strlen(filename)-1]='\0';
        if(fopen(filename,"r"))
            RoundRobin(filename);
        else
        {
            puts("File Not Found!");
            puts("----------------------------------");
        }
        puts("Enter file name or Ctrl+Z to exit:");
        puts("----------------------------------");
    }

    return 0;
}
