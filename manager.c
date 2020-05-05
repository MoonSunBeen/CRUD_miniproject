#include "manager.h"

int updatedelivery(H_delivery *H){
	printf("새로운 가게 이름?");
	scanf("%[^\n]", H->market);
	printf("새로운 가게 전화번호?");
	scanf("%s", H->phone);
	printf("새로운 대표메뉴?");
	scanf("%[^\n]", H->menu);
	printf("데표메뉴의 가격?");
	scanf("%d", &H->price);
	printf("가게의 별점?");
	scanf("%d", &H->star);
	return 0;
}

int deletedelivery(H_delivery *H){
	H->price = -1;
	printf(=>삭제됨!);
	return 0;
}

int selectdelivery(){
	int delivery;
	printf("***********한동대학교배달음식!*************\n");
	printf("******     1. 배달음식 조회          ******\n");
	printf("******     2. 배달음식 추가          ******\n");
	printf("******     3. 배달음식 수정          ******\n");
	printf("******     4. 배달음식 삭제          ******\n");
	printf("******     0. 종료                   ******\n");
	printf("*******************************************\n\n");
	printf("==> 원하는 메뉴는? ");
	scanf("%d", delivery);
	return delivery;
}

int selectDataNo(H_delivery *H, int count){
	int num;
	listdatadelivery(H, count);
	printf("==> 번호는 (취소:0)? ");
	scanf("%d", &num);
	getchar();
	return num;
}
