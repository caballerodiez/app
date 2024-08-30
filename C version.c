/* TEST.c (12_08_2024)*/
 
#include <stdio.h>

int x, frequency[35], i, num, N, choose[35];
int ind_date, day, month, year;
double risk[35], SUM_FREQUENCIES, PROB, JD;
long DATE;
int I, J, K, L, N, YEAR, MONTH, DAY;

/* ***************************************************** */

main()
{
	//	RISKS OF INDICATORS AND FREQUENCIES OF DATABASE

	/****** Risk values are assigned to each of the 34 indicators ******/

	for (i=1; i<=7; i++)	risk[i] = 1;
	for (i=8; i<=23; i++)	risk[i] = 0.66;
	for (i=24; i<=34; i++)	risk[i] = 0.33;

	/****** Frequencies for each indicator are assigned ******/

	frequency[1] = 5; frequency[2] = 4; frequency[3] = 4; frequency[4] = 3; frequency[5] = 1; frequency[6] = 1; frequency[7] = 1; 
	frequency[8] = 20; frequency[9] = 12; frequency[10] = 12; frequency[11] = 12; frequency[12] = 11; frequency[13] = 9; frequency[14] = 9; 
	frequency[15] = 5; frequency[16] = 4; frequency[17] = 3; frequency[18] = 3; frequency[19] = 3; frequency[20] = 2; frequency[21] = 2; 
	frequency[22] = 2; frequency[23] = 1; frequency[24] = 29; frequency[25] = 17; frequency[26] = 15; frequency[27] = 6; frequency[28] = 3; 
	frequency[29] = 1; frequency[30] = 1; frequency[31] = 1; frequency[32] = 1; frequency[33] = 1; frequency[34] = 1; 

	/****** Printing of indicators, risks and frequencies on the screen ******/

		printf("\n\n INDICATOR                                                 Frequency\n");
		printf("\n*** HIGH RISK *********************************************************\n");
		printf("1 Criminal suspect                                                 %d   \n", frequency[1]);
		printf("2 Contacting authorities about their intentions                    %d\n", frequency[2]);
		printf("3 Engaging in conspiracy                                           %d   \n", frequency[3]);
		printf("4 Contact with homeland terrorist                                  %d   \n", frequency[4]);
		printf("5 Direction of a cell                                              %d   \n", frequency[5]);
		printf("6 Confesing cellmatess about intentions                            %d   \n", frequency[6]);
		printf("7 Confesing terror charges from another state                      %d   \n", frequency[7]);
		printf("*** INTERMEDIATE RISK *************************************************\n");
		printf("8 Violent criminal records                                         %d   \n", frequency[8]);
		printf("9 Travelling to war zone or region with insurrectional activity    %d   \n", frequency[9]);
		printf("10 Radical statements made public                                  %d   \n", frequency[10]);
		printf("11 Considered as a threat                                          %d   \n", frequency[11]);
		printf("12 Specific foreign intelligence warnings                          %d   \n", frequency[12]);
		printf("13 Membership of radical group                                     %d   \n", frequency[13]);
		printf("14 Sentences for terrorism                                         %d   \n", frequency[14]);
		printf("15 Terrorism recruitment or training for foreign conflict          %d   \n", frequency[15]);
		printf("16 Adopting salafist behaviours                                    %d   \n", frequency[16]);
		printf("17 Weaponry acquisition                                            %d   \n", frequency[17]);
		printf("18 Contact with foreign terrorist                                  %d   \n", frequency[18]);
		printf("19 Suicide attempt                                                 %d   \n", frequency[19]);
		printf("20 Participation in jihadist insurgency abroad                     %d   \n", frequency[20]);
		printf("21 Relative contacting authorities about their intentions          %d   \n", frequency[21]);
		printf("22 Threatening institutions                                        %d   \n", frequency[22]);
		printf("23 Relative is a terror suspect                                    %d   \n", frequency[23]);
		printf("*** LOW RISK **********************************************************\n");
		printf("24 Non-violent criminal records                                    %d   \n", frequency[24]);
		printf("25 Contact with another suspect                                    %d   \n", frequency[25]);
		printf("26 Psychiatric records                                             %d   \n", frequency[26]);
		printf("27 Dissemination of radical propaganda                             %d   \n", frequency[27]);
		printf("28 Search of radical websites                                      %d   \n", frequency[28]);
		printf("29 Membership of a gang                                            %d   \n", frequency[29]);
		printf("30 Terminal disease                                                %d   \n", frequency[30]);
		printf("31 Participation in a deradicalization programme                   %d   \n", frequency[31]);
		printf("32 Criminal links                                                  %d   \n", frequency[32]);
		printf("33 School bullying                                                 %d   \n", frequency[33]);
		printf("34 Travelling to many arab couontries                              %d   \n", frequency[34]);

	//	READING INPUT

	/****** Input from keyboard ******/

	printf ("\nNumber of indicators to be selected - click enter\n");
	scanf("%d", &x);
	num = x;
	printf ("Which ones? (only between 1 and 34) - click enter\n");

	for (i=1; i<=num; i++)
	{
		/****** Take integer from keyboard and assign it to variable x ******/
		scanf("%d", &x);    	

	    	/****** A variable (choose) is made for indicador x which takes value 1 if this is chosen, or 0 if not ******/
		choose[x] = 1;
	}

	/****** Take the latest indicator checking that the variable choose for that indicator is 1 ******/
	do
	{
		printf ("Enter date for the latest indicador\n");
		printf ("Indicator number  ");
		scanf("%d", &x);
		ind_date = x;
	}
	while (choose[ind_date] == 0);

	printf ("Enter day of month (1-31)  ");
	scanf("%d", &x);
	day = x;
	printf ("Enter month (1-12)  ");
	scanf("%d", &x);
	month = x;
	printf ("Enter year (e.g. 2015)  ");
	scanf("%d", &x);
	year = x;

	//	CALCULATION OF PROBABILITY OF RISK

	/****** Frequencies of the chosen indicators are added up ******/
	for (i=1; i<=34; i++)
	if (choose[i] == 1)		SUM_FREQUENCIES += frequency[i];

	/****** The probability of risk is obtained with the frquencies of all chosen indicators ******/
	for (i=1; i<=34; i++)
	if (choose[i] == 1)
	PROB += (frequency[i] / SUM_FREQUENCIES) * risk[i];

	// CALCULATION OF PROBABLE DATE

	/****** Transform the date in Julian calendar from https://aa.usno.navy.mil/faq/JD_formula and add 15 months (15 x 30 = 450 days) ******/
	K = day; 
	J = month;
	I = year;
	JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
	DATE = JD + 450;

	/****** Transform to Gregorian calendar from https://aa.usno.navy.mil/faq/JD_formula ******/
	L = DATE + 68569;
	N = 4*L/146097;
	L = L-(146097*N+3)/4;
	I = 4000*(L+1)/1461001;
	L = L-1461*I/4+31;
	J = 80*L/2447;
	K = L-2447*J/80;
	L = J/11;
	J = J+2-12*L;
	I = 100*(N-49)+I+L;

	YEAR = I;
	MONTH = J;
	DAY = K;
	
	// OUTPUT

	/****** Screen output of risk probability and probable date ******/
	printf ("\n\n*** PROGRAMME OUTPUT ***\n");
	printf ("\nProbability = %f\n", PROB * 100.0);
	if (MONTH == 1)	printf ("Probable date: January %d\n", YEAR);
	else if (MONTH == 2)	printf ("Probable date: February %d\n", YEAR);
	else if (MONTH == 3)	printf ("Probable date: March %d\n", YEAR);
	else if (MONTH == 4)	printf ("Probable date: April %d\n", YEAR);
	else if (MONTH == 5)	printf ("Probable date: May %d\n", YEAR);
	else if (MONTH == 6)	printf ("Probable date: June %d\n", YEAR);
	else if (MONTH == 7)	printf ("Probable date: July %d\n", YEAR);
	else if (MONTH == 8)	printf ("Probable date: August %d\n", YEAR);
	else if (MONTH == 9)	printf ("Probable date: September %d\n", YEAR);
	else if (MONTH == 10)	printf ("Probable date: October %d\n", YEAR);
	else if (MONTH == 11)	printf ("Probable date: November %d\n", YEAR);
	else if (MONTH == 12)	printf ("Probable date: December %d\n", YEAR);

	return(0);
}
