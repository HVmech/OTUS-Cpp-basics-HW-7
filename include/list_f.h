#pragma once

#include <iostream>
#include <initializer_list>

// Include node_fb template class
#include "node_f.hpp"

// Include iter_fb template node_fb based class
#include "iter_f.h"

template <typename T>
class list_f
{
public:
	// No size c-tor
	list_f ();

	// List conversive c-tor
	list_f (std::initializer_list<T> vals);

	// Copy c-tor
	explicit list_f (const list_f<T>& other);

	// Move c-tor
	explicit list_f (list_f<T>&& other);

	// Assignment copy operator
	list_f<T>& operator= (const list_f<T>& other);

	// Assignment move operator
	list_f<T>& operator= (list_f<T>&& other);

    // [] operator
	T& operator[] (size_t i);

    // [] operator const
	const T& operator[] (size_t i) const;

    // == operator
	friend bool operator== (const list_f<T>& list1, const list_f& list2)
	{
		if(list1.size() != list2.size()) return false;

		for(size_t i = 0; i < list1.size(); ++i)
		{
			if(list1[i] != list2[i]) return false;
		}
		
		return true;
	}

    // != operator
	friend bool operator!= (const list_f<T>& list1, const list_f<T>& list2)
	{
		return !(list1 == list2);
	}

	T& at(size_t index);
    
    // Insert
	void insert (T val, size_t pos);

    // Push_back
	void push_back (T val);

    // Push_front
	void push_front (T val);

    // Erase
	void erase(size_t pos);

	// Clear
	void clear();

    // Size
	size_t size() const
	{
		return m_size;
	}

 	//iter begin();
	iter_f<T> begin()
	{
		return iter_f<T>{m_first};
	}

	//iter end();
	iter_f<T> end()
	{
		return iter_f<T>{m_last->next};
	}

    // D-ctor
	~list_f ();
	
private:
	node_f<T>* m_first;
	node_f<T>* m_last;
	size_t m_size;
};

// Iterator definitions
#include "iter_f.ipp"

// List definitions
#include "list_f.ipp"