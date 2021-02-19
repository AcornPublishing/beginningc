/* �������� 13.1 2���� ���� ���ϴ� ��ũ�� */
/*
  �� ��ũ�δ� � ���������� �������� �����Ѵٴ� ������ �ִ�. ���� �����̾
  �ǰ�, ���, ǥ���ĵ� �����ϴ�. double�� �Ű������� �Լ��ε� ���� ���� �� �� ��
  ����, �� ��� ���ڸ� �ݵ�� double������ ��ȯ�ؾ� �Ѵ�. �׷��� �� ��ũ�ο�����
  �� ���ڰ� �ٸ� ���������� ���� ����ȯ�ȴ�.
*/
#include <stdio.h>

#define COMPARE(x,y)   ((x)<(y)?-1:((x)==(y)?0:1))

void main()
{
  double a = 1.5;
  int n = 2;
  float z = 1.1f;
  printf("\n%lf(double)�� %f(float)�� �񱳰��: %d", a , z, COMPARE(a,z));
  printf("\n%lf(double)�� %d(int)�� �񱳰��: %d", a , n, COMPARE(a,n));
  printf("\n%d(int)�� %f(float)�� �񱳰��: %d", n , z, COMPARE(n,z));
  printf("\nǥ���� \"n*a\"�� ���� %lf(double)��\n"
    " ǥ���� \"n+1\"�� ���� %d(int)�� �񱳰��: %d", n*a , n+1, COMPARE(n*a,n+1));
  printf("\n");
}


