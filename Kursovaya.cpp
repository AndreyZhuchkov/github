#include "pch.h"
#include <iostream>
#include <string>
#include <utility> //необходим для класса pair
#include <vector> //
#include <algorithm>

#define EXP "2.7182818284"

using namespace std;

//Абстрактный класс интеграл
class Integral
{
public:
	//Квадратичная функция y = x^2
	virtual double squareFunc(double x) = 0;

	//Линейная функция y = x
	virtual double lineFunc(double x) = 0;

	//Иррациональная функция y = x^(0,5)
	virtual double sqrtFunc(double x) = 0;

	//Экспоненциальная функция y = e^x
	virtual double expFunc(double x) = 0;

	//Вычисляет интеграл
	virtual double ingrl(double a, double b, unsigned step_count) = 0;
	Integral() {}
	~Integral() {}
};

//Вычисление значение интеграла методом трапеции
class Intgrl_trap : public Integral
{
private:
	char choice;
	double squareFunc(double x)override
	{
		return x * x;
	}

	double lineFunc(double x)override
	{
		return x;
	}

	virtual double sqrtFunc(double x)
	{
		return sqrt(x);
	}

	virtual double expFunc(double x)
	{
		return exp(x);
	}

	double ingrl(double a, double b, unsigned step_count)override
	{
		double sum = .0, step;

		if (0 == step_count) return sum;
		step = (b - a) / (1.0 * step_count);
		switch (choice)
		{
		case '1':
			for (int i = 1; i < step_count; ++i) {
				sum += squareFunc(a + i * step);
			}
			sum += (squareFunc(a) + squareFunc(b)) / 2;
			break;
		case '2':
			for (int i = 1; i < step_count; ++i) {
				sum += lineFunc(a + i * step);
			}
			sum += (lineFunc(a) + lineFunc(b)) / 2;
			break;
		case '3':
			for (int i = 1; i < step_count; ++i) {
				sum += sqrt(a + i * step);
			}
			sum += (sqrt(a) + sqrt(b)) / 2;
			break;
		case '4':
			for (int i = 1; i < step_count; ++i) {
				sum += expFunc(a + i * step);
			}
			sum += (expFunc(a) + expFunc(b)) / 2;
			break;
		default:
			break;
		}
		sum *= step;
		return sum;
	}
public:
	Intgrl_trap()
	{
		cout << "1) f(x) = x^2\n";
		cout << "2) f(x) = x\n";
		cout << "3) f(x) = x^(0.5)\n";
		cout << "4) f(x) = e^x\n";
		cout << "Ваш выбор: ";
		cin >> choice;

		int a, b, step;
		cout << "\n\nВведите через Enter пределы интегрирования [a;b] и точность вычислений (три числа):\n";
		cin >> a;
		cin >> b;
		cin >> step;
		cout << ingrl(a, b, step);
	}
};

//Класс вычисляющий значение выражения
class Calculator
{
public:
	Calculator(string, string = "");

	string endValue();

private:
	string globalExp, parametr;

	void clearOperations(char);
	void clearBrackets();

	pair<double, int64_t> getNumberLeft(int64_t);
	pair<double, int64_t> getNumberRight(int64_t);
	pair<int64_t, int64_t> indexBrackets();
	int64_t indexOperator(char);

	int64_t indexRight(int64_t i);

	string checkParameter(int64_t i);

	void clearConstExponent();
	void clearExponentialform();

	bool breaking = false;
};

Calculator::Calculator(string globalExp, string parameter)
{
	globalExp.erase(remove(globalExp.begin(), globalExp.end(), ' '), globalExp.end());
	this->globalExp = globalExp;
	this->parametr = parameter;

	clearExponentialform();
	clearConstExponent();
}

pair<double, int64_t> Calculator::getNumberLeft(int64_t index)
{
	index--;
	string num;

	while (index >= 0 and index < globalExp.length() and ((globalExp[index] >= '0' and  globalExp[index] <= '9') or globalExp[index] == '.')) {
		num.insert(num.begin(), globalExp[index]);
		index--;
	}

	if (index >= 0 and globalExp[index] == '-') {
		num.insert(num.begin(), '-');
		index--;
	}

	return make_pair(atof(num.c_str()), index + 1);
}

pair<double, int64_t> Calculator::getNumberRight(int64_t index)
{
	index++;
	string num;
	if (globalExp[index - 1] == '-') num.insert(num.begin(), '-');
	else if (globalExp[index] == '-') {
		num.insert(num.begin(), '-');
		index++;
	}

	while (index >= 0 and index < globalExp.length() and ((globalExp[index] >= '0' and  globalExp[index] <= '9') or globalExp[index] == '.')) {
		num += globalExp[index];
		index++;
	}
	return make_pair(atof(num.c_str()), index - 1);
}

void Calculator::clearOperations(char operations)
{
	int64_t index = indexOperator(operations);

	if (index >= 0) {
		double answer;
		pair <double, int64_t> rightNum = getNumberRight(index);
		pair <double, int64_t> leftNum = getNumberLeft(index);

		switch (operations) {
		case '*': {
			answer = leftNum.first * rightNum.first;
			break;
		}
		case '+': {
			answer = leftNum.first + rightNum.first;
			break;
		}
		case '-': {
			if (leftNum.first == 0) {
				int64_t oldLeftIndex = leftNum.second;
				leftNum = rightNum;
				if (leftNum.second + 1 < globalExp.size() and globalExp[leftNum.second + 1] == '-')
				{
					rightNum = getNumberRight(leftNum.second + 1);
					answer = leftNum.first + rightNum.first;
					leftNum.second = oldLeftIndex;
				}
				else
				{
					answer = leftNum.first;
					string newLocalExp = to_string(answer);

					if (newLocalExp == globalExp) return;

					globalExp.erase(globalExp.begin() + leftNum.second, globalExp.begin() + rightNum.second + 1);
					globalExp.insert(leftNum.second, newLocalExp);

					return;
				}
			}
			else
				answer = leftNum.first + rightNum.first;
			break;
		}
		case '/': {
			if (rightNum.first == 0) {
				setlocale(LC_ALL, "Russian");
				cout << "Деление на ноль невозможно\n";
				setlocale(LC_ALL, "en_us");
				breaking = true;
				return;
			}
			answer = leftNum.first / rightNum.first;
			break;
		}
		}
		string newLocalExp = to_string(answer);

		if (leftNum.first < 0 and answer >= 0)
			newLocalExp.insert(newLocalExp.begin(), '+');

		if (newLocalExp != globalExp) {
			globalExp.erase(globalExp.begin() + leftNum.second, globalExp.begin() + rightNum.second + 1);
			globalExp.insert(leftNum.second, newLocalExp);
		}
		clearOperations(operations);
	}
}

string Calculator::checkParameter(int64_t i) {
	if (i >= 3) {
		string parametr = globalExp.substr(-3 + i, 3);
		if (parametr == "cos") return parametr;
		else if (parametr == "sin") return parametr;
		else if (parametr == "ctg") return parametr;
	}

	if (i >= 2) {
		string parametr = globalExp.substr(-2 + i, 2);
		if (parametr == "tg") return parametr;
		else if (parametr == "ln") return parametr;
	}
	return "";
}

void Calculator::clearBrackets()
{
	pair <int64_t, int64_t> index = indexBrackets();

	if (index.first >= 0 and index.second >= 0)
	{
		string local = globalExp.substr(index.first + 1, index.second - index.first - 1);

		globalExp.erase(globalExp.begin() + index.first, globalExp.begin() + index.second + 1);

		Calculator localExp(local, checkParameter(index.first));
		string localEndVal = localExp.endValue();

		if (localEndVal == "error")
			breaking = true;

		globalExp.insert(index.first, localEndVal);

		globalExp.erase(globalExp.begin() + index.first - localExp.parametr.size(), globalExp.begin() + index.first);
		clearBrackets();
	}
}

int64_t Calculator::indexOperator(char operation)
{
	int64_t index = globalExp.find(operation);
	if (index == 4294967295) {
		index = -1;
	}
	return index;
}

int64_t Calculator::indexRight(int64_t i) {
	int64_t countL = 0, countR = 0;

	for (int64_t indexR = i; indexR < globalExp.length(); indexR++) {
		if (globalExp[indexR] == ')') countR++;
		if (globalExp[indexR] == '(') countL++;
		if (countL == countR and countL != 0) return indexR;
	}
}

pair<int64_t, int64_t> Calculator::indexBrackets()
{
	int64_t leftIndex = globalExp.find('(');
	int64_t rightIndex = indexRight(leftIndex);

	if (leftIndex == 4294967295 or rightIndex == 4294967295) {
		rightIndex = -1;
		leftIndex = -1;
	}
	return make_pair(leftIndex, rightIndex);
}

string Calculator::endValue()
{
	clearBrackets();
	clearOperations('*');
	clearOperations('/');
	clearOperations('+');
	clearOperations('-');

	double endVal = atof(globalExp.c_str());

	if (parametr == "cos") endVal = cos(endVal);
	else if (parametr == "sin") endVal = sin(endVal);
	else if (parametr == "tg") endVal = tan(endVal);
	else if (parametr == "ctg") {
		if (endVal == 0) {
			setlocale(LC_ALL, "Russian");
			cout << "Ctg(0) не существует\n";
			setlocale(LC_ALL, "en_us");
			breaking = true;
		}
		endVal = pow(tan(endVal), -1);
	}
	else if (parametr == "ln") {
		if (endVal <= 0) {
			setlocale(LC_ALL, "Russian");
			cout << "ln(0) и ln(x<0) не существует\n";
			setlocale(LC_ALL, "en_us");
			breaking = true;
		}
		endVal = log(endVal);
	}

	globalExp = to_string(endVal);
	if (breaking) return "error";
	return globalExp;
}

void Calculator::clearExponentialform()
{
	int64_t indexE = globalExp.find('E');

	if (indexE = 4294967295) return;
	pair <double, int64_t> rightNum = getNumberRight(indexE);
	pair <double, int64_t> leftNum = getNumberLeft(indexE);

	if (leftNum.first == 0) leftNum.first = 1;

	string expForm = to_string(leftNum.first) + 'e' + to_string(rightNum.first);
	double num = atof(expForm.c_str());

	globalExp.erase(globalExp.begin() + leftNum.second, globalExp.begin() + rightNum.second + 1);

	globalExp.insert(leftNum.second, to_string(num));
}

void Calculator::clearConstExponent()
{
	for (int i = 0; i < globalExp.size(); i++) {
		if (globalExp[i] == 'e') {
			globalExp.erase(i);
			globalExp.insert(i, EXP);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	cout << "Меню: \n";
	cout << "1) Калькулятор\n";
	cout << "2) Посчитать значение интеграла методом трапеции\n";
	cout << "Ваш выбор: ";
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		cout << "Введите выражение для подсчета, используйте символы + - * / cos() sin() tg() ctg() ln() e и E для экспоненциальной формы записи числа\n";
		setlocale(LC_ALL, "en_us");
		string expression;
		getline(cin, expression);//для очистки потока
		getline(cin, expression);

		Calculator exp(expression);
		cout << exp.endValue();
		break;
	}
	case 2:
	{
		cout << "Выберите функцию f(x) значение интеграла, которой будем искать:\n\n";
		Intgrl_trap I;
		break;
	}
	default:
		break;
	}
	return 0;
}
