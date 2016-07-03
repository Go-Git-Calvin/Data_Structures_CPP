/* 
 * File:   LinkedList.cpp
 * Author: Viet
 * 
 * Created on July 2, 2016, 2:41 PM
 */

#include "LinkedList.hpp"
#include "Data.hpp"
#include <new>

LinkedList::LinkedList() {
    size = 0;
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList() {
    int i;
    Node* currNode = head;
    Node* nextNode = head->next;
    for(i = 0; i < size; i++){
        delete currNode;
        if(i < size - 1){
            currNode = nextNode;
            nextNode = currNode->next;
        }
    }
    delete head;
    delete tail;
}

int LinkedList::add(Data object) {
    try{
        Node* newNode = new Node(object, NULL);
        if(size == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    catch(std::bad_alloc e){
        return -1;
    }
    return 0;
}

Data* LinkedList::get(unsigned int index){
    if(index >= size || index < 0){
        return NULL;
    }
    unsigned int i;
    Node* tempNode = head;
    for(i = 0; i < index; i++){
        tempNode = tempNode->next;
    }
    static Data tempData = (tempNode->data).clone();
    return &tempData;
}

Data* LinkedList::remove(unsigned int index){
    if(index >= size || index < 0){
        return NULL;
    }
    static Data tempData;
    if(size == 1){
        tempData = (head->data).clone();
        delete head;
        head = NULL;
        tail = NULL;
        size = 0;
        return &tempData;
    }
    Node* deleteNode;
    if(index == 0){
        deleteNode = head;
        head = head->next;
        tempData = (deleteNode->data).clone();
        delete deleteNode;
        size--;
        return &tempData;
    }
    unsigned int i;
    Node* tempNode = head;
    for(i = 0; i < index - 1; i++){
        tempNode = tempNode->next;
    }
    deleteNode = tempNode->next;
    tempNode->next = deleteNode->next;
    if(deleteNode == tail){
        tail = tempNode;
    }
    tempData = (deleteNode->data).clone();
    delete deleteNode;
    size--;
    return &tempData;
}

Data* LinkedList::remove(Data object){
    Node* tempNode = head;
    if(head == NULL) return NULL;
    static Data tempData;
    if(head == tail){
        if((head->data).equals(object)){
            head = NULL;
            tail = NULL;
            delete tempNode;
            size = 0;
            tempData = object.clone();
            return &tempData;
        }
        return NULL;
    }
    Node* preNode = head;
    while(tempNode->next != NULL){
        if((tempNode->data).equals(object)){
            if(tempNode == head){
                head->next = (head->next)->next;
                head = head->next;
            }
            else{
                preNode->next = tempNode->next;
            }
            delete tempNode;
            size--;
            tempData = object.clone();
            return &tempData;
        }
        preNode = tempNode;
        tempNode = tempNode->next;
    }
    //tempNode->next == NULL: tail
    if((tempNode->data).equals(object)){
        tail = preNode;
        delete tempNode;
        size--;
        tempData = object.clone();
        return &tempData;
    }
    return NULL;
}

unsigned int LinkedList::getSize(){
    return size;
}

void LinkedList::empty(){
    int i;
    Node* currNode = head;
    Node* nextNode = head->next;
    for(i = 0; i < size; i++){
        delete currNode;
        if(i < size - 1){
            currNode = nextNode;
            nextNode = currNode->next;
        }
    }
    head = NULL;
    tail = NULL;
    size = 0;
}