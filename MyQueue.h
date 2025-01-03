#pragma once
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <memory>


template <typename T>
class MyQueue {
	private:
		struct Node {
			T data;
			Node* next;
			Node(const T& value) : data(value), next(nullptr) {}
		};

		Node* front;
		Node* back;
		std::size_t size;

		void ensureNotEmpty() const {
			if (isEmpty()) {
				throw std::out_of_range("Queue is empty!");
			}
		}
	
	public:
		MyQueue() : front(nullptr), back(nullptr), size(0) {}

		MyQueue(const MyQueue& queue) : front(nullptr), back(nullptr), size(0) {
			for (Node* curr = queue.front; curr; curr = curr->next) {
				push(curr->data);
			}
		}

		~MyQueue() {
			while (front) {
				pop();
			}
		}

		MyQueue& operator=(const MyQueue& queue) {
			if (this != &queue) {
				MyQueue temp(queue);
				std::swap(front, temp.front);
				std::swap(back, temp.back);
				std::swap(size, temp.size);
			}

			return *this;
		}

		void push(const T& item) {
			try {
				auto newNode = std::make_unique<Node>(item);
				if (back) {
					back->next = newNode.get();
				}
			
				back = newNode.release();
				if (!front) {
					front = back;
				}

				++size;
			}
			catch (...) {
				throw std::runtime_error("Bad alloc error while pushing!");
			}
		}

		const T& getFront() const {
			ensureNotEmpty();
			return front->data;
		}

		const T& getBack() const {
			ensureNotEmpty();
			return back->data;
		}

		T& getFront() {
			ensureNotEmpty();
			return front->data;
		}

		T& getBack() {
			ensureNotEmpty();
			return back->data;
		}

		void pop() {
			if (isEmpty()) {
				throw std::out_of_range("Queue is empty!");
			}

			Node* temp = front;
			front = front->next;
			delete temp;
			if(!front) {
				back = nullptr;
			}

			--size;
		}

		bool isEmpty() const {
			return size == 0;
		}

		size_t getSize() const {
			return size;
		}

		class Iterator {
			private:
				Node* current;

			public: 
				explicit Iterator(Node* start) : current(start) {}

				bool operator!=(const Iterator& it) const {
					return current != it.current;
				}
		
				Iterator& operator++() {
					if (current) current = current->next;

					return *this;
				}

				Iterator operator++(int) {
					Iterator iterator = *this;
					++(*this);
					
					return iterator;
				}

				const T& operator*() const {
					if (!current) throw std::out_of_range("Iterator is out of range!");
					return current->data;
				}

				T& operator*() {	
					if (!current) throw std::out_of_range("Iterator is out of range!");
					return current->data;
				}

		};

		Iterator begin() {
			return Iterator(front);
		}

		Iterator end() {
			return Iterator(nullptr);
		}

};
