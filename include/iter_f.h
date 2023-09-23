#pragma once

#include <iostream>

// Template class iter_f - iterator-like object for node-based biderectional arrays
template <typename T>
class iter_f
{
public:
	// C-tor
	explicit iter_f(node_f<T>* ptr);

	// Copy conversive c-tor
	iter_f (const iter_f<T>& other);

	// Assignment copy operator
	iter_f<T>& operator= (const iter_f<T>& other);

	// Prefix increment operator
	iter_f<T>& operator++ ();

	// Postfix increment operator
	iter_f<T> operator++ (int);

    // Get
	T& get ();

    // * operator
	T& operator* ();

    // + operator (only)
	iter_f<T>& operator+ (size_t i);

    // == operator
	friend bool operator== (const iter_f<T>& iter1, const iter_f<T>& iter2)
	{
		return iter1.m_ptr == iter2.m_ptr;
	}

    // != operator
	friend bool operator!= (const iter_f<T>& iter1, const iter_f<T>& iter2)
	{
		return iter1.m_ptr != iter2.m_ptr;
	}

    // D-ctor
	~iter_f ();
    
private:
	node_f<T>* m_ptr;
};