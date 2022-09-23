#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
Event *event = malloc(sizeof(Event)*1);
    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
