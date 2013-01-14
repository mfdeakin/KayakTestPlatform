#include "cmdqueue.h"
#include <stdlib.h>
#include <assert.h>

struct _cmd {
    struct cmd;
    struct _cmd *next;
};


struct _cmdQueue {
    /* Must be at the top of the struct for this trick to work */
    struct cmdQueue;
    struct _cmd *list;
    unsigned size;
};

bool cmdHasCommand(struct _cmdQueue *cmds);
void cmdExecuteCommand(struct _cmdQueue *cmds);
void cmdRemoveCommand(struct _cmdQueue *cmds);
void cmdAddCommand(struct _cmdQueue *cmds, struct cmd *command);

void cmdExecNil();

struct cmdQueue *CmdQueue()
{
    struct _cmdQueue *cmds = malloc(sizeof(struct _cmdQueue));
    cmds->hasCommand = (bool (*)(struct cmdQueue *))cmdHasCommand;
    cmds->executeCommand = (void (*)(struct cmdQueue *))cmdExecuteCommand;
    cmds->removeCommand = (void (*)(struct cmdQueue *))cmdRemoveCommand;
    cmds->addCommand = (void (*)(struct cmdQueue *))cmdAddCommand;
    cmds->list = NULL;
    return (struct cmdQueue *)cmds;
}

void CmdQueueFree(struct cmdQueue *cmds)
{
    free(cmds);
}

bool cmdHasCommand(struct _cmdQueue *cmds)
{
    assert(cmds);
    return cmds->list != NULL;
}

void cmdExecuteCommand(struct _cmdQueue *cmds)
{
    assert(cmds && cmds->size);
}

void cmdRemoveCommand(struct _cmdQueue *cmds)
{
    assert(cmds && cmds->size);
}

void cmdAddCommand(_cmdQueue *cmds, struct _cmd *command)
{
    assert(cmds && command);
    if(cmds->list == NULL) {
        cmds->list = command;
    }
    else {
        struct _cmd *c = cmds->list;
        while(c->next)
            c = c->next;
        c->next = command;
    }
}

void cmdExecNil()
{}
