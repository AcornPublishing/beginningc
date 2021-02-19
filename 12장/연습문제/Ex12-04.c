/* �������� 12.4 ���Ͽ� �̸��� ��ȭ��ȣ ��� */
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
struct PhoneRecord read_phonerecord();              /* Ű���忡�� �̸��� ��ȭ��ȣ�� �д� �Լ�        */
struct Name read_name();                            /* Ű���忡�� �̸��� �д� �Լ�                   */
void show_record(struct PhoneRecord record);        /* ��ȭ��ȣ ��Ͽ��� �̸��� ��ȣ�� ����ϴ� �Լ� */
void find_numbers(struct Name name);                /* �Է��� �̸��� �ش��ϴ� ��ȣ�� ã�� �Լ�       */
void add_record();                                  /* �� �̸��� ��ȣ�� �߰��ϴ� �Լ�                */
void delete_records(struct Name name);              /* ������ �̸��� ����� ����� �Լ�              */
void list_records();                                /* ������ ��� ����� ����ϴ� �Լ�              */
void show_operations();                             /* ���α׷��� �����ϴ� ����� ����ϴ� �Լ�      */
int equals(struct Name name1, struct Name name2);   /* �� �̸��� ������ �˻��ϴ� �Լ�                */

/* �������� */
FILE *pFile = NULL;                                 /* ���� ������                 */
char *filename = "C:\\records.bin";                 /* ����� �����ϴ� ������ �̸� */
char answer = 'n';                                  /* �Է� �ǵ��� �����ϴ� ����   */


void main()
{
  show_operations();                                /* ��밡���� ����� ��� */     

  for(;;)
  {
    printf("\n���ϴ� �۾��� �����ϼ���: ");
    scanf(" %c", &answer);
    switch(toupper(answer))
    {
      case 'A':                                     /* �� �̸�/��ȭ��ȣ ��� �߰�   */
        add_record();
        break;
      case 'D':                                     /* ������ �̸��� ��� ����      */
        delete_records(read_name());
        break;
      case 'F':                                     /* ������ �̸��� ��ȭ��ȣ �˻�  */
        find_numbers(read_name());
        break;
      case 'L':                                     /* ��ü �̸�/��ȭ��ȣ ��� ��� */
        list_records();
        break;
      case 'Q':                                     /* ���α׷� ����                */
        return;
      default:
        printf("\n�߸� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
        show_operations();
        break;
    }
  }
 }

/* Ű���忡�� �̸��� ��ȭ��ȣ�� �о� PhoneRecord ����ü�� ����� �Լ� */
struct PhoneRecord read_phonerecord()
{
  struct PhoneRecord record;    
  record.name = read_name();
  printf("��ȭ��ȣ�� �Է��ϼ���: ");
  scanf(" %[ 0123456789]",record.number);  /* ��ȣ �б� */
  return record;
}

/* ��ȭ��ȣ ��Ͽ��� �̸��� ��ȣ�� ����ϴ� �Լ� */
void show_record(struct PhoneRecord record)
{
  printf("\n%s %s   %s", record.name.firstname,record.name.secondname, record.number);
}

/* �� �̸��� ��ȭ��ȣ�� �߰� */
void add_record()
{
  struct PhoneRecord record;

  if((pFile = fopen(filename, "a+")) == NULL)  /* ����� ������ ���� ���� ����/����� */
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }
  record = read_phonerecord();                 /* �̸��� ��ȣ �б� */  
  fwrite(&record, sizeof record, 1, pFile);
  fclose(pFile);                               /* ���� �ݱ� */ 
  printf("\n�� �����͸� �߰��߽��ϴ�.");
}

/* Ű���忡�� �̸��� �о� Name ����ü�� ����� �Լ� */
struct Name read_name()
{
  struct Name name;
    printf("���� �Է��ϼ���: ");
    scanf(" %s", &name.firstname);
    printf("�̸��� �Է��ϼ���: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* ������ �̸��� ����� ����ϴ� �Լ� */
/* �ϳ� �̻��� ����� �����Ϸ���, ������ ���� ������ ������ 
   �� ���Ͽ� �����ϸ� �ȴ�. �׷� ���� ���� ������ �����
   �� ������ �̸��� ���� ������ �̸����� �ٲ۴�.
*/
void delete_records(struct Name name)
{
  FILE *pNewFile = NULL;
  char *pnewfilename = NULL;
  struct PhoneRecord record;

  if((pFile = fopen(filename, "r")) == NULL)         /* ���� ������ �б������ ���� */
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }

  pnewfilename = tmpnam(NULL);                       /* �ӽ����� �̸� �����      */
  if((pNewFile = fopen(pnewfilename, "w")) == NULL)  /* �ӽ������� ����뵵�� ����� */
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", pnewfilename);
    fclose(pFile);
    abort();
  }

  /* ���� ����� �����ϰ� ���� ������ ������ �ӽ����Ͽ� ���� */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);      /* ��� �б�             */
    if(feof(pFile))                               /* ���� �бⰡ �����°�? */
      break;                                      /* �� - ������ ����      */

    if(equals(name, record.name))                 /* ���� ����� ã�Ҵ°�? */
    {
      printf("\n����� ã�ҽ��ϴ�:");                /* �� */
      show_record(record);
      printf("\n������ ����ðڽ��ϱ�(y/n)? ");
      scanf(" %c", &answer);
      if(tolower(answer) == 'y')                  /* ���� ����̶�� */
        continue;                                 /* �������� ����   */
    }
    fwrite(&record, sizeof record, 1, pNewFile);  /* ���� ����� ���� */
  }
  fclose(pFile);
  fclose(pNewFile);

  if((pNewFile = fopen(pnewfilename, "r")) == NULL)   /* �ӽ� ���� ���� */
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", pnewfilename);
    abort();
  }
  if((pFile = fopen(filename, "w"))==NULL)            /* ���� ������ ���� �뵵�� ���� */
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }

  /* �� �ӽ������� ������ ���� ���Ͽ� ����                    */
  /* ���ϸ�尡 "w"�̹Ƿ� �� ������ ���� ������ ������ ��� */
  for(;;)
  {
    fread(&record, sizeof record, 1, pNewFile);   /* �ӽ����� �б� */
    if(feof(pNewFile))                            /* EOF�� ������  */
      break;                                      /* ��            */

    fwrite(&record, sizeof record, 1, pFile);     /* ���� ���Ͽ� ��� */
  }
  fclose(pFile);                       /* ���� ���� �ݱ� */
  fclose(pNewFile);                    /* �ӽ����� �ݱ�  */
  remove(pnewfilename);                /* �ӽ����� ����  */
  printf("�������ϴ�.");
}

/* ������ ��� ����� ��� */
void list_records()
{
  struct PhoneRecord record;
  int file_empty = TRUE;    /* ������ ������� ��Ÿ���� �÷��� */

  if((pFile = fopen(filename, "r")) == NULL)   /* ������ �б� �뵵�� ���� */      
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }

  /* ���� ������ ��� */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);
    if(feof(pFile))
      break;
    file_empty = FALSE;          /* ����� �����Ƿ� FALSE�� ���� */
    show_record(record);         /* ����� ���                  */
  }
  fclose(pFile);                 /* ���� �ݱ� */

  /* ����� �ִ��� �˻� */
  if(file_empty)
    printf("���Ͽ� �ƹ� ���뵵 �����ϴ�.\n");
  else
    printf("\n");
}

/* ���α׷��� �����ϴ� ��� ��� */
void show_operations()
{
  printf("�����ϴ� ����� ������ �����ϴ�."
    "\nA: �� �̸�/��ȭ��ȣ �Է��ϱ�"
    "\nD: ������ �̸� �����"
    "\nF: �̸�/��ȭ��ȣ �˻��ϱ�"
    "\nL: ���Ͽ� ��ϵ� ��ȭ��ȣ ��� ����ϱ�"
    "\nQ: ���α׷� ������");
}

/* ������ �̸��� �ش��ϴ� ��ȭ��ȣ ã�� */
void find_numbers(struct Name name) 
{
  struct PhoneRecord record;
  int name_found = FALSE;                    /* �̸��� ã�Ҵ��� ǥ���ϴ� �÷��� */

  if((pFile = fopen(filename, "r")) == NULL) /* ������ �б� �뵵�� ���� */      
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }

  /* ���Ͽ��� ���� ����� �˻� */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);     /* ��� �б�                 */
    if(feof(pFile))
      break;
   if(equals(name,record.name))                  /* ������ �̸��ΰ�?          */
   {
     if(!name_found)                             /* ������ ã�� ���� ���°�?  */
     {
       name_found = TRUE;                        /* �� - �÷��׸� TRUE�� ���� */
       printf("�Է��Ͻ� �̸��� ��ȭ��ȣ�� ������ �����ϴ�:"); /* �޽��� ���  */
     }
     printf("\n%s",record.number);               /* ��ȭ��ȣ ���             */
   }
  }
  fclose(pFile);                                 /* ���� �ݱ�                 */

  /* �̸��� ã�� ���ߴ��� �˻� */
  if(!name_found)
    printf("�̸��� ã�� �� �����ϴ�.\n");
  else
    printf("\n");
}

/* �� �̸��� ������ �˻��ϴ� �Լ� */
int equals(struct Name name1, struct Name name2)
{
  return (strcmp(name1.firstname, name2.firstname)==0) && (strcmp(name1.secondname, name2.secondname)==0);
}
