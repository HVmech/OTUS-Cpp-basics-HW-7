#pragma once

#include "iter_v.h"

#include <iostream>
#include <initializer_list>

// Template class vect - vector-like container
template <typename T>
class vect
{
public:
	// No size c-tor
	vect();

 	// List conversive c-tor
	explicit vect(std::initializer_list<T> vals);

	// Specified size c-tor
	explicit vect(size_t size);

	// Copy c-tor
	explicit vect(const vect<T>& other);

	// Move c-tor
	explicit vect(vect<T>&& other);

	// Assignment copy operator
	vect<T>& operator= (const vect<T>& other);

	// Assignment move operator
	vect<T>& operator= (vect<T>&& other);

    // [] operator
	T& operator[](size_t i);

    // [] operator
	const T& operator[](size_t i) const;

    // == operator
	friend bool operator== (const vect<T>& vect1, const vect<T>& vect2)
	{
		if(vect1.size() != vect2.size()) return false;

		for(size_t i = 0; i < vect1.size(); ++i)
		{
			if(vect1[i] != vect2[i]) return false;
		}

		return true;
	}

    // != operator
	friend bool operator!= (const vect<T>& vect1, const vect<T>& vect2)
	{
		return !(vect1 == vect2);
	}

    // [] operator
	T& at(size_t index);
    
    // Insert
	void insert(T val, size_t pos);

    // Push_back
	void push_back(T val);

    // Push_front
	void push_front(T val);

    // Erase
	void erase(size_t pos);

    // Erase
	void clear();

    // Size
	size_t size() const
	{
		return m_count;
	}

 	//iter_v begin();
	iter_v<T> begin(){
		return iter_v::iter_v<T>{m_data};
	}

	//iter_v end();
	iter_v<T> end(){
		return iter_v::iter_v<T>{m_data+m_count};
	}

	// TODO :

	// Why?
	// iter_v<T>::iter_v<T>{...} is obsolete syntax form
	// iter_v<T>::iter_v{...} is recommended but invalid
	// iter_v::iter_v<T>{...} is good

    // D-ctor
	~vect();
	
private:
	// Check allocated memory run out
	void size_check();

	// Resize container with additional size
	void resize(size_t delta);

	T* m_data;
	size_t m_count;
	size_t m_size;
};

// Definitions
#include "vect.ipp"