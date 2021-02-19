/* 연습문제 11.2 사람의 이름을 표현하는 구조체 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FIRST_NAME_LEN  31
#define SECOND_NAME_LEN 51
#define NUMBER_LEN      16
#define MAX_NUMBERS     50
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

struct Name read_name();               /* 키보드에서 이름을 입력받는 함수 */               
void show(struct PhoneRecord record);  /* 전화번호를 출력하는 함수        */
int has_name(struct PhoneRecord record, struct Name name); /* 이름 검사   */

void main()
{
  char answer = 'n';
  struct PhoneRecord records[MAX_NUMBERS];  /* 전화번호의 배열  */
  struct Name aName;                        /* 이름을 저장      */
  int count = 0;                            /* 전화번호 개수    */
  int found = FALSE;                        /* 이름을 검색했는지 여부 */
  int i = 0;                                /* 루프 제어변수    */
 
  /* 키보드로부터 임의 개수의 전화번호를 입력받음 */  
  do
  {
    records[count].name = read_name();                 /* 이름을 입력 */      
    printf("전화번호를 입력하세요: ");
    scanf(" %[ 0123456789]",records[count++].number);  /* 스페이스를 포함한 전화번호 입력 */

    printf("더 입력하시겠습니까(y/n)?: ");
    scanf(" %c", &answer);
  }while(count<=MAX_NUMBERS && tolower(answer) == 'y');

  /* 전화번호 검색 */
  do
  {
    printf("검색할 이름을 입력하세요.");
    aName =read_name();
    for(i = 0 ; i<count ; i++)
    {
      if(has_name(records[i], aName))                 /* 이름 검색 */
      {
        if(!found)                                    /* 처음으로 이름을 찾았으면*/
        {
          found = TRUE;                               /* found 플래그 설정       */
          printf("전화번호는 다음과 같습니다:\n");    /* 지시문 출력             */
        }
        printf("%s\n", records[i].number);            /* 전화번호 출력           */
      }
    }
    if(found)                                         /* 이름을 찾았으면         */
      found = FALSE;                                  /* found 플래그를 초기화   */
    else                                              /* 못 찾았으면 메시지 출력 */
      printf("찾는 이름이 없습니다.\n");
    printf("더 찾으시겠습니까(y/n)? ");
    scanf(" %c" , &answer);
  }while(tolower(answer) == 'y');

  for(i = 0 ; i<count ; i++)
    show(records[i]);
  printf("\n");

}

/* 이름을 읽어서 Name 구조체에 저장하는 함수 */
struct Name read_name()
{
  struct Name name;
    printf("\n성을 입력하세요: ");
    scanf(" %s", &name.firstname);
    printf("이름을 입력하세요: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* 기록을 출력하는 함수 */
void show(struct PhoneRecord record)
{
  printf("\n%s %s   %s", record.name.firstname,record.name.secondname, record.number);
}

/* 입력한 이름이 기록에 있는지 검사하는 함수 */
int has_name(struct PhoneRecord record, struct Name name)
{
  return (strcmp(name.firstname, record.name.firstname)==0 && strcmp(name.secondname, record.name.secondname)==0);
}
