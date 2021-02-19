/* ���α׷� 12.3 �����ִ� ���� I/O �غ��ϱ� */ 
#include <stdio.h> 
#include <stdlib.h>
void main() 
{ 
	long num1 = 234567L; 											/* �Է°� 				*/ 
	long num2 = 345123L; 
	long num3 = 789234L; 

	long num4 = 0L; 												/* ���Ͽ��� �о���� ��	*/
	long num5 = 0L;
	long num6 = 0L; 

	float fnum = 0.0f; 												/* ���Ͽ��� �о���� ��	*/ 
	int ival[6] = { 0 }; 											/* ���Ͽ��� �о���� ��	*/
	int i = 0; 														/* ���� ī���� 			*/ 
	FILE *pfile = NULL; 											/* ���� ������ 			*/ 
	char *filename = "C:\\myfile.txt";

	pfile = fopen(filename, "w"); 									/* ����� ���� ����� 	*/
	if(pfile == NULL)
	{
		printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename); 
		abort();
	}
	fprintf(pfile, "%6ld%6ld%6ld", num1, num2, num3); 				/* ���� ���� 		*/ 
	fclose(pfile); 													/* ���� �ݱ� 		*/ 
	printf("\n %6ld %6ld %6ld", num1, num2, num3);			 		/* ����� ���� ���	*/ 

	pfile = fopen(filename, "r"); 									/* ���� ���� ���� 	*/ 
	fscanf(pfile, "%6ld%6ld%6ld", &num4, &num5 ,&num6);				/* �ٽ� ���� ���� 	*/ 
	printf("\n %6ld %6ld %6ld", num4, num5, num6); 					/* ���� ���� ��� 	*/ 

	rewind(pfile); 													/* ������ ������ġ�� �̵� 	*/
	fscanf(pfile, "%2d%3d%3d%3d%2d%2d%3f", &ival[0], &ival[1],		/* �ٽ� ���� ����	*/
					&ival[2], &ival[3], &ival[4] , &ival[5], &fnum); 
	fclose(pfile); 													/* ������ �ݰ�			*/ 
	remove(filename); 												/* ������ ������ ����	*/ 

	/* ��� ��� */
	printf("\n");
	for( i = 0 ; i < 6 ; i++ )
		printf("%sival[%d] = %d", i == 4 ? "\n\t" : "\t", i, ival[i]); 
	printf("\nfnum = %f\n", fnum); 
} 
