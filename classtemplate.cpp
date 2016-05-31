#include <iostream>
#include<ostream>

using namespace std;

template <typename T>
T add(T a, T b);

template <typename T, typename U>
U add(T a, U b);



//class template with char specialization
template <typename T>
class tcontainer {
public:
	T var;
	tcontainer(T var) {this->var = var;}
	T inc() {return var + 1;}
};

template <>  //char specialization
class tcontainer<char> {
public:
	char var;
	tcontainer (char mychar): var(mychar) {} 
	char uppercase() {return toupper(var);}
};		


class position {
		public:
			int X, Y;
			position() {X=0;Y=0;cout<<"default point ini"<<endl;}

			position(int nx, int ny) {X=nx; Y=ny;cout<<"position ini as "<<"("<<X<<","<<Y<<")"<<endl;}//take parameter when ini

			position(position &p) {cout<<"custom copy constructor"<<endl;X = p.X; Y= p.Y;} //make a copy when ini
		};


class parts {
		public: 
			std::string name;
			int serial;
			position start;
			position end;   //class will be default initialized
			parts(){cout<<"default ini"<<endl; name = "";serial = 0;}
			void move (int dx, int dy)
			{
				start.X += dx;
				start.Y += dy;
				end.X   += dx;
				end.Y   += dy;
				updateserial(); 
			}
			
		private:
			void updateserial() {serial = serial + 1;}
		};


class money {
public:
	int dollar;
	int cent;
	money() {}
	money(int x, int y): dollar(x), cent(y) {}
};

//operator overriding
money operator+(const money &m1, const money &m2) {
	money tmp;
	tmp.dollar = m1.dollar+m2.dollar;
	tmp.cent = m1.cent + m2.cent;
	cout<<&m1<<endl;
	if (tmp.cent>=100) {
		tmp.dollar += 1;
		tmp.cent -= 100;
	}
	return tmp;
}

ostream& operator<<(ostream& o, const money &m) {
	o<<"$"<<m.dollar<<"."<<m.cent;
	return o;
}



int main()
{



int i;
int n=5;
int isum;
double dsum;
//std::string csum;
cout<<"hello world"<<endl;


			

parts part1;

position point1(3,5);
position point2;


cout<<"part start x = "<<part1.start.X<<endl;
cout<<"serial = "<<part1.serial<<endl;

part1.move(2,4);

cout<<"part start x = "<<part1.start.X<<endl;
cout<<"serial = "<<part1.serial<<endl;
//part1.updateserial();  //cannot access private member


//for (i=0;i<10;i++) std::cout<<(n=n+i)<<std::endl;

cout<<(isum=add(4,5))<<endl;
//std::cout<<(dsum=add(4.4,5.5))<<std::endl;
//std::cout<<(csum=add("str1","str2"))<<std::endl;


tcontainer<int> tc1(5);
tcontainer<double> tc2(5.5);
tcontainer<char> tc3('a');

cout<<tc1.inc()<<endl;
cout<<tc2.inc()<<endl;
cout<<tc3.uppercase()<<endl; //cout<<tc2.inc()<<endl; not work here


money m1(2, 50);
money m2(3, 75);

cout<<&m1<<endl;
money m3;
m3 = m1+m2;
cout<<m3<<endl;


return 0;
}

template <typename T>
T add(T a, T b)
{
	T sum;
	sum = a + b;
	return sum;
}

template <typename T, typename U>
U add(T a, U b)
{
	U sum;
	sum = a + b;
	return sum;
}

