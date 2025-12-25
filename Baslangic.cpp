//
// Created by yakup on 11/24/2025.
//

#include "bir.h"

#include <iostream>
class DynamicArray {
    int *data;
    int size;
    int capacity;
public:
   DynamicArray() {
       size=0;
       capacity=2;
       data=new int[capacity];
       std::cout<< "Düz\n";
   }
    DynamicArray(int kapasite) {
       size=0;
       capacity=kapasite;
       data=new int[capacity];
       std::cout<< "1Constructorlu \n";
   }
    DynamicArray(const DynamicArray &op) {
       this->size=op.size; this->capacity=op.capacity;
       this->data=new int[this->capacity];
       for (int i = 0; i < this->size; i++) {
           this->data[i]=op.data[i];
           std::cout<< "Kopya yapıcı çağrıldı\n";
       }
   }
       ~DynamicArray() {
           delete[] data;
           std::cout << "Bellek temizlendi.\n";
       }

    void push(int value) {
       if (size==capacity) {
           capacity+=2;
           int *newData=new int[capacity];
           for (int i=0;i<size;i++) {
               newData[i]=data[i];
           }
           delete[] data;
           data=newData;
       }
   }
       void pop() {
           if (size > 0) {
               size--;
           }
       }
    int get(int index) {
       for (int i=0;i<size;i++) {
           if (i==index) {
               return data[i];
           }
   }
   }
       int getSize() {
           return size;
       }
       int getCapacity() {
       return capacity;
   }
    bool isEmpty() {
       if (size==0) {
           return False;
       }
         else {
             return True;
         }
   }
    void print() {
       for (int i=0;i<size;i++) {
           std::cout << get(i);
       }

   }
void set(int index,int value) {
       data[index]=value;
   }
    void clear() {
         size=0;
   }











   };


















};

int main() {


}