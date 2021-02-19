/* �������� 12.2 ������ ���ڿ��� �������� �б� */
/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define BUFFER_SIZE 50

/* Global variables */
FILE *pInFile = NULL;                   /* �Է������� ���� ������ */
FILE *pOutFile = NULL;                  /* ��������� ���� ������ */
char *infilename = "C:\\myfile.txt";    /* ���� ������ �̸�       */
char *outfilename = "C:\\outfile.txt";  /* ����� ������ �̸�     */
char *buffer = NULL;
size_t buffer_size = BUFFER_SIZE;


void main()
{
  size_t str_length = 0;
  int str_count = 0;
  fpos_t *positions = NULL;
  int i = 0;

  buffer = (char*)malloc(buffer_size);            /* �ʱ� ���� ����� */

  if((pInFile = fopen(infilename, "r")) == NULL)  /* �Է� ���� ����   */
  {
    printf("%s�� �� �� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", infilename);
    abort();
  }

  /* ���ڿ��� � �ִ��� Ȯ�� */
  for(;;)
  {
    fread(&str_length, sizeof(size_t), 1, pInFile);  /* ���ڿ��� ���̸� ���� */
    if(feof(pInFile))                                /* ������ ���� �ٴٸ��� */
      break;                                         /* ����                 */

    /* ���۰� ����� ū�� �˻��ϰ� �ʿ��ϸ� ������Ŵ */
    if(str_length>buffer_size)
    {
      buffer_size = str_length+1;
      free(buffer);
      buffer = (char*)malloc(buffer_size);
    }
    fread(buffer, str_length, 1, pInFile);   /* ���ڿ� �б� */
    ++str_count;
  }
  printf("\nThere are %d strings in the input file.", str_count);

  /* ���� ���Ͽ� �ִ� �� ����� ������ġ�� �˾Ƴ�            */
  /* ���۴� ���� ���� �� ���ڿ��� ������ �� ������ŭ ū ���� */
  rewind(pInFile);
  positions = (fpos_t*)malloc(str_count*sizeof(fpos_t));  /* ������ġ�� ������ �迭 */
  for(i = 0 ; i<str_count ; i++)
  {
    fgetpos(pInFile, positions+i);                    /* ��ġ�� �˾Ƴ�      */
    fread(&str_length, sizeof(size_t), 1, pInFile);   /* ���ڿ� ���̸� ���� */
    fread(buffer, str_length, 1, pInFile);            /* ���ڿ��� ����      */
 }

  /* ������� ���� */
  if((pOutFile = fopen(outfilename, "w")) == NULL)
  {
    printf("%s�� �� �� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", outfilename);
    abort();
  }

  /* �Է����Ͽ��� ����� �������� �о� �� ���Ͽ� ��� */
  for(i = 0 ; i<str_count ; i++)
  {
    fsetpos(pInFile, positions+str_count-i-1);            /* ���� ��ġ ���� */
    fread(&str_length, sizeof(size_t), 1, pInFile);       /* ���� ���� �б� */
    fwrite(&str_length, sizeof(size_t), 1, pOutFile);     /* �� ���Ͽ� ��� */
    fread(buffer, str_length, 1, pInFile);                /* ���ڿ� �б�    */
    fwrite(buffer, str_length, 1, pOutFile);              /* �� ���Ͽ� ��� */
  }

  fclose(pInFile);                                        /* �Է����� �ݱ�  */
  fclose(pOutFile);                                       /* ������� �ݱ�  */
  printf("\n�� ���Ͽ� ����� �Ϸ��߽��ϴ�.\n");

  /* ��������� ���� ��� */
  if((pOutFile = fopen(outfilename, "r")) == NULL)        /* �� ���� ���� */
  {
    printf("%s�� �� �� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", outfilename);
    abort();
  }
  printf("\n�� ���Ͽ� �ִ� ���ڿ��� ������ �����ϴ�.");
  for(i = 0 ; i<str_count ; i++)
  {
    fread(&str_length, sizeof(size_t), 1, pOutFile);
    fread(buffer, str_length, 1, pOutFile);
    buffer[str_length] = '\0';
    printf("\n%s", buffer);
  }
  printf("\n");
  fclose(pOutFile);                                    /* ���� �ݱ� */

  /* �Ҵ��� �޸𸮸� ���� */
  if(buffer != NULL)
    free(buffer);
  if(positions != NULL)
    free(positions);
 }
