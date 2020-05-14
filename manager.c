#include "manager.h"

void listdatadelivery(H_delivery *H, int count){
	printf("\nNo. 가게이름        전화번호     대표메뉴   가격    별점\n");
	printf("***********************************************************\n");
	for(int i = 0 ; i < count ; i++){
		if(H[i].price == -1 || H[i].star == -1) continue;
		printf("%2.", i+1);
		readdelivery(&H[i]);
	}
	printf("\n");
}

void readdelivery(H_delivery* H) {
	printf("%-15s %-15s %-15s %4d[원] %d[star]\n", H->market, H->phone, H->menu, H->price, H->star);
}

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
	printf("=>삭제됨!");
	return 0;
}

void savedatadelivery(H_delivery *H, int count){
	FILE *fp;
	fp = fopen("delivery.txt", "wt");
	for(int i=0; i<count; i++){
		fprintf(fp, "%s %s, %d, %d, %s\n",H->market ,H->phone, H->price, H->star, H->menu);
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
		fscanf(fp, "%s %s, %d, %d, %[^\n]",H->market ,H->phone, &H->price, &H->star, H->menu);
		count++;
		if(feof(fp)) break;
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


void searchdelivery(H_delivery *H[], int count){
	int scount = 0;
	char smarket[30];
	printf("==> 찾고싶은 음식은?");
	scanf("%[^\n]", smarket);
	for(int i=0; i<count; i++){
		if(strstr(H[i].market, smarket)){
			readdelivery(H[i].market, i);
			scount++;
		}
	}
	if(scount == 0) printf("==>검색된 메뉴 없음");
	printf("\n");
}


int adddelivery(H_delivery *H){
	printf("가게 이름?");
	scanf("%[^\n]", H->market);

	printf("가게 전화번호?");
	scanf("%s", H->phone);

	printf("대표메뉴?");
	scanf("%[^\n]", H->menu);

	printf("데표메뉴의 가격?");
	scanf("%d", &H->price);

	printf("가게의 별점?");
	scanf("%d", &H->star);
	return 1;
}

void searchstarscore(H_delivery* H, int count){
	int scount = 0; 
	char search[20];

	printf("원하는 별점은? ");
	scanf("%s", search);

    printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (p[i] == NULL) continue;
		if (strstr(H[i]->star, search)) {
			readdelivery(*H[i]);
		} scount++;
	}
	if (scount == 0) printf("==> 검색결과 없음!!!\n");
}

void searchprice(H_delivery* H[], int count){
	int scount = 0; 
	char search[20];

	printf("원하는 가격은? ");
	scanf("%s", search);

    printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (p[i] == NULL) continue;
		if (strstr(H[i]->price, search)) {
			readdelivery(*H[i]);
		} scount++;
	}
	if (scount == 0) printf("==> 검색결과 없음!!!\n");
}


	

