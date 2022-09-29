#include "eventList.h"
#include <stdbool.h>
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
    free(this);
}



void AddEvent(EventList *this, Event *event)
{
    bool stateAdd = false;
    
    if(this->isEmpty != 0)
    {
        this->isEmpty = 0;
        this->head = event;
        this->last = event;
    }
    else
    {
        Event *currentEvent = this->head;
        while (currentEvent != NULL){
            int result = strcmp(event->eventName, currentEvent->eventName);
            if (result == 0){
                stateAdd = false;
                break;
            }
            else{
                stateAdd = true;
            }
            currentEvent = currentEvent->next;
        }
        if (stateAdd){
            this->last->next = event;
            this->last = event;
        }
    }
}


Event *SearchEvent(EventList *this, char *name)
{
    Event *currentEvent = this->head;
    while (currentEvent != NULL){
        int result = strcmp(name, currentEvent->eventName);
        if (result == 0){
            return currentEvent;
        }
        else{
            currentEvent = currentEvent->next;
        }
    }
    
}
//Listo
    //Hay 3 casos, si el evento que quiero eliminar es el primero el evento anterior es NULL
    //Si el ultimo evento es el que quiero eliminar el evento actual tiene que volverse el anterior
    
void RemoveEvent(EventList *this, char *name)
{
    Event *eventTmp = SearchEvent(this, name); // busco el evento
    if (eventTmp != NULL)                      // si lo encontró, va a eliminarlo
    {

        if (eventTmp == this->head && eventTmp == this->last)
        {
            this->head = NULL;
            this->last = NULL;
            this->isEmpty = 1;
            return;
        }
        else
        {
            if (eventTmp == this->head)
            {
                if (eventTmp->next != NULL){
                    this->head = NULL;
                    this->head = eventTmp->next;
                    return;
                }
                else{
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    return;
                }
                
            }
            else
            {
                Event *previousEvent = this->head;
                while (previousEvent != NULL)
                {
                    if (previousEvent->next == eventTmp)
                    {
                        previousEvent->next = NULL;
                        previousEvent->next = eventTmp->next;
                        return;
                    }
                    else if (previousEvent->next == this->last && previousEvent->next == eventTmp)
                    {
                        previousEvent->next = NULL;
                        this->last = previousEvent;
                        return;
                    }
                    previousEvent = previousEvent->next;
                }
            }
        }
    }
    else // de lo contrario, no se pudo borrar el evento
        return;
}


void ListEvents(EventList *this)
{
    if (this->isEmpty==1)
    {
            printf("empty\n");
    }
    else
    {
        Event *currentEvent=this->head;
        while(currentEvent != NULL)
        {
            printf("%s\n",currentEvent->eventName);
            currentEvent=currentEvent->next;
        }
    }
}