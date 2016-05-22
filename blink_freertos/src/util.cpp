#include "FreeRTOS.h"

void *operator new(size_t size) {
    return pvPortMalloc(size);
}

void *operator new[](size_t size) {
    return pvPortMalloc(size);
}

void operator delete(void *pointer) {
    vPortFree(pointer);
}

void operator delete[](void *pointer) {
    vPortFree(pointer);
}
