/*
Name:Alex Maingi Mwendwa
Reg no:CT101/G/26482/25
*/
#include <stdio.h>

// 1. Write a function to input 10 integers and store them in "input.txt"
void write_integers_to_file() {
    FILE *file_ptr;
    int number;
    
    // Open file for writing ("w") - creates or overwrites
    file_ptr = fopen("input.txt", "w"); 

    if (file_ptr == NULL) {
        
        // 4. Error Handling
        ("Error opening input.txt for writing");
        return; 
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        // Use scanf to read from the user (keyboard)
        if (scanf("%d", &number) != 1) {
            printf("Invalid input. Skipping to next.\n");
            // Clear input buffer for robust handling
            while (getchar() != '\n');
            number = 0; // Store 0 if input is invalid
        }
        // Use fprintf to write to the file
        fprintf(file_ptr, "%d\n", number);
    }

    fclose(file_ptr);
    printf("\nSuccessfully wrote 10 integers to 'input.txt'.\n");
}

// 2. Write a function to read, calculate sum/average, and write results to "output.txt"
void process_file_and_write_results() {
    FILE *input_file, *output_file;
    int number;
    int sum = 0;
    int count = 0;
    double average = 0.0;

    // 4. Error Handling: Open "input.txt" for reading ("r")
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        ("Error opening input.txt for reading");
        return;
    }

    // Read integers from "input.txt"
    // The loop continues as long as fscanf successfully reads an integer (returns 1)
    while (fscanf(input_file, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    
    fclose(input_file);

    // Calculate average
    if (count > 0) {
        average = (double)sum / count;
    }

    // 4. Error Handling: Open "output.txt" for writing ("w")
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output.txt for writing");
        return;
    }

    // Write sum and average to "output.txt"
    fprintf(output_file, "Sum of the numbers: %d\n", sum);
    fprintf(output_file, "Average of the numbers: %.2lf\n", average);

    fclose(output_file);
    printf("Successfully calculated sum/average and wrote results to 'output.txt'.\n");
}

// 3. Write a function to read and display the contents of both files
void display_file_contents(const char *filename) {
    FILE *file_ptr;
    char buffer[256]; // Buffer to hold one line of the file

    printf("\n--- Contents of %s ---\n", filename);

    // 4. Error Handling: Open file for reading ("r")
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        ("Error opening file for display");
        return;
    }

    // Read and print line by line
    // The loop continues as long as fgets successfully reads a line (not NULL)
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        printf("%s", buffer);
    }
    
    // Check for potential reading errors (beyond EOF)
    if (ferror(file_ptr)) {
        printf("An error occurred while reading %s.\n", filename);
    }

    fclose(file_ptr);
    printf("---------------------------\n");
}

int main() {
    // 1. Input and write
    write_integers_to_file();

    // 2. Process and write results
    process_file_and_write_results();

    // 3. Display contents
    display_file_contents("input.txt");
    display_file_contents("output.txt");

    return 0;
}
