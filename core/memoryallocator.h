/*
 *
 *  Класс для организации работы с памятью
 *
 * *****************************************/

#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H

#include <QtGlobal>

class MemoryAllocator
{
public:
    MemoryAllocator();

    static void * alloc(quint64 size);

private:
    void * __memory;
};

#endif // MEMORYALLOCATOR_H
