#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
Event *event = malloc(sizeof(Event)*1);
strncpy(event->eventName,name,strlen(name)+1);
event->next=NULL;
return event;
}

void DestroyEvent(Event *this)
{
free(this);
}
