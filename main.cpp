#include <iostream>
#include "MyStack.h" // Подключаем ваш заголовочный файл

int main() {
    try {
        // Создаем стек и добавляем элементы
        MyStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Текущий размер стека: " << stack.getSize() << '\n';
        std::cout << "Верхний элемент стека: " << stack.peekTop() << '\n';

        // Тестируем pop
        stack.pop();
        std::cout << "После pop: верхний элемент стека: " << stack.peekTop() << '\n';

        // Тестируем isEmpty
        std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << '\n';

        // Тестируем копирующий конструктор
        MyStack<int> stackCopy(stack);
        std::cout << "Скопированный стек: верхний элемент: " << stackCopy.peekTop() << '\n';

        // Тестируем оператор присваивания
        MyStack<int> anotherStack;
        anotherStack = stack;
        std::cout << "Присвоенный стек: верхний элемент: " << anotherStack.peekTop() << '\n';

        // Добавляем элементы в оригинальный стек
        stack.push(40);
        stack.push(50);
        std::cout << "Оригинальный стек после push: верхний элемент: " << stack.peekTop() << '\n';

        // Проверяем итератор
        std::cout << "Элементы в стеке через итератор: ";
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << '\n';

        // Очищаем стек
        while (!stack.isEmpty()) {
            std::cout << "Удаляем элемент: " << stack.peekTop() << '\n';
            stack.pop();
        }
        std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << '\n';

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}

