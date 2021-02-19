/* �������� 7.4 ������ ��� �Է°� ó�� */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DAYS             2        /* �Է°����� �ִ� �ϼ��� �ʱⰪ */
#define READINGS_PER_DAY 6        /* 1�� �µ� ���� ȸ��            */

void main()
{
   double **data = NULL;     /* �µ� �迭�� ����Ű�� �������� �迭�� ����Ű�� ������ */
   double **newdata = NULL;  /* �µ� �迭�� ����Ű�� �������� �迭�� ����Ű�� ������ */
   double *averages = NULL;  /* ��� �迭�� ����Ű�� ������ */
   int i = 0;
   int j = 0;
   int day = 0;
   int max_days = 0;
   char answer = 'n';

   do
   {
     if(day == max_days)
     {
       max_days += DAYS;
       /* �� ������ �迭�� ���� */
       newdata = (double**)malloc(max_days*sizeof(double*));
       /* ���ο� ���� ����� ������ double�� �迭�� ����� �ּҸ� ���� */
       for(i = day ; i<max_days ; i++)
         *(newdata+i) = (double*)malloc(READINGS_PER_DAY*sizeof(double));
       if(data != NULL)
       {
         /* ���� �µ� �迭�� �ּҸ� ���� */
         for(i = 0 ; i<day ; i++)
           *(newdata +i) = *(data+i);
         free(data);          /* ���� ������ �迭�� �޸𸮸� ���� */
       }
       data = newdata;        /* �� ������ �迭�� �ּҸ� ���� */
       newdata = NULL;        /* ������ �ʱ�ȭ                */
     }

     printf("�Ϸ��� �µ� ��� %d���� �Է��ϼ���:\n", READINGS_PER_DAY);
     for(i = 0 ; i<READINGS_PER_DAY ; i++)
       scanf(" %lf", *(data+day)+i); 
     ++day;
     printf("�ٸ� ���� ��ϵ� �Է��Ͻðڽ��ϱ�(y/n)? ");
     scanf(" %c", &answer);
   } while(tolower(answer) != 'n');

   /* �µ� ���� �������� ���� �޸𸮴� ���� */
   for(i = day ; i<max_days ; i++)
     free(*(data+i));

   /* ����� ������ �޸� �Ҵ� */
   averages = (double*)malloc(day*sizeof(double));

   /* ��� ��� */
   for(i = 0 ; i<day ; i++)
   {
     *(averages+i) = 0.0;
     for(j = 0 ; j<READINGS_PER_DAY ; j++)
       *(averages+i) += *(*(data+i)+j);
     *(averages+i) /= READINGS_PER_DAY;
   }
   printf("\n�Է��Ͻ� ���� ��°� ��ձ���� ������ �����ϴ�.\n");
   for(i = 0 ; i<day ; i++)
   {
     for(j = 0 ; j<READINGS_PER_DAY ; j++)
       printf("%10.1lf", *(*(data+i)+j));
     printf("%10.1lf\n", *(averages+i));
   }
   /* ��� �޸� ���� */
   free(averages);
   for(i = 0 ; i<day ; i++)
     free(*(data+i));
   free(data);
}

