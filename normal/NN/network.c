#include "network.h"

#include <stdio.h>
#include "layer.h"
#include "network_math.h"
#include "matrix_utils.h"

void process(network net, layer input){

  matrix_multiply(net.output_layer.values, input.rows, input.cols, input.values, net.l1.rows, net.l1.cols, net.l1.weights);

  for(int i = 0; i < net.output_layer.rows; i++){
    for(int j = 0; j < net.output_layer.cols; j++){
      net.output_layer.values[i][j] = sigmoid(net.output_layer.values[i][j]);
    }
  }

}

void train(network net, layer input, layer answers, int training_iterations){

  for(int i = 0; i < training_iterations; i++){

    //Run training sets through network
		process(net, input);

		//Adjust weight by error * input * output  * (1 - output)
    layer error_layer_1 = {.rows = answers.rows, answers.cols};
    initialize_double_pointer(&error_layer_1.values, error_layer_1.rows , error_layer_1.cols);
    matrix_subtract(error_layer_1.values, answers.values, net.output_layer.values, answers.rows, answers.cols);

    //TODO: pick up here! layer delta_layer_1 = scalar_multiply(error_layer_1)

    printf("answers\n");
    print_double_pointer(answers.values, answers.rows, answers.cols);
    printf("output_layer\n");
    print_double_pointer(net.output_layer.values, net.output_layer.rows, net.output_layer.cols);
    printf("error_layer_1\n");
    print_double_pointer(error_layer_1.values, error_layer_1.rows, error_layer_1.cols);

  }

}
