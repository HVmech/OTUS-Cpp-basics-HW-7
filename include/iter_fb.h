#pragma once

#include <iostream>

// Template class iter_fb - iterator-like object for node-based biderectional arrays
template <typename T>
class iter_fb
{
public:
	// C-tor
	explicit iter_fb(node_fb<T>* ptr);

	// Copy conversive c-tor
	iter_fb (const iter_fb<T>& other);

	// Assignment copy operator
	iter_fb<T>& operator= (const iter_fb<T>& other);

	// Prefix increment operator
	iter_fb<T>& operator++ ();

	// Postfix increment operator
	iter_fb<T> operator++ (int);

    // Get
	T& get ();

    // * operator
	T& operator* ();

    // + operator
	iter_fb<T>& operator+ (size_t i);

    // - operator
	iter_fb<T>& operator- (size_t i);

    // == operator
	friend bool operator== (const iter_fb<T>& iter1, const iter_fb<T>& iter2)
	{
		return iter1.m_ptr == iter2.m_ptr;
	}

    // != operator
	friend bool operator!= (const iter_fb<T>& iter1, const iter_fb<T>& iter2)
	{
		return iter1.m_ptr != iter2.m_ptr;
	}

    // D-ctor
	~iter_fb ();
    
private:
	node_fb<T>* m_ptr;
};