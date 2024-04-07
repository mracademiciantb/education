#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 2.1: Функція для обчислення коду Хемінга
vector<int> hammingCode(vector<int>& dataBits, int m, int r) {
    vector<int> hammingCode(r + m);

    for (int i = 0; i < r; ++i) {
        hammingCode[(int)pow(2, i) - 1] = -1;
    }

    int j = 0;
    for (int i = 0; i < (r + m); ++i) {
        if (hammingCode[i] != -1) {
            hammingCode[i] = dataBits[j];
            j++;
        }
    }

    for (int i = 0; i < r; ++i) {
        int x = (int)pow(2, i);
        int oneCount = 0;
        for (int j = 0; j < (r + m); ++j) {
            if (j & x && hammingCode[j] != -1) {
                oneCount += hammingCode[j];
            }
        }
        hammingCode[x - 1] = oneCount % 2;
    }

    return hammingCode;
}

// 3.2: Функція для введення одиночної помилки
void introduceError(vector<int>& hammingCode) {
    // Помилка
    hammingCode[0] = (hammingCode[0] == 1) ? 0 : 1;
}

// 4.1: Функція для виявлення та виправлення помилки в коді
int hammingErrorDetectionAndCorrection(vector<int>& hammingCode) {
    int errorPos = 0;
    int r = hammingCode.size() - ceil(log2(hammingCode.size()));

    // Виявлення помилки
    for (int i = 0; i < r; ++i) {
        int parity = 0;
        int x = (int)pow(2, i);

        for (int j = 0; j < hammingCode.size(); ++j) {
            if (j & x) {
                parity ^= hammingCode[j];
            }
        }

        if (parity != 0) {
            errorPos += x;
        }
    }

    // Виправлення помилки
    if (errorPos != 0) {
        hammingCode[errorPos - 1] ^= 1; // Коректування помилки
    }

    return errorPos; // Повернення позиції помилки (0 якщо помилок немає)
}

int main() {
   
    //vector<int> dataBits = {0, 1, 1, 1, 1}; 
   vector<int> dataBits;
   int dataBitsLen = 0;
   cin >> dataBitsLen;
   for(int i = 0; i < dataBitsLen; i++){
    int temp;
    cin >> temp; 
    dataBits.push_back(temp);
   }
   

    int m = dataBits.size();
    int r = ceil(log2(m + r + 1));

    // Код Хемінга
    vector<int> code = hammingCode(dataBits, m, r);
    cout << "Код Хемінга: ";
    for (int i : code) cout << i;
    cout << endl;

    // Введення помилки
    introduceError(code);
    cout << "Код Хемінга з помилкою: ";
    for (int i : code) cout << i;
    cout << endl;

    // Виявлення та виправлення помилки
    int errorPos = hammingErrorDetectionAndCorrection(code);
    cout << "Виправлений код Хемінга: ";
        for (int i : code) cout << i;

    return 0;
}
