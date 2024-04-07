#include "neural_network.h"
#include "image_processor.h"

int main() {
    const char* directoryPath = "/app/data";
    processFirstImageInDirectory(directoryPath);

    NeuralNetwork network;
    int layers[] = {3, 2, 1}; // Приклад: 3 нейрони на вхідному шарі, 2 - на прихованому, 1 - на вихідному
    initializeNetwork(&network, sizeof(layers) / sizeof(layers[0]), layers);

    // Тут можна виконати feedforward, backpropagation тощо

    freeNetwork(&network);
    return 0;
}
