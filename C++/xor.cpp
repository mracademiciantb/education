#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//using namespace std;
std::string xor_encrypt_decrypt(const std::string& message_1, const std::string& message_2) {
    std::string result = message_1;
    for (size_t i = 0; i < message_1.length(); ++i) {
        result[i] = message_1[i] ^ message_2[i % message_2.length()];
    }
    return result;
}

int main()
{
    std::string hexPair;

    // std::string result;
    std::string message_1 = "391813c092a2d5ac9acb705dfe41be3df08de67d1145cbcc3f";
    //std::getline(std::cin, message_1);
    std::string message_2 = "03adeae2c8c2f2336c8a8d312733c2456e76e0b2d9068adc3f";
   // std::getline(std::cin, message_2);
   // std::string message_3;
    //std::getline(std::cin, message_3);


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
std::cout << hexPair << std::endl;
}