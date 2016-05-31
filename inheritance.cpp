#include<iostream>
#include<string>


using std::string;
using std::cout;
using std::endl;


class VEHICLE {
protected:  //can be access by method inside class, cannot be accessed outside
	int year;
	string brand;
public:
	VEHICLE(const int myyear, const string &mybrand):    
	//must have const, & in string, no & in int
	year(myyear), brand(mybrand) {} //no ; after {}, no & in string, use , not ;

//methods:
	virtual void describe() {cout<<"is a "<<brand<<" licensed from "<<year<<endl;}

	int getyear() const {return year;} 
	//const make this function unable to change any value 

	const string &getbrand() const {return brand;}	
};




//class inheritance: every car is a vehicle, car is derived class
class CAR : public VEHICLE { 
protected:
	int milage;
	string style;  //also inherited year and brand from VEHICLE
public:
	CAR(const int myyear, const string &mybrand, const int mymilage, const string &mystyle): VEHICLE(myyear, mybrand), milage(mymilage), style(mystyle) {}
//constructor format, include parent class ini

//more methods:
	const string &getstyle() const {return style;}
	int getmilage() const {return milage;}
	virtual void describe() {cout<<"is a "<<brand<<"-"<<style<<" licensed from "<<year<<" with "<<milage<<" miles"<<endl;}   //method overriding (same method name as parent)
};





void printyear(VEHICLE * v);

int main()
{
int year;
string brand;

VEHICLE abc123(2008, "Ford");

year = abc123.getyear();
brand = abc123.getbrand();

CAR def123(2010, "BMW", 10000, "X6");

abc123.describe();

cout<<"vehicle brand: "<<brand<<endl;
cout<<"vehicle year: "<<year<<endl;

year = def123.getyear();
brand = def123.getbrand();

def123.describe();
cout<<"car brand: "<<brand<<endl;
cout<<"car year: "<<year<<endl;
cout<<"car style: "<<def123.getmilage()<<endl;


//virtual functions
VEHICLE *vptr = &def123;  //a CAR object  
vptr->describe();  //will use the describe() method in VEHICLE class

//add key word 'virtual' before describe() method in VEHICLE ( also in CAR)
vptr->describe(); //will use describe() method in CAR class


//polymorphism
printyear(&def123);  //def123 is a CAR object
printyear(&abc123);  //abc123 is a VEHICLE object

return 0;
}


void printyear(VEHICLE * v)
{
	cout<<"in function called: "<<endl;
	cout<<"year of vehicle = "<<v->getyear()<<endl;
	v->describe();
}


