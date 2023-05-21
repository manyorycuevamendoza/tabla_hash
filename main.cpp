//
// Created by ASUS on 20/05/2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "chainhash.h"

using namespace std;

int main(){
    /*
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

    umap.insert("San Martin", 11);
    umap.insert("upuch", 12);
    umap.insert("patito", 13);
    umap.insert("ugod", 14);
    umap.insert("a", 15);

    umap.insert("b", 16);
    umap.insert("c", 17);
    umap.insert("dfd", 18);
    umap.insert("sd", 19);
    umap.insert("g", 20);

    umap.insert("utec",21);

    cout<<"Display: ";
    umap.display();
    cout<<umap.find("utec"); // busca
    cout<<umap.find("ad"); // busca

    int n = umap.bucket_count();
    cout<<"\nsize of hash table: "<<n<<endl;

    cout<<umap.search("utec")<<endl;
    cout<<umap.search("upc")<<endl;
*/
/*
    for(int i=0;i<n;++i){
        cout<<"Bucket #"<<i<<", size: "<<umap.bucket_size(i)<<":  ";
        for(auto it = umap.begin(i); it != umap.end(i); ++it){
            cout<<"["<<(*it).key<<":"<<(*it).value<<"]";
        }
        cout<<endl;
    } // falta implementar iteradores
    */
    vector<ChainHash<string, int>>umap(5);

    std::ifstream file("test1_bchain.csv");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

   // umap[0]= new ChainHash<string, int>;
    std::string line;
    int i=0;
    std::getline(file, line);
    //umap[0].insert("a",i);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        i++;
        std::getline(ss, item, ',');
        umap[0].insert(item,i);

    }

    umap[0].display();
    cout<<"Size: "<<umap[0].get_size();
    file.close();

   return 0;
}

