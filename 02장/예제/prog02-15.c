/* ���α׷� 2.15 �Ѱ� �˾Ƴ��� */
#include <stdio.h>
#include <limits.h> 				/* �������� �Ѱ踦 �˷��ִ� ������� */
#include <float.h> 					/* �Ǽ����� �Ѱ踦 �˷��ִ� ������� */

void main() 
{ 
	printf("char�� ������ ������ �� �ִ� ���� %d���� %d���� �Դϴ�.", 
			CHAR_MIN, CHAR_MAX); 
	printf("\nunsigned char�� ������ ������ �� �ִ� ���� 0���� %u���� �Դϴ�.", 
			UCHAR_MAX); 
	printf("\nshort�� ������ ������ �� �ִ� ���� %d���� %d���� �Դϴ�.", 
			SHRT_MIN, SHRT_MAX); 
	printf("\nunsigned short�� ������ ������ �� �ִ� ���� 0���� %u���� �Դϴ�.", 
			USHRT_MAX); 
	printf("\nint�� ������ ������ �� �ִ� ���� %d���� %d���� �Դϴ�.", INT_MIN, INT_MAX); 
	printf("\nunsigned int�� ������ ������ �� �ִ� ���� 0 ���� %u���� �Դϴ�.", 
			UINT_MAX); 
	printf("\nlong�� ������ ������ �� �ִ� ���� %d���� %d���� �Դϴ�.", 
			LONG_MIN, LONG_MAX); 
	printf("\nunsigned long �� ������ ������ �� �ִ� ���� 0���� %u���� �Դϴ�.", 
			ULONG_MAX); 
		
	printf("\n\nfloat������ 0�� �ƴ� ���� ���� ����� ũ��� %.3e�Դϴ�.", 
			FLT_MIN); 
	printf("\nfloat������ ���� ū ���� %.3e�Դϴ�.", FLT_MAX); 
	printf("\ndouble������ 0�� �ƴ� ���� ���� ����� ũ��� %.3e�Դϴ�.", 
			DBL_MIN); 
	printf("\ndouble������ ���� ū ���� %.3e�Դϴ�.", DBL_MAX); 
	printf("\nlong double������ 0�� �ƴ� ���� ���� ����� ũ��� %.3e�Դϴ�.", 
			DBL_MIN); 
 
	printf("\nlong double������ ���� ū ���� %.3e�Դϴ�.\n", 
			DBL_MAX); 
} 
