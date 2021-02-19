/* �������� 7.2 �ݾ��� �Է¹޾� ���̼����� ����ϴ� �ڵ� */
/****************************************************************************
 * �� ���α׷��� ��� ������ �ݾ��� ��� �о���δ�.                  *
 * �Է¹����� ���̴� �ʱⰪ�� ������ ������ ��� �ڵ����� �����Ѵ�.         *
 * ���� ������ ���� ������ �� ���ۿ� ����ǰ�, ���� ���۴� �Է��� ����ϱ�  *
 * �ռ� �����ȴ�.                                                           *
 * ���� ������ �ݾ𿡵� ����ȴ�.�ݾ��� ����Ű�� �������� �ʱ�뷮�� �ʰ�   *
 * �ϸ� �� ū ������ �Ҵ�ǰ� ���� �����Ͱ� �� �޸𸮿� ����� �� ����      * 
 * �޸𸮰� �����ȴ�.                                                       *
 * �� �޸𸮰� �Ҵ�� �� printf()���� �̿��� �̸� ����� ���� ���� ���̴�.  *
 * BUFFER_LEN, BUFFER_LEN_INCR, CAPACITY_INCR���� �۰� ������ �����Ƿ�      *
 * ���� �޸𸮰� ���Ҵ�Ǿ� �������� �Է��� �޾Ƶ��� �� �ְ� �Ѵ�.          *
 * ���� ���α׷������� �̺��� �ξ� ū ������ ������ �ʹ� ����� �޸� �Ҵ� *
 * �� ������ �Ͼ�� ���ϰ� �� ���̴�.                                     *
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 5          /* �Է� ������ �ʱ� ���� */
#define BUFFER_LEN_INCR 2     /* ���� ������ ������    */
#define CAPACITY_INCR 2       /* �ݾ� �뷮�� ������    */

void main()
{
   char **pProverbs = NULL;        /* ���ڿ� �������� ������      */
   char **temp = NULL;             /* ���ڿ� �������� �ӽ� ������ */
   int capacity = 0;               /* ������ �� �ִ� �ݾ��� ����  */
   int count = 0;                  /* ���� �ݾ��� ����            */
   char *pbuffer = NULL;           /* ������ ������               */
   char *pstart = NULL;            /* ���� ������ġ�� ������      */
   char *pstr = NULL;              /* ���ڿ� ������               */
   int buffer_length = BUFFER_LEN; /* ���� ����                   */
   int i = 0;                      /* ���� ī����                 */
   int j = 0;                      /* ���� ī����                 */

   pbuffer = (char*)malloc(BUFFER_LEN);  /* �ʱ� ���� ũ��     */
   pstart = pbuffer;                     /* ���� ������ġ ���� */

   for(;;)
   {
     if(count==capacity)
     {
       capacity += CAPACITY_INCR;
       temp = (char**)malloc(capacity*sizeof(char*));
       if(temp == NULL)       /* �޸𸮰� �Ҵ���� �ʾ����� */
       {                      /* �޽����� ����ϰ� ����     */
         printf("Memory allocation failed. Terminating program.");
         exit(1);
       }
     
       if(pProverbs == NULL)  /* �ݾ��� �ϳ��� ���°�?                        */
         pProverbs = temp;    /* �ƴϿ� - �� �޸��� �ּҸ��� ���           */
       else                   /* �� - ���� �޸��� �����͸� �� �޸𸮷� ���� */
       {
         for(i = 0 ; i<count ; i++)
           *(temp+i) = *(pProverbs+i);
         free(pProverbs);     /* ���� �޸� ����      */
         pProverbs = temp;    /* �� �޸��� �ּ� ���� */
       } 
       temp = NULL;           /* ������ �ʱ�ȭ         */
     }
      printf("�ݾ��� �Է��ϼ���. �������� �׳� ���͸� ��������:\n");

     /* �ݾ� �Է� */
     while((*pbuffer++ = getchar()) != '\n')
     {
       if(pbuffer-pstart == buffer_length)     /* ���۰� ���� á���� �˻� */
       {
         buffer_length += BUFFER_LEN_INCR;     /* ���� ���� ����          */
         pstr = (char*)malloc(buffer_length);  /* �� ���� �Ҵ�            */

         /* ���� ������ ������ �� ���۷� ���� */
         for(i = 0; i<pbuffer-pstart ; i++)
           *(pstr+i) = *(pstart+i);

         pbuffer = pstr+(pbuffer-pstart);      /* �� ������ ���� �ּ� ���� */
         free(pstart);                         /* ���� ���� �޸� ����    */
         pstart = pstr;                        /* �� ������ ������ġ ����  */
         pstr = NULL;                          /* ������ �ʱ�ȭ            */
       }
     }

     /* �Է��� ���� �˸��� �� �� �˻� */
     if((pbuffer-pstart)<2)
       break;

     /* ���ڿ��� �ʹ� ���� ������ �˻� */
     if((pbuffer - pstart) == BUFFER_LEN && *(pbuffer-1)!= '\n')
     {
       printf("���ڿ��� �ʹ� ��ϴ�. �ִ� %d���ڱ��� �Է��� �� �ֽ��ϴ�.", BUFFER_LEN);
       pbuffer = pstart;
       continue;
     }
     *(pbuffer-1) = '\0';                  /* ���Ṯ�� ���� */
     pbuffer = pstart;

     *(pProverbs+count) = (char*)malloc(strlen(pstart)+1);
     strcpy(*(pProverbs+count++),pstart);
   }

   /* �ݾ��� ���� �������� ���� */
  for(i = 0 ; i<count-1 ; i++)
    for(j = i+1 ; j<count ; j++)
      if(strlen(*(pProverbs+i))>strlen(*(pProverbs+j)))
      {
        pstr = *(pProverbs+i);
        *(pProverbs+i) = *(pProverbs+j);
        *(pProverbs+j) = pstr;
      }

   /* ���ڿ� ��� */
   printf("\n�Է��Ͻ� ���ڿ��� ���̰� ª�� �ͺ��� ����մϴ�:\n");
   for (i = 0 ; i<count ; i++ )
   {
      printf("\n%s", *(pProverbs + i));
      free(*(pProverbs + i));   /* �ݾ��� ����� �޸� ���� */
      *(pProverbs + i) = NULL;  /* �����͸� �ٽ� NULL�� ���� */
   }
   free(pProverbs);             /* �����Ͱ� ����� �޸� ���� */
   free(pstart);                /* ���۰� ����� �޸� ����   */
}

