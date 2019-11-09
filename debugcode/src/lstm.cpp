#include"lstm.h"
#include"constants.h"
#include"activations.h"

void lstm_128(
	FDATA_T input_feature_map[LSTM_BATCH_SIZE1*LSTM_INPUT_SIZE1],
	FDATA_T hidden_state[LSTM_BATCH_SIZE1*LSTM_OUTPUT_SIZE1]
)
{
	FDATA_T computer_reg[LSTM_INPUT_SIZE1 + LSTM_OUTPUT_SIZE1];
	FDATA_T output_state_reg[LSTM_OUTPUT_SIZE1];
	FDATA_T it_state_reg[LSTM_OUTPUT_SIZE1];
	FDATA_T ft_state_reg[LSTM_OUTPUT_SIZE1];
	FDATA_T ot_state_reg[LSTM_OUTPUT_SIZE1];
	FDATA_T ct_state_reg[LSTM_OUTPUT_SIZE1];
	FDATA_T prev_memory[LSTM_OUTPUT_SIZE1] = { 0 };

	int computer_dim = LSTM_INPUT_SIZE1 + LSTM_OUTPUT_SIZE1;

	for (int batch_id = 0; batch_id < LSTM_BATCH_SIZE1; batch_id++) {
		
		for (int j = 0; j < LSTM_INPUT_SIZE1; j++) {
#pragma HLS PIPELINE
			computer_reg[j] =
				input_feature_map[batch_id*LSTM_INPUT_SIZE1 + j];
		}

		for (int j = 0; j < LSTM_OUTPUT_SIZE1; j++) {
			int offset = LSTM_INPUT_SIZE1 + j;
			if (batch_id == 0) {
				computer_reg[offset] = 0;
			}
			else {
				computer_reg[offset] =
					hidden_state[(batch_id - 1) * LSTM_OUTPUT_SIZE1 + j];
			}
		}

		vectorProduct(
			lstm_weight_i_1,
			computer_reg,
			LSTM_OUTPUT_SIZE1, 
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE1; i++) {
#pragma HLS PIPELINE
			it_state_reg[i] = m_sigmoid(output_state_reg[i] + lstm_bias_i_1[i]);
		}
		
		vectorProduct(
			lstm_weight_f_1,
			computer_reg,
			LSTM_OUTPUT_SIZE1,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE1; i++) {
#pragma HLS PIPELINE
			ft_state_reg[i] = m_sigmoid(output_state_reg[i] + lstm_bias_f_1[i]);
		}

		vectorProduct(
			lstm_weight_o_1,
			computer_reg,
			LSTM_OUTPUT_SIZE1,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE1; i++) {
#pragma HLS PIPELINE
			ot_state_reg[i] = m_sigmoid(output_state_reg[i] + lstm_bias_o_1[i]);
		}

		vectorProduct(
			lstm_weight_c_1,
			computer_reg,
			LSTM_OUTPUT_SIZE1,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE1; i++) {
#pragma HLS PIPELINE
			ct_state_reg[i] = m_tanh(output_state_reg[i] + lstm_bias_c_1[i]);
			ct_state_reg[i] =
				ft_state_reg[i] * prev_memory[i] + it_state_reg[i] * ct_state_reg[i];
		}

		for (int i = 0; i < LSTM_OUTPUT_SIZE1; i++) {
			hidden_state[batch_id*LSTM_OUTPUT_SIZE1 + i] =
				ot_state_reg[i] * m_tanh(ct_state_reg[i]);

			prev_memory[i] = ct_state_reg[i];
		}
	}
}
void lstm_64(
	FDATA_T input_feature_map[LSTM_BATCH_SIZE2*LSTM_INPUT_SIZE2],
	FDATA_T hidden_state[LSTM_OUTPUT_SIZE2])
{
	FDATA_T computer_reg[LSTM_INPUT_SIZE2 + LSTM_OUTPUT_SIZE2];
	FDATA_T output_state_reg[LSTM_OUTPUT_SIZE2];
	FDATA_T it_state_reg[LSTM_OUTPUT_SIZE2];
	FDATA_T ft_state_reg[LSTM_OUTPUT_SIZE2];
	FDATA_T ot_state_reg[LSTM_OUTPUT_SIZE2];
	FDATA_T ct_state_reg[LSTM_OUTPUT_SIZE2];
	FDATA_T prev_memory[LSTM_OUTPUT_SIZE2] = { 0 };
	FDATA_T hidden_reg[LSTM_OUTPUT_SIZE2] = { 0 };
	int computer_dim = LSTM_INPUT_SIZE2 + LSTM_OUTPUT_SIZE2;

	for (int batch_id = 0; batch_id < LSTM_BATCH_SIZE2; batch_id++) {

		for (int j = 0; j < LSTM_INPUT_SIZE2; j++) {
			computer_reg[j] =
				input_feature_map[batch_id*LSTM_INPUT_SIZE2 + j];
		}
		for (int j = 0; j < LSTM_OUTPUT_SIZE2; j++) {
			int offset = LSTM_INPUT_SIZE2 + j;
			if (batch_id == 0) {
				computer_reg[offset] = 0;
			}
			else {
				computer_reg[offset] =hidden_reg[j];
			}
		}

		vectorProduct(
			lstm_weight_i_2,
			computer_reg,
			LSTM_OUTPUT_SIZE2,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE2; i++) {
#pragma HLS PIPELINE
			it_state_reg[i] = m_sigmoid(output_state_reg[i] + lstm_bias_i_2[i]);
		}

		vectorProduct(
			lstm_weight_f_2,
			computer_reg,
			LSTM_OUTPUT_SIZE2,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE2; i++) {
#pragma HLS PIPELINE
			ft_state_reg[i] = m_sigmoid(output_state_reg[i] + lstm_bias_f_2[i]);
		}

		vectorProduct(
			lstm_weight_o_2,
			computer_reg,
			LSTM_OUTPUT_SIZE2,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE2; i++) {
#pragma HLS PIPELINE
			ot_state_reg[i] = m_sigmoid(output_state_reg[i] + lstm_bias_o_2[i]);
		}

		vectorProduct(
			lstm_weight_c_2,
			computer_reg,
			LSTM_OUTPUT_SIZE2,
			computer_dim,
			output_state_reg);
		for (int i = 0; i < LSTM_OUTPUT_SIZE2; i++) {
#pragma HLS PIPELINE
			ct_state_reg[i] = m_tanh(output_state_reg[i] + lstm_bias_c_2[i]);
			ct_state_reg[i] =
				ft_state_reg[i] * prev_memory[i] + it_state_reg[i] * ct_state_reg[i];
		}

		for (int i = 0; i < LSTM_OUTPUT_SIZE2; i++) {
			hidden_reg[i] =
				ot_state_reg[i] * m_tanh(ct_state_reg[i]);

			prev_memory[i] = ct_state_reg[i];
		}
	}

	for (int i = 0; i < LSTM_OUTPUT_SIZE2; i++) {
		hidden_state[i] = hidden_reg[i];
	}
}

void vectorProduct(
	const FDATA_T *weight_matrix,
	FDATA_T * input,
	int dim1,
	int dim2,
	FDATA_T * output)
{
	for (int i = 0; i < dim1; i++) {
		FDATA_T tmp = 0;
		for (int j = 0; j < dim2; j++) {
#pragma HLS PIPELINE
			tmp += (input[j] * weight_matrix[i*dim2 + j]);
		}
		output[i] = tmp;
	}
}
