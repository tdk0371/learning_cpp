#include<iostream>
#include<sstream>



int main()
{
	using std::endl;
	using std::cout;
	using std::stringstream;
	using std::string;

	stringstream os;
	os<<"omg!"<<endl;
	os<<"123!"<<endl;
	os<<"wtf!"<<endl;
	
	cout<<os.str();


	int nValue;
	string sValue;

	os.str("");
	os<<"omg "<<"123";

	os>>sValue;
	os>>nValue;

	cout<<sValue<<" "<<2*nValue<<endl;

	cout<<os.str()<<endl;






	return 0;
}
