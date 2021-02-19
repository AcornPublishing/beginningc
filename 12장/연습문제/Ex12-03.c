/* �������� 12.3 ���Ͽ� �̸��� ��ȭ��ȣ ��� */
/*
  �� ���α׷��� ������ ũ���� �迭�� ����� �̸��� ��ȭ��ȣ�� �̷��� PhoneRecord
  ����ü�� ����Ѵ�. �̷��� �ϸ� ���� �۾��� �ſ� ����������. ũ�Ⱑ ������������
  �� PhoneRecord ����ü�� �а� ���⸸ �ϸ� �Ǳ� �����̴�.

  �̸��� ��ȭ��ȣ�� �޸𸮸� �������� �Ҵ��ϰ� �ʹٸ� �̸�, ��ȭ��ȣ�� ���� 
  PhoneRecord ����ü�� ����ؾ� �Ѵ�. �׸��� ���Ͽ� �ִ� �� ������ �׸��� ���̵�
  ������ �ٽ� ���� �� ���̰� ��� �������� �˾ƾ� �Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_NAME_LENGTH  31
#define SECOND_NAME_LENGTH 51
#define NUMBER_LENGTH      21
#define TRUE                1
#define FALSE               0

/* �̸��� �����ϴ� ����ü */
struct Name
{
  char firstname[FIRST_NAME_LENGTH];
  char secondname[SECOND_NAME_LENGTH];
};

/* ��ȭ��ȣ�� �����ϴ� ����ü */
struct PhoneRecord
{
  struct Name name;
  char number[NUMBER_LENGTH];
};

/* �Լ����� */
struct PhoneRecord read_phonerecord();       /* Ű���忡�� �̸��� ��ȭ��ȣ�� �д� �Լ�        */               
struct Name read_name();                     /* Ű���忡�� �̸��� �д� �Լ�                   */
void list_records();                         /* ������ ��� ����� ����ϴ� �Լ�              */
void show_record(struct PhoneRecord record); /* ��ȭ��ȣ ��Ͽ��� �̸��� ��ȣ�� ����ϴ� �Լ� */

/* �������� */
FILE *pFile = NULL;                   /* ������� ������    */
char *filename = "C:\\records.bin";   /* ����� ������ �̸� */


void main()
{
  char answer = 'n';
  struct PhoneRecord record;
  int file_empty = TRUE;


  printf("��ȭ��ȣ ����� �Է��Ͻðڽ��ϱ�(y/n)?: ");
  scanf(" %c", &answer);
  if(tolower(answer) == 'y')
  {
    pFile = fopen(filename, "a+");           /* ����� ������ ����/����� */
    if(pFile == NULL)
    {
      printf("%s�� �� �� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
      abort();
    }

    /* Ű���忡�� ���� ������ ��ȭ��ȣ�� ���� */  
    do
    {
      record = read_phonerecord();                 /* �̸��� ��ȭ��ȣ �б� */  
      fwrite(&record, sizeof record, 1, pFile);

      printf("�� �Է��Ͻðڽ��ϱ�(y/n)?: ");
      scanf(" %c", &answer);
    }while(tolower(answer) == 'y');

    fclose(pFile);                                    /* ���� �ݱ� */ 
    printf("\n���� ����� �Ϸ��߽��ϴ�.");
  }
  printf("\n���Ͽ� ����� ����� ��� ����ұ��(y/n)? ");
    scanf(" %c", &answer);
  if(tolower(answer) == 'n')
    return;
  list_records();
 }

/* Ű���忡�� �̸��� ��ȣ�� �а� PhoneRecord ����ü�� ����� �Լ� */
struct PhoneRecord read_phonerecord()
{
  struct PhoneRecord record;    
  record.name = read_name();
  printf("Enter the number: ");
  scanf(" %[ 0123456789]",record.number);  /* �����̽��� ������ ��ȭ��ȣ �б� */
  return record;
}

/* Ű���忡�� �̸��� �а� Name ����ü�� ����� �Լ� */
struct Name read_name()
{
  struct Name name;
    printf("Enter a first name: ");
    scanf(" %s", &name.firstname);
    printf("Enter a second name: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* ���Ͽ� �ִ� ��� ��� ��� */
void list_records()
{
  struct PhoneRecord record;
  int file_empty = TRUE;    /* ������ ������� ��Ÿ���� �÷��� */

  if((pFile = fopen(filename, "r")) == NULL)   /* ���� ���� */      
  {
    printf("%s�� �� �� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }

  /* ������ ������ ��� */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);
    if(feof(pFile))
      break;
    file_empty = FALSE;          /* ����� �о����Ƿ� FALSE�� ���� */
    show_record(record);         /* ����� ���                    */
  }
  fclose(pFile);                 /* ���� �ݱ� */

  /* ����� �ִ��� �˻� */
  if(file_empty)
    printf("���Ͽ� �ƹ� ������ �����ϴ�.\n");
  else
    printf("\n");
}
/* ��ȭ��ȣ ��Ͽ��� �̸��� ��ȣ�� ����ϴ� �Լ� */
void show_record(struct PhoneRecord record)
{
  printf("\n%s %s   %s", record.name.firstname, record.name.secondname, record.number);
}
