#ifndef CMDQUEUE_H
#define CMDQUEUE_H

#include <stdbool.h>

enum Priorities {
    PRIORITY_HIGH,
    PRIORITY_LOW
};

struct cmd {
    /* The function used to complete the command */
    void (*exec)();
    /* The current type/priority of the command */
    enum Priorities priority;
    /* The length of time anticipated for the command to take */
    int runlength;
};

struct cmdQueue {
    bool (*hasCommand)(struct cmdQueue *);
    void (*executeCommand)(struct cmdQueue *);
    void (*removeCommand)(struct cmdQueue *);
    void (*addCommand)(struct cmdQueue *, struct cmd *)
};

struct cmdQueue *CmdQueue();
void CmdQueueFree(struct cmdQueue *);

#endif // CMDQUEUE_H
