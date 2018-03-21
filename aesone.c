#include <stdio.h>
#include <stdlib.h>
/*
 * E6 B1 CA B7
 * 1B 5B 12 7F
 * 50 FD 7C 7B
 * 18 79 04 23
 */
//��x�Ĳ���
unsigned xride(unsigned char num);
//�л�ϲ���
void mixcoluns(unsigned char input[4][4],unsigned char result[4][4]);
//��ӡ���
void prinfre(unsigned char result[4][4]);
unsigned xride(unsigned char num){

    unsigned  char ret;//����ֵ
    if(num&0x80){
        ret=(num<<1)^0x1B;
    }
    else{
        ret=num<<1;
    }
    return ret;
}
void mixcoluns(unsigned char input[4][4],unsigned char result[4][4]){
    int i=0,j=0;
    for(i=0;i<4;i++) {
        for (j = 0; j < 4; j++) {
            result[i][j]=xride(input[(i+0)%4][j])//0x02
                         ^xride(input[(i+1)%4][j])^input[(i+1)%4][j]//0x03
                    ^input[(i+2)%4][j] //0x01
                         ^input[(i+3)%4][j];//0x01
        }
    }
}
//��ӡ���
void prinfre(unsigned char result[4][4]){
    int i=0,j=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%2X ",result[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
  unsigned char input[4][4]={
          0x4D,0x82,0xD2,0x63,
          0xF3,0x07,0x63,0x51,
          0x63,0x63,0xD2,0x21,
          0x7C,0x51,0xF3, 0x63
  };
    unsigned char result[4][4];//��Ž��������
    int i=0;
    int j=0;
      printf("�л��֮ǰ������:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%2X ",input[i][j]);
        }
        printf("\n");
    }
    mixcoluns(input,result);
    printf("��ϵĽ��Ϊ��\n");
   prinfre(result);

    return 0;
}