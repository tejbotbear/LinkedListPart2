#include <iostream>
#include "Node.h"
#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif

using namespace std;

Node::Node(Student* pupil) {
  student = pupil;
  next = NULL;
}

Node::~Node() {
  delete student;
}

Student Node::getStudent() {//returns the "value" which is the student class
  return (*student);
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}
