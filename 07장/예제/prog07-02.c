/* ���α׷� 7.2 �������� ��ü */ 
#include <stdio.h> 

void main() 
{ 
	long num1 = 0; 
	long num2 = 0; 
	long *pnum = NULL; 

	pnum = &num1; 											/* num1�� �ּҸ� ������	*/
	*pnum = 2; 												/* num1�� ���� 2�� ����	*/
	++num2; 												/* num2�� 1 ���� 		*/
	num2 += *pnum; 											/* num2�� num1�� ���� 	*/

	pnum = &num2; 											/* num2�� �ּҸ� ������				*/
	++*pnum; 												/* num2�� ���� ���������� ������Ŵ	*/ 

	printf ("\nnum1 = %ld   num2 = %ld   *pnum = %ld   *pnum + num2 = %ld\n", 
					num1, num2, *pnum, *pnum + num2); 
} 

