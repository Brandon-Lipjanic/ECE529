#pragma once
void filter(float* b, int M, float* a, int N, float* x, int L, float* y);
void conv(float* x, int L, float* h, int M, float*y);