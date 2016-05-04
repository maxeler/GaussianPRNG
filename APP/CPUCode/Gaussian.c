#include <stdlib.h> //qsort
#include <math.h>

#include "random_mt.h"
#include <limits.h>


#define N 1000000
double phi(double);
int compare_float(const void *a, const void *b);
extern max_file_t* Gaussian_init();


int main ()
{
	float* mt = malloc(N * sizeof(float*));
	if(mt == NULL)
	{
		fprintf(stderr, "Was not able to allocate enough memory");
		exit(-1);
	}


	//load maxfile onto DFE
	max_file_t    *maxfile = Gaussian_init();
	max_actions_t *actions = max_actions_init(maxfile, NULL);
	max_engine_t  *engine  = max_load(maxfile, "*");

	// set IO values
	max_set_ticks(actions, "GaussianKernel", N);
	max_queue_output(actions, "mt", mt, N * sizeof(float));
	random_mt_init(maxfile, actions, "GaussianKernel", "Gauss_mt", time(NULL));

	//run on DFE and clean up
	max_run(engine, actions);
	max_actions_free(actions);
	max_unload(engine);


	//estimate the mean and sigma of the random numbers
	double arithmeticMean = 0.0;
	for(int i = 0; i < N; i++)
	{
		arithmeticMean += mt[i];
	}
	arithmeticMean = arithmeticMean / N;

	double sigma = 0.0;
	for(int i = 0; i < N; i++)
	{
		sigma += (mt[i]-arithmeticMean) * (mt[i]-arithmeticMean);
	}
	sigma = sqrt(sigma / (N-1));// for Anderson Darling Test


	//Anderson Darling Test
	//sorted input data is expected
	qsort((void*) mt, N, 4, compare_float);

	//1. create standardized Y values
	double* Yval = malloc(N * sizeof(double));
	if(Yval == NULL)
	{
		fprintf(stderr, "Was not able to allocate enough memory");
		exit(-1);
	}

	for(int i=0; i<N; i++)
	{
		Yval[i] = (mt[i]-arithmeticMean) / sigma;
	}

	//2. calculate test value A_squared
	double sum = 0.0;
	double savePhi = 0.0;
	for(int i=1; i < N+1; i++)
	{
		savePhi = phi(Yval[i-1]);
		sum += (2*i - 1)*log(savePhi) + (2*(N-i) + 1)*log(1-savePhi);
	}
	double A_squared = -N - sum/N;

	//the hypothesis of having a standard normal distribution is rejected if A_squared
	//is above the critical value for a test with below Significance levels
	//Significance level 15% 	10% 	5% 		2.5% 	1%
	//A_squared			 0.576	0.656	0.787	0.918	1.092
	double critical_value = 1.092;


	free(mt);
	free(Yval);

	if (A_squared <= critical_value)
	{
		printf("Test Passed!\n");
		return 0;
	}
	else
	{
		printf("Not uniformly distributed!\n");
		return 1;
	}
}



int compare_float(const void *a, const void *b)
{
	if (*(float*)a < *(float*)b) return -1;
	if (*(float*)a > *(float*)b) return 1;
	if (*(float*)a == *(float*)b) return 0;
	return 0;
}

double phi(double value)
{
   return 0.5 * erfc(-value * M_SQRT1_2);
}

