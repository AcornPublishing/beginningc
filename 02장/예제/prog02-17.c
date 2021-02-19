/* 프로그램 2.17 나무의 높이 계산하기 */ 
#include <stdio.h> 

void main() 
{ 
	long shorty = 0L; 							/* 센티미터 단위의 숏다리의 키			  */ 
	long lofty = 0L; 							/* 센티미터 단위의 롱다리의 키			  */ 

	long shorty_to_lofty = 0; 					/* 센티미터 단위의 롱다리와 숏다리의 거리 */ 
	long lofty_to_tree = 0L; 					/* 센티미터 단위의 숏다리와 나무의 거리   */ 

	float meter = 0.0f;
	long tree_height = 0L; 						/* 센티미터 단위의 나무의 높이            */

	const long centis_per_meter = 100L; 

	/* 롱다리의 키를 입력 */ 
	printf("롱다리의 키를 센티미터 단위로 입력하세요: "); 
	scanf("%ld", &lofty); 

	/* 숏다리의 키를 눈높이까지 입력 */
	printf("숏다리의 키를 센티미터 단위로 입력하세요: "); 
	scanf("%ld", &shorty); 

	/* 숏다리와 롱다리가 떨어진 거리를 입력 */
	printf("롱다리와 숏다리의 거리를 미터 단위로 입력하세요: ");
	scanf("%f", &meter);
	shorty_to_lofty = (long)(meter * centis_per_meter);

	/* 숏다리와 나무가 떨어진 거리를 입력 */
	printf("숏다리와 나무의 거리를 미터 단위로 입력하세요: ");
	scanf("%f", &meter);
	lofty_to_tree = (long)(meter * centis_per_meter);

	/* 나무의 높이를 센티미터 단위로 계산 */ 
	tree_height = shorty + (shorty_to_lofty + lofty_to_tree) * (lofty-shorty) /
 				  shorty_to_lofty;

	/* 나무의 높이를 미터, 센티미터 형식으로 출력 */ 
	printf("\n나무의 높이는 %ldm %ldcm입니다.\n", 
			tree_height / centis_per_meter, tree_height % centis_per_meter); 
} 
