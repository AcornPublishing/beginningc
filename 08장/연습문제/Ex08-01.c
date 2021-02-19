/* �������� 8.1 ����� ����ϴ� �Լ� */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double average(double data[], int count)
{
  int i = 0;
  double sum = 0.0;
  for( i = 0 ; i<count ; sum += data[i++])
    ;
  return sum/count;
}

#define CAPACITY_INCREMENT 6  /* ������ ���� ������ �뷮�� ������ */

void main()
{
   double *data = NULL;       /* �������� �迭�� ����Ű�� ������  */
   double *newdata = NULL;    /* �� ������ �迭�� ����Ű�� ������ */
   double *averages = NULL;   /* ����� �迭�� ����Ű�� ������    */
   int count = 0;             /* �������� ����                    */
   int capacity = 0;          /* ������ �� �ִ� �������� ����     */
   int i = 0;                 /* ���� ���� ����                   */
   char answer = 'n';

   do
   {
     if(count == capacity)
     {
       capacity += CAPACITY_INCREMENT;
       /* �� ������ �迭�� ���� */
       newdata = (double*)malloc(capacity*sizeof(double));
  
       if(data != NULL)
       {
         /* �� �迭�� ������ �� ���� */
         for(i = 0 ; i<count ; i++)
           *(newdata +i) = *(data+i);
         free(data);          /* ���� ������ �迭�� �޸𸮸� ���� */
       }
       data = newdata;        /* �� ������ �迭�� �ּҸ� ����     */
       newdata = NULL;        /* ������ �ʱ�ȭ                    */
     }

     printf("�����͸� �ϳ� �Է��ϼ���: ");
     scanf(" %lf", data+count++); 
     printf("�� �Է��Ͻðڽ��ϱ�(y/n)? ");
     scanf(" %c", &answer);
   } while(tolower(answer) != 'n');

   printf("\n�Է��Ͻ� �������� ����� %10.2lf�Դϴ�.\n", average(data, count));
   free(data);
}

