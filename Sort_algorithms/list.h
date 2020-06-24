#ifndef LIST_H
#define LIST_H
#include <QVector>
#include "it.h"

template<class T>
class List{
    it<T> *Head, *Tail;

public:
    // constructor
    List():Head(NULL),Tail(NULL){};
    ~List(){
        while (Head){
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }
    }

    QVector<T> Show(){
        QVector<T> res;

        it<T> *temp = Head;
        while (temp != NULL){
            res.push_back(temp->x);
            temp = temp->Next;
        }

        return res;
    }

    void add(T x){
        it<T> *temp = new it<T>;
        temp->Next = NULL;
        temp->x = x;

        if (Head != NULL){
            temp->Prev = Tail;
            Tail->Next = temp;
            Tail = temp;
        }
        else{
            temp->Prev = NULL;
            Head = Tail = temp;
        }
      }

    void clear(){
        while (Head){
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }
    }
};

#endif // LIST_H
