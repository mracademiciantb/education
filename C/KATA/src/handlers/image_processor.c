#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct {
    float *data; // Нормалізовані пікселі зображення
    int width;
    int height;
    int channels;
} Image;

void saveImage(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb"); // Відкриття файлу для бінарного запису
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("Saving image data to file: %s\n", filename);

    // Запис розмірів зображення та каналів
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->channels, sizeof(int), 1, file);

    // Запис даних зображення
    fwrite(image->data, sizeof(float), image->width * image->height * image->channels, file);

    fclose(file); // Закриття файлу
    printf("Image data saved successfully.\n");
}

void processFirstImageInDirectory(const char* folderPath) {
    int width, height, channels;
    DIR *dir;
    struct dirent *ent;
    char filePath[1024]; // Повний шлях до файлу

    // Відкриття директорії
    if ((dir = opendir(folderPath)) != NULL) {
        // Читання елементів (файлів/папок) в директорії
        while ((ent = readdir(dir)) != NULL) {
            // Пропускаємо '.' та '..'
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                // Формуємо повний шлях до файлу
                snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, ent->d_name);
                printf("File found: %s\n", filePath);

                // Завантаження зображення
                unsigned char *img = stbi_load(filePath, &width, &height, &channels, 0);
                if (img == NULL) {
                    printf("Error in loading the image: %s\n", stbi_failure_reason());
                    closedir(dir); // Не забудьте закрити директорію
                    return;
                }

                printf("Loaded image with a width of %d px, a height of %d px and %d channels\n", width, height, channels);

                // Алокуємо пам'ять для збереження нормалізованих пікселів
                Image image;
                image.width = width;
                image.height = height;
                image.channels = channels;
                image.data = (float *)malloc(width * height * channels * sizeof(float));

                // Нормалізація і збереження пікселів зображення
                for (int i = 0; i < width * height * channels; i++) {
                    image.data[i] = img[i] / 255.0f;
                }

                // Збереження обробленого зображення в файл
                saveImage("saved_image.bin", &image);

                // Пам'ять, виділена для зображення, повинна бути звільнена
                stbi_image_free(img);
                free(image.data);

                break; // Закінчуємо цикл після завантаження першого знайденого зображення
            }
        }
        closedir(dir);
    } else {
        // Не вдалося відкрити директорію
        perror("Failed to open directory");
    }
}
