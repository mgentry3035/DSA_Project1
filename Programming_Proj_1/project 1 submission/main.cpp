#include <iostream>
#include <fstream>
using namespace std;

class Item
{
private:
    int value;
public:


    Item(int x=0){value = x;}
    int getValue(){return value;}
    void setValue(int x){value = x;}
};

class Node
{
private:
    Item data;
    Node * next;
    int counter;
public:
    Node(const Item & it){
        data = it;
        next = nullptr;
        counter = 0;
    }
    Item getData(){return data;}
    void setNext(Node * ptr){next = ptr;}
    Node * getNext(){return next;}
    void incCounter(){counter++;}
    void rstCounter(){counter = 0;}
    int getCounter(){return counter;}

};

class LinkedList
{
private:
    Node * head;
    Node * tail;
    int threshold;

public:
    LinkedList(){head = nullptr; tail = nullptr;}

    void push_back(Item & x)
    {
        if(tail!=nullptr)
        {
            tail->setNext(new Node(x));
            tail = tail->getNext();
        }
        else
        {
            auto ptr = new Node(x);
            head = ptr;
            tail = ptr;
        }

    }

    void push_back(int x)
    {
        push_back(*(new Item(x)));

    }

    void pop_front(Item & val)
    {

        if(!head)
        {
            val = NULL;
            return;
        }

        auto ptr = head;
        val = head->getData();
        head = head->getNext();
        delete ptr;

    }

    bool empty()
    {

        if (!head)
            return true;
        else
            return false;

    }

    void print()
    {
        auto ptr = head;
        while(ptr)
        {
            cout<<"Item: "<<(ptr->getData()).getValue()<<endl;
            ptr = ptr->getNext();
        }

    }

    int search_MTF(int x){
        auto ptr = head;
        auto prev = head;
        int ctr = 0;

        while(ptr){
           // cout<<(ptr->getData()).getValue()<<endl;
            if((ptr->getData()).getValue()==x) {
               // ptr->incCounter();
               ctr++;
                //if (ptr->getCounter() == threshold) {
                    prev->setNext(ptr->getNext());
                    if (ptr != head) {
                        ptr->setNext(head);
                        head = ptr;
                    }
                    //head->rstCounter();
               // }

                //prev = ptr;
                //ptr = ptr->getNext();
                return ctr;
            }
            else{
                //ptr->incCounter();
                ctr++;
                prev = ptr;
                ptr = ptr->getNext();
            }
           // cout<<ctr<<endl;


        }
        //return ctr;
    }

    int search_trans(int x){
        auto ptr = head;
        auto prev = head;
        int ctr = 0;



        while(ptr){
            ctr++;
            if((ptr->getData()).getValue()==x) {
                if (ptr != head) {
                    prev->setNext(ptr->getNext());
                    ptr->setNext(prev);
                    if (prev != head) {
                        auto temp = head;
                        while (temp->getNext() != prev) {
                            temp = temp->getNext();
                        }
                        temp->setNext(ptr);
                    } else head = ptr;
                    return ctr;
                }
                else return ctr;
            }
            else{
                prev=ptr;
                ptr = ptr->getNext();
            }


        }
    }




};

int main(int argc, char* argv[]) {
    int instruction = *argv[1]-48;
    ifstream inFS;
    int currNum;
    char reqNum;
    int numFind;
    int steps;
    int counter = 0;

    LinkedList * list = new LinkedList();


    cout << "Opening file " << argv[3] << "." << endl;
    inFS.open(argv[3]);
    if (inFS.is_open()) {
        cout << "Opened file " << argv[3] << "." << endl;
        //return 1;
    }

    while(inFS>>currNum){
        //inFS>>currNum;
        list->push_back(currNum);
    }
    inFS.close();
    //list->print();
    cout << "Opening file " << argv[2] << "." << endl;
    inFS.open(argv[2]);
    if (inFS.is_open()) {
        cout << "Opened file " << argv[2] << "." << endl;
        //return 1;
    }
    while(inFS>>reqNum){
        numFind = reqNum-48;
        //cout<<numFind<<endl;
       if(instruction == 0){
           steps = list->search_MTF(numFind);}
       else if(instruction == 1){
           steps = list->search_trans(numFind);}
       counter += steps;
       //list->print();
       //cout<<numFind<<endl;
       //cout<<"next"<<endl;
    }
    inFS.close();
    cout<<counter<<endl;


    return 0;
}
