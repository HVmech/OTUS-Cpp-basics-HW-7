// Bidirectional node template class
template <typename T>
struct node_fb
{
    explicit node_fb(T val) : prev{nullptr}, next{nullptr}, value{val} {}

    node_fb(T val, node_fb<T>* prv) : prev{prv}, next{nullptr}, value{val} {}

    node_fb(T val, node_fb<T>* prv, node_fb<T>* nxt) : prev{prv}, next{nxt}, value{val} {}
	
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