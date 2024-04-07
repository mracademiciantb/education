#include "handlers/neural_network.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Для функції exp()



// Допоміжна функція для ініціалізації ваг та зсувів
void initializeWeightsAndBiases(NeuralNetwork *network) {
    for (int l = 0; l < network->numLayers; l++) {
        for (int n = 0; n < network->layers[l].numNeurons; n++) {
            network->layers[l].neurons[n].bias = (double)rand() / RAND_MAX * 2.0 - 1.0; // Випадкові значення від -1 до 1
            for (int w = 0; w < ((l == 0) ? 1 : network->layers[l-1].numNeurons); w++) {
                network->layers[l].neurons[n].weights[w] = (double)rand() / RAND_MAX * 2.0 - 1.0; // Випадкові значення
            }
        }
    }
}

void initializeNetwork(NeuralNetwork *network, int numLayers, const int *neuronsPerLayer) {
    network->numLayers = numLayers;
    network->layers = (Layer *)malloc(sizeof(Layer) * numLayers);

    for (int i = 0; i < numLayers; i++) {
        network->layers[i].numNeurons = neuronsPerLayer[i];
        network->layers[i].neurons = (Neuron *)malloc(sizeof(Neuron) * neuronsPerLayer[i]);
        
        for (int j = 0; j < neuronsPerLayer[i]; j++) {
            network->layers[i].neurons[j].weights = (double *)malloc(sizeof(double) * ((i == 0) ? 1 : neuronsPerLayer[i-1]));
        }
    }
    
    initializeWeightsAndBiases(network);
}

void freeNetwork(NeuralNetwork *network) {
    for (int i = 0; i < network->numLayers; i++) {
        for (int j = 0; j < network->layers[i].numNeurons; j++) {
            free(network->layers[i].neurons[j].weights);
        }
        free(network->layers[i].neurons);
    }
    free(network->layers);
}

// Активаційна функція (наприклад, сигмоїда)
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Пряме поширення
double feedforward(NeuralNetwork *network, const double *inputs, size_t inputCount) {
    double *outputs = NULL;
    double *previousLayerOutputs = (double *)malloc(sizeof(double) * inputCount);
    for (size_t i = 0; i < inputCount; i++) {
        previousLayerOutputs[i] = inputs[i]; // Ініціалізація вхідними даними
    }

    for (int l = 0; l < network->numLayers; l++) {
        Layer *layer = &network->layers[l];
        free(outputs); // Очищаємо пам'ять від попередніх виходів
        outputs = (double *)malloc(sizeof(double) * layer->numNeurons);
        for (int n = 0; n < layer->numNeurons; n++) {
            double activation = layer->neurons[n].bias;
            for (int w = 0; w < ((l == 0) ? inputCount : network->layers[l-1].numNeurons); w++) {
                activation += previousLayerOutputs[w] * layer->neurons[n].weights[w];
            }
            outputs[n] = sigmoid(activation); // Застосування активаційної функції
        }
        free(previousLayerOutputs); // Очищаємо пам'ять від попередніх виходів
        previousLayerOutputs = outputs; // Підготовка виходів для наступного шару
    }

    // Тут можна повернути виходи останнього шару або зробити додаткову обробку
    double finalOutput = outputs[0]; // Припустимо, що ми зацікавлені лише в одному виході
    free(outputs); // Не забудьте очистити пам'ять
    return finalOutput;
}
