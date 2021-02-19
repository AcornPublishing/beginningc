/* 연습문제 11.3 사람의 이름을 표현하는 구조체의 연결리스트 */
/*
   포인터 멤버를 추가해 PhoneRecord 구조체를 연결리스트로 연결할 수도 있다.
   그러나 이 프로그램에서는 연결리스트에서 노드 역할을 하는 Node 구조체를 정의한다.
   각 Node 구조체에는 PhoneRecord 구조체를 가리키는 포인터와, 다음 Node 구조체를 가리
   키는 포인터가 들어있다. Node 구조체와 PhoneRecord 구조체의 메모리는 동적으로 
   할당된다. 여러분이 직접 이름과 전화번호의 메모리도 동적으로 할당되도록 바꿔볼 수도
   있겠다.
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

/* 이름을 정의하는 구조체 */
struct Name
{
  char firstname[FIRST_NAME_LEN];
  char secondname[SECOND_NAME_LEN];
};

/* 전화번호를 정의하는 구조체 */
struct PhoneRecord
{
  struct Name name;
  char number[NUMBER_LEN];
};

/* PhoneRecord 구조체 연결리스트의 노드를 정의하는 구조체 */
struct Node
{
  struct PhoneRecord *pRecord;     /* PhoneRecord 구조체를 가리키는 포인터 */
  struct Node *pNext;              /* 리스트의 다음 노드를 가리키는 포인터 */
};

struct Name read_name();                /* 키보드에서 이름을 읽어들이는 함수       */               
void show(struct PhoneRecord *pRecord); /* 전화번호를 출력하는 함수                */
int has_name(struct PhoneRecord record, struct Name name); /* 이름을 검사하는 함수 */
struct Node* create_node();             /* 새 노드를 만드는 함수                   */
struct PhoneRecord* create_record();    /* 새 전화번호를 만드는 함수               */
void insert_node(struct Node *pNode);   /* 리스트에 노드를 추가하는 함수           */
int compare_records(struct PhoneRecord *pFirst, struct PhoneRecord *pSecond);  /* 기록을 비교하는 함수 */
int compare_names(struct Name first, struct Name second); /* 두 이름을 비교하는 함수   */
void list_numbers(struct Name name);    /* Name 구조체의 모든 전화번호를 출력하는 함수 */

struct Node *pStart = NULL;

void main()
{
  char answer = 'n';
  struct Node *pNode = NULL;                /* 노드를 가리키는 포인터               */
  struct PhoneRecord *pRecord = NULL;       /* PhoneRecord 구조체를 가리키는 포인터 */
  int found = FALSE;                        /* 이름을 찾았는지 여부                 */
  int i = 0;                                /* 루프 제어 변수                       */
 
  /* 키보드에서 전화번호를 입력받음 */  
  do
  {
    insert_node(create_node());      /* 새 노드를 만들어 추가함 */

    printf("더 입력하시겠습니까(y/n)?: ");
    scanf(" %c", &answer);
  }while(tolower(answer) == 'y');

  /* 전화번호 검색 */
  do
  {
    printf("\n찾으려는 이름을 입력하세요.");
    list_numbers(read_name());
    printf("더 찾으시겠습니까(y/n)? ");
    scanf(" %c" , &answer);
  }while(tolower(answer) == 'y');

  /* 연결리스트에 있는 모든 기록을 출력 */
  pNode = pStart;
  do
  {
    show(pNode->pRecord);
  }while((pNode = pNode->pNext) != 0);
  printf("\n");

  /* 메모리 해제를 잊지 말자! */
  pNode = pStart;
  do
  {
    free(pNode->pRecord);    /* 현재 노드 기록의 메모리를 해제 */
    pStart = pNode;          /* 현재 노드의 주소를 저장        */
    pNode = pNode->pNext;    /* 다음 노드의 주소를 얻어옴      */
    free(pStart);            /* 현재 노드의 메모리를 해제      */
  }while((pNode = pNode->pNext) != 0);
}

/* 키보드에서 이름을 읽어 구조체에 저장 */
struct Name read_name()
{
  unsigned long inches = 0;
  struct Name name;
    printf("\n성을 입력하세요: ");
    scanf(" %s", &name.firstname);
    printf("이름을 입력하세요: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* 기록 출력 */
void show(struct PhoneRecord *pRecord)
{
  printf("\n%s %s   %s", pRecord->name.firstname, pRecord->name.secondname, pRecord->number);
}

int has_name(struct PhoneRecord record, struct Name name)
{
  return (strcmp(name.firstname, record.name.firstname)==0 && strcmp(name.secondname, record.name.secondname)==0);
}

/* 새 노드를 만드는 함수 */
struct Node* create_node()
{
  struct Node *pNode = NULL;                         /* 새 노드를 가리키는 포인터        */
  pNode = (struct Node*)malloc(sizeof(struct Node)); /* 노드의 메모리 할당               */
  pNode->pNext = NULL;                               /* 아직 다음 노드가 없음            */
  pNode->pRecord = create_record();                  /* 노드에 기록을 만들고 주소를 저장 */
  return pNode;
}

/* 새 전화번호 기록을 만드는 함수 */
struct PhoneRecord* create_record() 
{
  struct PhoneRecord *pRecord = NULL;             /* 새 기록을 가리키는 포인터 */
  pRecord = (struct PhoneRecord*)malloc(sizeof(struct PhoneRecord)); /* 메모리 할당 */
  pRecord->name = read_name();                    /* 이름 읽기                 */      
  /* Get the number for the name */
  printf("Enter the number for this name: ");
  scanf(" %[ 0123456789]",pRecord->number);       /* 스페이스를 포함해 번호 읽기 */
  return pRecord;                                 /* 기록의 주소 반환            */
}

/*
  두 PhoneRecord 구조체를 비교하는 함수
  첫번째 이름이 두번째 이름보다 작으면 -1을,
  첫번째 이름과 두번째 이름이 같으면 -0을,
  첫번째 이름이 두번째 이름보다 크면 1을 반환
*/
int compare_records(struct PhoneRecord *pFirst, struct PhoneRecord *pSecond)
{
  return compare_names(pFirst->name, pSecond->name);
}

/* 
  비교는 성을 기준으로 이뤄진다. 성이 같으면 이름을 비교한다.
*/
int compare_names(struct Name first, struct Name second)
{
  int result = 0;
  result = strcmp(first.firstname,second.firstname);
  return (result != 0 ? result : strcmp(first.secondname,second.secondname));
}

/* 모드를 리스트에 삽입하는 함수 */
void insert_node(struct Node *pNode)
{
  struct Node *pCurrent = NULL;
  struct Node *pPrevious = NULL;
  struct Node *pTemp = NULL;

  /* 빈 목록을 검사 */
  if(pStart == NULL)
  {
    pStart = pNode;   /* 노드의 주소를 시작 노드로 저장 */
    return;
  }

  /* 새 노드를 삽입할 위치 결정 */
  pCurrent = pStart;
  while(pCurrent != NULL)
  {
    if(compare_records(pNode->pRecord, pCurrent->pRecord) <= 0)
    {                          /* 새 노드는 현재 리스트 노드의 앞에 위치 */
      pNode->pNext = pCurrent; /* 새 노드의 다음 포인터를 현재노드로     */
      if(pPrevious == NULL)    /* pCurrent가 첫째 노드이면               */
      {                        
        pNode->pNext = pStart; /* 새 노드의 다음 포인터가 현재 노드를 가리키도록 */
        pStart = pNode;        /* 새 노드는 첫째 노드임                          */
      }
      else
      {                           /* 그렇지 않으면... */
        pPrevious->pNext = pNode; /* 이전 노드의 다음 포인터가 새 노드를 가리키도록 */
        pNode->pNext = pCurrent;  /* 새 노드의 다음 포인터가 현재 노드를 가리키도록 */
      }
      return;
    }
    pPrevious = pCurrent;         /* 이전 노드는 현재 노드가 됨 */
    pCurrent = pCurrent->pNext;   /* 현재 노드는 다음 노드가 됨 */   
  }
  /* 여기까지 왔다면 pNode를 맨 끝에 추가 */
  pPrevious->pNext = pNode;
}

/* 이름에 해당하는 전화번호를 출력하는 함수 */
void list_numbers(struct Name name)
{
  struct Node *pNode = NULL;
  int found = FALSE;
  int result = 0;

  /* 이름을 비교하면서 리스트를 훑어나감 */
  pNode = pStart;
  while(pNode != NULL)
  {
    result = compare_names(name, pNode->pRecord->name);
    if(result == 0)
    {
      if(!found)                                    /* 처음으로 이름을 찾았으면 */
      {
        found = TRUE;                               /* found 플래그 설정        */
        printf("전화번호는 다음과 같습니다:\n");    /* 지시문 출력              */
      }
      printf("%s\n", pNode->pRecord->number);       /* 전화번호 출력            */
    }
   else if(result < 0)                              /* 이전에 이름이 나왔다면   */
      break;                                        /* 할 일 없음               */
    pNode = pNode->pNext;                           /* 다음 노드로 넘어감       */
  }

  if(!found)                                         /* 이름을 찾지 못하면      */
    printf("찾는 이름이 없습니다.\n");               /* 지시문 출력             */
}
