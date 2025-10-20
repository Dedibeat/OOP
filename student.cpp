#include "student.h"
#include <bits/stdc++.h>
using namespace std;

int Student::count = 0;

Student::Student()
    : name(nullptr), course(1), student_id(nullptr), gpa(0.0f)
{
    copy_str(name, "");
    copy_str(student_id, "");
    ++count;
}

Student::Student(const char *name_, const char *id_, int course_, float gpa_)
    : name(nullptr), course(1), student_id(nullptr), gpa(0.0f)
{
    if (!set_name(name_ ? name_ : "")) copy_str(name, "");
    if (!set_id(id_ ? id_ : "")) copy_str(student_id, "");
    if (!set_course(course_)) course = 1;
    if (!set_gpa(gpa_)) gpa = 0.0f;
    ++count;
}

Student::Student(const Student &other)
    : name(nullptr), course(other.course), student_id(nullptr), gpa(other.gpa)
{
    // deep copy strings
    copy_str(name, other.name ? other.name : "");
    copy_str(student_id, other.student_id ? other.student_id : "");
    ++count;
}

Student& Student::operator=(const Student &other)
{
    if (this == &other) return *this;
    if (!set_name(other.name ? other.name : "")) {}
    if (!set_id(other.student_id ? other.student_id : "")) {}
    course = other.course;
    gpa = other.gpa;
    return *this;
}

Student::~Student()
{
    delete[] name;
    delete[] student_id;
    --count;
}

void Student::read()
{
    char buf[256];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ner: ";
    cin.getline(buf, sizeof(buf));
    if (!set_name(buf)) {
        cerr << "[error] invalid name, keeping empty name\n";
    }

    cout << "Oyuutnii dugaar: ";
    cin.getline(buf, sizeof(buf));
    if (!set_id(buf)) {
        cerr << "[error] invalid id, keeping empty id\n";
    }

    cout << "Kurs (eyreg buhel too): ";
    int c; cin >> c;
    if (!set_course(c)) {
        cerr << "[error] invalid course, setting to 1\n";
        course = 1;
    }

    cout << "Golch (0.0 - 4.0): ";
    float g; cin >> g;
    if (!set_gpa(g)) {
        cerr << "[error] invalid gpa, setting to 0.0\n";
        gpa = 0.0f;
    }
}

void Student::print() const
{
    cout << "Ner: " << (name ? name : "") << "\n";
    cout << "Dugaar: " << (student_id ? student_id : "") << "\n";
    cout << "Kurs: " << course << "\n";
    cout << "Golch: " << fixed << setprecision(2) << gpa << "\n";
}

bool Student::greaterThan(const Student &other) const { return course > other.course; }
bool Student::lessThan(const Student &other) const { return course < other.course; }
bool Student::isEqual(const Student &other) const { return course == other.course; }

bool Student::before(const Student &other) const
{
    const char *a = name ? name : "";
    const char *b = other.name ? other.name : "";
    return strcmp(a, b) < 0;
}

bool Student::after(const Student &other) const
{
    const char *a = name ? name : "";
    const char *b = other.name ? other.name : "";
    return strcmp(a, b) > 0;
}

const char* Student::get_name() const { return name ? name : ""; }
const char* Student::get_id() const { return student_id ? student_id : ""; }
int Student::get_course() const { return course; }
float Student::get_gpa() const { return gpa; }

bool Student::set_name(const char *new_name)
{
    if (!new_name) new_name = "";
    size_t len = strlen(new_name);
    if (len > 200) {
        cerr << "Iim nertei hun baihgui!\n";
        return false;
    }
    copy_str(name, new_name);
    return true;
}

bool Student::set_id(const char *new_id)
{
    if (!new_id) new_id = "";
    size_t len = strlen(new_id);
    if (len > 100) {
        cerr << "Arai tom id yu!\n";
        return false;
    }
    copy_str(student_id, new_id);
    return true;
}

bool Student::set_course(int new_course)
{
    if (new_course <= 0) {
        cerr << "kurs ni eyreg baina\n";
        return false;
    }
    course = new_course;
    return true;
}

bool Student::set_gpa(float new_gpa)
{
    if (!(new_gpa >= 0.0f && new_gpa <= 4.0f)) {
        cerr << "golch ni 0 ees 4 iin hoorond baina\n";
        return false;
    }
    gpa = new_gpa;
    return true;
}

void Student::print_count()
{
    cout << "Student object-iin too: " << count << endl;
}

void Student::copy_str(char *&dest, const char *src)
{
    if (!src) src = "";
    size_t need = strlen(src) + 1;
    delete[] dest;
    dest = new char[need];
    strncpy(dest, src, need);
    dest[need - 1] = '\0';
}
