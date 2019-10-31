#include <initializer_list>
#include "G_List.h"
#include <cstddef>
template<typename T>


class Queue
{
	protected:
		List<T> c;

	public:
	//constructor
	Queue (const std::initializer_list<T> l) : c(l)
	{}

	//front n back n const ver
	T& front()
	{
		return c.front();
	}


	T& back()
	{
		return c.back();
	}


	const T& front() const
	{
		return c.front();
	}

	const T& back() const
	{
		return c.back();
	}

	//push which is pop front in a queue
	void push(const T& value)
	{
		c.pop_front();
	}

	bool empty() const 
	{
		return c.empty();
	}

	//operator
     	Queue<T>& operator=(const Queue<T>& other)
	{
		c = other.c;
		return *this;
	}
	//allows us to define operators == n =! as friend
	template <typename V>
	friend bool operator==(const Queue<V>& a, const Queue<V>& b);

	template <typename V>
	friend bool operator!=(const Queue<V>& a, const Queue<V>& b);
};
//== != methods
template <typename T>
inline bool operator==(const Queue<T>& a, const Queue<T>& b)
{
	return a.c == b.c;
}

template <typename T>
inline bool operator!=(const Queue<T>& a, const Queue<T>& b)
{
	return a.c != b.c;
}
