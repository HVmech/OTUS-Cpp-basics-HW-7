// Bidirectional node template class
template <typename T>
struct node_fb
{
    explicit node_fb(T val) : value{val}, prev{nullptr}, next{nullptr} {}

    node_fb(T val, node_fb<T>* prv) : value{val}, prev{prv}, next{nullptr} {}

    node_fb(T val, node_fb<T>* prv, node_fb<T>* nxt) : value{val}, prev{prv}, next{nxt} {}
	
	~node_fb()
	{
		if(next)
		{
			delete next;
		}

		if(prev)
		{
			prev = nullptr;
		}
	}

	T value;
	node_fb<T>* prev;
	node_fb<T>* next;
};
