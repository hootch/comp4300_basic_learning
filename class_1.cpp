#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string m_first   = "John";
    std::string m_last    = "Doe";
    int         m_id      = 0;
    float       m_avg     = 0;

public:
    Student() {}

    Student(std::string first, std::string last, int id, float avg)
        : m_first    (first)
        , m_last     (last)
        , m_id       (id)
        , m_avg      (avg)
    {
    }

    int getAvg() const
    {
        return m_avg;
    }

    //it is called const correctness
    int getId() const
    {
        return m_id;
    }

    std::string getFirst() const
    {
        return m_first;
    }

    std::string getLast() const
    {
        return m_last;
    }

    void print() const
    {
        std::cout << m_first << " " << m_last << " ";
        std::cout << m_id << " " << m_avg << "\n";
    }

};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course() {}

    Course(const std::string& name)
        : m_name(name)
    {}

    void addStudent(const Student& s)
    {
        m_students.push_back(s);
    }

    const std::vector<Student>& getStudents() const
    {
        return m_students;
    }

    void loadFromFile(const std::string& filename)
    {
        std::ifstream fin(filename);
        std::string first, last;
        int id;
        float avg;

        while (fin >> first)
        {
            fin >> last >> id >> avg;

            addStudent(Student(first, last, id, avg));
        }

    }

    void print() const
    {
        for (const auto& s : m_students)
          {
            s.print();
          }
    }

};


int main()
{
    Student s1;
    Student s2("Dave", "Churchill", 1, 3.14);
    Student s3("Jane", "Doe", 202200001, 99.99);

    Course comp4300("COMP 4300");
    comp4300.addStudent(s1);
    comp4300.addStudent(s2);
    comp4300.addStudent(s3);

    comp4300.addStudent(Student("John", "Doe", 202200002, 99.9));
//    comp4300.print();


    Course c("COMP 4400");
    c.loadFromFile("students.txt");
    c.print();

    return 0;
}