#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList   *eventList=malloc(sizeof(eventList));
    eventList->isEmpty=1;
    eventList->head=NULL;
    eventList->last=NULL;
    return eventList;
}

void DestroyEventList(EventList *this)
{

}

Event *SearchEvent(EventList *this, char *name)
{

}

void AddEvent(EventList *this, Event *event)
{
    if (this.isEmpty==1)
    {
        this.isEmpty=0;
        this->head=event;
        this->last=event;
        event->next=NULL;

    }
    else
    {
        this->last->next=event;
        this-> last=next;
    }
}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    if(this->isEmpty==1)
    {
     printf("Empty\n");   
    }
    else 
    {
        printf("%s\n",this->head->eventName);
    }
}
