#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Process: Each process has a name and has an execution time.
 *          We keep track of how long the process still needs
 *          to run on the processor. "remaining_time" is the
 *          remaining execution time of the process.
 */
typedef struct {
    char *name;
    int starting_time;
    int remaining_time;
} Process;

Process *newProcess(char *name, int starting_time, int remaining_time) {
    Process *p = malloc(sizeof(Process));
    p->name = malloc(sizeof(char) * 256);
    strcpy(p->name, name);
    p->starting_time = starting_time;
    p->remaining_time = remaining_time;
    return p;
}

/*
 *
 */
typedef struct Node {
    Process data;
    struct Node *next;
} Node;

Node *newNode(Process p) {
    Node *n = malloc(sizeof(Node));
    n->data = p;
    n->next = NULL;
    return n;
}

/*
 *
 */
typedef struct {
    Node *head;
    Node *tail;
} Queue;

/*
 *
 */
Queue *init() {
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

/*
 *
 */
int isEmpty(Queue *q) {
    return q->head == NULL;
}

/*
 *
 */
Process dequeue(Queue *q) {
    if (q->head) {
        Process result;
        Node *temp = q->head;
        result = temp->data;
        q->head = temp->next;
        free(temp);
        if (q->head == NULL)
            q->tail = NULL;
        return result;
    }
}

/*
 *
 */
void enqueue(Queue *q, Process p) {
    Node *n = newNode(p);
    if (q->head == NULL)
        q->head = q->tail = n;
    else {
        q->tail->next = n;
        q->tail = n;
    }
}

/*
 *
 */
void destroy(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

int getWatchTime(FILE *f) {
    int watch_time;
    char buffer[10];
    // gets watching time slots
    fscanf(f, "%s %s %s %s %d\n", buffer, buffer, buffer, buffer, &watch_time);
    return watch_time;
}

/*
 * RoundRobin Scheduling
 */
void RoundRobin(char *filename) {
    FILE *f = fopen(filename, "r");
    Queue *queue = init();
    int watch_time = getWatchTime(f);
    Process *processes[watch_time];
    int number_of_processes = 0;

    // reads processes into processes array
    while (!feof(f)) {
        char process_name[256];
        int starting_time;
        int remaining_time;
        // reads the processes
        fscanf(f, "%s %d %d\n", process_name, &starting_time, &remaining_time);
        Process *process = newProcess(process_name, starting_time, remaining_time);
        processes[number_of_processes++] = process;
    }

    for (int i = 0; i < watch_time; i++) {
        Process current_process;

        // puts the processes in queue at appropriate time
        for (int j = 0; j < number_of_processes; j++) {
            Process process = *processes[j];
            if (process.starting_time == i) {
                enqueue(queue, process);
            }
        }
        // gets the next element in queue
        current_process = dequeue(queue);

        // reduce remaining time and print the process if the process is not null
        if (current_process.name) {
            current_process.remaining_time--;
            printf("%s\t", current_process.name);
        } else // if the process is null prints idle
            printf("idle\t");

        // if the process is not null and there is remaining time enqueue it
        if (current_process.remaining_time != 0 && current_process.name)
            enqueue(queue, current_process);

        printf("(%d-->%d) ", i, i + 1);
        // if the process is finished prints aborts
        if (current_process.remaining_time == 0)
            printf("%s aborts", current_process.name);

        printf("\n");
    }

    destroy(queue);
    printf("stop\n");
}

/*
 *
 */
int main() {
    char filename[261];
    puts("Enter file name or Ctrl+Z to exit:");
    puts("----------------------------------");
    while (fgets(filename, 260, stdin) != NULL) {
        filename[strlen(filename) - 1] = '\0';
        if (fopen(filename, "r"))
            RoundRobin(filename);
        else {
            puts("File Not Found!");
            puts("----------------------------------");
        }
        puts("Enter file name or Ctrl+Z to exit:");
        puts("----------------------------------");
    }
    return 0;
}
