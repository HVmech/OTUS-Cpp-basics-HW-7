// Definitions of members list_fb template class - bidirectional list container

// Constructors and destructor :
// No size c-tor
template<typename T>
list_fb<T>::list_fb() : m_first{nullptr}, m_last{nullptr}, m_size{0} {}

// List c-tor
template<typename T>
list_fb<T>::list_fb(std::initializer_list<T> vals) : list_fb()
{
    const T* vptr = std::data(vals);

    node_fb<T>* tmp;

    for(size_t i = 0; i < vals.size(); ++i)
	{
        if (m_last)
		{
            tmp = new node_fb<T>{vptr[i], m_last};

            m_last->next = tmp;
            m_last = tmp;
        }
        else
		{
            tmp = new node_fb<T> {vptr[i]};

            m_first = tmp;
            m_last = tmp;
        }

        ++m_size;
    }
}

// Copy c-tor
template<typename T>
list_fb<T>::list_fb(const list_fb<T>& other) : list_fb()
{
    node_fb<T>* cur = other.m_first;

    for (size_t i = 0; i < other.m_size; ++i)
	{
        push_back(cur->value);

        cur = cur->next;
    }
}

// Move c-tor
template<typename T>
list_fb<T>::list_fb(list_fb<T>&& other)
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
list_fb<T>::~list_fb()
{
	delete m_first;
}

// Operators :
// Assignment copy operator
template<typename T>
list_fb<T>& list_fb<T>::operator= (const list_fb<T>& other)
{
    if (m_size > other.m_size)
	{
        node_fb<T>* cur1 = m_first;
        node_fb<T>* othr = other.m_first;

        for (size_t i = 0; i < other.m_size; ++i)
		{
            cur1->value = othr->value;
            othr = othr->next;
            cur1 = cur1->next;
        }

        node_fb<T>* cur2 = cur1->prev;
        cur2->next = nullptr;

        m_last = cur2;
        m_size = other.m_size;
        delete cur1;
    }
    else
	{
        node_fb<T>* cur = m_first;
        node_fb<T>* othr = other.m_first;

        for (size_t i = 0; i < other.m_size; ++i)
		{
            if (i < m_size)
			{
                cur->value = othr->value;
                othr = othr->next;
                cur = cur->next;
            }
            else
			{
                push_back(othr->value);

                othr = othr->next;
            }
        }
    }

    return *this;
}

// Assignment move operator
template<typename T>
list_fb<T>& list_fb<T>::operator= (list_fb<T>&& other)
{
    list_fb<T> tmp {std::move(other)};

    return *this = tmp;
}

// [] operator
template<typename T>
T& list_fb<T>::operator[](size_t i)
{
	node_fb<T>* cur = m_first;

	for(size_t j = 0; j < i; ++j)
	{
		cur = cur->next;
	}

	return cur->value;
}

// [] operator const
template<typename T>
const T& list_fb<T>::operator[](size_t i) const
{
	node_fb<T>* cur = m_first;

	for(size_t j = 0; j < i; ++j)
	{
		cur = cur->next;
	}

	return cur->value;
}

// Public methods :
// At with boundary checking
template<typename T>
T& list_fb<T>::at(size_t index)
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
void list_fb<T>::insert(T val, size_t pos)
{
	switch(pos)
	{
		case 1:
			if(m_size > 0)
			{
                node_fb<T>* new_node = new node_fb<T>{val, nullptr, m_first};

				m_first->prev = new_node;
				m_first = new_node;
			}
			else
			{
                node_fb<T>* new_node = new node_fb<T>{val};

				m_first = new_node;
				m_last = new_node;
			}
		break;

		default:
			if(pos == m_size + 1)
			{
                node_fb<T>* new_node = new node_fb<T>{val, m_last};

				m_last->next = new_node;
				m_last = new_node;
			}
			else
			{
				node_fb<T>* cur1 = m_first;

				for(size_t i = 1; i < pos-1; ++i)
				{
					cur1 = cur1->next;
				}

                node_fb<T>* new_node = new node_fb<T>{val, cur1, cur1->next};

				cur1->next = new_node;
                cur1 = new_node->next;
                cur1->prev = new_node;
			}
		break;
	}

	m_size++;
}

// Push_back
template<typename T>
void list_fb<T>::push_back(T val)
{
	insert(val, m_size+1);
}

// Push_front
template<typename T>
void list_fb<T>::push_front(T val)
{
	insert(val, 1);
}

// Erase
template<typename T>
void list_fb<T>::erase(size_t pos)
{
	node_fb<T>* cur1 = m_first;

	switch(pos)
	{
		case 1:
			if(m_size > 1)
			{
				m_first = cur1->next;
				m_first->prev = nullptr;
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

			node_fb<T>* cur2 = cur1->next;

			if(pos == m_size)
			{
				cur1->next = nullptr;
				cur2->prev = nullptr;
				m_last = cur1;
				delete cur2;
			}
			else
			{
				cur2 = cur2->next;
				cur1->next = cur2;
				cur1 = cur2->prev;
				cur2->prev = cur1->prev;
				cur1->next = nullptr;
				cur1->prev = nullptr;
				delete cur1;
			}
		break;
	}
	
	m_size--;
}

template<typename T>
void list_fb<T>::clear()
{
	if(size())
	{
		node_fb<T>* temp = m_first;

		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;
		
		delete temp;
	}
}