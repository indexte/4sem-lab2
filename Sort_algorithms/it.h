#ifndef IT_H
#define IT_H

//iterator pattern
template<class T>
class it
{
public:
    T x;
    it *Next, *Prev;
};

#endif // IT_H
