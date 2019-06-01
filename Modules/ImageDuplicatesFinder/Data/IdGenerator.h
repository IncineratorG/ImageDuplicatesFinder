#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <QObject>



class IdGenerator
{
public:
    static IdGenerator* getInstance();

    qint64 getNextId();

private:
    static IdGenerator* m_instance;

    qint64 m_nextId;

    IdGenerator();
};

#endif // IDGENERATOR_H
