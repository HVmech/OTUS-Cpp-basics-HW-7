// Definitions of members list_f template class - monodirectional list container

// Constructors and destructor :
// No size c-tor
template<typename T>
list_f<T>::list_f() : m_first{nullptr}, m_last{nullptr}, m_size{0} {}

// List conversive c-tor
template<typename T>
list_f<T>::list_f(std::initializer_list<T> vals) : list_f()
{
    const T* vptr = std::data(vals);

    node_f<T>* tmp;

    if (vals.size() > 0)
	{
        tmp = new node_f<T>{vptr[0]};

        m_first = tmp;
        m_last = tmp;

		++m_size;

		for(size_t i = 1; i < vals.size(); ++i)
		{
			tmp = new node_f<T>{vptr[i]};

			m_last->next = tmp;
			m_last = tmp;

			++m_size;
		}
	}
}

// Copy c-tor
template<typename T>
list_f<T>::list_f(const list_f<T>& other) : list_f()
{
	if (other.m_size > 0)
	{
		node_f<T>* tmp = other.m_first;

		m_first = new node_f<T>{tmp->value};

		m_last = m_first;

		for (size_t i = 1; i < other.m_size; ++i)
		{
			tmp = tmp->next;

			m_last->next = new node_f<T>{tmp->value};
			m_last = m_last->next;
		}

		m_size = other.m_size;
	}
}

// Move c-tor
template<typename T>
list_f<T>::list_f(list_f<T>&& other)
{
    m_first = other.m_first;
    m_last = other.m_last;
    m_size = other.m_size;

    other.m_first = nullptr;
    other.m_last = nullptr;
    other.m_size = 0;
}

// D-ctor
template<typename T>
list_f<T>::~list_f ()
{
	delete m_first;
}

// Operators :
// Assignment copy operator
template<typename T>
list_f<T>& list_f<T>::operator= (const list_f<T>& other)
{
	if (other.m_size)
	{
		if (m_size > other.m_size) 
		{
			node_f<T>* cur1 = m_first;
			node_f<T>* cur2 = other.m_first;

			while (cur2)
			{
				cur1->value = cur2->value;
				cur2 = cur2->next;

				if (cur2)
				{
					cur1 = cur1->next;
				}
				else
				{
					break;
				}
			}

			cur2 = cur1->next;
			cur1->next = nullptr;

			m_last = cur1;
			m_size = other.m_size;

			delete cur2;
		}
		else
		{
			node_f<T>* cur1 = m_first;
			node_f<T>* cur2 = other.m_first;

			if (m_size)
			{
				while (cur1)
				{
					cur1->value = cur2->value;
					cur2 = cur2->next;

					if (cur1->next)
					{
						cur1 = cur1->next;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				m_first = new node_f<T>{cur2->value};

				cur1 = m_first;
				cur2 = cur2->next;
			}
			while (cur2)
			{
				cur1->next = new node_f<T>{cur2->value};
				cur1 = cur1->next;
				cur2 = cur2->next;
			}

			m_last = cur1;
			m_size = other.m_size;
		}
	}
	else
	{
		node_f<T>* tmp = m_first;

		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;

		delete tmp;
	}

    return *this;
}

// Assignment move operator
template<typename T>
list_f<T>& list_f<T>::operator= (list_f<T>&& other)
{
	list_f<T> tmp {std::move(other)};

	return *this = tmp;
}

// [] operator
template<typename T>
	T& list_f<T>::operator[] (size_t i)
	{
	node_f<T>* cur = m_first;

	for(size_t j = 0; j < i; ++j)
	{
		cur = cur->next;
	}

	return cur->value;
}

// [] operator const
template<typename T>
	const T& list_f<T>::operator[] (size_t i) const
	{
	node_f<T>* cur = m_first;

	for(size_t j = 0; j < i; ++j)
	{
		cur = cur->next;
	}

	return cur->value;
}

// Public methods :
// At with boundary checking
template<typename T>
T& list_f<T>::at(size_t index)
{
	if(index < m_size)
	{
		return this->operator[](index);
	}
	else
	{
		// Out of range
		return this->operator[](0);
	}
}

// Insert
template<typename T>
void list_f<T>::insert(T val, size_t pos)
{
	switch(pos)
	{
		case 1:
			if(m_size < 1)
			{
                m_first = new node_f<T>{val};

				m_last = m_first;
			}
			else
			{
                m_first = new node_f<T>{val, m_first};
			}
		break;

		default:
			if (pos == m_size + 1)
			{
				m_last->next = new node_f<T>{val};
				m_last = m_last->next;
			}
			else
			{
				if (pos > 1 && pos < m_size + 1)
				{
					node_f<T>* cur = m_first;

					for(size_t i = 1; i < pos; ++i)
					{
						cur = cur->next;
					}

					cur->next = new node_f<T>{cur->value, cur->next};
					cur->value = val;
					m_last = cur->next;
				}
				else
				{
					std::cout << "Error!";
					return;
				}
			}

		break;
	}

	++m_size;
}

// Push_back
template<typename T>
void list_f<T>::push_back(T val)
{
	insert(val, m_size+1);
}

// Push_front
template<typename T>
void list_f<T>::push_front(T val)
{
	insert(val, 1);
}

// Erase
template<typename T>
void list_f<T>::erase(size_t pos)
{
	node_f<T>* cur1 = m_first;

	switch(pos)
	{
		case 1:
			if(m_size > 1)
			{
				m_first = m_first->next;
				cur1->next = nullptr;
			}
			else
			{
				m_first = nullptr;
				m_last = nullptr;
			}

			delete cur1;
		break;

		default:
			for(size_t i = 1; i < pos-1; ++i)
			{
				cur1 = cur1->next;
			}

			node_f<T>* cur2 = cur1->next;
			cur1->next = cur2->next;
			cur2->next = nullptr;

			delete cur2;

			if (pos == m_size) m_last = cur1;
		break;
	}

	m_size--;
}

template<typename T>
void list_f<T>::clear()
{
	if(size())
	{
		node_f<T>* temp = m_first;

		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;

		delete temp;
	}
}