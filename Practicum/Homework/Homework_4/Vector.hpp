#pragma once
#include <iostream>

/*TO DO: 
1) Iterators
2) Move constructor
3) Move assignment operator
4) Allocator
5) Range constructor
6) Initializer list constructor
*/
template <typename T>
class Vector {
public:
	// types:
	using value_type = T;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using size_type = size_t;

	Vector(); // Default constructor
	Vector(const size_type&, const value_type&); // Fill constructor
	Vector(const Vector<value_type>&); // Copy constructor
	Vector(const value_type*, const size_type&);
	~Vector();
	//Vector<value_type>& operator=(const Vector<value_type>&);

	// capacity
	bool empty() const;
	bool contains (const_reference) const;
	size_type getSize() const; 
	size_type getCapacity() const;

	// element access
	reference operator[](const size_type&);
	const_reference operator[](const size_type&) const;
	reference at(const size_type&);
	const_reference at(const size_type&) const;
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	// modifiers
	void push_back(const_reference);
	void pop_back();
	void remove(const size_type&);

	// comparison
	bool operator== (const Vector<value_type> &) const;
	bool operator!= (const Vector<value_type> &) const;
	bool operator< (const Vector<value_type> &) const;
	bool operator<= (const Vector<value_type> &) const;
	bool operator> (const Vector<value_type> &) const;
	bool operator>= (const Vector<value_type> &) const;

	static void swap(Vector<value_type>&, Vector<value_type>&);

	void print() const;

private:
	size_type size;
	size_type capacity;
	value_type* data;

	void erase();
	void increaseCapacity();
	int findIndex(const_reference) const;
	void copy(Vector<value_type>&, const Vector<value_type>&);
	void copyArray(value_type*, const value_type*, const size_type&);
};

// Private

template <typename T>
void Vector<T> :: erase() {
	if (data != nullptr) {
		delete[] this->data;
		this->data = nullptr;
	}	
}

template <typename T>
void Vector<T> :: increaseCapacity() {
	capacity *= 2;
	pointer buffer = nullptr;
	try {
		buffer = new T[capacity];
	}
	catch(const std::exception& e) {
		std::cerr << "Cannot increase the capacity: " << e.what() << '\n';
		return;
	}
	
	copyArray(buffer, this->data, size);
	data = buffer;
}

template <typename T>
void Vector<T> :: copy(Vector<value_type>& destination, const Vector<value_type>& source) {
	pointer buffer = nullptr;
	try {
		buffer = new value_type[source.capacity];
	}
	catch(const std::exception& e) {
		std::cerr << "Cannot copy the object: " << e.what() << '\n';
		return;
	}
	destination.erase();
	copyArray(buffer, source.data, source.size);
	destination.data = buffer;
	destination.size = source.size;
	destination.capacity = source.capacity;
}

template <typename T>
void Vector<T> :: copyArray(value_type* destination, const value_type* source, const size_type& size) {
	for (size_type i = 0; i < size; ++i) {
		destination[i] = source[i];
	}
}

template <typename T>
int Vector<T> :: findIndex(const_reference element) const {
	for (size_type i = 0; i < size; ++i) {
        if (data[i] == element) return i;
    }
    return -1;
}

// Public

template <typename T>
Vector<T> :: Vector () : size{0}, capacity{1}, data{nullptr} {
	try	{
		data = new value_type[capacity];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create default constructor: " << e.what() << '\n';
	}	
}

template <typename T>
Vector<T> :: Vector (const size_t& size, const value_type& value) : size{size}, capacity{size} {
	value_type* buffer = nullptr;
	try {
		buffer = new value_type[capacity];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot create fill constructor: " << e.what() << '\n';
		return;
	}
	
	for (size_type i = 0; i < size; ++i) {
		buffer[i] = value;
	}
	data = buffer;
}

template <typename T>
Vector<T> :: Vector (const Vector<value_type>& other) : data{nullptr} {
	copy(*this, other);
}

template <typename T>
Vector<T> :: Vector (const value_type* array, const size_type& size) : size{size}, capacity{size} {
	pointer buffer = nullptr;
	try {
		buffer = new value_type[capacity];
	}
	catch(const std::exception& e) {
		std::cerr << "Cannot create normal constructor: " << e.what() << '\n';
		return;
	}
	copyArray(buffer, array, size);
	data = buffer;
}

template <typename T>
Vector<T> :: ~Vector () {
	erase();
	capacity = 0;
	size = 0;
}

/*template <typename T>
Vector<typename Vector<T>::value_type>& Vector<T> :: operator=(const Vector<value_type>& rhs) {
	if (this != &rhs) {
		copy(*this, rhs);
	}
	return *this;
}*/

template <typename T>
bool Vector<T> :: empty() const {
	return size == 0;
}

template <typename T>
bool Vector<T> :: contains(const_reference element) const {
	return (findIndex(element) >= 0);
}

template <typename T>
typename Vector<T>::size_type Vector<T>::getSize() const {
	return size;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
typename Vector<T>::reference Vector<T> :: operator[](const size_type& index) {
	return data[index];
}

template <typename T>
typename Vector<T>::const_reference Vector<T> :: operator[] (const size_type& index) const {
	return data[index];
}

template <typename T>
typename Vector<T>::reference Vector<T> :: at(const size_type& position) {
	if (position < size)
		return data[position];
	else
		throw std::out_of_range("accessed position is out of range");
}

template <typename T>
typename Vector<T>::const_reference Vector<T> :: at(const size_type& position) const {
	if (position < size)
		return data[position];
	else
		throw std::out_of_range("accessed position is out of range");
}

template <typename T>
typename Vector<T>::reference Vector<T> :: front() {
	if (size == 0) {
		throw std::out_of_range("accessed position is out of range");
	}
	return data[0];
}

template <typename T>
typename Vector<T>::const_reference Vector<T> :: front() const {
	if (size == 0) {
		throw std::out_of_range("accessed position is out of range");
	}
	return data[0];
}

template <typename T>
typename Vector<T>::reference Vector<T>::back() {
	if (size == 0) {
		throw std::out_of_range("accessed position is out of range");
	}
	return data[size - 1];
}

template <typename T>
typename Vector<T>::const_reference Vector<T> :: back() const {
	if (size == 0) {
		throw std::out_of_range("accessed position is out of range");
	}
	return data[size - 1];
}

template <typename T>
void Vector<T> :: push_back(const_reference element) {
	if (size == capacity) {
		increaseCapacity();
	}
	data[size] = element;
	++size;
}

template <typename T>
void Vector<T> :: pop_back() {
	if (size == 0) {
		std::cerr << "pop_back(): " << "the vector is empty\n";
		return;
	}
	--size;
}

template <typename T>
void Vector<T> :: remove(const size_type& position) {
	if (position > size) {
		throw std::out_of_range("accessed position is out of range");
	} 
	for (size_type i = position; i < size - 1; ++i) {
		data[i] = data[i+1];
	}
	--size;
}

template <typename T>
bool Vector<T> :: operator == (const Vector<value_type> &rhs) const {
	if (size != rhs.size) return false;
	for (size_type i = 0; i < size; ++i)
		if (data[i] != rhs.data[i])
			return false;
	return true;
}

template <typename T>
bool Vector<T> :: operator != (const Vector<value_type> &rhs) const {
	if (size != rhs.size) return true;
	for (size_type i = 0; i < size; ++i)
		if (data[i] != rhs.data[i])
			return true;
	return false;
}

template <typename T>
bool Vector<T> :: operator < (const Vector<value_type> &rhs) const {
	size_type ub = size < rhs.size ? size : rhs.size;
	for (size_type i = 0; i < ub; ++i)
		if (data[i] != rhs.data[i])
			return data[i] < rhs.data[i];
	return size < rhs.size;
}

template <typename T>
bool Vector<T> :: operator <= (const Vector<value_type> &rhs) const {
	size_type ub = size < rhs.size ? size : rhs.size;
	for (size_type i = 0; i < ub; ++i)
		if (data[i] != rhs.data[i])
			return data[i] < rhs.data[i];
	return size <= rhs.size;
}

template <typename T>
bool Vector<T> :: operator > (const Vector<value_type> &rhs) const {
	size_type ub = size < rhs.size ? size : rhs.size;
	for (size_type i = 0; i < ub; ++i)
		if (data[i] != rhs.data[i])
			return data[i] > rhs.data[i];
	return size > rhs.size;
}

template <typename T>
bool Vector<T> :: operator >= (const Vector<value_type> &rhs) const {
	size_type ub = size < rhs.size ? size : rhs.size;
	for (size_type i = 0; i < ub; ++i)
		if (data[i] != rhs.data[i])
			return data[i] > rhs.data[i];
	return size >= rhs.size;
}

template <typename T>
void Vector<T> :: swap (Vector<value_type>& lhs, Vector<value_type>& rhs) {
	Vector<value_type> temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename T>
void Vector<T> :: print() const {
	std::cout << "{";
	for (size_type i = 0; i < size; ++i) {
		if (i == size - 1) {
			std::cout << data[i];
		}
		else {
			std::cout << data[i] << ", ";
		}
	}
	std::cout << "}\n";
}
