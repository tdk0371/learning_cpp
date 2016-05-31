#include<iostream>
#include<string>

using std::string;

class Person 
{
private:
	int m_age;
	string m_name;

public:
	Person(int age = 0, string name = ""):
		m_age(age), m_name(name) {}
	
	~Person() { std::cout<<"person destoryed"<<'\n'; }


	string& getname() { return m_name; }
	int getage() { return m_age; }
};

class Employee : virtual public Person
{
private:
	int m_uid;
	int m_pay;

public:
	Employee(int age = 0, string name = "", int uid = 0, int pay = 0):
		Person(age, name), m_uid(uid), m_pay(pay) {} //can access Person due to the virtual in Employee inheritance

	~Employee() { std::cout<<"employee destoryed"<<'\n'; }

	int getid() { return m_uid; }
	int getpay() { return m_pay; }
};

class Teacher : public Employee
{
private:
	string m_department;
	int m_depcode;
	//using Person::getage;  //hide getage() in Person, now not access through Teacher class

public:
	Teacher (int age = 0, string name = "", int uid = 0, int pay = 0, string department = "",int depcode = 0):
		Person (age, name), Employee(age, name, uid, pay), m_department(department),m_depcode(depcode) {}

	~Teacher() { std::cout<<"teacher destoryed"<<'\n'; }

	string& getdep() { return m_department; }
	//int getid() { return m_depcode; }  //decomment will replace getid() in Employee

};

//chain inheritance
// Person, Employee:Person, Teacher:Employee

//multiple inheritance
//Person, Employee, Teacher:Employee,Person


int main()
{

	using std::cout;
	using std::endl;

	Teacher teacher1 {25, "Peter", 23098, 70000, "math", 2022};
	//Teacher teacher2;

	cout<<"Teacher1 is "<<teacher1.getname()<<" in "<<teacher1.getdep()<<
	" department. UID is "<<teacher1.getid()<<". Currently at the age of "<<
	teacher1.getage()<<", earning "<<teacher1.getpay()<<" a year."<<endl;




















	return 0;
}


































