#ifndef _EVENT_H
#define _EVENT_H

// Event class
typedef struct _event
{
    char eventName[15];
    struct _event *next;
} Event;

Event *CreateEvent(char *name);
void DestroyEvent(Event *this);

#endif