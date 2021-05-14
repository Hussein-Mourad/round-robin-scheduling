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

Process *getProcesses(FILE *f, int watch_time) {
    char process_name[2];
    int starting_time;
    int remaining_time;
    Process *processes = malloc(sizeof(Process) * watch_time);

    int i = 0;
    while (!feof(f)) {
        // reads the processes
        fscanf(f, "%s %d %d", process_name, &starting_time, &remaining_time);
//        printf("%s %d %d", process_name, starting_time, remaining_time);
        Process process = {process_name, starting_time, remaining_time};
        processes[i++] = process;
    }
    return processes;
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
    char *s[watch_time];

    int number_of_processes = 0;

    while (!feof(f)) {
        char process_name[10];
        int starting_time;
        int remaining_time;
        // reads the processes
        fscanf(f, "%s %d %d\n", process_name, &starting_time, &remaining_time);
        Process *process = newProcess(process_name, starting_time, remaining_time);
        processes[number_of_processes++] = process;
    }

    for (int i = 0; i < watch_time; i++) {

        for (int j = 0; j < number_of_processes; j++) {
            Process process = *processes[j];
            if (process.starting_time == i) {
                enqueue(queue, process);
//                printf("%s\t%d\t%d\t", process.name, process.starting_time, process.remaining_time);
            }
        }
        Process current_process;
        char *process_id;
        char *message = (char *) malloc(20 * sizeof(char));
        if (isEmpty(queue)) {
            process_id = "idle";
        } else {
            current_process = dequeue(queue);
            process_id = current_process.name;
        }
        if (current_process.remaining_time != 0) {
            current_process.remaining_time--;
            enqueue(queue, current_process);
        }
        if (current_process.remaining_time == 0) {
            sprintf(message, "%s aborts", process_id);
            dequeue(queue);
        }

        printf("%s\t%d\t%d\t", current_process.name, current_process.starting_time, current_process.remaining_time);
        printf("%s (%d-->%d) %s\n", process_id, i, i + 1, message);
    }
    printf("stop\n");
}

/*
 *
 */
int main() {
//    char filename[261];
//    puts("Enter file name or Ctrl+Z to exit:");
//    puts("----------------------------------");
//    while (fgets(filename, 260, stdin) != NULL) {
//        filename[strlen(filename) - 1] = '\0';
//        if (fopen(filename, "r"))
//            RoundRobin(filename);
//        else {
//            puts("File Not Found!");
//            puts("----------------------------------");
//        }
//        puts("Enter file name or Ctrl+Z to exit:");
//        puts("----------------------------------");
//    }
    RoundRobin("test.txt");

    return 0;
}
