// neural_network.h
#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <stddef.h> // Для використання size_t

// Структури
typedef struct {
    double *weights;
    double bias;
} Neuron;

typedef struct {
    Neuron *neurons;
    int numNeurons;
} Layer;

typedef struct {
    Layer *layers;
    int numLayers;
} NeuralNetwork;

// Функції
void initializeNetwork(NeuralNetwork *network, int numLayers, const int *neuronsPerLayer);
void freeNetwork(NeuralNetwork *network);
double feedforward(NeuralNetwork *network, const double *inputs, size_t inputCount);
void backpropagation(NeuralNetwork *network, const double *inputs, size_t inputCount, const double *expectedOutputs, size_t outputCount);

#endif // NEURAL_NETWORK_H
