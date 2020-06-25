/**
 * @file it.h
 *
 * @brief This file describe the Iterator pattern.
 */

#ifndef IT_H
#define IT_H

template<class T>
class it
{
public:
    T x;
    it *Next, *Prev;
};

#endif // IT_H
