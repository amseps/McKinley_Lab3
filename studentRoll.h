/*
 * Author: Joshua Petersen, Evan Nordin
 * Oct 9th 2020
 */

#ifndef STUDENTROLL_H
#define STUDENTROLL_H

#include <string>
#include "Student.h"

class StudentRoll {

public:
    StudentRoll();
    void insertAtTail(const Student &s);
    std::string toString() const;

    StudentRoll(const StudentRoll &orig);
    ~StudentRoll();
    StudentRoll & operator=(const StudentRoll &right);

private:
    struct Node {
        Student *s;
        Node *next;
    };
    Node *head;
    Node *tail;
};


#endif
