#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>  //for exit()


int main()
{
	
	using namespace std;

	//output using append mode
	std::ofstream outf("testdata.dat", ios::app);


	//validation
	if (!outf)
	{
		cerr<<"cannot open file"<<endl;
		exit(1);
	}

	//ofstream object uses << to push into
	outf<<"this is line 1"<<'\n';
	outf<<"this is line 2"<<'\n';

	//if not close, ifstream cannot read properly
	outf.close();

	//read from file
	ifstream inf("testdata.dat");
	
	//validation
	if (!inf)
	{
		cerr<<"cannot open file"<<endl;
		exit(1);
	}

	while (inf)
	{
		string buff;
		
		//ifstream object uses >> to extract from, but only extract single word
		//use getline() cannot get the whole line
		getline(inf, buff);
		cout<<buff<<endl;
	}


































	return 0;
}
