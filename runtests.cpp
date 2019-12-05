#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "G_List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#include "Queue.h"
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write more tests to fully test your classes.

	StringList a;
	StringList b;

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;
	Assert (a == b, "b is a = test");
	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	// TODO: check all methods on StringList...

	StringStack c{};
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "B is not empty");
	c.pop();
	Assert(c.empty() == true, "B is empty");
	//own tests
	StringStack e{};
	e.push("A");
	e.push("B");
	StringStack d{};
	d.push("A");
	d.push("B");
	Assert(d == e, "Stack d is equal to stack e == test");
	d.pop();
	Assert(d != c, "Stack d and e are no longer equal =!");
	e = d;
	d = e;
	Assert (e == d, "Stack e and d are equal = test");

	// TODO: check all methods on StringStack...

	IntList ia;
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");
	//own tests
	IntList red { };
        IntList blu { };
        red.push_front(9);
        Assert(red.front() == 9, "front is 9 push test");
        red.push_front(6);
        Assert(red.front() == 6, "front is 6 push test");
        red.pop_front();
        Assert(red.front() == 9, "front is 9 pop test");
        red.push_front(8);
        Assert(red.front() == 8, "front is 8");
	Assert(blu != red, "blue doesn't equal red != test");

	// TODO: check all methods on IntList...

	IntStack ic{};
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top is 5");
	//own tests
	IntStack test {};
	test.push(10);
        Assert(test.top() == 10, "front is 10 push test");
        test.push(40);
        Assert(test.top() == 40, "front is 40 push test");
        test.pop();
        Assert(test.top() == 40, "front is 40 pop test");
        test.push(50);
        Assert(test.top() == 50, "front is 50 push test");

	Assert(test != ic, "=! test");

	// TODO: check all methods on IntStack...

	return 0;
}


