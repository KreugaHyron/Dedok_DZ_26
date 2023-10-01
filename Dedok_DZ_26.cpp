#include <iostream>
#include <cstdlib> 
using namespace std;
//функция к заданию 2
void addElements(int*& arr, int& size, int numToAdd) {
    int* newArray = new int[size + numToAdd];
    
    for (int i = 0; i < size; i++) {
        newArray[i] = arr[i];
    }
  
    for (int i = size; i < size + numToAdd; i++) {
        newArray[i] = rand() % 100;
    }
    delete[] arr;
    arr = newArray;
    size += numToAdd;
}
//функции к заданию 3
int* findCommonElements(int* A, int M, int* B, int N, int& resultSize) {
    int* tempArray = new int[(M < N) ? M : N];
    int index = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                bool alreadyExists = false;
                for (int k = 0; k < index; k++) {
                    if (tempArray[k] == A[i]) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists) {
                    tempArray[index++] = A[i];
                }
                break;
            }
        }
    }
    int* resultArray = new int[index];
    for (int i = 0; i < index; i++) {
        resultArray[i] = tempArray[i];
    }
    delete[] tempArray;
    resultSize = index;
    return resultArray;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    //Task_1
    int* dynamicArray = nullptr; 
    int currentSize = 0; 

    dynamicArray = new int[5];

    
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = rand() % 100; 
        currentSize++;
    }

    cout << "Динамический массив: ";
    for (int i = 0; i < currentSize; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << "\n";
    int numToAdd = 3;
    int* newDynamicArray = new int[currentSize + numToAdd];
    for (int i = 0; i < currentSize; i++) {
        newDynamicArray[i] = dynamicArray[i];
    }
    for (int i = currentSize; i < currentSize + numToAdd; i++) {
        newDynamicArray[i] = rand() % 100;
    }
    delete[] dynamicArray;
    dynamicArray = newDynamicArray;
    currentSize += numToAdd;

    cout << "Новый динамический массив: ";
    for (int i = 0; i < currentSize; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << "\n";;
    delete[] dynamicArray;
    cout << "\n";
    //Task_2
    int* dynamicArray_1 = nullptr; 
    int currentSize_1 = 0; 

    addElements(dynamicArray_1, currentSize_1, 3);

    std::cout << "Новый динамический массив: ";
    for (int i = 0; i < currentSize_1; i++) {
        std::cout << dynamicArray_1[i] << " ";
    }
    cout << "\n";
    delete[] dynamicArray_1;
    //Task_3
    int M, N;
    cout << "Введите размеры массивов M и N: ";
    cin >> M >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
       cin >> A[i];
    }

    cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int resultSize = 0;
    int* commonElements = findCommonElements(A, M, B, N, resultSize);

    cout << "Общие элементы массивов без повторений: ";
    for (int i = 0; i < resultSize; i++) {
        cout << commonElements[i] << " ";
    }
    cout << "\n";
    delete[] A;
    delete[] B;
    delete[] commonElements;
}
