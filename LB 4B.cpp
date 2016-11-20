#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

struct Average // Структура "средние"
{
	int age; // Средний возраст
	int height; // Средний рост
};

struct Country  // Структура стран
{
	char name[50]; // Название стран
	Average aver;
	int pop;  // Население
};


int main(int argc, char* argv[])
{
	Country *pG; // Указатель на массив структур
	int n; // Число элементов массива
	printf_s("n=");
	scanf_s("%d", &n); // Вводим число элементов массива
	pG = (Country *)malloc(n * sizeof(Country)); // Выделяем память под массив структур
	for (int i = 0; i<n; i++) // Цикл ввода данных с клавиатуры
	{
		printf_s("Country N=%d", i + 1);
		printf_s("\nName: ");
		_flushall(); // Сброс всех буферов ввода- вывода
		cin >> pG[i].name;
		printf_s("Population: ");
		scanf_s("%d", &pG[i].pop);
		printf_s("Average age: ");
		scanf_s("%d", &pG[i].aver.age);
		printf_s("Average height: ");
		scanf_s("%d", &pG[i].aver.height);
	}
	for (int i = 0; i<n; i++) // Цикл печати введенных данных
		printf_s("\n%s %d %d %d",
			pG[i].name, pG[i].pop, pG[i].aver.age, pG[i].aver.height);
	int k = 0;
	for (int i = 0; i<n; i++) // Просматриваем все страны
		if (pG[i].aver.age < 40)
			k++; // Нашли страны со средним возрастом < 40
	if (k) printf_s("\nCountries with an average age < 40: %d\n", k); // Выводим число найденных стран
	else printf_s("Not found\n"); // Таких стран нет
	free(pG); // Освобождаем память
	_getch(); // Останавливаем программу, ждем нажатия любой клавиши
	return 0;
}
