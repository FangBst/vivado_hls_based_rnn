#ifndef LSTM_H_
#define LSTM_H_
#include"types.h"

void vectorProduct(
	const FDATA_T *weight_matrix,
	FDATA_T *input,
	int dim1,
	int dim2,
	FDATA_T *output);

void lstm_128(
	FDATA_T *input_feature_map,
	FDATA_T *hidden_state
);

void lstm_64(
	FDATA_T *input_feature_map,
	FDATA_T *hidden_state);

#endif
