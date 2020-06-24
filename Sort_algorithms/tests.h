#ifndef TESTS_H
#define TESTS_H
#include "sort_algorithms.h"
#include "sort.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

class Tests
{
private:
    // test data
    QVector<int> data;

public:
    // constructor
    Tests() {
        for(int i = 0; i < 1000; i++)
            this->data.push_back(1000 - i);
    }
    ~Tests(){
        this->data.clear();
    }

    // manage class
    void test() {
        bool good;

        good = this->testHeapSort();

        if(good)
            this->success("Test 'Heap Sort'", "Success!");
        else
            this->error("Test 'Heap Sort'", "Failed!");

        good = this->testQuickSort();

        if(good)
            this->success("Test 'Quick Sort'", "Success!");
        else
            this->error("Test 'Quick Sort'", "Failed!");

        good = this->testInsertionSort();

        if(good)
            this->success("Test 'Insertion Sort'", "Success!");
        else
            this->error("Test 'Insertion Sort'", "Failed!");

        if(good)
            cout << "ALL TESTS PASSED" << endl;
        else
            cout << "TESTS FAILED" << endl;
    };

    // main tests
    bool testQuickSort(){
        Sort<int> sort;
        sort.set_sort_type(Sort_type::Quick);
        sort(this->data);
        cout << "Sorting \t" << this->data.size() << "\t elements...\t[Quick Sort]" << endl;
        for(int i = 1; i < this->data.size(); i++)
            if(this->data[i - 1] > this->data[i])
                return false;
        cout << "Checking \t" << this->data.size() << "\t elements...\t[Quick Sort]" << endl;
        for(int i = 0; i < 1000; i++)
            this->data.push_back(1000 - i);

        return true;
    };

    bool testHeapSort() {
        Sort<int> sort;
        sort.set_sort_type(Sort_type::Heap);
        cout << "Sorting \t" << this->data.size() << "\t elements...\t[Heap Sort]" << endl;
        sort(this->data);
        cout << "Checking \t" << this->data.size() << "\t elements...\t[Heap Sort]" << endl;
        for(int i = 1; i < this->data.size(); i++)
            if(this->data[i - 1] > this->data[i])
                return false;

        for(int i = 0; i < 1000; i++)
            this->data.push_back(1000 - i);

        return true;
    };

    bool testInsertionSort() {
        Sort<int> sort;
        sort.set_sort_type(Sort_type::Insertion);
        sort(this->data);
        cout << "Sorting \t" << this->data.size() << "\t elements...\t[Insertion Sort]" << endl;
        for(int i = 1; i < this->data.size(); i++)
            if(this->data[i - 1] > this->data[i])
                return false;
        cout << "Checking \t" << this->data.size() << "\t elements...\t[Insertion Sort]" << endl;
        for(int i = 0; i < 1000; i++)
            this->data.push_back(1000 - i);

        return true;
    };

    // messages
    void error(string title, string message) {
        cout << "TEST: " << title << ":\t" << message << endl << endl;
    };
    void success(string title, string message) {
        cout << "TEST: " << title << ":\t" << message << endl << endl;
    };
};

#endif // TESTS_H
