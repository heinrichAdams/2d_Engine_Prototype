#ifndef SEND_H
#define SEND_H


typedef struct 
{
    void (*Update)(void);
    void (*RenderGameObjects)(void);
}Send;


#endif