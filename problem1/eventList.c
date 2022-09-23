#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
<<<<<<< HEAD
    EventList   *eventList=malloc(sizeof(eventList));
    eventList->isEmpty=1;
    eventList->head=NULL;
    eventList->last=NULL;
    return eventList;
=======

EventList *eventlist = malloc(sizeof(EventList));
eventlist->isEmpty=1;
eventlist->head=NULL;
eventlist->last=NULL;
return eventlist;

>>>>>>> 511c749521569255d7c9e42bd4ad8defdae7529c
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

<<<<<<< HEAD
    }
    else
    {
        this->last->next=event;
        this-> last=next;
    }
=======
if (this->isEmpty==1)
{
  this->isEmpty=0;
  this->head=event;
  this->last=event;
  event->next=NULL;
}

else
{
    this->last->next=event;
    this->last=event;
}

>>>>>>> 511c749521569255d7c9e42bd4ad8defdae7529c
}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    if(this->isEmpty==1)
    {
<<<<<<< HEAD
     printf("Empty\n");   
    }
    else 
    {
        printf("%s\n",this->head->eventName);
    }
=======
    printf("empty\n");
    }
    else
    {
        printf("%s\n",this->head->eventName);
        
    }

>>>>>>> 511c749521569255d7c9e42bd4ad8defdae7529c
}
