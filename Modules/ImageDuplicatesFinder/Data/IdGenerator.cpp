#include "IdGenerator.h"



IdGenerator* IdGenerator::m_instance = nullptr;

IdGenerator* IdGenerator::getInstance() {
    if (!m_instance) {
        m_instance = new IdGenerator();
    }

    return m_instance;
}

IdGenerator::IdGenerator()
    : m_nextId(1)
{

}

qint64 IdGenerator::getNextId() {
    return m_nextId++;
}
