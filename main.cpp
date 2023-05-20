//
// Created by ASUS on 20/05/2023.
//
#include <iostream>
#include "chainhash.h"

using namespace std;

int main(){
    ChainHash<string, int> umap;

    umap.insert("utec",1);
    umap.insert("san marcos", 2);
    umap.insert("pucp", 3);
    umap.insert("ucal", 4);
    umap.insert("upc", 5);
    umap.insert("utp", 6);
    umap.insert("upch", 7);
    umap.insert("unam", 8);
    umap.insert("unt", 9);
    umap.insert("usp", 10);
    umap.insert("San Martin", 8);
    umap.insert("upuch", 10);
    umap.insert("patito", 6);
    umap.insert("ugod", 6);
    umap.insert("a", 10);
    umap.insert("b", 6);
    umap.insert("c", 6);
    umap.insert("dfd", 10);
    umap.insert("sd", 6);
    umap.insert("g", 6);

    cout<<umap.find("utec"); // busca

    int n = umap.bucket_count();
    cout<<"\nsize of hash table: "<<n<<endl;
/*
    for(int i=0;i<n;++i){
        cout<<"Bucket #"<<i<<", size: "<<umap.bucket_size(i)<<":  ";
        for(auto it = umap.begin(i); it != umap.end(i); ++it){
            cout<<"["<<(*it).key<<":"<<(*it).value<<"]";
        }
        cout<<endl;
    } // falta implementar iteradores
    */
   return 0;
}


