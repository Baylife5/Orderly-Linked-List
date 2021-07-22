#ifndef OLIST1_H
#define OLIST1_H

#include<iostream>
#include<stdexcept>
using namespace std;

template <class T>

class Node{

    public:
        Node <T> *next;
        T value;
};

template <class T>

class OList1
{
    private:
        Node <T> head;
        Node <T> *tailpointer;
        int size;
        Node <T> *FindInsertinPoint(const int &val){
                int i = 0;
                Node <T> *locator = new Node<T>;

            if(isEmpty()){
                cout << "\n empty list ";
            }
            else{
                locator = &head;
                while(i <= val){
                    locator = locator ->next;
            }
            return locator;
        }
    }


    public:
        /** Default constructor */
        OList1(){
            head.next = NULL;
            head.value = -1;
            tailpointer = &head;
            size = 0;
        }

        /// copy constructor
        OList1(OList1 <T> &obj){

                clear();
                head.value = -1;
                head.next = NULL;                  /// or obj.head
                Node <T> *ptr = new Node <T>;
                ptr = obj.head.next;
            while(ptr != NULL){
                    ptr = ptr -> next;
                    insertion(ptr -> value);
            }
        }


        // see if the list is empty
        bool isEmpty(){
            return size == 0;
        }

        // see if the element in the list is found
        bool find( const T val){
            Node <T> *finder = new Node <T>;
            finder = &head;

            if(isEmpty()){
                 throw logic_error("\n the list is empty nothing to be found");
            }
            else{

                while((finder!= NULL)) /// maybe able to use tailpointer
                     finder = finder -> next;
                    if(finder -> value == val)
                            return true;
            }
            delete finder;
         }

         /// helper function that will be passed into the constructor
         /// purpose is to insert at the beginning of the linked list
         void insertion(T val){

             Node <T> *add = new Node <T>;
             Node <T> *ptr = head.next;
             Node <T> *follower = &head;
             add -> value = val;
            while(ptr!= NULL  && val > ptr -> value){
                     follower = ptr;
                     ptr = ptr -> next;
            }

            add -> next = ptr;
            follower -> next = add;
            size++;
        }

        /// for fixed location
        void remove(int index){

             Node <T> *p = new Node <T>;
             Node <T> *q = new Node <T>;
             p = head.next;
             q = &head;
             int i = 0;

             if(isEmpty()){
                throw logic_error("\n empty list");
             }
            while(i < index){
             q = p;
             p = p-> next;
             i++;
            }
             q -> next = p -> next;
             delete p;
             size--;
    }

     /// helper function for the clear all
     void removeFromBeginning(){

     Node <T> *temp = new Node <T>;
     temp = head.next;
     head.next = temp -> next;
     delete temp;
     size --;
    }

    /// clear will be passed in to the destructor
    /// call the clear recursively
    void clear(){

    if(head.next != NULL){
        removeFromBeginning();
        clear();
        }
    }

    /// helper function for print forward recursive call
    void printForwardHelper(Node <T> *printer){

        if(printer!= NULL){
            cout <<" " <<printer -> value;
            printForwardHelper(printer -> next);
        }
    }



    /// print forward
    void printForward(){
         printForwardHelper(&head);
    }

    /// helper for print backwards
    void printBackwardHelper(Node <T> *p)const{

    if(p!= NULL){
            printBackwardHelper(p -> next);
            cout <<" "<< p -> value;
        }
    }

    void printBackward(){
      printBackwardHelper(&head); /// prevents from prompting the user always has a starting point
    }

    int getSize(){
        return size;
    }

    T getsmallest(){
        return head.next -> value;
    }

    T getBiggest(){

        tailpointer = &head;
    
        while(tailpointer -> next != NULL){
            tailpointer = tailpointer -> next;
        }

        cout << "i am the tailpointer therefore i am the largest ";
        return tailpointer -> value;
    }

    OList1 & operator =( const OList1 <T> &C){

                
                head.value = C.head.value;         /// or obj.head
                head.next = NULL;

                Node <T> *p;
                Node <T> *traversal;
               
                traversal = C.head.next;

                if(traversal == NULL){
                     throw logic_error("\n the list you are trying to copy is empty list");
                }

                p = &head;

                while(traversal != NULL){

                     Node <T> *create = new Node <T>;
                     create -> value = traversal -> value;
                     create -> next = NULL;
                     p -> next = create;
                     p = p -> next;
                     traversal = traversal -> next;
                    
            }

            return *this;
    }


    ostream &operator <<(const OList1 &obj){
           return obj.printForward(head.value);
            }



    /// Default destructor
    /// pass in the helper function
    ~OList1(){
        clear();
        size = 0;
    }
};

#endif // OLIST1_H
