#ifndef SORT_H
#define SORT_H
#include <QVector>
#include "sort_algorithms.h"

//strategy pattern

enum Sort_type { Insertion, Quick, Heap };

template<class T>
class Sort{
    Sort_type flag;
public:
    void set_sort_type(Sort_type new_flag){flag = new_flag;}
    void operator()(QVector<T> &arr){
        switch (flag) {
        case Sort_type::Insertion:
            insertion_sort(arr.data(), arr.size());
            break;
        case Sort_type::Quick:
            quick_sort(arr.data(), 0, arr.size() - 1);
            break;
        case Sort_type::Heap:
            heap_sort(arr.data(), arr.size());
            break;
        }
    }
};

#endif // SORT_H
