#ifndef UTIL_HPP_
#define UTIL_HPP_

void *operator new(size_t size);
void *operator new[](size_t size);
void operator delete(void *pointer);
void operator delete[](void *pointer);

#endif /* UTIL_HPP_ */
