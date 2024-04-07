#include "handlers/neural_network.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Структура для нейрона
typedef struct {
    double weight; // Припустимо, маємо лише один вхід для спрощення
    double bias;
} Neuron;

// Структура для шару
typedef struct {
    Neuron* neurons;
    int numNeurons;
} Layer;

// Функція активації (сигмоїда)
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Ініціалізація нейрона
void initializeNeuron(Neuron* neuron) {
    neuron->weight = (double)rand() / RAND_MAX * 2.0 - 1.0; // Ваги в діапазоні [-1, 1]
    neuron->bias = (double)rand() / RAND_MAX * 2.0 - 1.0;
}

// Ініціалізація шару
void initializeLayer(Layer* layer, int numNeurons) {
    layer->neurons = (Neuron*)malloc(numNeurons * sizeof(Neuron));
    layer->numNeurons = numNeurons;
    for(int i = 0; i < numNeurons; i++) {
        initializeNeuron(&layer->neurons[i]);
    }
}

// Пряме поширення для шару
double feedforwardLayer(Layer* layer, double input) {
    double output = 0.0;
    for(int i = 0; i < layer->numNeurons; i++) {
        output += sigmoid(layer->neurons[i].weight * input + layer->neurons[i].bias);
    }
    return output / layer->numNeurons; // Повертаємо середнє значення виходів нейронів
}

int main() {
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    // Створення та ініціалізація шару
    Layer hiddenLayer;
    initializeLayer(&hiddenLayer, 5); // 5 нейронів у прихованому шарі

    // Тестування з фіктивним вхідним значенням
    double input = 0.5; // Припустимо, що це фіктивне вхідне значення
    double output = feedforwardLayer(&hiddenLayer, input);
    printf("Output: %f\n", output);

    // Очищення пам'яті
    free(hiddenLayer.neurons);

    return 0;
}
