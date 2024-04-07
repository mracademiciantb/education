#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

//using namespace std;
std::string xorHex(const std::string& hexPair1, const std::string& hexPair2, const std::string& hexPair3) {
    // Convert hexadecimal characters to integers
    int num1, num2, num3;
    std::istringstream iss1(hexPair1);
    std::istringstream iss2(hexPair2);
    std::istringstream iss3(hexPair3);
    iss1 >> std::hex >> num1;
    iss2 >> std::hex >> num2;
    iss3 >> std::hex >> num3;

    // XOR the integers and convert the result back to hexadecimal
    int xorResult = num1 ^ num2;
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << xorResult;

    int xorResult_1 =  xorResult ^ num3;
    ss << std::hex << std::setw(2) << std::setfill('0') << xorResult_1;

    return ss.str();
}

int main()
{
    //std::string hexPair;

    // std::string result;
    std::string message_1 = "391813c092a2d5ac9acb705dfe41be3df08de67d1145cbcc3f";
    //std::getline(std::cin, message_1);
    std::string message_2 = "03adeae2c8c2f2336c8a8d312733c2456e76e0b2d9068adc3f";
   // std::getline(std::cin, message_2);
    std::string message_3 = "72d0954e354045f09461dc4c911d0b58ff8963efb12c34303f";
    //std::getline(std::cin, message_3);

/*
    std::string key = "secret";

    // Шифрування
    std::string encrypted_result = xor_encrypt_decrypt(message_1, message_2);


    // Дешифрування
    std::string decrypted_result = xor_encrypt_decrypt(message_1, message_2);

for (int i = 0; i < decrypted_result.length(); i += 2) {
    // Взяти два символи шістнадцяткового рядка
    std::string hexPair = decrypted_result.substr(i, 2);

    // Перевірити, чи hexPair є коректним шістнадцятковим числом
    if (hexPair.size() == 2 && std::all_of(hexPair.begin(), hexPair.end(), ::isxdigit)) {
        // Конвертувати їх у десяткове число
        int decimalValue = std::stoi(hexPair, 0, 16);

        // Вивести відповідний ASCII-символ
        std::cout << static_cast<char>(decimalValue);
    } else {
        // Обробка помилки, наприклад, можна вивести повідомлення про некоректний формат
        std::cerr << "Некоректний шістнадцятковий формат: " << hexPair << std::endl;
    }
    
}
*/
std::cout << hexPair << std::endl;
}