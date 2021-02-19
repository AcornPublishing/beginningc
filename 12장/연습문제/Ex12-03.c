/* 연습문제 12.3 파일에 이름과 전화번호 기록 */
/*
  이 프로그램은 고정된 크기의 배열에 저장된 이름과 전화번호로 이뤄진 PhoneRecord
  구조체를 사용한다. 이렇게 하면 파일 작업이 매우 간단해진다. 크기가 고정돼있으므
  로 PhoneRecord 구조체를 읽고 쓰기만 하면 되기 때문이다.

  이름과 전화번호의 메모리를 동적으로 할당하고 싶다면 이름, 전화번호는 물론 
  PhoneRecord 구조체도 기록해야 한다. 그리고 파일에 있는 각 데이터 항목의 길이도
  포함해 다시 읽을 때 길이가 어느 정도인지 알아야 한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_NAME_LENGTH  31
#define SECOND_NAME_LENGTH 51
#define NUMBER_LENGTH      21
#define TRUE                1
#define FALSE               0

/* 이름을 정의하는 구조체 */
struct Name
{
  char firstname[FIRST_NAME_LENGTH];
  char secondname[SECOND_NAME_LENGTH];
};

/* 전화번호를 정의하는 구조체 */
struct PhoneRecord
{
  struct Name name;
  char number[NUMBER_LENGTH];
};

/* 함수원형 */
struct PhoneRecord read_phonerecord();       /* 키보드에서 이름과 전화번호를 읽는 함수        */               
struct Name read_name();                     /* 키보드에서 이름을 읽는 함수                   */
void list_records();                         /* 파일의 모든 기록을 출력하는 함수              */
void show_record(struct PhoneRecord record); /* 전화번호 기록에서 이름과 번호를 출력하는 함수 */

/* 전역변수 */
FILE *pFile = NULL;                   /* 출력파일 포인터    */
char *filename = "C:\\records.bin";   /* 기록할 파일의 이름 */


void main()
{
  char answer = 'n';
  struct PhoneRecord record;
  int file_empty = TRUE;


  printf("전화번호 기록을 입력하시겠습니까(y/n)?: ");
  scanf(" %c", &answer);
  if(tolower(answer) == 'y')
  {
    pFile = fopen(filename, "a+");           /* 기록할 파일을 열기/만들기 */
    if(pFile == NULL)
    {
      printf("%s를 열 때 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
      abort();
    }

    /* 키보드에서 임의 개수의 전화번호를 읽음 */  
    do
    {
      record = read_phonerecord();                 /* 이름과 전화번호 읽기 */  
      fwrite(&record, sizeof record, 1, pFile);

      printf("더 입력하시겠습니까(y/n)?: ");
      scanf(" %c", &answer);
    }while(tolower(answer) == 'y');

    fclose(pFile);                                    /* 파일 닫기 */ 
    printf("\n파일 기록을 완료했습니다.");
  }
  printf("\n파일에 저장된 기록을 모두 출력할까요(y/n)? ");
    scanf(" %c", &answer);
  if(tolower(answer) == 'n')
    return;
  list_records();
 }

/* 키보드에서 이름과 번호를 읽고 PhoneRecord 구조체를 만드는 함수 */
struct PhoneRecord read_phonerecord()
{
  struct PhoneRecord record;    
  record.name = read_name();
  printf("Enter the number: ");
  scanf(" %[ 0123456789]",record.number);  /* 스페이스를 포함해 전화번호 읽기 */
  return record;
}

/* 키보드에서 이름을 읽고 Name 구조체를 만드는 함수 */
struct Name read_name()
{
  struct Name name;
    printf("Enter a first name: ");
    scanf(" %s", &name.firstname);
    printf("Enter a second name: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* 파일에 있는 모든 기록 출력 */
void list_records()
{
  struct PhoneRecord record;
  int file_empty = TRUE;    /* 파일이 비었는지 나타내는 플래그 */

  if((pFile = fopen(filename, "r")) == NULL)   /* 파일 열기 */      
  {
    printf("%s를 열 때 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }

  /* 파일의 내용을 출력 */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);
    if(feof(pFile))
      break;
    file_empty = FALSE;          /* 기록을 읽었으므로 FALSE로 설정 */
    show_record(record);         /* 기록을 출력                    */
  }
  fclose(pFile);                 /* 파일 닫기 */

  /* 기록이 있는지 검사 */
  if(file_empty)
    printf("파일에 아무 내용이 없습니다.\n");
  else
    printf("\n");
}
/* 전화번호 기록에서 이름과 번호를 출력하는 함수 */
void show_record(struct PhoneRecord record)
{
  printf("\n%s %s   %s", record.name.firstname, record.name.secondname, record.number);
}
