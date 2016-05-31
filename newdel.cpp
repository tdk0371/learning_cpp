#include<iostream>

using std::string;
using std::cout;
using std::endl;

class POINT {
public:
	int x;
	int y;
	POINT() {};
	POINT(int nx, int ny): x(nx), y(ny) {cout<<"point initialized"<<endl;}
	~POINT() {cout<<"destructor invoked"<<endl;}
};

class VECTOR {
public:
	POINT start;
	POINT end;

	VECTOR () {start.x=0;start.y=0;end.x=0;end.y=0;cout<<"vector initialized"<<endl;}
	VECTOR (VECTOR &o) {start = o.start; end = o.end; cout<<"vector copied"<<endl;}

	void offset(int x, int y) {
		start.x += x;
		start.y += y;
		end.x += x;
		end.y += y;
		cout<<"vector offseted"<<endl;}
	
	void startoffset(int x, int y) {
		start.x += x;
		start.y += y;
		cout<<"start point offseted"<<endl;}

	void endoffset(int x, int y) {
		end.x += x;
		end.y += y;
		cout<<"end point offseted"<<endl;}
	
	void print() {
		cout<<"vector start at ("<<start.x<<","<<start.y<<")"<<
		" end at ("<<end.x<<","<<end.y<<")"<<endl;}

	~VECTOR() {cout<<"destructor invoked"<<endl;}

};

//array wrapper object
class IARRAY {
public:
	int * arr;  //array pointer
	int size;   //array size
//constructor:
	IARRAY (int size) {
		arr = new int[size]; 
		this->size = size; 
		cout<<"constructor invoked"<<endl;}
//copy constructor:
	IARRAY (IARRAY &o) {
		arr = new int[o.size]; 
		size = o.size;
		for (int i=0;i<size;i++) arr[i] = o.arr[i]; 
		cout<<"copy constructor invoked"<<endl;}
//method:
	int sum() {
		int sum = 0;
		for (int i=0;i<size;i++) sum += arr[i];
		return sum;}
//destructor:	
	~IARRAY () {delete[] arr;cout<<"destructor invoker"<<endl;}
};
 




int main()
{
int i;
int arrsize = 5;


//use new to generate array
int * arr = new int[arrsize];
for (i=0;i<arrsize;i++) arr[i] = arrsize-i;
for (i=0;i<arrsize;i++) cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
delete[] arr;  //free memory 


POINT * p1 = new POINT(20,30);

VECTOR *v1 = new VECTOR;

v1->offset(2,3);
v1->print();

v1->startoffset(3,-1);
v1->print();

v1->endoffset(-1,2);
v1->print();




IARRAY table(arrsize);
for (i=0;i<arrsize;i++) table.arr[i] = arrsize-i;
for (i=0;i<arrsize;i++) cout<<"table.arr["<<i<<"] = "<<table.arr[i]<<endl;

if (true) 
{
	IARRAY b = table; //b go out of scope after this line
	for (i=0;i<arrsize;i++) cout<<"b.arr["<<i<<"] = "<<b.arr[i]<<endl;
}
	
for (i=0;i<arrsize;i++) cout<<"table.arr["<<i<<"] = "<<table.arr[i]<<endl;
//table became a dangling pointer after b is deleted
//solution: make a copy constructor in IARRAY class

cout<<"table.sum = "<<table.sum()<<endl;


return 0;
}
