#include <bits/stdc++.h>
using namespace std;

class Employee {
    unsigned int id;
    char *name;
    char *position;
    float total_work_hour;

public:
    Employee()
        : id(0), name(nullptr), position(nullptr), total_work_hour(0.0f)
    {}
    Employee(unsigned int id, char *name, char *position, float total_work_hout)
        : id(id), name(nullptr), position(nullptr), total_work_hour(total_work_hout)
    {
        copy_str(this->name, name);
        copy_str(this->position, position);
    }

    Employee(const Employee &other)
        : id(other.id), name(nullptr), position(nullptr), total_work_hour(other.total_work_hour)
    {
        if (this == &other) return;
        copy_str(name, other.name);
        copy_str(position, other.position);
    }

    void assign(const Employee &other) {
        if (this == &other) return;
        id = other.id;
        total_work_hour = other.total_work_hour;
        copy_str(name, other.name);
        copy_str(position, other.position);
    }

    ~Employee() {
        delete[] name;
        delete[] position;
    }
    void read() {
        cout << "Ajilchnii medeelludig oruulna uu" << endl;
        cout << "Dugaar (id): ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        char tmp[100];
        cout << "Ner: ";
        cin.getline(tmp, sizeof(tmp));
        copy_str(name, tmp);

        cout << "Alban tushaal: ";
        cin.getline(tmp, sizeof(tmp));
        copy_str(position, tmp);

        cout << "Ajilsan tsag: ";
        cin >> total_work_hour;
    }

    void read_rest()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        char tmp[100];
        cout << "Ner: ";
        cin.getline(tmp, sizeof(tmp));
        copy_str(name, tmp);

        cout << "Alban tushaal: ";
        cin.getline(tmp, sizeof(tmp));
        copy_str(position, tmp);

        cout << "Ajilsan tsag: ";
        cin >> total_work_hour;
    }

    void print() const {
        cout << id << " dugaartai ajiltnii medeelel\n";
        cout << "Ner: " << (name ? name : "") << "\n";
        cout << "Alban tushaal: " << (position ? position : "") << "\n";
        cout << "Ajilsan tsag: " << fixed << setprecision(2) << total_work_hour << endl;
        cout << "Tsaling: " << fixed << setprecision(2) << get_salary() << endl;
    }

    float get_salary() const {
        if (position && strcasecmp(position, "zahiral") == 0)
            return get_owner_salary();
        const float rate = 20000;
        return rate * total_work_hour;
    }

    bool add_hour(float work_hour) {
        if (work_hour < 0 || work_hour > 24) return false;
        total_work_hour += work_hour;
        return true;
    }

    float get_whour() const { return total_work_hour; }
    unsigned int get_id() const { return id; }
    const char* get_name() const { return name ? name : ""; }
    const char* get_pos() const { return position ? position : ""; }

    void set_id(unsigned int new_id) { id = new_id; }
    void set_name(const char* new_name) { copy_str(name, new_name ? new_name : ""); }
    void set_position(const char* new_position) { copy_str(position, new_position ? new_position : ""); }
    void set_work_hour(float new_hour) { total_work_hour = max(0.0f, new_hour); }

private:
    float get_owner_salary() const {
        const float rate = 40000;
        const float extra = 1000000;
        return rate * total_work_hour + extra;
    }

    void copy_str(char *&dest, const char *src) {
        if (!src) src = "";
        size_t need = strlen(src) + 1;
        delete[] dest;
        dest = new char[need];
        strncpy(dest, src, need);
    }
};

bool id_exist(Employee **arr, unsigned int id, int sz) {
    for(int i = 0; i < sz; i++) {
        if(arr[i]->get_id() == id) return 1;
    }
    return 0;
}
int main() {
    cout << "Ajilchni toogo oruulna uu:" << flush;
    int n; cin >> n;

    Employee **arr = new Employee*[n];
    for(int i = 0; i < n; i++)
    {
        unsigned int id;
        while(true)
        {
            cout << i + 1 << "-deh Ajilchnii medeelludig oruulna uu" << endl;
            cout << "Dugaar (id): ";
            cin >> id;
            if(id_exist(arr, id, i))
            {
                cout << "Id burtgeltei baina!!\n";
                continue;
            }
            else break;
        }
        arr[i] = new Employee();
        arr[i] -> set_id(id);
        arr[i] -> read_rest();
    }

    sort(arr, arr + n, [&](const Employee *e1, const Employee *e2)
    {
        return (strcmp(e1->get_name(), e2->get_name()) < 0);
    });

    for(int i = 0; i < n; i++)
    {
        arr[i] -> print();
    }
    return 8 >> 13;
}
