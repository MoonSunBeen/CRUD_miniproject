#include "manager.h"

void listdatadelivery(H_delivery *H, int count){
	printf("\nNo. 가게이름        전화번호     대표메뉴   가격    별점\n");
	printf("***********************************************************\n");
	for (int i = 0; i < count; i++) {
		if (H[i].price != -1) {
			printf("%2d", i + 1);
			readdelivery(&H[i]);
		}
	}
	printf("\n");
}

void readdelivery(H_delivery *H) {
	printf("%-15s %-15s %-15s %4d[원] %d[star]\n", H->market, H->phone, H->menu, H->price, H->star);
}

int updatedelivery(H_delivery *H){
	printf("새로운 가게 이름?");
	scanf("%[^\n]s", H->market);
	getchar();
	
	printf("새로운 가게 전화번호?");
	scanf("%[^\n]s", H->phone);
	getchar();
	
	printf("새로운 대표메뉴?");
	scanf("%[^\n]s", H->menu);
	getchar();
	
	printf("데표메뉴의 가격?");
	scanf("%d", &H->price);
	printf("가게의 별점?");
	scanf("%d", &H->star);
	return 0;
}

int deletedelivery(H_delivery *H){
	H->price = -1;
	printf("=>삭제됨!");
	return 0;
}

void savedatadelivery(H_delivery *H, int count){
	FILE *fp;
	fp = fopen("delivery.txt", "wt");
	for(int i=0; i<count; i++){
		fprintf(fp, "%s\n%s %d %d %s\n",H->market ,H->phone, H->price, H->star, H->menu);
	}
	fclose(fp);
	printf("=>저장됨!!!\n");
}
int loaddatadelivery(H_delivery *H){
	int count = 0;
	FILE *fp;
	fp = fopen("delivery.txt", "rt");
	if(fp == NULL){
		printf("=>파일 없음\n");
		return 0;
	}
	while(1){
		if(feof(fp)) break;
		fscanf(fp, "%[^\n]",H[count].market);
		fscanf(fp, "%s %d %d %[^\n]",H[count].phone, &H[count].price, &H[count].star, H[count].menu);
		count++;
	}
	fclose(fp);
	printf("=>로딩 성공!!!\n");
	return count;
}



int selectdelivery(){
	int delivery;
	printf("***********한동대학교배달음식!*************\n");
	printf("******     1. 배달음식 조회          ******\n");
	printf("******     2. 배달음식 추가          ******\n");
	printf("******     3. 배달음식 수정          ******\n");
	printf("******     4. 배달음식 삭제          ******\n");
	printf("******     5. 배달음식 저장          ******\n");
	printf("******     6. 배달음식점 이름검색    ******\n");
	printf("******     7. 배달음식 별점검색      ******\n");
	printf("******     8. 배달음식 가격검색      ******\n");
	printf("******     9. 배달음식 전화번호검색  ******\n");
	printf("******     0. 종료                   ******\n");
	printf("*******************************************\n\n");
	printf("==> 원하는 메뉴는? ");
	scanf("%d", &delivery);
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


void searchdelivery(H_delivery *H, int count){
	int scount = 0;
	char smarket[30];
	printf("==> 찾고싶은 음식은?");
	getchar();
	scanf("%[^\n]", smarket);
	for(int i=0; i<count; i++){
		if (strstr(H[i].market, smarket)) {
			readdelivery(&H[i]);
			scount++;
		}
	}
	if(scount == 0) printf("==>검색된 메뉴 없음");
	printf("\n");
}


int adddelivery(H_delivery *H){
	printf("가게 이름?");
	scanf("%[^\n]s", H->market);
	getchar();

	printf("가게 전화번호?");
	scanf("%[^\n]s", H->phone);
	getchar();

	printf("대표메뉴?");
	scanf("%[^\n]s", H->menu);
	getchar();
	
	printf("데표메뉴의 가격?");
	scanf("%d", &H->price);

	printf("가게의 별점?");
	scanf("%d", &H->star);
	return 1;
}

void searchstarscore(H_delivery* H, int count){
	int scount = 0; 
	int score;

	printf("원하는 별점은? ");
	scanf("%d", &score);

    printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (H[i].market == NULL) continue;
		if (H[i].star == score) {
			readdelivery(&H[i]);
			scount++;
		}
	}
	if (scount == 0) printf("==> 검색결과 없음!!!\n");
}

void searchprice(H_delivery* H, int count){
	int scount = 0; 
	int search;

	printf("원하는 가격은? ");
	scanf("%d", &search);

    printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (H[i].price/search == 1) {
			readdelivery(&H[i]);
		scount++;
		}
	}
	if (scount == 0) printf("==> 검색결과 없음!!!\n");
}
	
void searchphone(H_delivery *H, int count){
	int scount = 0;
	char sphone[30];
	printf("==> 찾고싶은 전화번호는?");
	scanf("%s", sphone);
	for(int i=0; i<count; i++){
		if (strstr(H[i].phone, sphone)) {
			readdelivery(&H[i]);
			scount++;
		}
	}
	if(scount == 0) printf("==>검색된 메뉴 없음");
	printf("\n");
}

