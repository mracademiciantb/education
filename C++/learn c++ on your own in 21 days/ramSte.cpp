#include <iostream>
#include <memory>

class Player {
public:
    // Конструктор класу Player, приймає ім'я гравця та виводить повідомлення про створення.
    Player(const std::string& name) : name(name) {
        std::cout << "Player " << name << " created." << std::endl;
    }

    // Деструктор класу Player, виводить повідомлення про знищення об'єкта при завершенні його життєвого циклу.
    ~Player() {
        std::cout << "Player " << name << " destroyed." << std::endl;
    }

    // Метод play, виводить повідомлення про те, що гравець грає.
    void play() {
        std::cout << "Player " << name << " is playing." << std::endl;
    }

private:
    std::string name;  // Приватне поле для зберігання імені гравця.
};

int main() {
    int g;  // Оголошення цілочисельної змінної g в стековій пам'яті.

    int* x = new int(10);  // Оголошення вказівника x, який вказує на цілочисельний об'єкт, виділений у купі пам'яті і ініціалізується значенням 10.

    Player* player = new Player("DefaultPlayer");  // Оголошення вказівника player, який вказує на об'єкт класу Player, створений за допомогою оператора new.

    // Код функції main...

    delete x;  // Вивільнення пам'яті, зарезервованої для об'єкта, на який вказує x.
    delete player;  // Вивільнення пам'яті, зарезервованої для об'єкта, на який вказує player.

    // Використання std::unique_ptr
    std::unique_ptr<Player> uniquePlayer = std::make_unique<Player>("Alice");
    uniquePlayer->play();  // Виклик методу об'єкта через std::unique_ptr

    // Використання std::shared_ptr
    std::shared_ptr<Player> sharedPlayer = std::make_shared<Player>("Bob");
    sharedPlayer->play();  // Виклик методу об'єкта через std::shared_ptr

    // Звертання до об'єкта за допомогою вказівника raw pointer
    Player* rawPlayer = sharedPlayer.get();
    rawPlayer->play();

    // unique_ptr автоматично вивільняє пам'ять при виході з області видимості
    // shared_ptr автоматично вивільнює пам'ять, коли всі shared_ptr на цей об'єкт видаляються

    return 0;  // Повертаємо 0, що означає успішне завершення програми.
}
