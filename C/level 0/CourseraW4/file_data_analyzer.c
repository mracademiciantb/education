#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    FILE *file = fopen("DataNumber.txt", "r");
    if(file == NULL) {
        printf("Error! File not found!\nDo you want to create it? (y/n): ");
        char want;
        // Clear input buffer
        while ((want = getchar()) != '\n' && want != EOF);
        scanf(" %c", &want);
        if(want == 'y' || want == 'Y') {
            file = fopen("DataNumber.txt", "w"); // Create file for writing
            if (file == NULL) {
                printf("Error creating file!\n");
                return 1;  
            }
            printf("Enter numbers to save in the file. The first number should indicate how many numbers will follow. Enter -1 to finish.\n");
            int num;
            while (1) {
                scanf("%d", &num);
                if (num == -1) break; // Criterion for completing the input
                fprintf(file, "%d ", num); // Write data in file
            }
            fclose(file); // Close file after writing
            printf("Data saved successfully. Please rerun the program.\n");
            return 0; // Exit to allow user to rerun the program
        } else {
            printf("Operation cancelled.\n");
            return 1; // Exit as user chose not to create file
        }
    }
    
    // Re-open the file for reading
    file = fopen("DataNumber.txt", "r");
    fscanf(file, "%d", &n);

    int *data = (int*)calloc(n, sizeof(int));
    if(data == NULL) {
        printf("Memory allocation failed\n");
        fclose(file); // Ensure file is closed before exiting
        return 1;
    }

    for(int i = 0; i < n; i++) {
        fscanf(file, "%d", &data[i]);
    }
    fclose(file); // Close file after reading

    int max = data[0];
    double sum = 0;
    for(int i = 0; i < n; i++) {
        if(data[i] > max) {
            max = data[i];
        }
        sum += data[i];
    }
    double awr = sum / n;

    printf("The greatest value: %d\n", max);
    printf("Average value: %.2f\n", awr);

    file = fopen("answer-hw3.txt", "w"); // Open file for writing the results
    fprintf(file, "The greatest value: %d\nAverage value: %.2f\n", max, awr);
    fclose(file); // Close file after writing
    printf("answer-hw3.txt saved successfully.\n");

    free(data);
    return 0;
}
