#include <iostream>
#include "MyStack.h" // Подключаем ваш заголовочный файл

void testMyStack() {
	try {
        	// Тест 1: Создаем стек и добавляем элементы
        	MyStack<int> stack;
        	stack.push(10);
        	stack.push(20);
        	stack.push(30);

        	std::cout << "Текущий размер стека: " << stack.getSize() << '\n';
        	std::cout << "Верхний элемент стека: " << stack.peekTop() << '\n';

        	// Тест 2: Тестируем pop
        	stack.pop();
        	std::cout << "После pop: верхний элемент стека: " << stack.peekTop() << '\n';

        	// Тест 3: Тестируем isEmpty
        	std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << '\n';

        	// Тест 4: Тестируем копирующий конструктор
        	MyStack<int> stackCopy(stack);
        	std::cout << "Скопированный стек: верхний элемент: " << stackCopy.peekTop() << '\n';

        	// Тест 5: Тестируем оператор присваивания
        	MyStack<int> anotherStack;
        	anotherStack = stack;
        	std::cout << "Присвоенный стек: верхний элемент: " << anotherStack.peekTop() << '\n';

        	// Тест 6: Добавляем элементы в оригинальный стек
        	stack.push(40);
        	stack.push(50);
        	std::cout << "Оригинальный стек после push: верхний элемент: " << stack.peekTop() << '\n';

        	// Тест 7: Проверяем итератор
        	std::cout << "Элементы в стеке через итератор: ";
        	for (auto it = stack.begin(); it != stack.end(); ++it) {
            		std::cout << *it << " ";
        	}
        	std::cout << '\n';

        	// Тест 8: Очищаем стек
        	while (!stack.isEmpty()) {
            		std::cout << "Удаляем элемент: " << stack.peekTop() << '\n';
            	stack.pop();
        	}
        	std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << '\n';

        	// Тест 9: Попытка pop() на пустом стеке
        	try {
            		stack.pop();
        	} 
		catch (const std::exception& e) {
            		std::cerr << "Ожидаемая ошибка pop(): " << e.what() << '\n';
        	}

        	// Тест 10: Попытка peekTop() на пустом стеке
        	try {
            		stack.peekTop();
        	} 
		catch (const std::exception& e) {
            		std::cerr << "Ожидаемая ошибка peekTop(): " << e.what() << '\n';
        	}

        	// Тест 11: Итератор на пустом стеке
        	std::cout << "Итерация по пустому стеку: ";
        	for (auto it = stack.begin(); it != stack.end(); ++it) {
            		std::cout << *it << " ";
        	}
        	std::cout << "(нет элементов)\n";

        	// Тест 12: Присваивание пустого стека
        	anotherStack = stack;
        	std::cout << "Присваивание пустого стека успешно. Размер: " << anotherStack.getSize() << '\n';
    	}
    	catch (const std::exception& e) {
        	std::cerr << "Ошибка: " << e.what() << '\n';
    	}
}


int main() {
   	testMyStack();


	return 0;
}

