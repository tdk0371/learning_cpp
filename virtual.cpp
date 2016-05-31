#include<iostream>
#include<string>

using std::string;


class Animal
{
private:
	string m_name;
public:
	Animal(const string &name): m_name(name) {}

	//make base destoryor virtual, then it cannot be called by base pointer
	virtual ~Animal() { std::cout<<"animal destoryed"<<'\n'; }

	const string& getname() const { return m_name; }

	//pure virtual function, making Animal an abstrat base class	
	virtual const char* speak() = 0;
};



class Cat : public Animal
{
public:
	Cat(const string &name): Animal(name) {}
	~Cat() { std::cout<<"cat destoryed"<<'\n'; }

	virtual const char* speak() { return "meow"; }
};

class Dog : public Animal
{
public:
	Dog(const string &name): Animal(name) {}
	~Dog() { std::cout<<"dog destoryed"<<'\n'; }

	virtual const char* speak() { return "woof"; }
};


//interface class, with pure virtual functions
class Ilog
{
public:
	virtual const char* myid() = 0;
	virtual int log_id() = 0;
	virtual string& log_print() = 0;
};


class Errorlog : public Ilog
{
private:
	int m_id;
	string m_log;
public:
	Errorlog(int id, string myerr): m_id(id), m_log(myerr) {}

	virtual const char* myid() { return "error log: "; }
	virtual int log_id() { return m_id; }
	virtual string& log_print() { return m_log; }
};

 
class Syslog : public Ilog
{
private:
	int m_id;
	string m_log;
public:
	Syslog(int id, string mysys): m_id(id), m_log(mysys) {}

	virtual const char* myid() { return "system log: "; }
	virtual int log_id() { return m_id; }
	virtual string& log_print() { return m_log; }
};


//use interface class as argument, then all derived classes can be passed into
void showlog(Ilog &ilog)
{
	std::cout<<ilog.myid()<<ilog.log_id()<<"____"<<ilog.log_print()<<'\n';
}


int main()
{
	using std::cout;
	using std::endl;

	//Animal animal("ani"); //invalid, abstrat base class cannot be instanized

	Cat ccat("jade");
	Dog ddog("wangcai");

	Animal* pcat = &ccat;
	Animal& rdog = ddog;  //base pointer and ref can point to its derived

	cout<<pcat->getname()<<" says "<<pcat->speak()<<endl;
	cout<<rdog.getname()<<" says "<<rdog.speak()<<endl;

	Errorlog elog(2086, "error happens in daf.dll");
	Syslog slog(1394, "system maintance at 9:30");

	showlog(elog);
	showlog(slog);





	return 0;
}
