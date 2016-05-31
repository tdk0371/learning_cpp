#include<iostream>

template <typename T>
class Myarr
{
private:
	int m_size;
	T* m_arr;
public:
	Myarr(int size = 1)
	{	
		m_size = size;
		m_arr = new T[m_size];
	}

	//exception should not be put in destructor
	~Myarr()
	{
		delete[] m_arr;
	}

	T& operator[](int index);	
};

template <typename T>
T& Myarr<T>::operator[](int index)
{
	//throw std exception class: out_of_range
	if (index<0 || index>=m_size)
		throw std::out_of_range("outofrange");
	return m_arr[index];
}


int main()
{


	using std::cout;
	using std::endl;

	int size = 5;
	Myarr<double> arr(size);

	
	//functions, class put in try block, error will be thrown out
	try
	{
		for (int i=0;i<size;++i) arr[i] = i + 0.5;
		for (int i=0;i<size+1;++i) cout<<"  "<<arr[i];
		cout<<endl;
	}
	//catch follows try, catch any thrown object with data type as specified
	catch(std::out_of_range &Oor)
	{
		cout<<'\n';
		cout<<Oor.what()<<'\n';
	}
	//all std exception class are inherit from std::excpetion, it can catch all derived calss
	//so put it after all its derived class catch
	catch(std::exception &Exc)
	{
		cout<<Exc.what()<<'\n';
	}	
	



	return 0;
}
