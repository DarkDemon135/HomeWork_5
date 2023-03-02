#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;
 
class Student
{
    public:
        std::string m_FirstName;
        std::string m_MiddleName;
        std::string m_LastName;
        char m_Gender;
        unsigned short m_Group;
        std::string m_Faculty;
 
    public:
        Student() { };
        Student(const Student& Student) { };
        Student(std::string first_name, std::string middle_name, std::string last_name,
            char gender, unsigned short group, std::string faculty)
        {
            m_FirstName = first_name;
            m_MiddleName = middle_name;
            m_LastName = last_name;
            m_Gender = gender;
            m_Group = group;
            m_Faculty = faculty;
        }
 
        ~Student()
        {
            m_FirstName = "\0";
            m_MiddleName = "\0";
            m_LastName = "\0";
            m_Gender = '\0';
            m_Group = 0;
            m_Faculty = "\0";
        }
 
    public:
        void Show()
        {
            std::cout << m_FirstName << endl;
            std::cout << m_MiddleName << endl;
            std::cout << m_LastName << endl;
            std::cout << m_Gender << endl;
            std::cout << m_Group << endl;
            std::cout << m_Faculty << endl;
        }
 
        friend ostream& operator<<(ostream& output, const Student& S)
        {
            output << "FirstName : " << S.GetFirstName() << " MiddleName : " \
                << S.GetMiddleName() << " LastName : " << S.GetLastName() << " Gender : " << S.GetGender() \
                << " Group : " << S.GetGroup() << " Faculty : " << S.GetFaculty();
            return output;
        }
 
        friend istream& operator>>(istream& input, Student& S)
        {
            input >> S.m_FirstName >> S.m_MiddleName >> S.m_LastName >> \
                S.m_Gender >> S.m_Group >> S.m_Faculty;
            return input;
        }
 
        std::string ToString() const
        {
            std::ostringstream ss;
            ss << this->m_FirstName << this->m_MiddleName << this->m_LastName << \
                this->m_Gender << this->m_Group << this->m_Faculty;
 
            return ss.str();
        }
 
    public:
        void SetFirstName(std::string first_name)
        {
            m_FirstName = first_name;
        }
 
        void SetMiddleName(std::string middle_name)
        {
            m_MiddleName = middle_name;
        }
 
        void SetLastName(std::string last_name)
        {
            m_LastName = last_name;
        }
 
        void SetGender(char gender)
        {
            m_Gender = gender;
        }
 
        void SetGroup(unsigned short group)
        {
            m_Group = group;
        }
 
        void SetFaculty(std::string faculty)
        {
            m_Faculty = faculty;
        }
 
    public: 
        std::string GetFirstName() const
        {
            return m_FirstName;
        }
 
        std::string GetMiddleName() const
        {
            return m_MiddleName;
        }
 
        std::string GetLastName() const
        {
            return m_LastName;
        }
 
        char GetGender() const
        {
            return m_Gender;
        }
 
        unsigned short GetGroup() const
        {
            return m_Group;
        }
 
        std::string GetFaculty() const
        {
            return m_Faculty;
        }
};
 
class Aspirant : public Student
{
    public:
        std::string m_ResearchTitle;
        std::string m_Coordinator;
 
    public:
        Aspirant() { };
        Aspirant(const Aspirant& aspirant) { };
        Aspirant(std::string research_title, std::string coordinator)
        {
            m_ResearchTitle = research_title;
            m_Coordinator = coordinator;
        }
 
        ~Aspirant() 
        {
            m_ResearchTitle = "\0";
            m_Coordinator = "\0";
        }
 
    public:
        void Show()
        {
            std::cout << m_ResearchTitle << endl;
            std::cout << m_Coordinator << endl;
        }
 
        friend ostream& operator<<(ostream& output, const Aspirant& A)
        {
            output << "ResearchTitle : " << A.GetResearchTitle() << " Coordinator : " << A.GetCoordinator();
            return output;
        }
 
        friend istream& operator >> (istream& input, Aspirant& A)
        {
            input >> A.m_ResearchTitle >> A.m_Coordinator;
            return input;
        }
 
        std::string ToString() const
        {
            std::ostringstream ss;
            ss << this->m_ResearchTitle << this->m_Coordinator;
 
            return ss.str();
        }
    
    public:
        void SetFirstName(std::string research_title)
        {
            m_ResearchTitle = research_title;
        }
 
        void SetMiddleName(std::string coordinator)
        {
            m_Coordinator = coordinator;
        }
 
    public:
        std::string GetResearchTitle() const
        {
            return m_ResearchTitle;
        }
 
        std::string GetCoordinator() const
        {
            return m_Coordinator;
        }
};