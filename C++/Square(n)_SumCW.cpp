#include <iostream>
#include <vector>

int square_sum(const std::vector<int>& numbers)
{
    int x = 0;
    for (int i = 0; i < numbers.size(); i++)
        x += numbers[i] * numbers[i];

    return x;
}

/*
shorter and more modern due to the use of a range cycle!!

    int ret=0;
    for (auto x:numbers) ret+=(x*x);
    return ret;

*/

int main()
{
    // Створюємо вектор з числами для прикладу
    std::vector<int> example_numbers = {1, 2, 3, 4, 5};

    // Викликаємо функцію square_sum та виводимо результат
    int result = square_sum(example_numbers);
    std::cout << "Sum of squares: " << result << std::endl;

    return 0;
}
