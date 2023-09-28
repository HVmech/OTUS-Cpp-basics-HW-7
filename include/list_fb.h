#pragma once

#include <iostream>
#include <initializer_list>

// Include node_fb template class
#include "node_fb.hpp"

// Include iter_fb template node_fb based class
#include "iter_fb.h"

template <typename T>
class list_fb
{
public:
	// No size c-tor
	list_fb();

	// List c-tor
	list_fb(std::initializer_list<T> vals);

	// Copy c-tor
	explicit list_fb(const list_fb<T>& other);

	// Move c-tor
	explicit list_fb(list_fb<T>&& other);

	// Assignment copy operator
	list_fb<T>& operator= (const list_fb<T>& other);

	// Assignment move operator
	list_fb<T>& operator= (list_fb<T>&& other);

    // [] operator
	T &operator[](size_t i);

    // [] operator const
	const T &operator[](size_t i) const;

    // == operator
	friend bool operator== (const list_fb<T>& list1, const list_fb& list2)
	{
		if(list1.size() != list2.size()) return false;

		for(size_t i = 0; i < list1.size(); ++i)
		{
			if(list1[i] != list2[i]) return false;
		}
		
		return true;
	}

    // != operator
	friend bool operator!= (const list_fb<T>& list1, const list_fb<T>& list2)
	{
		return !(list1 == list2);
	}

	T& at(size_t index);
    
    // Insert
	void insert(T val, size_t pos);

    // Push_back
	void push_back(T val);

    // Push_front
	void push_front(T val);

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
	iter_fb<T> begin(){
		return iter_fb<T>{m_first};
	}

	//iter end();
	iter_fb<T> end(){
		return iter_fb<T>{m_last->next};
	}

    // D-ctor
	~list_fb();
	
private:
	node_fb<T>* m_first;
	node_fb<T>* m_last;
	size_t m_size;
};

// Iterator definitions
#include "iter_fb.ipp"

// List definitions
#include "list_fb.ipp"