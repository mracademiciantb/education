// шифрування

#include <iostream>
#include <array>
#include <algorithm>

// Визначаємо ключ шифрування за допомогою constexpr
constexpr std::array<uint8_t, 16> encryptionKey = {0x2A, 0x7F, 0xC4, 0x1B, 0x6D, 0xE9, 0x8F, 0x03, 0x5A, 0xB6, 0x9C, 0x71, 0xD8, 0x24, 0x58, 0xF2};

// Функція для шифрування даних
void encryptData(std::array<uint8_t, 16>& data) {
    // Використовуємо ключ шифрування
    std::transform(data.begin(), data.end(), encryptionKey.begin(), data.begin(), std::bit_xor<uint8_t>());
}

int main() {
    // Дані для шифрування
    std::array<uint8_t, 16> inputData = {0x45, 0x23, 0x76, 0x98, 0xAB, 0xCD, 0xEF, 0x01, 0x34, 0x67, 0x89, 0xBA, 0xDC, 0xFE, 0x21, 0x43};

    // Шифруємо дані
    encryptData(inputData);

    // Виводимо зашифровані дані
    for (const auto& byte : inputData) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }

    return 0;
}
