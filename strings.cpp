#include<iostream>
#include<string>
#include<cstring>


int main()
{
	using std::string;
	using std::cout;
	using std::endl;

	string str1("this is test string one");
	string str2("0123456789");
	string str3("aabbccddee");

	//string assignment 
	string str4;
	str4.assign("zzyyxxww");
	string str5 = str4;
	string str6;
	str6.assign(9, 'm');

	cout<<str1<<'\n'<<str2<<'\n'<<str3<<'\n'<<str4<<'\n'<<str5<<'\n'<<str6<<'\n'<<endl;


	//c-style string
	cout<<strlen(str1.c_str())<<endl;   
	cout<<strlen(str1.data())<<endl;    //this does not change str1

	char cstr1[16];
	int nlength = str1.copy(cstr1,15,5); //copy start at index 5, copy 15 length
	cstr1[nlength] = '\0';

	cout<<cstr1<<" : "<<strlen(cstr1)<<" "<<nlength<<'\n'<<endl;

	//string swap
	
	swap(str1, str2);
	str2.swap(str3);
	

	cout<<str1<<'\n'<<str2<<'\n'<<str3<<'\n'<<endl;

	//string append
	str1 += str2;
	str3.append(str2, 3, 2);
	str2.append(5, 'n');
	str1.push_back('f');
	cout<<str1<<'\n'<<str2<<'\n'<<str3<<'\n'<<endl;

	//string insert
	str4.insert(2, "1234");
	str5.insert(2, str1, 5, 4);
	str6.insert(3, 5, 'k');
	cout<<str4<<'\n'<<str5<<'\n'<<str6<<'\n'<<endl;
	
	


	return 0;
}
