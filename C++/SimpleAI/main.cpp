#include <iostream>
#include </Users/mandalorian/local/include/eigen/Eigen/Dense>
#include "/Users/mandalorian/Dev/education/C++/2/csv-parser/csv.h"


int main() {
    /* Дані для навчання (приклад, замініть це реальними даними)
    Eigen::MatrixXd trainingData(5, 2);
    trainingData << 1, 2,
                    2, 3,
                    3, 4,
                    4, 5,
                    5, 6;

    // Розмітка (ціна наступного періоду, приклад)
    Eigen::VectorXd labels(5);
    labels << 3, 4, 5, 6, 7;

    // Одношарова нейромережа з одним виходом
    Eigen::MatrixXd weights(2, 1);
    weights << 0.5,
               0.5;

    Eigen::VectorXd biases(1);
    biases << 0.1;
*/

io::CSVReader<9> in("/Users/mandalorian/Dev/education/C++/2/quotes.csv"); 
    in.read_header(io::ignore_extra_column,
                   "Symbol", "Current Price", "Date", "Time", "Change",
                   "Open", "High", "Low", "Volume");

    std::string symbol, date, time;
    double currentPrice, change, open, high, low, volume;

    Eigen::MatrixXd trainingData(in.count_lines(), 2);
    Eigen::VectorXd labels(in.count_lines());

    int row = 0;
    while (in.read_row(symbol, currentPrice, date, time, change, open, high, low, volume)) {
        trainingData(row, 0) = currentPrice;
        trainingData(row, 1) = volume;
        // Виберіть, яку змінну використовувати як розмітку, наприклад, change або іншу.
        labels(row) = change;
        ++row;
    }

    // Навчання: простий градієнтний спуск
    double learningRate = 0.01;
    int epochs = 1000;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        // Forward pass
        Eigen::VectorXd predictions = trainingData * weights + biases.replicate(trainingData.rows(), 1);

        // Compute loss (mean squared error)
        Eigen::VectorXd errors = predictions - labels;
        double loss = errors.array().square().mean();

        // Backward pass
        Eigen::MatrixXd gradients = 2 * trainingData.transpose() * errors / labels.size();

        // Update weights and biases
        weights = weights - learningRate * gradients;
        biases = biases.array() - learningRate * errors.mean();
    }

    // Виведення прогнозу для нових даних
    Eigen::VectorXd newInput(2);
    newInput << 6, 7;
    double prediction = (newInput.transpose() * weights).value() + biases[0];

    std::cout << "Predicted Price: " << prediction << std::endl;

    return 0;
}
