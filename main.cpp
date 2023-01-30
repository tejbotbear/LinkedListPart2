// Tej Hiremath
// This is a project similar to the Student List assignment, that uses linked lists and pointers to store student data.
// 1/29/2023
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <numbers>
#include <cstring> 
#include "Student.h"
#include "Node.h"
using namespace std;



Node* AddStudent(Node *current) {
  char studentName[256];
  double studentGpa;
  int studentId;
  Student *pStudent;
  Node *pNode;

  cout << "Enter student name: ";
  cin >> studentName;
  cout << "Enter student gpa: ";
  cin >> studentGpa;
  cout << "Enter student id: ";
  cin >> studentId;

  pStudent = new Student();
  pNode = new Node(pStudent);

  pStudent->setName(studentName);
  pStudent->setGpa(studentGpa);
  pStudent->setId(studentId);

  pNode->setNext(NULL);

  if(current == NULL)
  {
    return pNode; // first node
  }
  // add new node pointer to current node
  current->setNext(pNode);
  // rertun new node (last node in list)
  return current->getNext();
}


void printStudent(Node *head) {
  Node* temp = head;
  Student tempStudent;

  while (temp != NULL) {
    tempStudent = temp->getStudent();
    cout << tempStudent.getName() << " " << fixed << setprecision(2) << tempStudent.getGpa() << " " << tempStudent.getId() << endl;
    temp = temp->getNext();
  }
}

void DeleteStudent(int DeleteId, Node* head)
{
  Node* temp = head;
  Node* prev = NULL;
  Student tempStudent;

  if(head == NULL)
  {
    cout << "Linked List is empty" << endl;
    return;
  }

  while (temp != NULL) {
    tempStudent = temp->getStudent();
    if(tempStudent.getId() == DeleteId)
    {
      if(prev == NULL)
      {
        head = temp->getNext();
      }
      else
      {
        prev->setNext(temp->getNext());
      }
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->getNext();
  }
}

void AverageGpa(Node* head) {
  Node* temp = head;
  Student tempStudent;
  double totalGpa = 0;
  int StudentCount = 0;

  if(head == NULL)
  {
    cout << "Linked List is empty, average cannot be calculated!" << endl;
    return;
  }

  while (temp != NULL) {
    tempStudent = temp->getStudent();
    totalGpa = totalGpa + tempStudent.getGpa();
    StudentCount = StudentCount + 1;
    temp = temp->getNext();
  }
  cout << "The average GPA amongst the entered students is: " << fixed << setprecision(2) << totalGpa/StudentCount << endl;
}

void DeleteAll(Node* head) {
  Student *tempStudent;
  Node* temp = head;
  Node* next = NULL;

   while (temp != NULL) {
    next = temp->getNext();
    delete temp;
    temp = next;
  }
}

int main() {
  char userInput[10];
  char* name;
  double gpa;
  int id;
  Node* head = NULL;
  Node* current = NULL;
  Student tempStudent;

  memset(userInput, 0, 10);
  cout << "Enter a command: add, print, delete, average, quit" << endl;
  cin >> userInput;

  while (strcmp(userInput, "quit")) {
    if (!strcmp(userInput, "add")) {
      if(head == NULL){
        // first node
        head = AddStudent(head);
      }
      else{
        current = head;
        // find last node
        while(current->getNext() != NULL)
        {
          current = current->getNext();
        }
        AddStudent(current);
      }
      memset(userInput, 0, 10);
    }
    else if(!strcmp(userInput, "print")){
      printStudent(head);
    }
    else if(!strcmp(userInput, "delete")){
      cout << "Enter ID of Student to delete: ";
      cin >> id;

      if(head == NULL){
        cout << "Linked List is empty" << endl;
      }
      else{
        tempStudent = head->getStudent();
        current = head;
        if(tempStudent.getId() == id)
        {
          head = current->getNext();
        }
        DeleteStudent(id, current);
      }
    }
    else if(!strcmp(userInput, "average")) {
      AverageGpa(head);
    }
    else{
      cout << "Invalid command" << endl;
    }
  memset(userInput, 0, 10);
  cout << "Enter a command: add, print, delete, average, quit" << endl;
  cin >> userInput;
  }
  DeleteAll(head);
  return 0;
}