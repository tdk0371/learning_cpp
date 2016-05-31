#include"hub.h"


//overlaod IO
std::ostream& operator<<(std::ostream& out, Hub &hub)
{
	out<<"FIrst="<<hub.getfirst()<<" Second="<<hub.getsecond()<<
	" Third="<<hub.getthrid();

	return out;
}


//overload increment
//prefix: ++Hub
Hub& Hub::operator++()
{
	++m_first;
	++m_second;
	++m_third;

	return (*this);
}
//suffix: Hub++
Hub Hub::operator++(int)
{
	Hub temp = (*this);
	++(*this);
	return temp;
}


//overload assignment =
//for deep copy due to dynamic memoery allocation new 
Hub& Hub::operator=(const Hub& hub)
{
	//check if assign to itself (by checking address)
	if (this == &hub) return *this;

	else
	{
		delete[] m_arr; //delete existing memory

		//shallow copy
		m_first = hub.m_first;
		m_second = hub.m_second;
		m_third = hub.m_third;
		m_size = hub.m_size;

		//reallocate memory and copy elemets
		int* m_arr = new int[m_size];
		for (int i=0;i<m_size;++i) m_arr[i]=hub.m_arr[i];
	}
	
	//so we can chain assignment=
	return *this;
}

//overload copy constructor
Hub::Hub(Hub& hub)
{
	//shallow copy
	m_first = hub.m_first;
	m_second = hub.m_second;
	m_third = hub.m_third;
	m_size = hub.m_size;
	//deep copy
	int* m_arr = new int[m_size];
	for (int i=0;i<m_size;++i) m_arr[i]=hub.m_arr[i];
}


//overload []
int& Hub::operator[](int index)
{
	assert (index>=0 && index<m_size);
	return m_arr[index];

}


//overload -
Hub& Hub::operator-()
{
	m_first = -m_first;
	m_second = -m_second;
	m_third = -m_third;

	return *this;
}











