#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

class Student {
 public:
    Student();
  //  Student(char* name, double gpa, int id);
    ~Student();
    void setName(char* Name);
    void setGpa(double Gpa);
    void setId(int Id);
    char* getName();
    double getGpa();
    int getId();
    void printStudent();

private:
    char name[1000];
    double gpa;
    int id;
};

#endif /* STUDENT_H_ */