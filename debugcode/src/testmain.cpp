#include<iostream>
#include"constants.h"
#include"top.h"
#include"fileOperator.h"
#include"testData.h"


FDATA_T resTmp[TEST_DATA_SIZE];
char filename[20] = "float_output";
FDATA_T fc_output_feature_map_2;
FDATA_T lstm_input_feature_map_1[LSTM_BATCH_SIZE1*LSTM_INPUT_SIZE1];
int main(){

	//build & inference
	for (int i = 0; i < TEST_DATA_SIZE; i++) {
		for (int j = 0; j < LSTM_BATCH_SIZE1; j++) {
			for (int k = 0; k < LSTM_INPUT_SIZE1; k++) {
				lstm_input_feature_map_1[j*LSTM_INPUT_SIZE1 + k] =
					test_data_input[(i*TEST_DATA_STEP + j)*TEST_DATA_DIM+k];
			}
		}
		
		top(lstm_input_feature_map_1, 
			lstm_hidden_1,
			lstm_hidden_2,
			fc_output_feature_map_2);

		resTmp[i] = fc_output_feature_map_2;
	}

	writeArrayIntoFile(filename, resTmp, TEST_DATA_SIZE);
    return 0;
}

