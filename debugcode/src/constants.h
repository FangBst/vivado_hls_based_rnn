#include "types.h"


#define FC_INPUT_SIZE1 64
#define FC_OUTPUT_SIZE1 16


#define FC_INPUT_SIZE2 16
#define FC_OUTPUT_SIZE2 1

extern const FDATA_T fc_kernel_1[FC_OUTPUT_SIZE1*FC_INPUT_SIZE1];
extern const FDATA_T fc_bias_1[FC_OUTPUT_SIZE1];
extern FDATA_T fc_output_feature_map_1[FC_OUTPUT_SIZE1];

extern const FDATA_T fc_kernel_2[FC_INPUT_SIZE2];
extern const FDATA_T fc_bias_2;
extern FDATA_T fc_output_feature_map_2;

#define LSTM_BATCH_SIZE1 5
#define LSTM_INPUT_SIZE1 4
#define LSTM_OUTPUT_SIZE1 128

#define LSTM_BATCH_SIZE2 5
#define LSTM_INPUT_SIZE2 128
#define LSTM_OUTPUT_SIZE2 64

extern FDATA_T lstm_input_feature_map_1[LSTM_BATCH_SIZE1*LSTM_INPUT_SIZE1];
extern FDATA_T lstm_prev_hidden_1[LSTM_OUTPUT_SIZE1];
extern FDATA_T lstm_prev_memory_1[LSTM_OUTPUT_SIZE1];
extern FDATA_T lstm_memory_1[LSTM_OUTPUT_SIZE1];
extern FDATA_T lstm_hidden_1[LSTM_BATCH_SIZE1*LSTM_OUTPUT_SIZE1];
extern const FDATA_T lstm_weight_i_1[LSTM_OUTPUT_SIZE1*(LSTM_INPUT_SIZE1 + LSTM_OUTPUT_SIZE1)];
extern const FDATA_T lstm_weight_f_1[LSTM_OUTPUT_SIZE1*(LSTM_INPUT_SIZE1 + LSTM_OUTPUT_SIZE1)];
extern const FDATA_T lstm_weight_o_1[LSTM_OUTPUT_SIZE1*(LSTM_INPUT_SIZE1 + LSTM_OUTPUT_SIZE1)];
extern const FDATA_T lstm_weight_c_1[LSTM_OUTPUT_SIZE1*(LSTM_INPUT_SIZE1 + LSTM_OUTPUT_SIZE1)];
extern const FDATA_T lstm_bias_i_1[LSTM_OUTPUT_SIZE1];
extern const FDATA_T lstm_bias_f_1[LSTM_OUTPUT_SIZE1];
extern const FDATA_T lstm_bias_o_1[LSTM_OUTPUT_SIZE1];
extern const FDATA_T lstm_bias_c_1[LSTM_OUTPUT_SIZE1];

extern FDATA_T lstm_input_feature_map_2[LSTM_BATCH_SIZE2*LSTM_INPUT_SIZE2];
extern FDATA_T lstm_prev_hidden_2[LSTM_OUTPUT_SIZE2];
extern FDATA_T lstm_prev_memory_2[LSTM_OUTPUT_SIZE2];
extern FDATA_T lstm_memory_2[LSTM_OUTPUT_SIZE2];
extern FDATA_T lstm_hidden_2[LSTM_BATCH_SIZE2*LSTM_OUTPUT_SIZE2];
extern const FDATA_T lstm_weight_i_2[LSTM_OUTPUT_SIZE2*(LSTM_INPUT_SIZE2 + LSTM_OUTPUT_SIZE2)];
extern const FDATA_T lstm_weight_f_2[LSTM_OUTPUT_SIZE2*(LSTM_INPUT_SIZE2 + LSTM_OUTPUT_SIZE2)];
extern const FDATA_T lstm_weight_o_2[LSTM_OUTPUT_SIZE2*(LSTM_INPUT_SIZE2 + LSTM_OUTPUT_SIZE2)];
extern const FDATA_T lstm_weight_c_2[LSTM_OUTPUT_SIZE2*(LSTM_INPUT_SIZE2 + LSTM_OUTPUT_SIZE2)];
extern const FDATA_T lstm_bias_i_2[LSTM_OUTPUT_SIZE2];
extern const FDATA_T lstm_bias_f_2[LSTM_OUTPUT_SIZE2];
extern const FDATA_T lstm_bias_o_2[LSTM_OUTPUT_SIZE2];
extern const FDATA_T lstm_bias_c_2[LSTM_OUTPUT_SIZE2];

#define TEST_DATA_SIZE 1361
#define TEST_DATA_DIM 4
#define TEST_DATA_STEP 5

extern const FDATA_T test_data_output[TEST_DATA_SIZE];
extern const FDATA_T test_data_input[TEST_DATA_SIZE*TEST_DATA_STEP*TEST_DATA_DIM];