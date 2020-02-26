// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : MyVector.h

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class MyVector
{
	private:
		T* m_arr;
		int m_size;
		int m_available;
		
	public:
		// The Big 3 //
		MyVector();
		MyVector(const int size);
		MyVector(const std::initializer_list<T> & list);
		MyVector(const MyVector<T> & cpy_vec);
		MyVector<T>& operator=(const MyVector<T> & cpy_vec);
		~MyVector();
		
		// Mutators //
		void push_back(const T & item);
		void resize(const int new_size);
		void resize(const int new_size, const T& filler);
		void clear();
		T& operator[](const int index);
		MyVector<T> operator+(const MyVector & add_vec);
		MyVector<T> operator-(const MyVector & rhs);
		MyVector<T> operator*(const T & rhs);
		MyVector<T> operator-();
		MyVector<T>& operator()(auto 
		
		// Accessors //
		T get(const int index);
		int size() const;
		const T& operator[](const int index) const;
		T operator*(const MyVector<T> & rhs) const;
		
		
		// Friend //
		template <typename U>
		friend ostream& operator << (ostream& out, const MyVector<U>& rhs);
		
	class iterator
    {
	
		private:
			MyVector<T>* m_array;
			unsigned int m_idx;
			
		public:
			iterator(MyVector<T>* a, unsigned int idx): m_array(a), m_idx(idx) {}

			T& operator*() { return (*m_array)[m_idx]; }

			T& operator->() { return (*m_array)[m_idx]; } // for arrays of structs/classes

			iterator& operator++()
			{
			  m_idx++;
			  return *this;
			}

			iterator operator++(int)
			{
			  iterator temp = *this;
			  m_idx++;
			  return temp;
			}

			iterator& operator+=(const unsigned int inc)
			{
			  m_idx += inc;
			  return *this;
			}

			iterator& operator--()
			{
			  m_idx--;
			  return *this;
			}

			iterator operator--(int)
			{
			  iterator temp = *this;
			  m_idx--;
			  return temp;
			}

			iterator& operator-=(const unsigned int dec)
			{
			  m_idx -= dec;
			  return *this;
			}

			friend bool operator==(const iterator& a, const iterator& b)
			{
			  return a.m_array == b.m_array && a.m_idx == b.m_idx;
			}

			friend bool operator!=(const iterator& a, const iterator& b)
			{
			  return !(a == b);
			}
    };

    iterator begin() { return iterator(this, 0); }

    iterator end() { return iterator(this, m_size); }
};

template <typename T>
std::ostream & operator << (ostream & out, const MyVector<T> & rhs);

#include "MyVector.hpp"
#endif