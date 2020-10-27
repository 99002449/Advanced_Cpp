#include <iostream>
template<class T>
class MoveConstructor
{
	T* m_ptr;

public:
	// Move constructor
	
	MoveConstructor(T* ptr=nullptr):m_ptr(ptr)
	{
	
	}
	//Destructor to distroy the pointer after completion of task
	~MoveConstructor()
	{
		delete m_ptr;
	}
	
	// Transfer ownership of a.m_ptr to m_ptr
	MoveConstructor(MoveConstructor&& a) noexcept: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; 
	}
	
	MoveConstructor& operator=(MoveConstructor&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;
 
		// Release any resource we're holding
		delete m_ptr;
 
		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
 
		return *this;
	}
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
 
MoveConstructor<Resource> generateResource()
{
	MoveConstructor<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}
 
int main()
{
	MoveConstructor<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment
 
	return 0;
}


