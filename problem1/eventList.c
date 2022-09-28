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
    Event   *EventoActual;
    while(this->head!=NULL)
        {
            EventoActual=this->head;
            this->head=this->head->next;
        }
}
//listo
Event *SearchEvent(EventList *this, char *name)
{
    if(this->isEmpty!=1)
    {
        Event *EncontrarEvento=NULL;
        Event *EventoActual=this->head;
        while(1)
        {
            if(EventoActual==NULL)
            {
                break;
            }
            int A=strcmp(EventoActual->eventName,name);

            if(!A)
            {
                EncontrarEvento=EventoActual;
                break;
            }
            EventoActual=EventoActual->next;
        }
        return EncontrarEvento;
    }
    else
    {
        return NULL;
    }
}
//Listo
void AddEvent(EventList *this, Event *event)
{
    int Revision=0;
    if (this->isEmpty!=1)
    {
        Event *EventoActual=this->head;
        while(1)
        {
            if(EventoActual==NULL)
            {
                break;
            }
            int A=strcmp(EventoActual->eventName,event->eventName);
            if(!A)
            {
                Revision=1;
                break;
            }
            EventoActual=EventoActual->next;
        }
    }
    if(Revision!=1)
    {
        if(this->isEmpty==1)
        {
            this->head=event;
            this->isEmpty=2;
        }
        else if(this->isEmpty==2)
        {
            this->head->next = event;
            this->last = event;
            this->isEmpty = 3; 
        }
        else
        {
            this->last->next=event;
            this->last=event;
        }
    }
}
    //Hay 3 casos, si el evento que quiero eliminar es el primero el evento anterior es NULL
    //Si el ultimo evento es el que quiero eliminar el evento actual tiene que volverse el anterior
    
    void RemoveEvent(EventList *this, char *name)
    {
        Event *EliminarEvento=NULL;
        Event *EventoActual=this->head;
        Event *EventoAnterior=NULL;
        int A;
        //Event *PtrEmpty=this->isEmpty;
        //Mientras el evento actual sea NULL se rompe
        //Se crea una variable A que con la funcion strcmp va a comparar si las cadenas de caracteres son iguales 
        //¿Que cadenas de caracteres?
        //La cadena EventoActual->evenName y la Cadena Name.
        while(1)
        {
            if(EventoActual==NULL)
            {
                break;
            }
             A=strcmp(EventoActual->eventName,name);
            if(A == 0)
            {
                EliminarEvento=EventoActual;
                break;
            }
            //Si Diferente de A, se meta al condicional y convierta EliminarEvento en el Evento Actual.
            EventoAnterior=EventoActual;
            EventoActual=EventoActual->next;
        }
        if(EliminarEvento!=NULL)
        {
            if(EliminarEvento==this->head)
            {
                if(this->head->next)
                {

                    //this->isEmpty=PtrEmpty;
                    this->isEmpty=1;
                    this->head=NULL;
                    DestroyEvent(EliminarEvento); 
                }
                else
                {
                    this->head=this->head->next;
                    DestroyEvent(EliminarEvento);
                }
            }
            else
            {
                EventoAnterior->next=EventoActual->next;
                DestroyEvent(EliminarEvento);
            }
        }
        

    }
    void ListEvents(EventList *this)
    {
        if (this->isEmpty==1)
        {
            printf("empty\n");
        }
        else
        {
            Event *EventoActual=this->head;
            while(1)
            {
                if(EventoActual==NULL)
                {
                    break;
                }
                printf("%s\n",EventoActual->eventName);
                EventoActual=EventoActual->next;
            }
        }
    }