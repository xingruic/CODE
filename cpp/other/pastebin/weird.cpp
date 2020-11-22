#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

	const double version = 0.0011;
	const double E = 2.71828182845904523536;
	const int cyclesi = 900000;
	const int training_inputs=1000;

	double training_set_inputs[training_inputs][3];
    double training_set_outputs[training_inputs];
	double SynapticWeight[4], new_situation[training_inputs][3];
	double i=1,j,l, Output5, DOToutput5, output,cool, indicator;
    double Boutput[training_inputs], BsigmoidPart[training_inputs], Bsigmoid_DerivativePart[training_inputs], BerrorPart[training_inputs], BadjustmentPart[training_inputs], BadjustSynapticWeight[4];
	int m,q,qq, create;


	//generate output values for the randomly generated training inputs
double outt(double (*array)[training_inputs][3], int b)
{
	double calc;


	// for now, the 'A.I.' only works with simple formula's like 12*x+3*y+8*z ;
      // it does not work with formulas like x^3-y^2+z etc need more neurons for that.
	calc =  20*(*array)[b][0] + 31*(*array)[b][1] + 4*(*array)[b][2];

        //avoid 0, major bug
		if (calc==0) { calc=1;  printf("\ntest\n");
					}


	return calc;
}


 int _tmain(int argc, _TCHAR* argv[])
{

	srand (time(NULL));

	//requested data
	new_situation[0][0]=55;new_situation[0][1]=3;new_situation[0][2]=68;

    	cool = outt(&new_situation,0);
	   printf("\n the output should be approx %.2f\n",cool);


	new_situation[0][0]= 1/(1 + exp(-(1/new_situation[0][0])));
	new_situation[0][1]= 1/(1 + exp(-(1/new_situation[0][1])));
	new_situation[0][2]= 1/(1 + exp(-(1/new_situation[0][2])));

	for (create = 0; create < training_inputs; create++) {

				bool redo=false;

				do
				{

				training_set_inputs[create][0]= (rand() % 100) + 1;
				training_set_inputs[create][1]= (rand() % 100) + 1;
				training_set_inputs[create][2]= (rand() % 100) + 1;


				training_set_outputs[create] = outt(&training_set_inputs, create);
				   if (training_set_outputs[create]==0) redo=true;


				}  while (redo==true);







			}




	for(auto& rows: training_set_inputs)
{
	for(auto& elem: rows)
	{
		elem =  1/(1 + exp(-(1/elem)));

	}
}


	for (auto& number : training_set_outputs)
	{
		number =  1/(1 + exp(-(1/number)));

	}










   printf("\n");
   for( m = 1; m <= 19; m++ ){


	SynapticWeight[1]=rand() % 2000/double(1000)-double(1);
	SynapticWeight[2]=rand() % 2000/double(1000)-double(1);
	SynapticWeight[3]=rand() % 2000/double(1000)-double(1);


    //avoid 0, bugfix
	if (SynapticWeight[1]==0) {  SynapticWeight[1]=0.001; }
	if (SynapticWeight[2]==0) {  SynapticWeight[2]=0.001; }
	if (SynapticWeight[3]==0) {  SynapticWeight[3]=0.001; }

	printf("SynapticWeight[1]=%.2f , SynapticWeight[2]=%.2f, SynapticWeight[3]=%.2f\n\n", SynapticWeight[1], SynapticWeight[2], SynapticWeight[3]);


	//eternal loop
	// the number(output) will usually go up from 20, to reach 700.000+ within 5 to 10 minutes
	// then it will crash back down to the approximate(plus or minus 10% :| ) to_be calculated value, in this case around 1465
            //increasing the cycles/per step or the nr of traininginputs should improve that.
	while (i++) {


        for( q = 1; q <= training_inputs; q++) {

        Boutput[q] = training_set_inputs[q-1][0]*SynapticWeight[1]+training_set_inputs[q-1][1]*SynapticWeight[2]+training_set_inputs[q-1][2]*SynapticWeight[3];

        BsigmoidPart[q] = 1 / (1 + exp(-(Boutput[q])));

        Bsigmoid_DerivativePart[q] = BsigmoidPart[q] * (1 - BsigmoidPart[q]);

        BerrorPart[q] = (training_set_outputs[q-1] - BsigmoidPart[q]);

        BadjustmentPart[q] =  BerrorPart[q] * Bsigmoid_DerivativePart[q];

        }


		for( q = 1; q <= 3; q++) {

			BadjustSynapticWeight[q]=0;
			for( qq = 1; qq <= training_inputs; qq++) {  BadjustSynapticWeight[q] += (training_set_inputs[qq-1][q-1]*BadjustmentPart[qq])/(cyclesi/(pow(14,0.5)));}
										// the dividing is done, bc of the thing will bug out if too many value is added.  so a subtler addition.


		SynapticWeight[q]=SynapticWeight[q]+BadjustSynapticWeight[q];

		}

		if ((floor(i/cyclesi*100))!=indicator)
				{

					printf("Step %.0f ",indicator); printf("S1:%.16f S2:%.16f S3:%.16f\n",SynapticWeight[1], SynapticWeight[2], SynapticWeight[3]);

	Output5=new_situation[0][0]*SynapticWeight[1]+new_situation[0][1]*SynapticWeight[2]+new_situation[0][2]*SynapticWeight[3];

	DOToutput5 = 1 / (1 + exp(-(Output5)));


	output = 1 / DOToutput5;
	output = output - 1;
	output = log10(exp(1))/log10(output);
	output = abs(output);


	printf("\nBetweenvalues (%.0d training-inputs, %d iterations) has output %.2f  (%.2f)\n",training_inputs, cyclesi, output,cool);
				}



		indicator = floor(i/cyclesi*100);


	}






    Output5=new_situation[0][0]*SynapticWeight[1]+new_situation[0][1]*SynapticWeight[2]+new_situation[0][2]*SynapticWeight[3];

	DOToutput5 = 1 / (1 + exp(-(Output5)));


	output = 1 / DOToutput5;
	output = output - 1;
	output = log10(exp(1))/log10(output);
	output = abs(output);


	printf("\n Final Values (%.0d inputs, %d iterations) has output %.2f\n",training_inputs, cyclesi, output);
   } //m










    cout << "\n\nPress enter to exit..." << endl;
    cin.get();





    return 0;
}