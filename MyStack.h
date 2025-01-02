#pragma once
#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class MyStack {
	private:
		Node<T>* head{};
		std::size_t size{};

		void copy(Node<T>* _head) {
			if (_head == nullptr) return;

			free();

			Node<T>* p = _head;;
			Node<T>* last = nullptr;

			while (p != nullptr) {
				Node<T>* new_node = new Node<T>;
				new_node->data = p->data;
				new_node->next = nullptr;

				if (head == nullptr) {
					head = new_node;
				}
				else {
					last->next = new_node;
				}
				last = new_node;
				size++;

				p = p->next;
			}
		}
		

		void free() {
			Node<T>* p = head;
			while (p != nullptr) {
				head = head->next;
				delete p;
				p = head;
			}
			size = 0;
			head = nullptr;
		}

	public:

		MyStack() {
			head = nullptr;
			size = 0;
		}

		~MyStack() {
			free();
		}

		MyStack(const MyStack<T>& stack) {
			copy(stack.head);
		}

		MyStack<T>& operator=(const MyStack<T>& stack) {
			if (this != &stack) {
				free();
				copy(stack.head);
			}

			return *this;
		}

		void push(T item) {
			Node<T>* new_node = new Node<T>{item, head};
			head = new_node;
			size++;
		}

		void pop() {
			if (isEmpty()) return;
			
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			size--;
		}

		T& peekTop() {
			if (isEmpty()) throw std::runtime_error("Stack is empty!");
			return head->data;
		}

		bool isEmpty() const {
			return size == 0;
		}

		std::size_t getSize() const {
			return size;
		}	

		class Iterator {
			private:
				Node<T>* curr_node;

			public:
				Iterator() noexcept : curr_node(nullptr) {}
				Iterator(const Iterator& it) : curr_node(it.curr_node) {}
				Iterator(Node<T>* node) noexcept : curr_node(node) {}

				Iterator& operator=(Node<T>* node) {
					if(this->curr_node != node) {
						this->curr_node = node;
					}
					
					return *this;
				}

				Iterator& operator++() {
					if (curr_node) curr_node = curr_node->next;

					return *this;
				}

				Iterator operator++(int) {
					Iterator iterator = *this;
					++(*this);
					
					return iterator;
				}

				bool operator!=(const Iterator& it) {
					return curr_node != it.curr_node;
				}

				const T& operator*() const {
					return curr_node->data;
				}

				T& operator*() {
					return curr_node->data;
				}
		};

		Iterator begin() {
			return Iterator(head);
		}

		Iterator end() {
			return Iterator(nullptr);
		}
};
