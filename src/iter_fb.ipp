// Definitions of members iter_fb template class
    
// Constructors and destructor :
// C-tor
template <typename T>
iter_fb<T>::iter_fb(node_fb<T>* ptr) : m_ptr{ptr} {}

// Copy conversive c-tor
template <typename T>
iter_fb<T>::iter_fb(const iter_fb<T>& other) : iter_fb<T>::iter_fb(other.m_ptr) {}

// D-ctor
template <typename T>
iter_fb<T>::~iter_fb()
{
	m_ptr = nullptr;
}

// Operators :
// Assignment copy operator
template <typename T>
iter_fb<T>& iter_fb<T>::operator= (const iter_fb<T>& other)
{
	m_ptr = other.m_ptr;

	return *this;
}

// Prefix increment operator
template <typename T>
iter_fb<T>& iter_fb<T>::operator++()
{
	m_ptr = m_ptr->next;

	return *this;
}

// Postfix increment operator
template <typename T>
iter_fb<T> iter_fb<T>::operator++(int)
{
	iter_fb<T> tmp = *this;
	++(*this);

	return tmp;
}

// Dereference operator
template <typename T>
T& iter_fb<T>::operator* ()
{
	return m_ptr->value;
}

// Addition operator
template <typename T>
iter_fb<T>& iter_fb<T>::operator+ (size_t i)
{
    for (size_t j = 0; j < i; ++j)
	{
        m_ptr = m_ptr->next;
    }

	return *this;
}

// Substraction operator
template <typename T>
iter_fb<T>& iter_fb<T>::operator- (size_t i)
{
    for (size_t j = 0; j < i; ++j)
	{
        m_ptr = m_ptr->prev;
    }

	return *this;
}

// Public methods :
// Get    
template <typename T>
T& iter_fb<T>::get()
{
	return m_ptr->value;
}