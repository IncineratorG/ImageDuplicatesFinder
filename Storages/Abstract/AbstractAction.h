#ifndef ABSTRACTACTION_H
#define ABSTRACTACTION_H


class AbstractAction
{
public:
    virtual ~AbstractAction() = 0;

    virtual void execute() = 0;
};

#endif // ABSTRACTACTION_H
