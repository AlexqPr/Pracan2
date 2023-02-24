#include <iostream>
using namespace std;


int Random(int min, int max){
    return min + rand() % (max - min); //первые числа трех массивов (8,24,28)
}

//void func5(int** matrix, int n, int m){
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            sum += matrix[i][j];
//        }
//    }
//}

//void matrix(){
//    int n,m;
//    cout << "Введите размер первого измерения:";
//    cin >> n;
//    cout << "Введите размер второго измерения:";
//    cin >> m;
////    int matrica[n][m];
//    int** matrica = reinterpret_cast<int **>((int *) ::malloc(n * m * sizeof(int)));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            matrica[i][j] = Random(1,101);
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << matrica[i][j] << "  ";
//        }
//        cout << endl;
//    }
//    func5(matrica,n,m);
//}

void matrix(){
    int n,m;
    cout << "Введите размер первого измерения:";
    cin >> n;
    cout << "Введите размер второго измерения:";
    cin >> m;
    int matrica[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrica[i][j] = Random(1,101);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrica[i][j] << "  ";
        }
        cout << endl;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += matrica[i][j];
        }
    }
    cout << "Сумма матрицы:" << sum << endl;
}

void naimensh(){
    int size;
    cout << "Введите размер массива:";
    cin >> size;
    int* newmassive = new int[size];
    for (int i = 0; i < size; ++i) {
        newmassive[i] = Random(1,101);
    }
    for (int i = 0; i < size; ++i) {
        cout << i << " элемент массива: " << newmassive[i] << endl;
    }
    int min = newmassive[0];
    for (int i = 0; i < size; ++i) {
        if(newmassive[i] < min)
            min = newmassive[i];
    }
    cout << "Наименьший элемент массива:" << min << endl;
}

int factorial(int n){
    if(n>1)
        return n*factorial(n-1);
    return 1;
}

void func3(int* massive, int size){
    //на 4 (1 задание)
    for (int i = 0; i < size; ++i) {
        cout << i << " элемент массива:" << massive[i] << endl;
    }
}


void func1(int* first, int* second){
    //на 3 (2 задание)


    int temp = *first;
    *first = *second;
    *second = temp;

}


void vvod(){
    //чисто нужна нам для ввода переменных
    cout << "Введите значение для первой переменной:";
    int x;
    cin >> x;

    cout << "Введите значение для второй переменной:";
    int b;
    cin >> b;

    func1(&x, &b);
    cout << x << endl << b << endl;
}



void func2(){
    //на 3 (3 задание)
    int numbers[5];
    int a;
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); ++i) {
        cout << "Введите " << i << " элемент:";
        cin >> a;
        numbers[i] = a;
    }
    int sum = 0;
    for (int j = 0; j < sizeof(numbers)/sizeof(numbers[0]); ++j) {
        sum += numbers[j];
    }
    cout << "Сумма элементов массива:" << sum << endl;
}
void lol(){
    //на 4 (2 задание)
    int x;
    int number[5];
    for (int i = 0; i < sizeof(number)/sizeof(number[0]); ++i) {
        cout << "Введите " << i << " элемент:";
        cin >> x;
        number[i] = x;
    }
    int sum = 0;
    for (int i = 0; i < sizeof(number)/sizeof(number[0]); ++i){
        sum += number[i];
    }
    cout << "Среднее арифмитическое:" << sum/(sizeof(number)/sizeof(number[0])) << endl;
}



void lol2(){
    //на 4 (3 задание)
    int x;
    int number[5];
    for (int i = 0; i < sizeof(number)/sizeof(number[0]); ++i) {
        cout << "Введите " << i << " элемент:";
        cin >> x;
        number[i] = x;
    }
    for (int i = 0; i < sizeof(number)/sizeof(number[0]); ++i){
        cout << i << " элемент массива:" << number[i] << endl;
    }
}

int main() {
    int n;
    int result;
    cout << "Выберите функцию" << endl;
    cout << "Чтобы выйти нажмите на 9" << endl;
    cout << "Ваш выбор:";
    int vibor;
    cin >> vibor;
    int* massive = new int[6];//для 4 случая
    while (vibor != 9)
    {
        switch (vibor) {
            case 1:
                cout << "Введите число:";
                cin >> n;
                result = factorial(n);
                cout << "Ваш результат:" << result << endl;
                break;
            case 2:
                vvod();//изменение значений переменных через указатели
                break;
            case 3:
                func2(); //заполнение массива и вывод их суммы
                break;
            case 4:
                for (int i = 0; i < 6; ++i) {
                    *(massive + i) = i + 1;
                }
                func3(massive,6);
                break;
            case 5:
                lol(); //заполнение массива и вывод среднего арифмитического
                break;
            case 6:
                lol2(); //заполнение массива и вывод его на экран
                break;
            case 7:
                matrix();
                break;
            case 8:
                naimensh();
                break;

        }
        cout << "Ваш выбор:";
        cin >> vibor;
    }
}

