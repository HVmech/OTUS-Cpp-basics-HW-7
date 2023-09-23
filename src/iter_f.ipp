// Definitions of members iter_f template class
    
// Constructors and destructor :
// C-tor
template <typename T>
iter_f<T>::iter_f(node_f<T>* ptr) : m_ptr{ptr} {}

// Copy conversive c-tor
template <typename T>
iter_f<T>::iter_f(const iter_f<T>& other) : iter_f<T>::iter_f(other.m_ptr) {}

// D-ctor
template <typename T>
iter_f<T>::~iter_f()
{
	m_ptr = nullptr;
}

// Operators :
// Assignment copy operator
template <typename T>
iter_f<T>& iter_f<T>::operator= (const iter_f<T>& other)
{
	m_ptr = other.m_ptr;

	return *this;
}

// Prefix increment operator
template <typename T>
iter_f<T>& iter_f<T>::operator++()
{
	m_ptr = m_ptr->next;

	return *this;
}

// Postfix increment operator
template <typename T>
iter_f<T> iter_f<T>::operator++(int)
{
	iter_f<T> tmp = *this;
	++(*this);

	return tmp;
}

// Dereference operator
template <typename T>
T& iter_f<T>::operator* ()
{
	return m_ptr->value;
}

// Addition operator
template <typename T>
iter_f<T>& iter_f<T>::operator+ (size_t i)
{
    for (size_t j = 0; j < i; ++j)
	{
        m_ptr = m_ptr->next;
    }

	return *this;
}

// Public methods :
// Get    
template <typename T>
T& iter_f<T>::get()
{
	return m_ptr->value;
}