/*
*  _   _ _   _  ____    _    ____
* | \ | | | | |/ ___|  / \  |  _ \
* |  \| | | | | |     / _ \ | |_) |
* | |\  | |_| | |___ / ___ \|  _ <
* |_| \_|\___/ \____/_/   \_\_| \_\
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define DATAPOINTS 699
#define BUFFER_SIZE 5000
#define NUMBER_OF_FEATURES 9
#define GROUND_TRUTH_POSITION 10

// Function Declarations
int read_data(char *file_name, float **input_data, int *ground_truth);
void fill_single_datapoint(char *line_data, float **input_data, int *ground_truth, int line_iterator);
int allocate_matrix_and_vector(float **input_data, int *ground_truth);


int read_data(char *file_name, float **input_data, int *ground_truth) {
   FILE *file_obj = fopen ( file_name, "r" );

   if (file_obj == NULL) {
      printf("ERROR: Could not find file: %s.", file_name);
      return -1;
   }

   if (file_obj != NULL) {
      char *line_data;
      line_data = (char *) malloc(BUFFER_SIZE * sizeof(char));
      // Remove header
      fgets(line_data, sizeof line_data, file_obj);
      // Iterate over data.
      int line_iterator=0;
      while(fgets(line_data, sizeof line_data, file_obj)!= NULL) {
         printf("line_iterator: %d\n", line_iterator);
         fill_single_datapoint(line_data, input_data, ground_truth, line_iterator);
         line_iterator++;
      }
      fclose(file_obj);
   }

   return 0;
}

void fill_single_datapoint(char *line_data, float **input_data, int *ground_truth, int line_iterator) {
   printf("%s", line_data);
   char *cut_line;
   float float_data;
   // Remove ID
   cut_line = strtok (line_data, ",\n");
   // printf("%s\n", cut_line);
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      cut_line = strtok (NULL, ",\n");
      // printf("Test: %p\n", input_data);
      // input_data[i] = 500.0;
      // printf("%s\n", cut_line);
      float_data = atof(cut_line);
      printf("F_data: %f\n", float_data);
      input_data[line_iterator][i] = float_data;
   }
   cut_line = strtok (NULL, ",\n");
   printf("Truth String: %s\n", cut_line);
   ground_truth[line_iterator] = atoi(cut_line);
}

int allocate_matrix_and_vector(float **input_data, int *ground_truth) {
   input_data = (float **) malloc(DATAPOINTS * sizeof(float *));
    for (int index=0; index<DATAPOINTS; index++) {
       input_data[index] = malloc(NUMBER_OF_FEATURES * sizeof(float));
    }
    ground_truth = (int *) malloc(DATAPOINTS * sizeof(int));

    return 0;
}




#endif