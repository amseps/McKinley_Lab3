/*
 * Author: Joshua Petersen, Evan Nordin
 * Oct 9th 2020
 */

#include <string>
#include "studentRoll.h"

/*
 * @description: empty constructor
 */
StudentRoll::StudentRoll() {
    head = tail = NULL;
}

/*
 * @description: inserts param at the end of the linked list
 * @param &s: the student to add
 */
void StudentRoll::insertAtTail(const Student &s) {
    Node * newnode = new Node();
    newnode->s = new Student(s);
    newnode->next = NULL;

    if(this->head == nullptr){ // if 0 values
        this->head = newnode;
    }else if(this->head->next == nullptr){ // if only one value
        this->tail = newnode;
        this->head->next = this->tail;
    }else{ // more than one val
        this->tail->next = newnode;
        this->tail = newnode;
    }
}

/*
 * @description: toString for StudentRoll
 * @return the string form
 */
std::string StudentRoll::toString() const {
    Node * currnode = this->head;
    if(currnode == nullptr) return "[]";
    std::string toret = currnode->s->toString();
    while(currnode->next != nullptr){
        currnode = currnode->next;
        toret += "," + currnode->s->toString();
    }
    return "[" + toret + "]";
}

/*
 * @description: StudentRoll clone constructor
 * @return the cloned StudentRoll
 * @param &orig: the StudentRoll to clone
 */
StudentRoll::StudentRoll(const StudentRoll &orig) {
    if(orig.head != NULL) { //if length >=1
        this->head = new Node();
        this->head->s = (orig.head->s); // clone s;
        this->head->next = orig.head->next;
        if(orig.head != NULL) { // if it has a tail / length >=2
            Node *thisnode = this->head;
            Node *orignode = orig.head->next;
            while (orignode != NULL) { // while orig has a next node
                thisnode->next = new Node();//thisnode is one behind orignode
                thisnode = thisnode->next;
                thisnode->s = new Student(orignode->s->getName(), orignode->s->getPerm());
                orignode = orignode->next;
            }
            this->tail = thisnode;
        }
    }else{ //length ==0
        this->head = NULL;
        this->tail = NULL;
    }
}

/*
 * @description: destructor
 */
StudentRoll::~StudentRoll() {
    for(auto toDelete = this->head; toDelete != nullptr;){
        const auto next = toDelete->next;
        delete toDelete->s;
        delete toDelete;
        toDelete = next;
    }
}

/*
 * @description: ::operator=
 * @param &right: the value on the right of the equals sign
 */
StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
    if (&right == this)
        return (*this);
    if(right.head != NULL) { //if length >=1
        this->head = new Node();
        this->head->s = (right.head->s); // clone s;
        this->head->next = right.head->next;
        if(right.head != NULL) { // if it has a tail / length >=2
            Node *thisnode = this->head;
            Node *orignode = right.head->next;
            while (orignode != NULL) { // while orig has a next node
                thisnode->next = new Node();//thisnode is one behind orignode
                thisnode = thisnode->next;
                thisnode->s = new Student(orignode->s->getName(), orignode->s->getPerm());
                orignode = orignode->next;
            }
            this->tail = thisnode;
        }
    }else{ //length ==0
        this->head = NULL;
        this->tail = NULL;
    }//FROM COMPYE CONSTRUCTORE

    return (*this);

}





