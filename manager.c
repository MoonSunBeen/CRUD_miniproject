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
