#pragma once

class CRefCounter
{
public:
	CRefCounter() { counter=0; }
	int Add() { return(++counter); }
	int Dec() { return(--counter); };
	int Get() { return(counter); }
private:
	int counter;
};//class CRefCounter

template <typename T>
class CMySmartPointer
{
public:
	CMySmartPointer(T* pcPointer);
	~CMySmartPointer();
	CMySmartPointer(const CMySmartPointer& other);
	T& operator*() { return(*pointer); }
	T* operator->() { return(pointer); }
	T operator=(CMySmartPointer& other);
private:
	T* pointer;
	CRefCounter* counter;
};



template<typename T>
 CMySmartPointer<T>::CMySmartPointer(T* ptr)
{
	 pointer = ptr;
	 counter = new CRefCounter();
	 counter->Add();
}

template<typename T>
 CMySmartPointer<T>::~CMySmartPointer()
{
	 if (counter->Dec() <= 0) 
	 {
		 delete pointer;
		 delete counter;
	 }
}

 template<typename T>
 CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& other)
 {
	 pointer = other.pointer;
	 counter = other.counter;
	 counter->Add();
 }

 template<typename T>
  T CMySmartPointer<T>::operator=(CMySmartPointer& other)
 {
	  if (counter->Dec() <=0) 
	  {
		  delete pointer;
		  delete counter;
	  }
	  pointer = other.pointer;
	  counter = other.counter;

	 return this;
 }
