#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{

EventList *eventlist = malloc(sizeof(EventList));
eventlist->isEmpty=1;
eventlist->head=NULL;
eventlist->last=NULL;
return eventlist;

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

}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    int i=1; 

  
   if (this->isEmpty==1)
   {
    printf("empty\n");
   }
   else
   { 
     printf("%s\n",this->head->eventName);

     while (i!=0)
     {
      if((this->head+i)->next==NULL)
      {
        i=0;
         printf("%s\n",(this->head+i)->eventName);
      }
      else
      {
        printf("a");
        printf("%s\n",(this->head+i)->eventName);
      }
     }
     
   }