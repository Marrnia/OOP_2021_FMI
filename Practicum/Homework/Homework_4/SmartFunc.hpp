#pragma once
#include <iostream>
#include "Vector.hpp"

template<typename T>
using map_comparator = T (*)(T);

template<typename T>
using filter_comparator = bool (*)(T);

template<typename T>
using reduce_comparator = T (*)(T,T);

template<typename T>
struct SmartFunc {
    map_comparator<T> mapPtr = nullptr;
    filter_comparator<T> filterPtr = nullptr;
    reduce_comparator<T> reducePtr = nullptr;

    void setMap(map_comparator<T> func) {
        mapPtr = func;
    }

    void setFilter(filter_comparator<T> func) {
        filterPtr = func;
    }

    void setReduce(reduce_comparator<T> func) {
        reducePtr = func;
    }


    void useMap(Vector<T>& list) {
        if (mapPtr == nullptr) {
            std::cerr << "useMap(): set function is empty\n";
            return;
        }
        for (size_t i = 0; i < list.getSize(); ++i) {
            list[i] = mapPtr(list[i]);
        }
    }

    void useFilter(Vector<T>& list) {
        if (filterPtr == nullptr) {
            std::cerr << "useFilter(): set function is empty\n";
            return;
        }
        for (size_t i = 0; i < list.getSize(); ++i) {
            if (!filterPtr(list[i])) {
                list.remove(i);
                --i;
            }
        }
    }

    T useReduce(const Vector<T>& list, const size_t& n) {
        if (reducePtr == nullptr) {
            std::cerr << "useReduce(): set function is empty\n";
            return -1;
        }
        if (n == 1)
            return list.front();
        return reducePtr(list[n - 1], useReduce(list, n - 1));
    }

    //filter_map
    void filter_map(Vector<T>& list) {
        useFilter(list);
        useMap(list);
    }
    //filter_reduce
    T filter_reduce(const Vector<T>& list) {
        Vector<T> temp(list);
        useFilter(temp);
        return useReduce(temp);
    }
    //filter_map_reduce
    T filter_map_reduce(const Vector<T>& list) {
        Vector<T> temp(list);
        useFilter(temp);
        useMap(temp);
        return useReduce();
    }
    //map_reduce
    T map_reduce(const Vector<T>& list) {
        Vector<T> temp(list);
        useMap(temp);
        return useReduce(temp);
    }
    //map_filter
    void map_filter(Vector<T>& list) {
        useMap(list);
        useFilter(list);
    }
    //map_filter_reduce
    T map_filter_reduce(const Vector<T>& list) {
        Vector<T> temp(list);
        useMap(temp);
        useFilter(temp);
        return useReduce(temp);
    }

    /*Vector<U> useMap(const Vector<T>& list) {
        Vector<U> temp;
        for (size_t i = 0; i < list.getSize(); ++i) {
            temp.push_back(mapPtr(list[i]));
        }
        return temp;
    }

    Vector<T> useFilter(const Vector<T>& list) {
        Vector<T> temp;
        for (size_t i = 0; i < list.getSize(); ++i) {
            if (filterPtr(list[i])) {
                temp.push_back(list[i]);
            }
        }
        return temp;
    }

     T useReduce(const Vector<T>& list, const size_t& n) {
        if (n == 1)
            return list.front();
        return reducePtr(list[n - 1], useReduce(list, n - 1));
    }*/
};
