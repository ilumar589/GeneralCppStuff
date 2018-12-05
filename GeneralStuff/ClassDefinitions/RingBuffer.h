#pragma once

template<class T>
class Ring
{
private:
	int m_Position;
	int m_Size;
	T * m_Value;
public:
	class Iterator;

public:
	Ring(int Size) : m_Position(0), m_Size(Size), m_Value(nullptr)
	{
		m_Value = new T[Size];
	}
	 
	void Add(T Value)
	{
		m_Value[m_Position++] = Value;

		if (m_Position == m_Size)
		{
			m_Position = 0;
		}
	}
	// Can't believe the compiler wants a case sensitive begin function in order to make the class iterable. If you set another standard for naming
	// functions like upper case Begin() wich a lot of cpp libraries use, you can't actually respect that
	Iterator begin()
	{
		return Iterator{ 0, *this };
	}

	Iterator end()
	{
		return Iterator{ m_Size, *this };
	}

	T & Get(int Position)
	{
		return m_Value[Position];
	}

};

template<class T>
class Ring<T>::Iterator
{
private:
	int m_Position;
	Ring & m_Ring;

public:
	Iterator(int Position, Ring & ARing ) : m_Position(Position), m_Ring(ARing) {}

	Iterator &operator++()
	{
		m_Position++;

		return *this;
	}

	Iterator &operator++(int Unused)
	{
		m_Position++;

		return *this;
	}

	T &operator*()
	{
		return m_Ring.Get(m_Position);
	}

	bool operator!=(const Iterator & Other) const
	{
		return m_Position != Other.m_Position;
	}
};
