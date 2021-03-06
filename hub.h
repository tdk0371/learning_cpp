#ifndef HUB_H
#define HUB_H

#include<iostream>
#include<cassert>

class Hub
{
private:
	int  m_first;
	int  m_second;
	int  m_third;
	int  m_size;
	int* m_arr = new int[m_size];
	
public:
	Hub(): m_first(0), m_second(0), m_third(0), m_size(5) {}
	Hub(int first, int second, int thrid):
		m_first(first), m_second(second), m_third(thrid), m_size(5) {}
	//copy constructor for deep copy due to dynamic memoery allocation new
	Hub(Hub& hub);

	~Hub() 
	{ 
		std::cout<<"Hub destroyed"<<'\n'; 
		delete[] m_arr;
	}

	int getfirst() { return m_first; }
	int getsecond() { return m_second; }
	int getthrid() { return m_third; }

	friend std::ostream& operator<<(std::ostream& out, Hub &hub);
	
	Hub& operator++();
	Hub  operator++(int);
	
	Hub& operator=(const Hub& hub);

	int& operator[](int index);

	Hub& operator-();
};


#endif
