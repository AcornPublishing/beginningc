/* ���α׷� 2.4 ������ ��� */ 
#include <stdio.h> 

void main() 
{ 	
	int Total_Pets; 									/* ��ü ������ ��	*/ 
	int Cats; 											/* ������� �� 		*/ 
	int Dogs; 											/* �������� �� 		*/ 
	int Ponies; 										/* �������� �� 		*/ 
	int Others; 										/* �� �� ������ ��	*/ 

	/* ������ ������ �� ���� */
	Cats = 2;
	Dogs = 1;
	Ponies = 1;
	Others = 46;

	/* ��ü ������ �� ��� */
	Total_Pets = Cats + Dogs + Ponies + Others;

	printf("������ ��� %d�����Դϴ�.", Total_Pets); 	/* ��� ���       */ 
} 
