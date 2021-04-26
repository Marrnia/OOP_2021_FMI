#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <ctime>

namespace my
{
    template <class T>
    class vector
    {
		typedef T& reference;

        T *data;
        size_t currentSize;
        size_t capacity;

        void erase();
        void reserve();
        void resize();
        void create(const vector<T>&);
        void copy(const vector<T>&);

    public:

    	// Constructors
        vector();
        vector(const size_t&);
        vector(const size_t&, const T&);
        vector(const vector<T>&);
        ~vector();

        //Operators
        vector<T>& operator=(const vector<T>&);

        const reference operator[](const size_t& index) const{
			if (index < 0 || index >= currentSize) {
				throw std::out_of_range("position is out of range");
			}
			return data[index];
		}

        reference operator[](const size_t& index) {
			if (index < 0 || index >= currentSize) {
				throw std::out_of_range("position is out of range");
			}
		return data[index];
	}

        //Encapsulation
        size_t size() const;
        size_t getCapacity() const;

        //Vector
        bool empty() const;
        T& front();
        T& back();
        void push_back(const T&);
		void push_front(const T&);
        void pop_back();
		bool find_element(const T&);
		void shuffle();

        //Print
        void print();
    };

    //Private

    template <typename T>
	void vector<T> :: erase() {
		delete[] data;
		data = nullptr;
	}

	template <typename T>
	void vector<T> :: reserve() {
		T* newBuffer = new T[capacity];

		for (size_t i = 0; i < currentSize; ++i) {
			newBuffer[i] = data[i];
		}

		T temp;
		for (size_t i = currentSize; i < capacity; ++i) {
			newBuffer[i] = temp;
		}

		erase();
		data = newBuffer;
	}

	template <typename T>
	void vector<T> :: resize() {
		capacity *= 2;
		reserve();
	}

	template <typename T>
	void vector<T> :: create(const vector<T>& rhs) {
		data = new T[rhs.capacity];
		for (size_t i = 0; i < rhs.size; ++i) {
			data[i] = rhs.data[i];
		}
	}

	template <typename T>
	void vector<T> :: copy(const vector<T>& rhs) {
		currentSize = rhs.currentSize;
		capacity = rhs.capacity;
		data = new T[capacity];
		for (size_t i = 0; i < currentSize; ++i) {
			data[i] = rhs.data[i];
		}
	}

	//Public

	//Constructors

	template <typename T>
	vector<T> :: vector() :
	currentSize{0},
	capacity{1} 
	{
		T temp;
		data = new T[capacity];
		data[0] = temp;
	}

	template <typename T>
	vector<T> :: vector(const size_t& size) {
		currentSize = size;
		capacity = 2 * size;
		data = new T[capacity];
	}

	template <typename T>
	vector<T> :: vector(const size_t& size, const T& init_value) :
	currentSize{size}, capacity{size*2} {
		data = new T[capacity];
		for (size_t i = 0; i < currentSize; ++i) {
			data[i] = init_value;
		}
	}

	template <typename T>
	vector<T> :: vector(const vector<T>& rhs) :
	currentSize{rhs.size},
	capacity{rhs.capacity} {
		create(rhs);
	}

	template <typename T>
	vector<T> :: ~vector() {
		erase();
		currentSize = 0;
		capacity = 0;
	}

	//Operators

	template <typename T>
	vector<T>& vector<T> :: operator=(const vector<T>& rhs) {
		if (this != &rhs) {
			erase();
			data = new T[rhs.currentSize];
			copy(rhs);
		}
		return *this;
	}

	//Encapsulation 

	template <typename T>
	size_t vector<T> :: size() const {
		return currentSize;
	}

	template <typename T>
	size_t vector<T> :: getCapacity() const {
		return capacity;
	}

	//Vector
	template <typename T>
	bool vector<T> :: empty() const {
		return currentSize == 0;
	}

	template <typename T>
    T& vector<T> :: front() {
    	return data[0];
    }

    template <typename T>
    T& vector<T> :: back() {
    	return data[currentSize-1];
    }
    
    template <typename T>
    void vector<T> :: push_back(const T& value) {
    	if (currentSize >= capacity) {
    		resize();
    	}
    	data[currentSize] = value;
    	++currentSize;
    }

	template <typename T>
	void vector<T> :: push_front(const T& value) {
		if (currentSize >= capacity) {
			resize();
		}
		for (size_t i = currentSize; i >= 1; --i) {
			data[i] = data[i-1];
		}
		data[0] = value;
		++currentSize;
	}
    
    template <typename T>
    void vector<T> :: pop_back() {
    	if (currentSize > 0) {
    		--currentSize;
    	}
    	else {
    		std::cerr << "Empty vector.\n";
    		return;
    	}
    }

	template <typename T>
    bool vector<T> :: find_element(const T& element) {
    	for (size_t i = 0; i < currentSize; ++i) {
    		if (data[i] == element) {
    			return true;
    		}
    	}
    	return false;
    }

	template <typename T>
	void vector<T> :: shuffle() {
		std::srand(time(NULL));
		std::random_shuffle(&data[0], &data[currentSize]);
	}

	//Print

	template <typename T>
	void vector<T> :: print() {
		for (size_t i = 0 ; i < currentSize; ++i) {
			std::cout << data[i];
		}
	} 
} // namespace my
#endif