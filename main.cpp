#include <iostream>
#include "MyStack.h" 
#include "MyQueue.h"
#include <string>

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
		
		for (auto el : stack) {
			std::cout << el << ' ';
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


void testMyQueue() {
    	MyQueue<int> intQueue;

    	// Тест: проверка isEmpty() на новой очереди
    	std::cout << "Тест 1: isEmpty для новой очереди: " << (intQueue.isEmpty() ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

    	// Тест: добавление элементов и проверка getFront/getBack
    	intQueue.push(10);
    	intQueue.push(20);
    	intQueue.push(30);
    	std::cout << "Тест 2: push и getFront: " << (intQueue.getFront() == 10 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';
    	std::cout << "Тест 3: push и getBack: " << (intQueue.getBack() == 30 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

    	// Тест: проверка размера
    	std::cout << "Тест 4: getSize: " << (intQueue.getSize() == 3 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

    	// Тест: удаление элемента pop
    	intQueue.pop();
    	std::cout << "Тест 5: pop и getFront: " << (intQueue.getFront() == 20 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

    	// Тест: итератор
    	intQueue.push(40);
    	std::cout << "Тест 6: итератор: ";
    	bool iteratorPass = true;
    	int expected[] = {20, 30, 40};
    	int i = 0;
    	for (auto it = intQueue.begin(); it != intQueue.end(); ++it) {
        	if (*it != expected[i++]) {
            		iteratorPass = false;
           		break;
        	}
    	}
	for (auto el : intQueue) {
		std::cout << el << ' ';
	}
	std::cout << '\n';
    	std::cout << (iteratorPass ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

    	// Тест: удаление всех элементов
    	intQueue.pop();
    	intQueue.pop();
    	intQueue.pop();
    	std::cout << "Тест 7: удаление всех элементов: " << (intQueue.isEmpty() ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

    	// Тест: исключения
    	try {
        	intQueue.pop();
        	std::cout << "Тест 8: исключение при pop на пустой очереди: НЕ ПРОЙДЕН" << '\n';
    	} 
    	catch (const std::out_of_range&) {
		std::cout << "Тест 8: исключение при pop на пустой очереди: ПРОЙДЕН" << '\n';
    	}

   	try {
        	intQueue.getFront();
      		std::cout << "Тест 9: исключение при getFront на пустой очереди: НЕ ПРОЙДЕН" << '\n';
    	} 
    	catch (const std::out_of_range&) {
		std::cout << "Тест 9: исключение при getFront на пустой очереди: ПРОЙДЕН" << '\n';
    	}

    	// Тест: копирование очереди
	MyQueue<int> copiedQueue = intQueue; // Проверяем копирование
	copiedQueue.push(50);
	std::cout << "Тест 10: копирование очереди: " << (copiedQueue.getSize() == 1 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << '\n';

}

int main() {
	std::cout << "Проверка Стека:\n";
   	testMyStack();
	std::cout << "\n\nПроверка Очереди:\n";
	testMyQueue();

	return 0;
}

