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
void enqueue(Queue *q, Process x) {
    Node *n = newNode(x);
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

Process *getProcesses(FILE *f, int watchTime) {
    char process_name[2];
    int starting_time;
    int remaining_time;
    Process processes[watchTime];

    int i = 0;
    while (!feof(f)) {
        // reads the processes
        fscanf(f, "%s %d %d", process_name, &starting_time, &remaining_time);
        Process process = {process_name, starting_time, remaining_time};
        processes[i++] = process;
    }
    return processes;
}

int getWatchTime(FILE *f) {
    int watch_time;
    char buffer[10];
    // gets watching time slots
    fscanf(f, "%s %s %s %s %d", buffer, buffer, buffer, buffer, &watch_time);
    return watch_time;
}

/*
 * RoundRobin Scheduling
 */
void RoundRobin(char *filename) {
    FILE *f = fopen(filename, "r");
    Queue *queue = init();
    int watch_time = getWatchTime(f);
    Process *processes = getProcesses(f, watch_time);
    int number_of_processes = sizeof processes / sizeof processes[0];

    for (int i = 0; i < watch_time; i++) {
        Process process = processes[i % number_of_processes];
        if (process.starting_time == i)
            enqueue(queue, process);
        Process current_process = dequeue(queue);
        current_process.remaining_time = current_process.remaining_time - 1;
        char *process_id = isEmpty(queue) ? "idle" : current_process.name;
        char *message = current_process.remaining_time == 0 ? strcat(process_id, " aborts") : "";
        printf("%s (%d-->%d) %s\n", process_id, i, i + 1, message);
    }
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
