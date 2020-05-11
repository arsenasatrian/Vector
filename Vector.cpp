#include"Vector.h"

template<class T>
MyVector<T>::MyVector()
	: size_(0)
	, capacity_(0)
	, arr_(nullptr) { cout << "default ctor" << endl; }

template<class T>
MyVector<T>::MyVector(unsigned int size)
	: size_(size)
	, capacity_(size)
{
	try {
		arr_ = new T[size];
	}
	catch (const bad_alloc& other) {
		cerr << other.what() << endl;
		exit(0);
	}
	cout << "ctor" << endl;
}

template<class T>
MyVector<T>::MyVector(unsigned int size, const T& value)
	: size_(size)
	, capacity_(size)
{
	try {
		arr_ = new T[size];
	}
	catch (const bad_alloc& other) {
		cerr << other.what() << endl;
		exit(0);
	}
	for (unsigned int i = 0; i < size; ++i) {
		arr_[i] = value;
	}
	cout << "initial ctor" << endl;
}


template<class T>
MyVector<T>::MyVector(const MyVector& other)
	: size_(other.size_)
	, capacity_(other.capacity_)
{
	try {
		arr_ = new T[size];
	}
	catch (const bad_alloc& other) {
		cerr << other.what() << endl;
		exit(0);
	}
	for (unsigned int i = 0; i < size; ++i) {
		arr_[i] = other.arr_[i];
	}
	cout << "copy ctor" << endl;
}

template<class T>
MyVector<T>::MyVector(MyVector&& other) 
	: size_(other.size_)
	, capacity_(other.capacity_)
	, arr_(other.arr_)
{
	other.arr_ = nullptr;
	cout << "move ctor" << endl;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
	if (this == &other) {
		return *this;
	}
	if (size_ != other.size_) {
		delete[] arr_;
		if (other.size_ == 0) {
			size_ = 0;
			capacity_ = 0;
			arr_ = nullptr;
			return *this;
		}
		size_ = other.size_;
		capacity_ = other.capacity_;
		try {
			arr_ = new T[size];
		}
		catch (const bad_alloc& other) {
			cerr << other.what() << endl;
			exit(0);
		}
	}
	for (unsigned int i = 0; i < size_; ++i) {
			arr_[i] = other.arr_[i];
	}
	cout << "copy assignment" << endl;
	return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) {
	if (this == &other) {
		return *this;
	}
	delete[] arr_;
	arr_ = other.arr_;
	other.arr_ = nullptr;
	cout << "move assignment" << endl;
	return *this;
}


template<class T>
MyVector<T>::~MyVector() {
	cout << "dtor" << endl;
	delete[] arr_;
}


template<class T>
void MyVector<T>::pushBack(const T& data) {
	try {
		if (size_ == capacity_) {
			T* temp = new T[2 * capacity_];
			for (int i = 0; i < capacity_; ++i) {
				temp[i] = arr_[i];
			}
			delete[] arr_;
			capacity_ *= 2;
			arr_ = temp;
		}
	}
	catch (const bad_alloc& other) {
		cerr << other.what() << endl;
		exit(0);
	}
	arr_[size_] = data;
	++size_;
}

template<class T>
void MyVector<T>::popBack() {
	if (!empty()) {
		--size_;
	}
}

template<class T>
void MyVector<T> ::insert(const T& data, const unsigned int& index) {
	try {
		if (index > capacity_) {
			throw out_of_range("The index  that you want to use,it out of vector range") ;
		}
	}
	catch (const out_of_range other) {
		cerr << other.what() << endl;
		exit(0);
	}
	if (index == capacity_) {
		pushBack(data);
	}
	else {
		arr_[index] = data;
	}
}

template<class T>
void MyVector<T> ::erase(const unsigned int& index) {
	for (int i = index; i < size_ - 1; ++i) {
		arr_[i] = arr_[i + 1];
	}
	--size_;
}

template<class T>
void MyVector<T>::clear() noexcept {
	if (!empty()) {
		size_ = 0;
		capacity_ = 0;
		arr_ = nullptr;
	}
}

template<class T>
bool MyVector<T>::empty()const noexcept{
	if (arr_ == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void MyVector<T> ::reserve(const unsigned int& capacity) {
	if (arr_ == 0) {
		size_ = 0;
		capacity_ = 0;
	}
	T* newarr;
	try {
		newarr = new T[capacity];
	}
	catch (const bad_alloc& other) {
		cerr << other.what() << endl;
		exit(0);
	}
	
	auto size = capacity > size_ ? size_ : capacity;
	for (int i= 0; i < size; ++i) {
		newarr[i] = arr_[i];
	}
	capacity_ = capacity;
	delete[] arr_;
	arr_ = newarr;
}

template<class T>
void MyVector<T> ::resize(const unsigned int& size) {
	reserve(size);
	size_ = size;
}

template<class T>
T& MyVector<T>::operator[](const unsigned int& index) {
	try {
		if (index > size_ || index < 0) {
			throw out_of_range("out of range");
		}
	}
	catch (const out_of_range& ind){
		cerr << ind.what() << endl;
		exit(0);
		}
	return arr_[index];
}