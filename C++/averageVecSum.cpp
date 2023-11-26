#include <iostream>
#include <vector>



#include <vector>
#include <numeric>

bool betterThanAverage(const std::vector<int>& classPoints, const int yourPoints) {
  return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0) < classPoints.size() * yourPoints;
}

/*
#include <vector>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {
   int sum = 0;
int aver = 0; 
  for (int i = 0; i < classPoints.size(); i++)
       sum += classPoints[i];
       aver = sum / classPoints.size();
      if(aver < yourPoints) {
        return true;
      }
      else {
        return false;
      }
}
*/

int main() {
    // Створюємо вектор балів класу
    std::vector<int> classPoints = {85, 90, 78, 92, 88};

    // Ваш бал
    int yourPoints = 88;

    // Викликаємо функцію та виводимо результат
    if (betterThanAverage(classPoints, yourPoints)) {
        std::cout << "Ви кращі за середній бал класу!\n";
    } else {
        std::cout << "Ваш бал не вищий за середній бал класу.\n";
    }

    return 0;
}