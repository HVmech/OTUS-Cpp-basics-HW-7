#include <iostream>

// Template class iter_v - iterator-like object for linear arrays
template <typename T>
class iter_v
{
public:
	// C-tor
	explicit iter_v(T* ptr);

	// Copy conversive c-tor
	iter_v (const iter_v<T>& other);

	// Assignment copy operator
	iter_v<T>& operator= (const iter_v<T>& other);

	// Prefix increment operator
	iter_v<T>& operator++ ();

	// Postfix increment operator
	iter_v<T> operator++ (int);

    // Get
	T& get ();

    // * operator
	T& operator* ();

    // + operator
	iter_v<T>& operator+ (size_t i);

    // - operator
	iter_v<T>& operator- (size_t i);

    // == operator
	friend bool operator== (const iter_v<T>& iter1, const iter_v<T>& iter2) {
		return iter1.m_ptr == iter2.m_ptr;
	}

    // != operator
	friend bool operator!= (const iter_v<T>& iter1, const iter_v<T>& iter2) {
		return iter1.m_ptr != iter2.m_ptr;
	}

    // D-ctor
	~iter_v ();
    
private:
	T* m_ptr;
};

// Definitions
#include "iter_v.ipp"