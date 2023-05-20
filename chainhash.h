//
// Created by ASUS on 20/05/2023.
//
#include <iostream>
<<<<<<< HEAD
=======
#include "forward_list.h"
//#include "SHA256.h"
>>>>>>> 6a8c442b6ec03290f2c876e9c8e8840d0fdb9345
#include <functional>
#include "forward_list.h"
using namespace std;

const float maxFillFactor = 0.4;
const int maxColision = 3;


template<typename TK, typename TV>
class ChainHash{
<<<<<<< HEAD
private:
    ForwardList<Entry<TK,TV>>* array;
=======
public:

struct Entry
{
        TK key;
        TV value;

        Entry(){
        }

        Entry(TK k, TV v) {
            this->key = k;
            this->value = v;
        }
};
private:
    ForwardList<Entry<TK,TV>>* array;//array de listas
>>>>>>> 6a8c442b6ec03290f2c876e9c8e8840d0fdb9345
    int capacity;//tamanio del array
    int size;//cantidad total de elementos
    hash<TK> hasher;//hash de string

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
<<<<<<< HEAD
        array = new ForwardList<Entry<TK,TV>>(); //sese borra porque se tiene que generar con el fores list de l aclase sha
=======
        array = new ForwardList<Entry<TK,TV>>[capacity];
>>>>>>> 6a8c442b6ec03290f2c876e9c8e8840d0fdb9345
    }

    void insert(TK key, TV value){
        int index = hasher(key)%capacity;
<<<<<<< HEAD
        //if (size/(maxColision*capacity)>=maxFillFactor) {cout<<"rehashing\n"; rehashing();}
        array[index].push_front(Entry<TK,TV>(key,value));
        cout<<array[index].get_size()<<endl;
=======
        array[index].push_front(Entry (key,value));
>>>>>>> 6a8c442b6ec03290f2c876e9c8e8840d0fdb9345
        size++;
        if ((maxColision*capacity)>=maxFillFactor) {cout<<"rehashing\n"; rehashing();}
    }

    TV find(TK key){

    }

    void remove(TK key){


    }

    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return array[i].get_size();
    }

    ~ChainHash(){

    }

private: // ver rehashing
    void rehashing(){

    }
};


