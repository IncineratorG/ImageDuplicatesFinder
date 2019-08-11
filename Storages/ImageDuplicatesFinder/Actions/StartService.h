#ifndef STARTSERVICE_H
#define STARTSERVICE_H

#include "Storages/Abstract/AbstractAction.h"



class StartService : public AbstractAction
{
public:
    StartService();

    void execute();
};

#endif // STARTSERVICE_H
