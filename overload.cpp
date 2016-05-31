//g++ hub.h hub.cpp overload.cpp -std=c++11


#include"hub.h"




int main()
{

	Hub hub1 {1, 2, 3};
	Hub hub2; //0, 0, 0

	std::cout<<hub1<<std::endl;

	hub2 = ++hub1;
	std::cout<<"Hub1: "<<hub1<<std::endl; // 2, 3, 4
	std::cout<<"Hub2: "<<hub2<<std::endl; // 2, 3, 4
	
	hub2 = hub1++;
	std::cout<<"Hub1: "<<hub1<<std::endl; // 3, 4, 5
	std::cout<<"Hub2: "<<hub2<<std::endl; // 2, 3, 4

	hub1[2] = 5;
	std::cout<<hub1[2]<<std::endl;

	hub2 = -(-(-hub2));
	std::cout<<"Hub2: "<<hub2<<std::endl; // -2, -3, -4




	return 0;
}
