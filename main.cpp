/*
 * Author: Joshua Petersen, Evan Nordin
 * Oct 9th 2020
 * A program that organizes c *s, and linked lists in some annoying ways, and allocates memory in annoying ways
 * what a goofy program
 */

#include "Student.h" // will be unused if studentRoll is implemented,
                     // included for students who implement/test Student first
#include "studentRoll.h"
#include <iostream>
#include "tddFuncs.h"
using namespace std;

// STUDENT TEST 1
/*
 * @description: Tests Basics of student 1
 */
void studentTest1() {
    cout << "Running student test (set 1) from from: " << __FILE__ << endl;

    Student s("Phill Conrad", 1234567);

    ASSERT_EQUALS("Phill Conrad", s.getName());
    ASSERT_EQUALS(1234567, s.getPerm());
    ASSERT_EQUALS("[Phill Conrad,1234567]", s.toString());
}

// STUDENT TEST 2
/*
 * @description: Tests Basics of student 2
 */
void studentTest2() {
    cout << "Running student test (set 2) from from: " << __FILE__ << endl;

    Student s("Phill Conrad",1234567);

    ASSERT_EQUALS("Phill Conrad", s.getName());
    ASSERT_EQUALS(1234567, s.getPerm());

    s.setName("Chris Gaucho");
    ASSERT_EQUALS("Chris Gaucho", s.getName());

    s.setPerm(9876543);
    ASSERT_EQUALS(9876543, s.getPerm());
}

// STUDENT TEST 3
/*
 * @description: Tests Basics of student 3
 */
void studentTest3() {
    cout << "Running student test (set 3) from from: " << __FILE__ << endl;

    const char *const origName = "Phill Conrad";

    Student s(origName,1234567);

    s.setName(origName);
    s.setPerm(1234567);

    ASSERT_EQUALS(origName, s.getName());
    ASSERT_EQUALS(1234567, s.getPerm());

    const char *const name1 = "Chris Gaucho";
    const char *const name2 = "Adam Twelve";
    const char *const name3 = "Betty Boop";

    Student s1(s);
    Student s2(s);
    Student s3(s);

    s.setName(name1);
    ASSERT_EQUALS(name1, s.getName());

    s2.setName(name2);
    ASSERT_EQUALS(name2, s2.getName());

    s3.setName(name3);
    ASSERT_EQUALS(name3, s3.getName());

    ASSERT_EQUALS(origName, s1.getName());
}

// STUDENT TEST 4
/*
 * @description: Tests Basics of student 4
 */
void studentTest4() {
    cout << "Running student test (set 4) from from: " << __FILE__ << endl;

    const char *const name0 = "Phill Conrad";
    const char *const name1 = "Chris Gaucho";
    const char *const name2 = "Adam Twelve";

    Student s0(name0, 1000000);
    Student s1(s0);
    s1.setName(name1);
    s1.setPerm(1111111);
    ASSERT_EQUALS(name1, s1.getName());
    ASSERT_EQUALS(1111111, s1.getPerm());

    Student s2(s0);
    s2 = s1;
    ASSERT_EQUALS(s1.getName(), s2.getName());
    ASSERT_EQUALS(s1.getPerm(), s2.getPerm());

    s2.setName(name2);
    s2.setPerm(2222222);

    ASSERT_EQUALS(name1, s1.getName());
    ASSERT_EQUALS(1111111, s1.getPerm());
    ASSERT_EQUALS(name2, s2.getName());
    ASSERT_EQUALS(2222222, s2.getPerm());

    Student s3 = s2;

    ASSERT_EQUALS(s2.getName(), s3.getName());
    ASSERT_EQUALS(s2.getPerm(), s3.getPerm());
}

// ROLL TEST 1
/*
 * @description: Tests Basics of StudentRoll 1
 */
void rollTest1(){
    cout << "Running roll test (set 1) from: " << __FILE__ << endl;

    StudentRoll sr;
    ASSERT_EQUALS("[]",sr.toString());
}

// ROLL TEST 2
/*
 * @description: Tests Basics of StudentRoll 2
 */
void rollTest2(){
    cout << "Running roll test (set 2) from: " << __FILE__ << endl;

    Student s("Phill Conrad",1234567);

    ASSERT_EQUALS("Phill Conrad",s.getName());
    ASSERT_EQUALS(1234567,s.getPerm());

    StudentRoll sr;
    ASSERT_EQUALS("[]",sr.toString());

    sr.insertAtTail(s);

    ASSERT_EQUALS("[[Phill Conrad,1234567]]",sr.toString());

    s.setName("Chris Gaucho");
    s.setPerm(2222222);
    ASSERT_EQUALS("Chris Gaucho",s.getName());

    sr.insertAtTail(s);

    ASSERT_EQUALS("[[Phill Conrad,1234567],[Chris Gaucho,2222222]]",sr.toString());
}

// ROLL TEST 3
/*
 * @description: Tests Basics of StudentRoll 3
 */
void rollTest3(){
    cout << "Running roll test (set 3) from: " << __FILE__ << endl;

    const char * const name1="One One";
    const char * const name2="Two Two";
    const char * const name3="Tre Tre";

    Student s1(name1,1111111);
    Student s2(name2,2222222);
    Student s3(name3,3333333);


    StudentRoll sr0;
    StudentRoll sr1(sr0);
    sr1.insertAtTail(s1);
    StudentRoll sr2(sr1);
    sr2.insertAtTail(s2);
    StudentRoll sr3;
    sr3 = sr2;
    sr3.insertAtTail(s3);

    ASSERT_EQUALS("[]",sr0.toString());
    ASSERT_EQUALS("[[One One,1111111]]",sr1.toString());
    ASSERT_EQUALS("[[One One,1111111],[Two Two,2222222]]",sr2.toString());
    ASSERT_EQUALS("[[One One,1111111],[Two Two,2222222],[Tre Tre,3333333]]",sr3.toString());
}

/*
 * @description: Tests Copy Constructor of Student
 */
bool testStudentCopy(){
    try {
        Student a("Cool Guy", 12345678);
        Student b(a);
        Student c(b);
    }catch(...){
        return false;
    }
    return true;
}
/*
 * @description: Tests ::operator= of Student
 */
bool testStudentAss(){
    try {
        Student a("Cool Guy", 12345678);
        Student b = a;
        Student c = b;
    }catch(...){
        return false;
    }
    return true;
}
/*
 * @description: Tests Copy Constructor of StudentRoll
 */
bool testRollCopy(){
    try{
        Student s("Cool Guy", 12345678);
        StudentRoll a;
        a.insertAtTail(s);
        StudentRoll b(a);
        StudentRoll  c(b);
    }catch(...){
        return false;
    }
    return true;
}
/*
 * @description: Tests ::operator= of StudentRoll
 */
bool testRollAss(){
    try{
        Student s("Cool Guy", 12345678);
        StudentRoll  a;
        a.insertAtTail(s);
        StudentRoll b = a;
        b.insertAtTail(s);
        StudentRoll c = b;
    }catch(...){
        return false;
    }
    return true;
}
/*
 * @description: Constains a bunch of tests
 */
bool extraTests(){
    try {
        cout << "Testing testStudentCopy():\n";
        const int TEST_CASES = 10000000;
        for (int i = 0; i < TEST_CASES; i++) {
            if (!testStudentCopy()) {
                cout << "FAIL!" << endl;
            }
        }
        cout << "Testing testStudentAss():\n";
        for (int i = 0; i < TEST_CASES; i++) {
            if (!testStudentAss()) {
                cout << "FAIL!" << endl;
            }
        }
        cout << "Testing testRollCopy():\n";
        for (int i = 0; i < TEST_CASES; i++) {
            if (!testRollCopy()) {
                cout << "FAIL!" << endl;
            }
        }
        cout << "Testing testRollAss():\n";
        for (int i = 0; i < TEST_CASES; i++) {
            if (!testRollAss()) {
                cout << "FAIL!" << endl;
            }
        }
    }catch(exception& e){
        cout << "extraTests() failed!: " <<  e.what() << endl;
    }
    return true;
}

int main() {
    studentTest1();
    studentTest2();
    studentTest3();
    studentTest4();
    rollTest1();
    rollTest2();
    rollTest3();
    extraTests();
    return 0;
}
