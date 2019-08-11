#ifndef ABSTRACTSTORE_H
#define ABSTRACTSTORE_H

#include <QObject>



class AbstractStore : public QObject
{
public:
    virtual ~AbstractStore() = 0;
};

#endif // ABSTRACTSTORE_H
