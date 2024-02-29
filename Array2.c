#include<stdio.h>
#include<stdlib.h>
struct DynArray{
    int capacity;
    int lastIndex;
    int* ptr;
};

// Function to Create Array variable dynamically and initilize member variable.
struct DynArray* createArray(int size){
    struct DynArray* Arr;
    Arr=(struct DynArray*)malloc(sizeof(struct DynArray));
    Arr->capacity=size;
    Arr->lastIndex=-1;
    Arr->ptr=(int*)(malloc(sizeof(int)*size));
    printf("Array crerated Successfully...");
    return Arr;
}

//append value in an array.

void appendElement(struct DynArray* Arr,int val){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==Arr->capacity-1){
        printf("Sorry,array is full.Try to expend it. \n");
    }
    else{
        Arr->lastIndex++;
        Arr->ptr[Arr->lastIndex]=val;
    }
    
}

// insert value at a given index.

void insertElementAtIndex(struct DynArray* Arr,int index,int value){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==Arr->capacity-1){
        printf("Sorry,array is full.Try to expend it. \n");
    }
    else if(index<0||index>Arr->capacity-1||index>Arr->lastIndex+1){
        printf("Invalid index.\n");
    }
    else if(index==Arr->lastIndex+1){
        Arr->ptr[index]=value;
        Arr->lastIndex++;
    }
    else{
        for(int i=Arr->lastIndex;i>=index;i--){
            Arr->ptr[i+1]=Arr->ptr[i];
        }
        Arr->ptr[index]=value;
        Arr->lastIndex++;
    }
}

//get value at a given index.

int getValueAtIndex(struct DynArray* Arr,int index){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(index<0||index>Arr->capacity-1){
        printf("Invalid index.\n");
    }
    else if(index>Arr->lastIndex){
        printf("These index Are not Filled Yet./n");
    }
    else{
        return Arr->ptr[index];
    }
}

//edit a value at given index

void editValueAtIndex(struct DynArray* Arr,int index,int value){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==Arr->capacity-1){
        printf("Sorry,array is full.Try to expend it. \n");
    }
    else if(index<0||index>Arr->capacity-1||index>Arr->lastIndex){
        printf("Invalid index.\n");
    }
    else{
        Arr->ptr[index]=value;
    }
}

//count number of element present in array.

int countElement(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else
        return Arr->lastIndex+1;
}

//check if array is empty

void checkEmpty(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==(-1)){
        printf("Array is empty.\n");
    }
    else
        printf("Array is not Empty.\n");
}

//check if array is full

void checkFull(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==(Arr->capacity-1)){
        printf("Array is Full.\n");
    }
    else
        printf("Array is not Full.\n");
}

//Systematic Memory Release

void releaseMemory(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else{
        free(Arr->ptr);
        free(Arr);
    }
}

//delete Element of Array

void deleteElement(struct DynArray* Arr,int index){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(index<0||index>Arr->capacity-1||index>Arr->lastIndex){
        printf("Invalid index.\n");
    }
}

//define a function to delete an element of array.

void deleteElementAtIndex(struct DynArray* Arr,int index){
        if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(index<0||index>Arr->capacity-1||index>Arr->lastIndex){
        printf("Invalid index.\n");
    }
    else if(index==Arr->lastIndex){
        Arr->lastIndex--;
    }
    else{
        for(int i=index;i<Arr->lastIndex;i++){
            Arr->ptr[i]=Arr->ptr[i+1];
        }
        Arr->lastIndex--;
    }

}
// method doubleArray() to increase the size of array by  double of its size.

struct DynArray* doubleArray(struct DynArray* Arr){
    struct DynArray* Array;
    Array=(struct DynArray*)malloc(sizeof(struct DynArray));
    Array->capacity=Arr->capacity*2;
    Array->lastIndex=-1;
    Array->ptr=(int*)malloc(sizeof(Array->capacity));
    for(int i=0;i<=Arr->lastIndex;i++){
        Array->lastIndex++;
        Array->ptr[Array->lastIndex]=Arr->ptr[i];
    }
    free(Arr->ptr);
    free(Arr);
    return Array;
}