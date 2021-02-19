/* �������� 11.2 ����� �̸��� ǥ���ϴ� ����ü */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FIRST_NAME_LEN  31
#define SECOND_NAME_LEN 51
#define NUMBER_LEN      16
#define MAX_NUMBERS     50
#define TRUE             1
#define FALSE            0

/* �̸��� �����ϴ� ����ü */
struct Name
{
  char firstname[FIRST_NAME_LEN];
  char secondname[SECOND_NAME_LEN];
};

/* ��ȭ��ȣ�� �����ϴ� ����ü */
struct PhoneRecord
{
  struct Name name;
  char number[NUMBER_LEN];
};

struct Name read_name();               /* Ű���忡�� �̸��� �Է¹޴� �Լ� */               
void show(struct PhoneRecord record);  /* ��ȭ��ȣ�� ����ϴ� �Լ�        */
int has_name(struct PhoneRecord record, struct Name name); /* �̸� �˻�   */

void main()
{
  char answer = 'n';
  struct PhoneRecord records[MAX_NUMBERS];  /* ��ȭ��ȣ�� �迭  */
  struct Name aName;                        /* �̸��� ����      */
  int count = 0;                            /* ��ȭ��ȣ ����    */
  int found = FALSE;                        /* �̸��� �˻��ߴ��� ���� */
  int i = 0;                                /* ���� �����    */
 
  /* Ű����κ��� ���� ������ ��ȭ��ȣ�� �Է¹��� */  
  do
  {
    records[count].name = read_name();                 /* �̸��� �Է� */      
    printf("��ȭ��ȣ�� �Է��ϼ���: ");
    scanf(" %[ 0123456789]",records[count++].number);  /* �����̽��� ������ ��ȭ��ȣ �Է� */

    printf("�� �Է��Ͻðڽ��ϱ�(y/n)?: ");
    scanf(" %c", &answer);
  }while(count<=MAX_NUMBERS && tolower(answer) == 'y');

  /* ��ȭ��ȣ �˻� */
  do
  {
    printf("�˻��� �̸��� �Է��ϼ���.");
    aName =read_name();
    for(i = 0 ; i<count ; i++)
    {
      if(has_name(records[i], aName))                 /* �̸� �˻� */
      {
        if(!found)                                    /* ó������ �̸��� ã������*/
        {
          found = TRUE;                               /* found �÷��� ����       */
          printf("��ȭ��ȣ�� ������ �����ϴ�:\n");    /* ���ù� ���             */
        }
        printf("%s\n", records[i].number);            /* ��ȭ��ȣ ���           */
      }
    }
    if(found)                                         /* �̸��� ã������         */
      found = FALSE;                                  /* found �÷��׸� �ʱ�ȭ   */
    else                                              /* �� ã������ �޽��� ��� */
      printf("ã�� �̸��� �����ϴ�.\n");
    printf("�� ã���ðڽ��ϱ�(y/n)? ");
    scanf(" %c" , &answer);
  }while(tolower(answer) == 'y');

  for(i = 0 ; i<count ; i++)
    show(records[i]);
  printf("\n");

}

/* �̸��� �о Name ����ü�� �����ϴ� �Լ� */
struct Name read_name()
{
  struct Name name;
    printf("\n���� �Է��ϼ���: ");
    scanf(" %s", &name.firstname);
    printf("�̸��� �Է��ϼ���: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* ����� ����ϴ� �Լ� */
void show(struct PhoneRecord record)
{
  printf("\n%s %s   %s", record.name.firstname,record.name.secondname, record.number);
}

/* �Է��� �̸��� ��Ͽ� �ִ��� �˻��ϴ� �Լ� */
int has_name(struct PhoneRecord record, struct Name name)
{
  return (strcmp(name.firstname, record.name.firstname)==0 && strcmp(name.secondname, record.name.secondname)==0);
}
