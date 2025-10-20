// File: Student.h
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
class Student {
public:

char *name; 
int course;


private:
char *student_id; 
float gpa; 
static int count;


public:
    Student(); 
    Student(const char *name_, const char *id_, int course_, float gpa_); // parameterized
    Student(const Student &other);
    Student& operator=(const Student &other); 
    ~Student(); 


    // Read / print helpers
    void read();
    void print() const;


    // Comparison by course
    bool greaterThan(const Student &other) const;
    bool lessThan(const Student &other) const;
    bool isEqual(const Student &other) const;


  
    bool before(const Student &other) const; 
    bool after(const Student &other) const; 


    const char* get_name() const;
    const char* get_id() const;
    int get_course() const;
    float get_gpa() const;


    bool set_name(const char *new_name);
    bool set_id(const char *new_id);
    bool set_course(int new_course);
    bool set_gpa(float new_gpa);


    static void print_count();

    private:
    void copy_str(char *&dest, const char *src);
};

#endif