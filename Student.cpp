/*
 * Author: Joshua Petersen, Evan Nordin
 * Oct 9th 2020
 */

#include "student.h"
#include <iostream>
#include <string>
#include <cstring>

/*
 * @description: constructor
 * @param name: holds input for name of student
 * @param perm: the number of the student
 */
Student::Student(const char * const name, int perm) {
    this->setPerm(perm);
    this->setName(name);
}
/*
 * @description: getter
 * @return student perm
 */
int Student::getPerm() const {
    return perm;
}
/*
 * @description: name getter
 * @return name of student
 */
const char * const Student::getName() const {
    return this->name;
}
/*
 * @description: perm setter
 * @param permNumber, the number to set
 */
void Student::setPerm(const int permNumber) {
    this->perm = permNumber;
}
/*
 * @description: sets the name of the student
 * @param name: the name to set it to
 */
void Student::setName(const char * const name) {
    try {
        //delete  &this->name; // why does this not work
        //delete this->name; //rarely segfaults :)
        //delete []  this->name; //sometimes segfaults
        //I can't fix it because you can't tell if the char * is pointing to anything
        // if(this->name == nullptr) doesn't work
        // impossible to tell if memory is allocated already
        // but u can if u just use string so please can i just use string ???????
        // char * is shit blows up myu computer
    }catch(...){ //brilliant
    }     // this causes a memory leake if I take this owute
//      I spent ten hours staring at this line of code
//  char * is the worst  ever written
//      stupid
// actually you know what
// there is still a memory leak but it only happens when you call setName() on a Student
//      that is already defined
// but whatever what's written here is to the specs so I don't care
    this->name = new char[strlen(name)+1]; //now I removed the delete above... and there's no memleak????
    strcpy(this->name,name); // i can't even begin to fathom
}

/*
 * @description: copy constructor
 * @param &orig: Student to clone from
 */
Student::Student(const Student &orig) {
    this->setName(orig.getName());
    this->setPerm(orig.getPerm());
}
/*
 * @description: destructor
 */
Student::~Student() { // destructor
    delete this->name;
}
/*
 * @description: ::operator=, same as copy constructor
 * @param &right: value on the right of equals sign
 */
Student & Student::operator=(const Student &right) {
    if (&right == this)
        return (*this);

    this->name = nullptr;
    this->perm = 0;
    this->setPerm(right.getPerm());
    this->setName(right.getName());

    return (*this);
}

/*
 * @description: toString method, returns it in a string form
 * @return string form
 */
std::string Student::toString() const {
    return ("[" + std::string(this->name) +  "," + std::to_string(this->perm) + "]");
}

