#include <initializer_list>

template<typename T>
class Stack
{
	protected:
		List<T> c;
	public:

	//constructor
	Stack(const std::initializer_list<T> l) : c(l)
	{}
	//top n top const
       	T& top()
        {
                return c.back();
        }

	const T& top() const
	{
		return c.back();
	}

	//push n pop adds value to end and pops end value
	void push(const T& value)
	{
		c.push_back(value);
	}

	void pop()
	{
		c.pop_back();
	}

	//size n empty n = operator
	size_t size() const
	{
		return c.size();
	}

	bool empty() const
	{
		return c.empty();
	}

	Stack<T>& operator=(const Stack<T>& a)
	{
	     c = a.c;
	     return *this;
	}

	// friend operator == n =!
     template <typename V>
     friend bool operator==(const Stack<V>& a, const Stack<V>& b);
     template <typename V>
     friend bool operator!=(const Stack<V>& a, const Stack<V>& b);


};

	// == n =! method
	template <typename T>
	inline bool operator==(const Stack<T>& a, const Stack<T>& b)
		{
			return a.c == b.c;
		}
	template <typename T>
	inline bool operator!=(const Stack<T>& a, const Stack<T>& b)
		{
			return a.c != b.c;
		}
