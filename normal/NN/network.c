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

    //Create error layer (answers - output) = error
    layer error_layer_1 = {.rows = answers.rows, answers.cols};
    initialize_double_pointer(&error_layer_1.values, error_layer_1.rows , error_layer_1.cols);
    matrix_subtract(error_layer_1.values, answers.values, net.output_layer.values, answers.rows, answers.cols);

    //build sigmoid derivative applied output layer
    layer sd_output_layer = {.rows = net.output_layer.rows, .cols = net.output_layer.cols};
    initialize_double_pointer(&sd_output_layer.values, sd_output_layer.rows, sd_output_layer.cols);

    //Apply every value to function sigmoid_derivative
    for(int i = 0; i < sd_output_layer.rows; i++){
      for (int j = 0; j < sd_output_layer.cols; j++) {
        sd_output_layer.values[i][j] = sigmoid_derivative(net.output_layer.values[i][j]);
      }
    }

    //This layer describes how much the weights sould be adjusted by
    layer delta_layer_1 = {.rows = sd_output_layer.rows, .cols = error_layer_1.cols};
    initialize_double_pointer(&delta_layer_1.values, delta_layer_1.rows, delta_layer_1.cols);
    scalar_multiply(delta_layer_1.values, error_layer_1.rows, error_layer_1.cols, error_layer_1.values, sd_output_layer.rows, sd_output_layer.cols, sd_output_layer.values);

    //Created transposed version of input matrix

    layer transposed_input = {.rows = input.cols, .cols = input.rows};
    initialize_double_pointer(&transposed_input.values, transposed_input.rows, transposed_input.cols);
    matrix_transpose_new(transposed_input.values, transposed_input.rows, transposed_input.cols, input.values);
      //r1 c2
    layer adjustment_layer_1 = {.rows = transposed_input.rows, .cols = delta_layer_1.cols};
    initialize_double_pointer(&adjustment_layer_1.values, adjustment_layer_1.rows, adjustment_layer_1.cols);
    matrix_multiply(adjustment_layer_1.values, transposed_input.rows, transposed_input.cols, transposed_input.values, delta_layer_1.rows, delta_layer_1.cols, delta_layer_1.values);

    //Apply adjustment
    for(int i = 0; i < net.l1.rows; i++){
      for(int j = 0; j < net.l1.cols; j++){
        net.l1.weights[i][j] += adjustment_layer_1.values[i][j];
      }
    }

    if(i%100 == 0){

      printf("%d/%d\n", i, training_iterations);
    }
    /*
    if(i>9998){
      printf("\nweights\n");
      print_double_pointer(net.l1.weights, net.l1.rows, net.l1.cols);
      printf("answers\n");
      print_double_pointer(answers.values, answers.rows, answers.cols);
      printf("output_layer\n");
      print_double_pointer(net.output_layer.values, net.output_layer.rows, net.output_layer.cols);
      printf("error_layer_1\n");
      print_double_pointer(error_layer_1.values, error_layer_1.rows, error_layer_1.cols);
      //printf("sd_output_layer\n");
      //print_double_pointer(sd_output_layer.values, sd_output_layer.rows, sd_output_layer.cols);
      printf("delta_layer_1\n");
      print_double_pointer(delta_layer_1.values, delta_layer_1.rows, delta_layer_1.cols);
      printf("transposed_input\n");
      print_double_pointer(transposed_input.values, transposed_input.rows, transposed_input.cols);
      printf("adjustment_layer_1\n");
      print_double_pointer(adjustment_layer_1.values, adjustment_layer_1.rows, adjustment_layer_1.cols);
    }
    */
  }

}
