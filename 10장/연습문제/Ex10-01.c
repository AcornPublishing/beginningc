/* �������� 10.1 Ű���忡�� Ư�� ������ ���ڿ� �б� */
/*
���� 1: �ϳ� �̻��� ���ĺ� �ҹ��� ������ �ϳ��� ���ڰ� ������ ���ڿ� (��: number1) 
���� 2: �빮�ڷ� �����ϴ� 2���� �ܾ�. �� �ܾ�� ���������� ����� (��: Seven-Up) 
���� 3: 10���� (��: 7.35) 
���� 4: �빮��, �ҹ���, �����̽��� �̷��� ���ڿ� (��: East Hill)
���� 5: �����̽��� ���ڸ� ������ ��� ���ڷ� �̷��� ���ڿ� (��: floating-point)

�� ���ڿ��� ���� ���ڿ��� ���� ���ڷ� �����Ѵٴ� ���� Ȱ������. ���� �� ���ڿ���
���ڴ� �ڵ��� ������ ���ڿ��� ù��° ���ڰ� �ƴ��� �����ϸ� �ȴ�.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
   char word1[50];
   char word2[50];
   char word3[50];
   char word4[50];
   char word5[50];
   char temp[50];
   int k = 0;

   printf("5���� ���ڿ��� �Է��ϼ���:\n");

   /* ó������ �ҹ���, ���߿� ���ڰ� ������ ù��° ���ڿ� */
   k = scanf(" %[abcdefghijklmnopqrstuvwxyz]%1[0123456789]", word1, temp);
   if(k<2)
   {
     printf("ù��° ���ڿ����� ���� �߻� - ���α׷� ����\n");
     exit(1);
   }
   strcat(word1,temp);

   /* �ι�° ���ڿ�. �빮�ڰ� ������, �� �ڿ� ����, ������, �빮��, 
      ���ڰ� ����                                                
   */
   k = scanf(" %1[ABCDEFGHIJKLMNOPQRSTUVWXYZ]", word2);
   if(k<1)
   {
     printf("�ι�° ���ڿ����� ���� �߻� - ���α׷� ����\n");
     exit(1);
   }
   scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]", temp);
   strcat(word2,temp);
   k = scanf("%1[-]", temp);
   if(k<1)
   {
     printf("�ι�° ���ڿ����� ���� �߻� - ���α׷� ����\n");
     exit(1);
   }
   k = scanf(" %1[ABCDEFGHIJKLMNOPQRSTUVWXYZ]", temp);
   if(k<1)
   {
     printf("�ι�° ���ڿ����� ���� �߻� - ���α׷� ����\n");
     exit(1);
   }
   strcat(word2,temp);
   scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]", temp);
   strcat(word2,temp);

   /* ����° ���ڿ�. 10������ ���ڿ��� �о���δ�.*/
   k = scanf(" %[0123456789.-]", word3);
   if(k<1)
   {
     printf("����° ���ڿ����� ���� �߻� - ���α׷� ����\n");
     exit(1);
   }

   /* �׹�° ���ڿ� */
   scanf("%[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]", word4);
   if(k<1)
   {
     printf("�׹�° ���ڿ����� ���� �߻� - ���α׷� ����\n");
     exit(1);
   }

   /* �ټ���° ���ڿ�. �ٹٲ� ���ڴ� ���Խ�Ű�� �ȵ� */
   scanf(" %[^ 0123456789\n]", word5);

   printf("�Է��� ���ڿ��� ������ �����ϴ�.\n%s  %s  %s  %s  %s\n",
            word1, word2, word3, word4, word5);
}

