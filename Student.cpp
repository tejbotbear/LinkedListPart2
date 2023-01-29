#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Student.h"

using namespace std;

void Student::setName(char* Name) {
    strcpy(name, Name);
}

void Student::setGpa(double Gpa) {
    gpa = Gpa;
}

void Student::setId(int Id) {
    id = Id;
}

char* Student::getName() {
    return name;
}

double Student::getGpa() {
    return gpa;
}

int Student::getId() {
    return id;
}

void Student::printStudent() {
    cout << name << " " << gpa << " " << id << endl;
}

Student::Student() {
    id = -1;
}

Student::~Student() {

}