/*
*  _   _ _   _  ____    _    ____
* | \ | | | | |/ ___|  / \  |  _ \
* |  \| | | | | |     / _ \ | |_) |
* | |\  | |_| | |___ / ___ \|  _ <
* |_| \_|\___/ \____/_/   \_\_| \_\
*/

#include "functions.h"


char FILENAME[] = "../data/tumor.csv";

int main() {
   float **input_data;
   int *ground_truth;
   allocate_matrix_and_vector(input_data, ground_truth);
   read_data(FILENAME, input_data, ground_truth);

   return 0;
}


