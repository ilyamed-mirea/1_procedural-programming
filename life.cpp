#include <iostream>
#include "Header.h"
#include <fstream>
#include <string> 
#include "Windows.h"

using namespace std;

// Задаем размеры всего поля. на 2 больше что бы не заходить за границы
const int height = 23;
const int width = 23;
// Для рабочей области (workspace)
const int wheight = height - 1;
const int wwidth = width - 1;

// считает колво живых микробов на поле
int aliveCount(char mas[height][width]) {
	int count = 0;
	for (int i = 1; i < wheight; i++) {
		for (int j = 1; j < wwidth; j++) {
			if ((mas[i][j] - '0') > 0) { // если микроб жив увеличиваем счетчик
				count++;
			}
		}
	}
	return count;
}

// вывод массива в консоль
void printOut(char arr[height][width]) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((arr[i][j] - '0') == -48) { // если это граница, её выводить не надо
				cout << "  ";
			}
			if ((arr[i][j] - '0') == 0) { // нули тоже не выводим, для удобства
				cout << "  ";
			}
			else {
				cout << arr[i][j] << " "; // вывод всего остального
			}
		}
		cout << endl;
	}
}

// копирование одного массива в другой
void copying(char(&_old)[height][width], char(&_new)[height][width]) {
	for (int i = 1; i < wheight; i++) {
		for (int j = 1; j < wwidth; j++) {
			_new[i][j] = _old[i][j];
		}
	}
}

int LIFE() {
	// установка кодировки консоли, создание файлов и открытие их для чтение и записи через fstream
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fdat("work.dat.txt");
	ofstream fout("work.out.txt");
	fdat.close();
	fout.close();
	fstream data("work.dat.txt", fstream::out | fstream::in);
	fstream out("work.out.txt", fstream::out | fstream::in);

	char arr_old[height][width]{}; // Массив прошлого 
	char arr_new[height][width]{}; // Массив будущего

	// 1
	// пользователь вводит колво различных символов (параметр, отвечающий за частоту микробов на поле) и файл заполняется символами (буквами англ алфавита)
	int freq = 0;
	while (true) {
		cout << "Сколько различных символов будет в файле dat? (частота микробов)" << endl << "Введите число [1,26]: ";
		freq = getInt();
		if (freq >= 1 && freq <= 26) {
			break;
		}
		else {
			cout << "ошибка. заданное число должно быть в пределах [1,26]. попробуйте еще раз" << endl;
		}
	}
	// заполнение файла dat символами.
	srand(time(NULL));
	for (int i = 0; i < 21*21; i++) {
		char smvl = 97 + (rand() % freq); // в char будет записывать случайный символ от a до z по таблице ASCII (число от 97 до 122)
		data << smvl; // ввод в файл 
	}
	data.seekg(0); // установка курсора в начало файла после заполнения

	// 2
	// считывание символов из файла в массив прошлого
	char microb = 97 + (rand() % freq); // выбор случайного символа, который будет обозначать микроба
	for (int i = 1; i < wheight; i++) {
		for (int j = 1; j < wwidth; j++) {
			char ch;
			data.get(ch);  // считывание символа из файла
			if (ch == microb) { // проверка символа, если микроб - заносим в массив 1
				arr_old[i][j] = '1';
			}
			else { // если нет - 0
				arr_old[i][j] = '0';
			}
		}
	}
	data.close();

	// теперь у нас есть готовое поле с начальным расположением микробов в arr_old
	copying(arr_old, arr_new); // копирование старого массива в новый

	int colv_pok;
	while (true) {
		cout << "Введите количество поколений: ";
		colv_pok = getInt();
		if (colv_pok > 0) {
			break;
		}
		else {
			cout << "ошибка. попробуйте еще раз" << endl;
		}
	}

	int num = 1; // отвечает за номер поколения
	printOut(arr_old); // вывод в консоль начального положения микробов

	// добавления в файл out, первый прогон
	for (int i = 1; i < wheight; i++) {
		for (int j = 1; j < wwidth; j++) {
			if (arr_old[i][j] == '0') { // Если микроба нет вписываем пробел
				out << "  ";
			}
			else {
				out << arr_old[i][j] << " ";
			}
		}
		out << endl;
	}
	out << "Поколение: " << num << endl << "Количество живых микробов: " << aliveCount(arr_new) << endl << "------------------------------------------" << endl;
	if (aliveCount(arr_old) == 0) { // если микробов не осталось в живых - конец
		cout << "Больше микробов нет..." << endl;
		exit(0);
	}
	cout << "Поколение: " << num << endl << "Количество живых микробов: " << aliveCount(arr_new) << endl << "------------------------------------------" << endl;

	// 3
	for (int zzz = 1; zzz < colv_pok; zzz++) {
		for (int i = 1; i < wheight; i++) {
			for (int j = 1; j < wwidth; j++) {
				int sosedi = 0;// колво соседей
				for (int q = i-1; q < i+2; q++) { // перебор значения в окрестности Мура для [i][j] элемента
					for (int w = j-1; w < j+2; w++) {
						if ((arr_new[q][w] - '0') == -48) { // не учитываем границы
							continue;
						}
						if ((arr_new[q][w] - '0') > 0) { // если микроб жив, то +1 к соседу
							sosedi++;
						}
					}
				}
				if ((arr_new[i][j] - '0') > 0) { // вычитаем [i][j] элемент так как его считать в окрестность не нужно
					sosedi--;
				}

				// проверка условий. изменения происходят в старом массиве, для того что бы новые изменения не учитывались сразу
				if ((sosedi == 3) && ((arr_new[i][j] - '0') >= 0)) { // если есть 3 соседа => продолжает жить или рождается
					if (arr_new[i][j] == '9') { // если микробу 9 лет, то на следующий год должно отобразиться А(по 16ричной сс) 
						arr_old[i][j] += 7; // чтобы перейти от 9 к A, по таблице ASCII прибавляем 8 (прибавляем 7 и 1 на след строке)
					}
					arr_old[i][j]++; // если микроб выжил - плюсуем ему год
					if ((arr_old[i][j]) == 'C') { // если микроб дожил до 12 лет => он умирает
						arr_old[i][j] = '0';
					}
				}

				if ((sosedi < 2 || sosedi > 3) && (arr_new[i][j] - '0') >= 1) { // если у микроба больше 3 или меньше 2 соседей => он умирает
					arr_old[i][j] = '0';
				}

				if ((sosedi == 2) && ((arr_new[i][j] - '0') > 0)) { // если есть 2 соседа => продолжает жить 
					if (arr_new[i][j] == '9') { // чтобы после 9 было A
						arr_old[i][j] += 7; // надо прибавить 8
					}
					arr_old[i][j]++;
					if ((arr_old[i][j]) == 'C') { // если микроб дожил до 12 лет => он умирает
						arr_old[i][j] = '0';
					}
				}
			}
		}


		// копирование из старого массива в новый и вывод текущего состояние
		copying(arr_old, arr_new);
		printOut(arr_new); 

		// запись в файл
		for (int i = 1; i < wheight; i++) {
			for (int j = 1; j < wwidth; j++) {
				if (arr_old[i][j] == '0') {
					out << "  ";
				}
				else {
					out << arr_old[i][j] << " ";
				}
			}
			out << endl;
		}
		num++; // увеличение номера поколений
		out << "Поколение: " << num << endl << "Количество живых микробов: " << aliveCount(arr_new) << endl << "------------------------------------------" << endl;

		// вывод информации в консоль
		cout << "Поколение: " << num << endl << "Количество живых микробов: " << aliveCount(arr_new) << endl << "------------------------------------------" << endl;
		if (aliveCount(arr_new) == 0) {
			cout << endl << "Все микробы умерли(" << endl;
			break;
		}
	}

	out.close();
	cout << endl << "Конец" << endl;
	return 0;
}