#include <iostream>
#include <iterator>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template <class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template <class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template <class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template <class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};

template <class T>
T Search_End(T* begin, T* end, T* elem)
{
	for (T* from = begin; from < end; from++) 
	{ 
		if (from == end - 1)
		{
			elem = from;
		}
	}
	return *elem;
}

template <class T>
T Search_End_If(T* begin, T* end, T* elem, Predicate<T>& p)
{
	for (T* from = begin; from < end; from++)
	{
		if (p(*from))
			elem = from;
	}
	return *elem;
}

int main()
{
	int a[10] = { 3, -2, 0, 4, -5, -2, 3, 8, -2, -5 };

	cout << "a = { ";
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' '; 
	cout << "}" << endl;

	cout << "Last element: " << Search_End(&a[0], &a[10], &a[0]) << endl;

	Predicate<int>* neg = new Negative<int>(); 
	cout << "Last negative element: " << Search_End_If(&a[0], &a[10], &a[0], *neg) << endl;

	Predicate<int>* pos = new Positive<int>();
	cout << "Last positive element: " << Search_End_If(&a[0], &a[10], &a[0], *pos) << endl;

	Predicate<int>* odd = new Odd<int>();
	cout << "Last odd element: " << Search_End_If(&a[0], &a[10], &a[0], *odd) << endl;

	Predicate<int>* even = new Even<int>();
	cout << "Last even element: " << Search_End_If(&a[0], &a[10], &a[0], *even) << endl;
}