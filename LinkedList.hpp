/* 
 * File:   LinkedList.hpp
 * Author: Hang
 *
 * Created on July 3, 2016, 10:52 AM
 */

#ifndef LINKEDLIST_HPP
#define	LINKEDLIST_HPP

#include <cstdlib>
#include "Data.hpp"

class LinkedList {
public:
    LinkedList();
    virtual ~LinkedList();
    Data* get(unsigned int index);
    int add(Data object);
    Data* remove(unsigned int index);
    Data* remove(Data object);
    void empty();
    unsigned int getSize();
private:
    class Node{
        public:
            Data data;
            Node* next;
            Node(Data nodeData, Node* nextNode){
                data = nodeData;
                next = nextNode;
            }
    };
    unsigned int size;
    Node* head;
    Node* tail;
};
#endif	/* LINKEDLIST_HPP */

