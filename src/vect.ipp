// Definitions of members vect template class - vector-like container

// Constructors and destructor :
// No size c-tor
template<typename T>
vect<T>::vect() : m_data{nullptr}, m_count{0}, m_size{10}
{
	m_data = new T[m_size];
}

// Specified size c-tor
template<typename T>
vect<T>::vect(size_t size) : m_data{nullptr}, m_count{0}, m_size{size}
{
	m_data = new T[m_size];
}

// List conversive c-tor
template <typename T>
vect<T>::vect(std::initializer_list<T> vals) : m_count{vals.size()}, m_size{vals.size()}
{
	const T* vptr = std::data(vals);

	m_data = new T[m_size];

	for(size_t i = 0; i < vals.size(); ++i)
	{
		m_data[i] = vptr[i];
	}
}

// Copy c-tor
template<typename T>
vect<T>::vect(const vect<T>& other) : vect<T>::vect(other.m_size)
{
	m_count = other.m_count;

	for(size_t i = 0; i < m_count; ++i)
	{
		m_data[i] = other.m_data[i];
	}
}

// Move c-tor
template<typename T>
vect<T>::vect(vect<T>&& other)
{
	m_data = other.m_data;
	m_size = other.m_size;
	m_count = other.m_count;

	other.m_data = nullptr;
	other.m_count = 0;
	other.m_size = 0;
}

// D-ctor
template<typename T>
vect<T>::~vect()
{
	delete[] m_data;
}

// Operators :
// Assignment copy operator
template<typename T>
vect<T>& vect<T>::operator= (const vect<T>& other)
{
	if (m_size < other.m_size)
	{
		resize(other.m_size);
	}

	m_count = other.m_count;

	for(size_t i = 0; i < m_count; ++i)
	{
		m_data[i] = other.m_data[i];
	}

	return *this;
}

// Assignment move operator
template<typename T>
vect<T>& vect<T>::operator= (vect<T>&& other)
{
	vect<T> tmp {std::move(other)};

	return *this = tmp;
}

// [] operator
template<typename T>
T& vect<T>::operator[](size_t i)
{
	return m_data[i];
}

// [] operator
template<typename T>
const T& vect<T>::operator[](size_t i) const
{
	return m_data[i];
}

// Public methods :
// At with boundary checking
template<typename T>
T& vect<T>::at(size_t index)
{
	if(index < m_count)
	{
		return m_data[index];
	}
	else
	{
		// Out of range
		return m_data[0];
	}
}

// Insert
template<typename T>
void vect<T>::insert(T val, size_t pos)
{
	size_check();

	for(size_t i = m_count; i > pos-1; --i)
	{
		m_data[i] = m_data[i-1];
	}

	m_data[pos-1] = val;
	m_count++;
}

// Push_back
template<typename T>
void vect<T>::push_back(T val)
{
	vect<T>::size_check();

	vect<T>::insert(val, size()+1);		
}

// Push_front
template<typename T>
void vect<T>::push_front(T val)
{
	vect<T>::size_check();

	vect<T>::insert(val, 1);
}

// Erase
template<typename T>
void vect<T>::erase(size_t pos)
{
	for(size_t i = pos-1; i < m_count; ++i)
	{
		m_data[i] = m_data[i+1];
	}

	m_count--;
}

// Clear
template<typename T>
void vect<T>::clear()
{
	if (m_count)
	{
		m_count = 0;
	}
}

// Private section :
// Size_check
template<typename T>
void vect<T>::size_check()
{
	if (m_count == m_size)
	{
		(m_size/2 < 10) ? vect<T>::resize(10) : vect<T>::resize(m_size/2);
	}
}

// Resize
template<typename T>
void vect<T>::resize(size_t delta)
{
	T* new_data = new T[m_size + delta];

	for(size_t i = 0; i < m_size; ++i)
	{
		new_data[i] = m_data[i];
	}

	delete[] m_data;
	m_data = new_data;
	m_size += delta;
}