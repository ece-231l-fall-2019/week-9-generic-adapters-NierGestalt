#include <iostream>
#include <string>
#include <cstddef>
#include <initializer_list>

template <typename T>

class List
{
	private:
	size_t _size;
	typedef struct llist {
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;
	llist *_data;
	llist *_dataL;


	public:
	
	// default constructor
	List()
	{
	_data = 0;
	_dataL = 0;
	_size = 0;
	}


	// copy constructor
	List(const std::initializer_list<T>& l)
	{
	_data = 0;
	_dataL = 0;
	_size = 0;
	for (auto value : l)
		push_back(value);
	}

	// destructor
	~List()
	{
	while(!empty())
	pop_front();
	}

	// copy operator
		List& operator= (const List& a)
	{
		for (const llist* b = a._data; b != 0; b = b->next)
		{
			push_back(b->value);
		}
		return *this;
	}


	T& front()
	{
	return _data->value;
	}

	const T& front() const
	{
		return _data->value;
	}


	void push_front(T value)
	{
	llist *newItem = new llist;
	newItem->value = value;
	newItem->next = _data;
	newItem->prev = NULL;
	if (_data != NULL)
		_data->prev = newItem;
	if( _dataL == NULL)
		_dataL = newItem;
	_data = newItem;
	_size++;
	}

	void pop_front()
	{
		llist *front = _data;
		if (front)
		{
		_data = front -> next;
		delete front;
		_size--;
		}
	}
	
	bool empty() const
	{
		return size() == 0;
	}
	void clear()
	{
	while( !empty())
        pop_front();
	}
// Back, pop_back
	T& back()
	{
	return _dataL->value;
	}

	void pop_back ()
	{
		if (!empty())
	{
		llist *ptr = _data;
		_data = _data->next;
		if (_data!= NULL)
			_data->prev = _data->prev->prev;
		else
			_dataL = NULL;
		delete ptr;
		_size--;
	}
	}

	const T& back() const
	{
		return _dataL->value;
	}
	void unique()
	{
		for (llist *ptr = _data; ptr != 0; ptr = ptr->next)
	{
		while (ptr -> next != 0 && ptr->value == ptr->next->value)
		{
			llist *savePtr = ptr->next;
			ptr->next = savePtr->next;
			if(savePtr->next != 0)
			savePtr->next->prev = ptr;
			else
				_dataL = ptr;
			delete savePtr;
			_size--;

		}
	}
	}
	size_t size() const
	{
		size_t count = 0;
		if (_data == NULL)
			return count;
		if (_data == _dataL)
		{
			count++;
			return count;
		}
		
		for (llist *temp = _data; temp != NULL;temp= temp->next, count++){}

		return count;
	}
	void push_back(const T value)
	{
	llist *newItem = new llist;
	newItem->value = value;
	newItem->next = 0;
	newItem->prev = _dataL;
	if (_dataL != 0)
		_dataL->next = newItem;
	if (_data == 0)
		_data = newItem;
	_dataL = newItem;
	_size++;
	}
	void reverse()
	{
	if (size() <=1)
		return;
	}

	template <typename V> friend bool operator ==(const List<V>& a, const List<V>& b);

	template <typename V> friend bool operator !=(const List<V>& a, const List<V>& b);

//---------------return function--------------------------------
	/*	StringList::llist *getdata()const
		{
			return _data;
		}
		StringList::llist *getdatal()const
		{
			return _dataL;
	*///	}
};

     template<typename T>
     bool operator == (const List<T>& a, const List<T>& b){
             if (a.size() != b.size())
                     return false;
             auto *aptr = a._data;
             auto *bptr = b._data;

             for ( ; aptr != nullptr && bptr != nullptr; aptr = aptr->next , bptr = bptr -> next)
             {
                     if (aptr -> value != bptr -> value)
                             return false;
             }
             return true;
     }

	template<typename T>
	bool operator != (const List<T>& a, const List<T>& b){
		if (a.size() != b.size())
			return true;

	     auto *aptr = a._data;
             auto *bptr = b._data;

             for ( ; aptr != nullptr && bptr != nullptr; aptr = aptr->next , bptr = bptr -> next)
             {
                     if (aptr -> value != bptr -> value)
                             return true;
	     }
             return false;
     }

