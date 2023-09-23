// Monodirectional node template class
template <typename T>
struct node_f
{
    explicit node_f(T val) : value{val}, next{nullptr} {}

    node_f(T val, node_f<T>* nxt) : value{val}, next{nxt} {}

	~node_f()
	{
		if(next)
		{
			delete next;
		}
	}
	
	T value;
	node_f<T>* next;
};