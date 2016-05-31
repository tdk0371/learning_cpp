#include<iostream>

//-std=c++11


//class prototype
class Object_b;

class Object_a 
{
private:
	const int serial;
	int data;
	int myarr [5];
public:
	//faverable contstructor style: 
	Object_a():  serial {8088}, data {12}, myarr {1, 2, 3, 4, 5} 
	{
	}
	
	//another constructor with function call (to reduce redundant code)
	Object_a(int a, int b): data {a}, serial {b}  { unifyarr(2); }

	//another constructor with constructor chaining (to reduce redundant code)
	Object_a(int c): Object_a() { data = c; }

	//destructor
	~Object_a() { std::cout<<"invoke destructor"<<'\n'; }

	//memeber functions
	int getserial() const { return serial; }
	
	//make function const friendly if the function does not change anything
	int getdata() const { return data; }
	
	void dataoffset(int index)
	{
		if (index>4 || index<0) 
		{
			std::cout<<"invalid index"<<std::endl;
			return;
		}
		data = data + myarr[index];
	}

	void unifyarr(int a) { for (int i=0;i<5;++i) myarr[i] = a; }
	
	//member functions can also define outside of class declearation
	Object_a& add(int value);
	Object_a& sub(int value);
	Object_a& mul(int value);

	//friend: so that isEqual() can access all members in this class
	friend void isEqual(const Object_a &obj1, const Object_b &obj2);
};

class Object_b
{
private:
	const int serial;
	int data;
public:
	Object_b(): serial {0}, data {35} 
	{
	}
	
	~Object_b() { std::cout<<"invoke destructor"<<'\n'; }

	//cannot use friend to add member function
	//friend int Object_a::getdata() const;  

	static int static_objb;
	static void print() { std::cout<<static_objb<<'\n'; }

	friend void isEqual(const Object_a &obj1, const Object_b &obj2);
	
};


void isEqual(const Object_a &obj1, const Object_b &obj2) 
{
	if (obj1.data == obj2.data) std::cout<<"a == b"<<'\n';
}
	 
	//this pointer and chainning, *this is a ref to the object
	//member functions can also define outside of class declearation
	Object_a& Object_a::add(int value) {data += value; return *this;}
	Object_a& Object_a::sub(int value) {data -= value; return *this;}
	Object_a& Object_a::mul(int value) {data *= value; return *this;}

//static member no need to be in class object, cannot ini in main()
int Object_b::static_objb = 1;

int main()
{
	using std::cout;
	using std::endl;

	Object_a aaaa;
	
	cout<<aaaa.getserial()<<endl;
	cout<<aaaa.getdata()<<endl;
	aaaa.dataoffset(4);
	aaaa.dataoffset(5);
	cout<<aaaa.getdata()<<endl;

	cout<<endl;

	Object_a bbbb{111};  //uniform ini
	
	cout<<bbbb.getserial()<<endl;
	cout<<bbbb.getdata()<<endl;
	bbbb.dataoffset(4);
	bbbb.dataoffset(5);
	cout<<bbbb.getdata()<<endl;

	//this pointer chainning: aaaa.mul(2) called, return &aaaa, then aaaa.add(4)
	aaaa.mul(2).add(4).sub(3);
	//cout is also a chainning cout<<aaaa.get -> return cout
	cout<<aaaa.getdata()<<endl;

	//static member no need to be in class object
	Object_b::print();

	cout<<endl;

	Object_b objb;
	objb.print();
	isEqual(aaaa, objb);
	





	return 0;
}
