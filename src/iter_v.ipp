	// Definitions of members iter_v template class
    
    // Constructors and destructor :
    // C-tor
    template <typename T>
	iter_v<T>::iter_v(T* ptr) : m_ptr{ptr} {}

	// Copy conversive c-tor
    template <typename T>
	iter_v<T>::iter_v(const iter_v<T>& other) : iter_v<T>::iter_v(other.m_ptr) {}

    // D-ctor
    template <typename T>
	iter_v<T>::~iter_v()
	{
		m_ptr = nullptr;
	}

    // Operators :
	// Assignment copy operator
    template <typename T>
	iter_v<T>& iter_v<T>::operator= (const iter_v<T>& other)
	{
		m_ptr = other.m_ptr;

		return *this;
	}

	// Prefix increment operator
    template <typename T>
	iter_v<T>& iter_v<T>::operator++()
	{
		++m_ptr;

		return *this;
	}

	// Postfix increment operator
    template <typename T>
	iter_v<T> iter_v<T>::operator++(int)
	{
		iter_v<T> tmp = *this;
		++(*this);

		return tmp;
	}

    // Dereference operator
    template <typename T>
	T& iter_v<T>::operator* ()
	{
		return *m_ptr;
	}

    // Addition operator
    template <typename T>
	iter_v<T>& iter_v<T>::operator+ (size_t i)
	{
		m_ptr += i;

		return *this;
	}

    // Substraction operator
    template <typename T>
	iter_v<T>& iter_v<T>::operator- (size_t i)
	{
		m_ptr -= i;

		return *this;
	}

    // TODO :

    // Unary equality operator
    // Latest try :
    //template <typename T>
	//bool operator== (const iter_v<T>& iter1, const iter_v<T>& iter2) {
	//	return iter1.m_ptr == iter2.m_ptr;
	//} // Linker error!

    // Unary inequality operator
    // Latest try :
    //template <typename T>
	//bool operator!= (const iter_v<T>& iter1, const iter_v<T>& iter2) {
	//	return iter1.m_ptr != iter2.m_ptr;
	//} // Linker error!

    // Public methods :
    // Get
    template <typename T>
	T& iter_v<T>::get()
	{
		return *m_ptr;
	}

