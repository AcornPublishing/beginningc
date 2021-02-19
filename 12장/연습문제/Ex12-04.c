/* 연습문제 12.4 파일에 이름과 전화번호 기록 */
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
struct PhoneRecord read_phonerecord();              /* 키보드에서 이름과 전화번호를 읽는 함수        */
struct Name read_name();                            /* 키보드에서 이름을 읽는 함수                   */
void show_record(struct PhoneRecord record);        /* 전화번호 기록에서 이름과 번호를 출력하는 함수 */
void find_numbers(struct Name name);                /* 입력한 이름에 해당하는 번호를 찾는 함수       */
void add_record();                                  /* 새 이름과 번호를 추가하는 함수                */
void delete_records(struct Name name);              /* 지정된 이름의 기록을 지우는 함수              */
void list_records();                                /* 파일의 모든 기록을 출력하는 함수              */
void show_operations();                             /* 프로그램이 지원하는 기능을 출력하는 함수      */
int equals(struct Name name1, struct Name name2);   /* 두 이름이 같은지 검사하는 함수                */

/* 전역변수 */
FILE *pFile = NULL;                                 /* 파일 포인터                 */
char *filename = "C:\\records.bin";                 /* 기록을 저장하는 파일의 이름 */
char answer = 'n';                                  /* 입력 의도를 저장하는 변수   */


void main()
{
  show_operations();                                /* 사용가능한 기능을 출력 */     

  for(;;)
  {
    printf("\n원하는 작업을 선택하세요: ");
    scanf(" %c", &answer);
    switch(toupper(answer))
    {
      case 'A':                                     /* 새 이름/전화번호 기록 추가   */
        add_record();
        break;
      case 'D':                                     /* 지정한 이름의 기록 삭제      */
        delete_records(read_name());
        break;
      case 'F':                                     /* 지정한 이름의 전화번호 검색  */
        find_numbers(read_name());
        break;
      case 'L':                                     /* 전체 이름/전화번호 기록 출력 */
        list_records();
        break;
      case 'Q':                                     /* 프로그램 종료                */
        return;
      default:
        printf("\n잘못 선택하셨습니다. 다시 입력해주세요.");
        show_operations();
        break;
    }
  }
 }

/* 키보드에서 이름과 전화번호를 읽어 PhoneRecord 구조체를 만드는 함수 */
struct PhoneRecord read_phonerecord()
{
  struct PhoneRecord record;    
  record.name = read_name();
  printf("전화번호를 입력하세요: ");
  scanf(" %[ 0123456789]",record.number);  /* 번호 읽기 */
  return record;
}

/* 전화번호 기록에서 이름과 번호를 출력하는 함수 */
void show_record(struct PhoneRecord record)
{
  printf("\n%s %s   %s", record.name.firstname,record.name.secondname, record.number);
}

/* 새 이름과 전화번호를 추가 */
void add_record()
{
  struct PhoneRecord record;

  if((pFile = fopen(filename, "a+")) == NULL)  /* 기록할 파일을 연결 모드로 열기/만들기 */
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }
  record = read_phonerecord();                 /* 이름과 번호 읽기 */  
  fwrite(&record, sizeof record, 1, pFile);
  fclose(pFile);                               /* 파일 닫기 */ 
  printf("\n새 데이터를 추가했습니다.");
}

/* 키보드에서 이름을 읽어 Name 구조체를 만드는 함수 */
struct Name read_name()
{
  struct Name name;
    printf("성을 입력하세요: ");
    scanf(" %s", &name.firstname);
    printf("이름을 입력하세요: ");
    scanf(" %s", &name.secondname);
  return name;
}

/* 지정한 이름의 기록을 삭게하는 함수 */
/* 하나 이상의 기록을 제거하려면, 제거할 기존 파일의 내용을 
   새 파일에 복사하면 된다. 그런 다음 기존 파일을 지우고
   새 파일의 이름을 기존 파일의 이름으로 바꾼다.
*/
void delete_records(struct Name name)
{
  FILE *pNewFile = NULL;
  char *pnewfilename = NULL;
  struct PhoneRecord record;

  if((pFile = fopen(filename, "r")) == NULL)         /* 현재 파일을 읽기용으로 열기 */
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }

  pnewfilename = tmpnam(NULL);                       /* 임시파일 이름 만들기      */
  if((pNewFile = fopen(pnewfilename, "w")) == NULL)  /* 임시파일을 쓰기용도로 만들기 */
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", pnewfilename);
    fclose(pFile);
    abort();
  }

  /* 지울 기록은 무시하고 현재 파일의 내용을 임시파일에 복사 */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);      /* 기록 읽기             */
    if(feof(pFile))                               /* 파일 읽기가 끝났는가? */
      break;                                      /* 예 - 루프를 끝냄      */

    if(equals(name, record.name))                 /* 지울 기록을 찾았는가? */
    {
      printf("\n기록을 찾았습니다:");                /* 예 */
      show_record(record);
      printf("\n정말로 지우시겠습니까(y/n)? ");
      scanf(" %c", &answer);
      if(tolower(answer) == 'y')                  /* 지울 기록이라면 */
        continue;                                 /* 복사하지 않음   */
    }
    fwrite(&record, sizeof record, 1, pNewFile);  /* 현재 기록을 복사 */
  }
  fclose(pFile);
  fclose(pNewFile);

  if((pNewFile = fopen(pnewfilename, "r")) == NULL)   /* 임시 파일 열기 */
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", pnewfilename);
    abort();
  }
  if((pFile = fopen(filename, "w"))==NULL)            /* 원본 파일을 쓰기 용도로 열기 */
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }

  /* 새 임시파일의 내용을 기존 파일에 복사                    */
  /* 파일모드가 "w"이므로 이 과정은 기존 파일의 내용을 덮어씀 */
  for(;;)
  {
    fread(&record, sizeof record, 1, pNewFile);   /* 임시파일 읽기 */
    if(feof(pNewFile))                            /* EOF를 읽으면  */
      break;                                      /* 끝            */

    fwrite(&record, sizeof record, 1, pFile);     /* 기존 파일에 기록 */
  }
  fclose(pFile);                       /* 기존 파일 닫기 */
  fclose(pNewFile);                    /* 임시파일 닫기  */
  remove(pnewfilename);                /* 임시파일 제거  */
  printf("지웠습니다.");
}

/* 파일의 모든 기록을 출력 */
void list_records()
{
  struct PhoneRecord record;
  int file_empty = TRUE;    /* 파일이 비었는지 나타내는 플래그 */

  if((pFile = fopen(filename, "r")) == NULL)   /* 파일을 읽기 용도로 열기 */      
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }

  /* 파일 내용을 출력 */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);
    if(feof(pFile))
      break;
    file_empty = FALSE;          /* 기록이 있으므로 FALSE로 설정 */
    show_record(record);         /* 기록을 출력                  */
  }
  fclose(pFile);                 /* 파일 닫기 */

  /* 기록이 있는지 검사 */
  if(file_empty)
    printf("파일에 아무 내용도 없습니다.\n");
  else
    printf("\n");
}

/* 프로그램이 지원하는 기능 출력 */
void show_operations()
{
  printf("지원하는 기능은 다음과 같습니다."
    "\nA: 새 이름/전화번호 입력하기"
    "\nD: 선택한 이름 지우기"
    "\nF: 이름/번화번호 검색하기"
    "\nL: 파일에 기록된 전화번호 모두 출력하기"
    "\nQ: 프로그램 끝내기");
}

/* 지정한 이름에 해당하는 전화번호 찾기 */
void find_numbers(struct Name name) 
{
  struct PhoneRecord record;
  int name_found = FALSE;                    /* 이름을 찾았는지 표시하는 플래그 */

  if((pFile = fopen(filename, "r")) == NULL) /* 파일을 읽기 용도로 열기 */      
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }

  /* 파일에서 읽은 기록을 검색 */
  for(;;)
  {
    fread(&record, sizeof record, 1, pFile);     /* 기록 읽기                 */
    if(feof(pFile))
      break;
   if(equals(name,record.name))                  /* 지정한 이름인가?          */
   {
     if(!name_found)                             /* 이전에 찾은 적이 없는가?  */
     {
       name_found = TRUE;                        /* 예 - 플래그를 TRUE로 설정 */
       printf("입력하신 이름의 전화번호는 다음과 같습니다:"); /* 메시지 출력  */
     }
     printf("\n%s",record.number);               /* 전화번호 출력             */
   }
  }
  fclose(pFile);                                 /* 파일 닫기                 */

  /* 이름을 찾지 못했는지 검사 */
  if(!name_found)
    printf("이름을 찾을 수 없습니다.\n");
  else
    printf("\n");
}

/* 두 이름이 같은지 검사하는 함수 */
int equals(struct Name name1, struct Name name2)
{
  return (strcmp(name1.firstname, name2.firstname)==0) && (strcmp(name1.secondname, name2.secondname)==0);
}
