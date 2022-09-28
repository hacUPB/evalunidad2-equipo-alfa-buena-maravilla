#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    if(strlen(name)>=16)
    {
        Event *event = malloc(sizeof(Event));
        memcpy(event->eventName, name, strlen(name));
        event->eventName[15]=0;
        event->next=NULL;
        return event;
    }
    else
    {
        Event *event = malloc(sizeof(Event));
        memcpy(event->eventName, name, strlen(name));
        event->next=NULL;
        return event;
    }
    
    
}

void DestroyEvent(Event *this)
{
    free(this);

}
