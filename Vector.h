#include<iostream>
#include<exception>
using namespace std;

#pragma once

template<class T>
class MyVector {
public:
	MyVector();
	MyVector(unsigned int size);
	MyVector(unsigned int size, const T& value);
	MyVector(const MyVector&);//copy ctor
	MyVector(MyVector&&);//move ctor
	MyVector& operator=(const MyVector&);//copy assignment
	MyVector& operator=(MyVector&&);//move assignment
	~MyVector();
	

	void pushBack(const T& data);
	void popBack();
	void insert(const T& data, const unsigned int& index);
	void erase(const unsigned int& index);
	void clear() noexcept;
	bool empty()const noexcept;
	auto size() const noexcept { return size_; }
	auto capacity()const noexcept { return capacity_; }
	void reserve(const unsigned int& capacity);
	void resize(const unsigned int& size);
	auto being() { return arr_; }
	auto end() { return arr_ + size(); }
	T& operator[](const unsigned int& index) ;
	T front() { return arr_[0]; }
	T back() { return arr_[size_ - 1]; }
	
private:
	unsigned int size_;
	unsigned int capacity_;
	T* arr_;
 };