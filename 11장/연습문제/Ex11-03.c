/* �������� 11.3 ����� �̸��� ǥ���ϴ� ����ü�� ���Ḯ��Ʈ */
/*
   ������ ����� �߰��� PhoneRecord ����ü�� ���Ḯ��Ʈ�� ������ ���� �ִ�.
   �׷��� �� ���α׷������� ���Ḯ��Ʈ���� ��� ������ �ϴ� Node ����ü�� �����Ѵ�.
   �� Node ����ü���� PhoneRecord ����ü�� ����Ű�� �����Ϳ�, ���� Node ����ü�� ����
   Ű�� �����Ͱ� ����ִ�. Node ����ü�� PhoneRecord ����ü�� �޸𸮴� �������� 
   �Ҵ�ȴ�. �������� ���� �̸��� ��ȭ��ȣ�� �޸𸮵� �������� �Ҵ�ǵ��� �ٲ㺼 ����
   �ְڴ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FIRST_NAME_LEN  31
#define SECOND_NAME_LEN 51
#define NUMBER_LEN      16
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

/* PhoneRecord ����ü ���Ḯ��Ʈ�� ��带 �����ϴ� ����ü */
struct Node
{
  struct PhoneRecord *pRecord;     /* PhoneRecord ����ü�� ����Ű�� ������ */
  struct Node *pNext;              /* ����Ʈ�� ���� ��带 ����Ű�� ������ */
};

struct Name read_name();                /* Ű���忡�� �̸��� �о���̴� �Լ�       */               
void show(struct PhoneRecord *pRecord); /* ��ȭ��ȣ�� ����ϴ� �Լ�                */
int has_name(struct PhoneRecord record, struct Name name); /* �̸��� �˻��ϴ� �Լ� */
struct Node* create_node();             /* �� ��带 ����� �Լ�                   */
struct PhoneRecord* create_record();    /* �� ��ȭ��ȣ�� ����� �Լ�               */
void insert_node(struct Node *pNode);   /* ����Ʈ�� ��带 �߰��ϴ� �Լ�           */
int compare_records(struct PhoneRecord *pFirst, struct PhoneRecord *pSecond);  /* ����� ���ϴ� �Լ� */
int compare_names(struct Name first, struct Name second); /* �� �̸��� ���ϴ� �Լ�   */
void list_numbers(struct Name name);    /* Name ����ü�� ��� ��ȭ��ȣ�� ����ϴ� �Լ� */

struct Node *pStart = NULL;

void main()
{
  char answer = 'n';
  struct Node *pNode = NULL;                /* ��带 ����Ű�� ������               */
  struct PhoneRecord *pRecord = NULL;       /* PhoneRecord ����ü�� ����Ű�� ������ */
  int found = FALSE;                        /* �̸��� ã�Ҵ��� ����                 */
  int i = 0;                                /* ���� ���� ����                       */
 
  /* Ű���忡�� ��ȭ��ȣ�� �Է¹��� */  
  do
  {
    insert_node(create_node());      /* �� ��带 ����� �߰��� */

    printf("�� �Է��Ͻðڽ��ϱ�(y/n)?: ");
    scanf(" %c", &answer);
  }while(tolower(answer) == 'y');

  /* ��ȭ��ȣ �˻� */
  do
  {
    printf("\nã������ �̸��� �Է��ϼ���.");
    list_numbers(read_name());
    printf("�� ã���ðڽ��ϱ�(y/n)? ");
    scanf(" %c" , &answer);
  }while(tolower(answer) == 'y');

  /* ���Ḯ��Ʈ�� �ִ� ��� ����� ��� */
  pNode = pStart;
  do
  {
    show(pNode->pRecord);
  }while((pNode = pNode->pNext) != 0);
  printf("\n");

  /* �޸� ������ ���� ����! */
  pNode = pStart;
  do
  {
    free(pNode->pRecord);    /* ���� ��� ����� �޸𸮸� ���� */
    pStart = pNode;          /* ���� ����� �ּҸ� ����        */
    pNode = pNode->pNext;    /* ���� ����� �ּҸ� ����      */
    free(pStart);            /* ���� ����� �޸𸮸� ����      */
  }while((pNode = pNode->pNext) != 0);
}

/* Ű���忡�� �̸��� �о� ����ü�� ���� */
struct Name read_name()
{
  unsigned long inches = 0;
  struct Name name;
    printf("\n���� �Է��ϼ���: ");
    scanf(" %s", &name.firstname);
    printf("�̸��� �Է��ϼ���: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* ��� ��� */
void show(struct PhoneRecord *pRecord)
{
  printf("\n%s %s   %s", pRecord->name.firstname, pRecord->name.secondname, pRecord->number);
}

int has_name(struct PhoneRecord record, struct Name name)
{
  return (strcmp(name.firstname, record.name.firstname)==0 && strcmp(name.secondname, record.name.secondname)==0);
}

/* �� ��带 ����� �Լ� */
struct Node* create_node()
{
  struct Node *pNode = NULL;                         /* �� ��带 ����Ű�� ������        */
  pNode = (struct Node*)malloc(sizeof(struct Node)); /* ����� �޸� �Ҵ�               */
  pNode->pNext = NULL;                               /* ���� ���� ��尡 ����            */
  pNode->pRecord = create_record();                  /* ��忡 ����� ����� �ּҸ� ���� */
  return pNode;
}

/* �� ��ȭ��ȣ ����� ����� �Լ� */
struct PhoneRecord* create_record() 
{
  struct PhoneRecord *pRecord = NULL;             /* �� ����� ����Ű�� ������ */
  pRecord = (struct PhoneRecord*)malloc(sizeof(struct PhoneRecord)); /* �޸� �Ҵ� */
  pRecord->name = read_name();                    /* �̸� �б�                 */      
  /* Get the number for the name */
  printf("Enter the number for this name: ");
  scanf(" %[ 0123456789]",pRecord->number);       /* �����̽��� ������ ��ȣ �б� */
  return pRecord;                                 /* ����� �ּ� ��ȯ            */
}

/*
  �� PhoneRecord ����ü�� ���ϴ� �Լ�
  ù��° �̸��� �ι�° �̸����� ������ -1��,
  ù��° �̸��� �ι�° �̸��� ������ -0��,
  ù��° �̸��� �ι�° �̸����� ũ�� 1�� ��ȯ
*/
int compare_records(struct PhoneRecord *pFirst, struct PhoneRecord *pSecond)
{
  return compare_names(pFirst->name, pSecond->name);
}

/* 
  �񱳴� ���� �������� �̷�����. ���� ������ �̸��� ���Ѵ�.
*/
int compare_names(struct Name first, struct Name second)
{
  int result = 0;
  result = strcmp(first.firstname,second.firstname);
  return (result != 0 ? result : strcmp(first.secondname,second.secondname));
}

/* ��带 ����Ʈ�� �����ϴ� �Լ� */
void insert_node(struct Node *pNode)
{
  struct Node *pCurrent = NULL;
  struct Node *pPrevious = NULL;
  struct Node *pTemp = NULL;

  /* �� ����� �˻� */
  if(pStart == NULL)
  {
    pStart = pNode;   /* ����� �ּҸ� ���� ���� ���� */
    return;
  }

  /* �� ��带 ������ ��ġ ���� */
  pCurrent = pStart;
  while(pCurrent != NULL)
  {
    if(compare_records(pNode->pRecord, pCurrent->pRecord) <= 0)
    {                          /* �� ���� ���� ����Ʈ ����� �տ� ��ġ */
      pNode->pNext = pCurrent; /* �� ����� ���� �����͸� �������     */
      if(pPrevious == NULL)    /* pCurrent�� ù° ����̸�               */
      {                        
        pNode->pNext = pStart; /* �� ����� ���� �����Ͱ� ���� ��带 ����Ű���� */
        pStart = pNode;        /* �� ���� ù° �����                          */
      }
      else
      {                           /* �׷��� ������... */
        pPrevious->pNext = pNode; /* ���� ����� ���� �����Ͱ� �� ��带 ����Ű���� */
        pNode->pNext = pCurrent;  /* �� ����� ���� �����Ͱ� ���� ��带 ����Ű���� */
      }
      return;
    }
    pPrevious = pCurrent;         /* ���� ���� ���� ��尡 �� */
    pCurrent = pCurrent->pNext;   /* ���� ���� ���� ��尡 �� */   
  }
  /* ������� �Դٸ� pNode�� �� ���� �߰� */
  pPrevious->pNext = pNode;
}

/* �̸��� �ش��ϴ� ��ȭ��ȣ�� ����ϴ� �Լ� */
void list_numbers(struct Name name)
{
  struct Node *pNode = NULL;
  int found = FALSE;
  int result = 0;

  /* �̸��� ���ϸ鼭 ����Ʈ�� �Ⱦ�� */
  pNode = pStart;
  while(pNode != NULL)
  {
    result = compare_names(name, pNode->pRecord->name);
    if(result == 0)
    {
      if(!found)                                    /* ó������ �̸��� ã������ */
      {
        found = TRUE;                               /* found �÷��� ����        */
        printf("��ȭ��ȣ�� ������ �����ϴ�:\n");    /* ���ù� ���              */
      }
      printf("%s\n", pNode->pRecord->number);       /* ��ȭ��ȣ ���            */
    }
   else if(result < 0)                              /* ������ �̸��� ���Դٸ�   */
      break;                                        /* �� �� ����               */
    pNode = pNode->pNext;                           /* ���� ���� �Ѿ       */
  }

  if(!found)                                         /* �̸��� ã�� ���ϸ�      */
    printf("ã�� �̸��� �����ϴ�.\n");               /* ���ù� ���             */
}
