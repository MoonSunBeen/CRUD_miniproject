#include <stdio.h>
#include <string.h>

typedef struct{
	char market[60];
	char phone[60];
	char menu[60];
	int price;
	int star;
} H_delivery;

//상품 조회
void listdatadelivery(H_delivery *H[], int count);
//상품추가
int adddelivery(H_delivery *H);
//상품읽기
void readdelivery(H_delivery H);
//상품수정
int updatedelivery(H_delivery *H);
//상품삭제
int deletedelivery(H_delivery *H);
//상품 번호 조회
int selectDataNo(H_delivery *H, int count);
//메뉴 조회
int selectdelivery();
//파일 저장
void savedatadelivery(H_delivery *H, int count);
//파일 로드
int loaddatadelivery(H_delivery *H[]);
//검색함수
//이름 검색
void searchdelivery(H_delivery *H[], int count);
//별점 검색
void searchstarscore(H_delivery *H[], int count);
//가격 검색
void searchprice(H_delivery *H[], int count);
