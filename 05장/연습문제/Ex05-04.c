/*연습문제 5.4 역수, 제곱, 세제곱, 네제곱의 표 */
#include <stdio.h>

void main()
{
  double data[11][5];                   /* 데이터 저장      */
  double value = 0.0;                   /* 배열에 저장할 값 */
  int row = 0;                          /* 루프 인덱스      */
  int col = 0;                          /* 루프 인덱스      */


  for(row = 0, value = 2.0 ; row<11 ; row++, value += 0.1)
    data[row][0] = value;

  for(row = 0 ; row<11 ; row++)
  {
    data[row][1] = 1.0/data[row][0];               /* 1/x     */
    data[row][2] = data[row][0]*data[row][0];      /* x*x     */
    data[row][3] = data[row][2]*data[row][0];      /* x*x*x   */
    data[row][4] = data[row][3]*data[row][0];      /* x*x*x*x */
  }


  printf("\n         x     ");
  printf("         1/x    ");
  printf("        x*x    ");
  printf("       x*x*x   ");
  printf("       x*x*x*x  ");

    for(row = 0 ; row<11 ; row++)
  {
    printf("\n");
    for(col = 0 ; col<5 ; col++)
      printf("%15.4lf", data[row][col]);
  }

  printf("\n");
}

