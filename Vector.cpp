//
// Created by rudri on 3/29/2019.
//

#include "Vector.h"
#include <iostream>

namespace UTEC {
    void vector::push_back(const int &value) {
        if(_arr == nullptr){
            _arr = new int[1];
            _arr[0] = value;
            _size = 1;
        }
        else{
            int* temp = new int[_size+1];
            for(int i = 0; i < _size; i++)
                temp[i] = _arr[i];
            temp[_size] = value;
            _size++;
            _arr = temp;
        }
    }

    void vector::pop_back() {
        if(_arr == nullptr){
            std::cout << "El vector esta vacio";
        }
        else{
            int* temp = new int[_size-1];
            for(int i = 0; i < _size-1; i++)
                temp[i] = _arr[i];
            _arr = temp;
            _size--;
        }
    }

    vector::vector() : _arr{nullptr}, _size(0) {}
    vector::~vector() {
        delete [] _arr;
        _arr = nullptr;
    }

    int vector::size() {return _size;}

    int vector::get_item(int i) {return _arr[i];}

    void vector::insert(int pos, const int& value){
        int* temp = new int[_size+1];
        for(int i = 0; i < pos-1; i++)
            temp[i] = _arr[i];
        temp[pos-1] = value;
        for(int i = pos; i < _size; i++)
            temp[i] = _arr[i];
        _size++;
    }

}