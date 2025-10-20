#include <bits/stdc++.h>

using namespace std;

unsigned int id_max = 0;
inline unsigned int get_new_id(void) {
    assert(id_max + 1 > 0);
    return ++id_max;
}


class Employee {
    unsigned int id;
    char *name;
    char *position;
    float total_work_hour;

public:
    Employee()
        : id(get_new_id()), name(nullptr), position(nullptr), total_work_hour(0.0f)
    {}

    Employee(const char *name_, const char *position_, float work_hour)
        : id(get_new_id()), name(nullptr), position(nullptr), total_work_hour(0.0f)
    {
        set_name(name_);
        set_position(position_);
        set_work_hour(work_hour);
    }

    Employee(const Employee &other)
        : id(get_new_id()), name(nullptr), position(nullptr), total_work_hour(other.total_work_hour)
    {
        if (this == &other) return;
        set_name(other.name);
        set_position(other.position);
        set_work_hour(other.total_work_hour);
    }

    ~Employee() {
        delete[] name;
        delete[] position;
    }

    bool read() {
        cout << "Ajilchnii medeelludig oruulna uu\n";
        unsigned int tmp_id;
        while (true) {
            cout << "id: (0 gej oruulval automataar songono)" << flush;
            cin >> tmp_id;
            if (set_id(tmp_id)) break;
            cout << "Id davhtssan bain. Dahin oroldnu!" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool ok = true;

        char tmp[200];
        cout << "Ner: ";
        cin.getline(tmp, sizeof(tmp));
        ok &= set_name(tmp);

        cout << "Alban tushaal: ";
        cin.getline(tmp, sizeof(tmp));
        ok &= set_position(tmp);

        cout << "Ajilsan tsag: ";
        float wh;
        cin >> wh;
        ok &= set_work_hour(wh);
        return ok;
    }


    void print() const {
        cout << id << " dugaartai ajiltnii medeelel\n";
        cout << "Ner: " << (name ? name : "") << "\n";
        cout << "Alban tushaal: " << (position ? position : "") << "\n";
        cout << "Ajilsan tsag: " << fixed << setprecision(2) << total_work_hour << '\n';
        cout << "Tsaling: " << fixed << setprecision(2) << get_salary() << '\n';
    }

    float get_salary() const {
        if (position && strcasecmp(position, "zahiral") == 0)
            return get_owner_salary();
        const float rate = 20000;
        return rate * total_work_hour;
    }

    bool add_hour(float work_hour) {
        if (work_hour < 0 || work_hour > 24) return false;
        if (total_work_hour + work_hour > 31 * 24) return false;
        total_work_hour += work_hour;
        return true;
    }

    float get_whour() const { return total_work_hour; }
    unsigned int get_id() const { return id; }
    const char* get_name() const { return name ? name : ""; }
    const char* get_pos() const { return position ? position : ""; }


    bool set_id(unsigned int new_id) {
        if (new_id == 0) {
            id = get_new_id();
            return true;
        }
        if (new_id <= id_max) {cerr << "aldaa garlaa! set_id\n"; return false; }
        id_max = new_id;
        id = new_id;
        return true;
    }

    bool set_name(const char* new_name) {
        if (!new_name) new_name = "";
        size_t len = strlen(new_name);
        if (len == 0 || len > 200) {cerr << "aldaa garlaa! set_name\n"; return false; }
        copy_str(name, new_name);
        return true;
    }

    bool set_position(const char* new_position) {
        if (!new_position) new_position = "";
        size_t len = strlen(new_position);
        if (len == 0 || len > 200) {cerr << "aldaa garlaa! set_pos\n"; return false; }
        copy_str(position, new_position);
        return true;
    }

    bool set_work_hour(float new_hour) {
        if (new_hour < 0.0f || new_hour > 31 * 24) {cerr << "aldaa garlaa! set_hr\n"; return false; }
        total_work_hour = new_hour;
        return true;
    }

    void assign(const Employee &other) {
        if (this == &other) return;
        set_id(get_new_id());
        set_name(other.name);
        set_position(other.position);
        set_work_hour(other.total_work_hour);
    }

private:
    float get_owner_salary() const {
        if(strcasecmp(position, "zahiral") != 0) return 0.f;
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
        dest[need - 1] = '\0';
    }
};

bool cmp(const Employee *e1, const Employee *e2)
{
    return (strcmp(e1->get_name(), e2->get_name()) < 0);
}
void myswap(Employee *&e1, Employee *&e2)
{
    Employee *tmp = e1;
    e1 = e2;
    e2 = tmp;
}
int main()
{
    cout << "Ajilchni toogo oruulna uu:" << flush;
    int n; cin >> n;

    Employee **arr = new Employee*[n];
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << "-deh Ajilchnii medeelludig oruulna uu" << endl;
        arr[i] = new Employee;
        arr[i] -> read();
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (!cmp(arr[j], arr[j + 1])) 
                myswap(arr[j], arr[j + 1]);
        }
    }

    for(int i = 0; i < n; i++) arr[i] -> print();

    for(int i = 0; i < n; i++) delete arr[i];
    delete[] arr;
}


