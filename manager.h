typedef struct{
	char market[60];
	char phone[60];
	char menu[60];
	int price;
	int star;
} H_delivery;

//상품 조회
void listdatadelivery(H_delivery *H, int count);
//상품추가
int adddelivery(H_delivery *H);
//상품수정
int updatedelivery(H_delivery *H);
//상품삭제
int deletedelivery(H_delivery *H);
