#pragma once
#include<ostream>
#include<iostream>;
#include"My_exception.h"
using namespace std;

template<typename T>
class my_queue {

	T* arr_queue;
	int size_arr;


public:

	my_queue(); // Конструктор
	~my_queue(); // Деструктор
	void enque(T x); // Вставляет новый элемент в конец queue.
	T deque(); // Удаляет передний элемент queue и возвращает его.
	T& operator[](size_t index); // Перегрузка оператор взятия элемента по индексу в массиве
	int size();
	void clear();
	
	template<typename Ty>
	friend ostream& operator<<(ostream& ost, const my_queue<Ty>& q);
};

template<class T>
ostream& operator<<(ostream& ost, const my_queue<T>& q) {
	ost << "[";
		for (int i = 0; i <q.size_arr; i++) {
			ost << " " << q.arr_queue[i] << " ";
		}
		ost << "]" << "\n";
		return ost;
}

template<class T>
T& my_queue<T>::operator[](size_t index) {
	return arr_queue[index];
}

template <class T>
my_queue<T>::my_queue() {
	arr_queue = nullptr;
	size_arr = 0;
}

template <class T>
int my_queue<T>::size() {
	return size_arr;
}

template <class T>
void my_queue<T>::enque(T x) {
	if (arr_queue == nullptr) {
		arr_queue = new T;
		arr_queue[0] = x;
		size_arr++;
	}
	else {
		T* tmp = new T[size_arr + 1]; //Выделяю временный массив , чтобы копировать в него основной, на основном масииве
									  //перевыделить память с большим размером, для нового элемента.
		for (int i = 0; i < size_arr; i++) {
			tmp[i] = arr_queue[i];
		}
		//delete arr_queue;
		arr_queue = new T[size_arr + 2];  // + 2 т.к. память на 1 новый элемент + на последнюю ячейку для нуля
		for (int i = 0; i < size_arr; i++) {
			arr_queue[i] = tmp[i];
		}
		arr_queue[size_arr] = x;
		size_arr++;
		delete[] tmp;
	}
}

template <class T>
void my_queue<T>::clear() {
	delete[] arr_queue;
	size_arr = 0;
}

template <class T>
T my_queue<T>::deque() {
	if (size_arr == 0) {
		throw(MyException("Queue is empty\n"));
	}
	T first_element = arr_queue[0];
		T* tmp = new T[size_arr];
	for (int i = 0; i < size_arr-1; i++) {
		tmp[i] = arr_queue[i+1];
	}
	delete[] arr_queue;
	arr_queue = new T[size_arr];
	size_arr--;
	for (int i = 0; i < size_arr; i++) {
		arr_queue[i] = tmp[i];
	}

	return first_element;
}

template <class T>
my_queue<T>::~my_queue() {
	
	delete[] arr_queue;
	
}