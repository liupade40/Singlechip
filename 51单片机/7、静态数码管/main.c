#include <REGX52.H>

#define uint unsigned int 
#define uchar unsigned char 

sbit duan = P2^6;
sbit wei = P2^7; 

//code代表不能被修改，共阴极数码管显示 0-9
uchar code LED[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

//毫秒级延时
void dely( uint z ){
	uint x,y;
	for(x = z;x > 0;x--){
		for(y = 114; y > 0;y--);
	}
}

void play(uint n){
	uint ge,shi,bai; //输入3位数，分别得出百十个位
	bai = n / 100;
	shi = n / 10 % 10;
	ge = n % 10;
	
	//第一位(百位)
	P0 = 0xFF;//清除断码
	wei = 1;
	P0 = 0xFE;//显示第一位
	wei = 0;
	
	duan = 1;
	P0 = LED[bai];
	duan = 0;
	dely(5);
	
	
	//第二位(十位)
	P0 = 0xFF;//清除断码
	wei = 1;
	P0 = 0xFD;//显示第二位
	wei = 0;
	
	duan = 1;
	P0 = LED[shi];
	duan = 0;
	dely(5);
	
	//第三位(个位)
	P0 = 0xFF;//清除断码
	wei = 1;
	P0 = 0xFB;//显示第三数码管
	wei = 0;
	
	duan = 1;
	P0 = LED[ge];
	duan = 0;
	dely(5);
}

void main(){
	while(1){
		play(512);
	}
}
