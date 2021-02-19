/* 연습문제 12.2 파일의 문자열을 역순으로 읽기 */
/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define BUFFER_SIZE 50

/* Global variables */
FILE *pInFile = NULL;                   /* 입력파일의 파일 포인터 */
FILE *pOutFile = NULL;                  /* 출력파일의 파일 포인터 */
char *infilename = "C:\\myfile.txt";    /* 읽을 파일의 이름       */
char *outfilename = "C:\\outfile.txt";  /* 기록할 파일의 이름     */
char *buffer = NULL;
size_t buffer_size = BUFFER_SIZE;


void main()
{
  size_t str_length = 0;
  int str_count = 0;
  fpos_t *positions = NULL;
  int i = 0;

  buffer = (char*)malloc(buffer_size);            /* 초기 버퍼 만들기 */

  if((pInFile = fopen(infilename, "r")) == NULL)  /* 입력 파일 열기   */
  {
    printf("%s를 열 때 오류가 발생했습니다. 프로그램을 종료합니다.", infilename);
    abort();
  }

  /* 문자열이 몇개 있는지 확인 */
  for(;;)
  {
    fread(&str_length, sizeof(size_t), 1, pInFile);  /* 문자열의 길이를 읽음 */
    if(feof(pInFile))                                /* 파일의 끝에 다다르면 */
      break;                                         /* 끝남                 */

    /* 버퍼가 충분히 큰지 검사하고 필요하면 증가시킴 */
    if(str_length>buffer_size)
    {
      buffer_size = str_length+1;
      free(buffer);
      buffer = (char*)malloc(buffer_size);
    }
    fread(buffer, str_length, 1, pInFile);   /* 문자열 읽기 */
    ++str_count;
  }
  printf("\nThere are %d strings in the input file.", str_count);

  /* 이제 파일에 있는 각 기록의 시작위치를 알아냄            */
  /* 버퍼는 이제 가장 긴 문자열을 저장할 수 있을만큼 큰 상태 */
  rewind(pInFile);
  positions = (fpos_t*)malloc(str_count*sizeof(fpos_t));  /* 시작위치를 저장할 배열 */
  for(i = 0 ; i<str_count ; i++)
  {
    fgetpos(pInFile, positions+i);                    /* 위치를 알아냄      */
    fread(&str_length, sizeof(size_t), 1, pInFile);   /* 문자열 길이를 읽음 */
    fread(buffer, str_length, 1, pInFile);            /* 문자열을 읽음      */
 }

  /* 출력파일 열기 */
  if((pOutFile = fopen(outfilename, "w")) == NULL)
  {
    printf("%s를 열 때 오류가 발생했습니다. 프로그램을 종료합니다.", outfilename);
    abort();
  }

  /* 입력파일에서 기록을 역순으로 읽어 새 파일에 기록 */
  for(i = 0 ; i<str_count ; i++)
  {
    fsetpos(pInFile, positions+str_count-i-1);            /* 파일 위치 설정 */
    fread(&str_length, sizeof(size_t), 1, pInFile);       /* 파일 길이 읽기 */
    fwrite(&str_length, sizeof(size_t), 1, pOutFile);     /* 새 파일에 기록 */
    fread(buffer, str_length, 1, pInFile);                /* 문자열 읽기    */
    fwrite(buffer, str_length, 1, pOutFile);              /* 새 파일에 기록 */
  }

  fclose(pInFile);                                        /* 입력파일 닫기  */
  fclose(pOutFile);                                       /* 출력파일 닫기  */
  printf("\n새 파일에 기록을 완료했습니다.\n");

  /* 출력파일의 내용 출력 */
  if((pOutFile = fopen(outfilename, "r")) == NULL)        /* 새 파일 열기 */
  {
    printf("%s를 열 때 오류가 발생했습니다. 프로그램을 종료합니다.", outfilename);
    abort();
  }
  printf("\n새 파일에 있는 문자열은 다음과 같습니다.");
  for(i = 0 ; i<str_count ; i++)
  {
    fread(&str_length, sizeof(size_t), 1, pOutFile);
    fread(buffer, str_length, 1, pOutFile);
    buffer[str_length] = '\0';
    printf("\n%s", buffer);
  }
  printf("\n");
  fclose(pOutFile);                                    /* 파일 닫기 */

  /* 할당한 메모리를 해제 */
  if(buffer != NULL)
    free(buffer);
  if(positions != NULL)
    free(positions);
 }
