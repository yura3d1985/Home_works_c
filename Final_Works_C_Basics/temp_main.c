#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "temp_api.h"

#define SIZE 1000000

int main(int argc, char *argv[])
{
	int16_t year;
	int8_t month, month_aim, day, hour, minute; 
	int8_t temp, temp_min, temp_max;

	int month_statistics = -1;
	int year_statistics = -1;
		 
	float temp_average;

	char file_name[100];

	struct temp_sensor* temp_data = malloc(SIZE*sizeof(struct temp_sensor));

	if(!temp_data) 
	{
		printf("\n");
		printf("-------------------------------------------------------\n");
		printf("memory error\n");
		printf("-------------------------------------------------------\n");
		printf("\n");
		return 0;
	} 
// -------------------- обработка параметров командной строки -------------------- начало
	int result = 0;

	if (argc == 1)
	{
		printf("\n");
		printf("-------------------------------------------------------\n");
		printf("no parameters, for more information write parameter -h\n");
		printf("-------------------------------------------------------\n");
		printf("\n");
		return 0;
	}
	
	while ((result = getopt(argc,argv,"hf:m:")) != -1)
	{
		if (result == 'h')
		{
			printf("\n");
			printf("-------------------------------------------------------\n");
			printf("'-h' for help\n");
			printf("'-f file name' file with input temperature data\n");
			printf("'-m xx' statistic for xx mounth\n");
			printf("-------------------------------------------------------\n");
			printf("\n");
			if (argc == 2) return 0;
			else continue;
			
		}
		if (result == 'f')
		{
			sscanf(optarg,"%s", &file_name);
			year_statistics = 1;
			continue;
		}
		if (result == 'm')
		{
			if (year_statistics == -1)
			{
				printf("\n");
				printf("-------------------------------------------------------\n");
				printf("'-f file name' file with temperature data not specify\n");
				printf("-------------------------------------------------------\n");
				printf("\n");
				return 0;
			}
			else
			{
				sscanf(optarg, "%" SCNu8 , &month_aim);
				month_statistics = 1;
				continue;
			}
			
		}
		if (result == '?')
		{
			printf("\n");
			printf("-------------------------------------------------------\n");
			printf("input parameters error found! \n");
			printf("-------------------------------------------------------\n");
			printf("\n");
			return 0;
		}
	};
// -------------------- обработка параметров командной строки -------------------- конец

// ---------------------- считывание входных данных из файла --------------------- начало
	int i = 0, n = 0;
	uint32_t line_number = 1;
	signed char c_tmp, str_tmp[25] = {0};
	
	FILE *input_data;
	input_data = fopen(file_name, "r");

	printf("\n");
	printf("-------------------------------------------------------\n");
	
	if (input_data == NULL)
	{
		printf("open file error: file not found or name is incorrect\n");
		return 0;
	}

	
	do {
		if(((c_tmp = fgetc(input_data)) != '\n') && (c_tmp != EOF))
		{
			str_tmp[i] = c_tmp;
			i++;
		}
		else 
		{	
			n = sscanf(str_tmp, "%" SCNd16 ";" 
								"%" SCNd8  ";" 
								"%" SCNd8  ";" 
								"%" SCNd8  ";" 
								"%" SCNd8  ";" 
								"%" SCNd8, &year, &month, &day, &hour, &minute, &temp);

			if ((n<6) || (year   < 0)		|| (year   > 10000) 
					  || (month  < 0)		|| (month  > 12) 
					  || (day    < 0)		|| (day    > 31) 
					  || (hour   < 0)		|| (hour   > 24) 
					  || (minute < 0)		|| (minute > 60) 
					  || (temp   < -99)		|| (temp   > 99))
			{
				printf("ERROR FORMAT in line %d\t\t", line_number);
				printf("[%s]",str_tmp);
				printf("\t\tcorrect FORMAT [xxxx;xx;xx;xx;xx;+/-xx] 'x' - positive digits only\n");
				i = 0;
				memset(str_tmp, 0, sizeof(str_tmp));
			}
			else
			{
				AddRecord(temp_data, line_number-1, year, month, day, hour, minute, temp);	
				line_number++;
				i = 0;
				memset(str_tmp, 0, sizeof(str_tmp));
			}
		}
	} while (c_tmp != EOF);
	
	fclose (input_data);
// ---------------------- считывание входных данных из файла --------------------- конец

	uint16_t year_aim = temp_data[0].year; // если по ТЗ в файле данные только за один год
	
if (month_statistics == -1)
{
	printf("-------------------------------------------------------\n");
	printf("#\tYears\tMonth\tAverage T\tMin T\tMax T\n");
	for (month_aim = 1; month_aim <= 12; month_aim = month_aim + 1)
	{
		temp_average = Average_Month_temp(temp_data, line_number, year_aim, month_aim);
		temp_min = Min_Month_temp(temp_data, line_number, year_aim, month_aim);
		temp_max = Max_Month_temp(temp_data, line_number, year_aim, month_aim);
		printf("%" SCNd8"\t", month_aim);
		printf("%" SCNd16"\t" "%" SCNd8"\t" "%+2.2f\t\t" "%+" SCNd8"\t" "%+" SCNd8 "\n", year_aim, month_aim, temp_average, temp_min, temp_max);
	}	
	printf("-------------------------------------------------------\n");
	temp_average = Average_Year_temp(temp_data, line_number, year_aim);
	temp_min = Min_Year_temp(temp_data, line_number, year_aim);
	temp_max = Max_Year_temp(temp_data, line_number, year_aim);
	printf("Year statistic:   Avarage T = %+2.2f   " "Min T = %+" SCNd8"   " "Max T = %+" SCNd8 "\n",temp_average, temp_min, temp_max);
	printf("-------------------------------------------------------\n");
}
else
{
	temp_average = Average_Month_temp(temp_data, line_number, year_aim, month_aim);
	temp_min = Min_Month_temp(temp_data, line_number, year_aim, month_aim);
	temp_max = Max_Month_temp(temp_data, line_number, year_aim, month_aim);
	
	printf("-------------------------------------------------------\n");
	printf("#\tYears\tMonth\tAverage T\tMin T\tMax T\n");
	printf("1\t");
	printf("%" SCNd16"\t" "%" SCNd8"\t" "%+2.2f\t\t" "%+" SCNd8"\t" "%+" SCNd8 "\n", year_aim, month_aim, temp_average, temp_min, temp_max);
	printf("-------------------------------------------------------\n");
}
	free (temp_data);
	printf("\n");
	return 0;
}