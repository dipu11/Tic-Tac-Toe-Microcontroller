/*
 * GccApplication2.c
 *
 * Created: 12/2/2015 12:02:36 AM
 *  Author: DIPU
 *  Co-author: Raisul arefin nahid
 */

#include <util/delay.h>
#include <avr/io.h>
#include <avr/wdt.h>
#define soft_reset()
//#include <iom32.h>
//#define MCUCSR MCUSR;
/*int arr[16]={0b10000000,0b10100000,0b10010000,0b10110000,0b10001000,0b10101000,0b10011000,0b10111000,
	       	0b01000000,0b01100000,0b010010000,0b01110000,0b01001000,0b01101000,0b01011000,0b01111000};*/

/*int arr[16]={0b10111000,0b10110000,0b10101000,0b10100000,0b10011000,0b10010000,0b10001000,0b10000000,
			0b01000000,0b01001000,0b01010000,0b01011000,0b01100000,0b01101000,0b01110000,0b01111000};
*/
int arr[16]={0b10000000,0b10100000,0b10010000,0b10110000,0b10001000,0b10101000,0b10011000,0b10111000,
	       	 0b01000000,0b01100000,0b01010000,0b01110000,0b01001000,0b01101000,0b01011000,0b01111000};


int border[2]={0b10000100,0b00100001};
	int full=0b11111111;
	int rows[16][2]={{0b11111111,0b11111111},
{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},
{0b11111111,0b11111111},
{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},
{0b11111111,0b11111111},
{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},
{0b11111111,0b11111111}};
	int rows_saver[16][2]={{0b11111111,0b11111111},
{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},
{0b11111111,0b11111111},
{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},
{0b11111111,0b11111111},
{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},{0b10000100,0b00100001},
{0b11111111,0b11111111}};
int turn=0;
int play_arr[3][3];
int wait=0;
int wait_looper=0;
float delay=.5f;
int halt=0;
int halt_looper=0;
int new_winner=3;
int main(void)
{
	MCUCSR=(1<<JTD);
	MCUCSR=(1<<JTD);
	//MCUCSR=(1<<jtag);
	//Mcucsr=(1<<jtag);
	//Mcucsr=(1<<jtag);
	DDRB= 0XFF; // DDRD= 0b10000000;
	DDRA= 0XFF;
	DDRC= 0XFF;
	DDRD= 0b11111110;


	//};
			     //0b01000000,0b01001000,0b01010000,0b01011000,0b01100000,0b01101000,0b01110000,0b01111000};




	int looper=0;
	int i=0;
	//sign(0,1);
//	sign(1,1);
//	sign(2,1);

	//sign(3,1);
	//sign(4,0);
//	sign(5,1);

	//sign(6,1);
//	sign(7,1);
//	sign(8,0);
	//int test[]={0b10000000,0b01000000,0b00100000,0b10000000,0b00010000,0b00001000,0b00000010,0b00000001};
	set_zero();// set the play array zero
	while(1)
	{
		for(i=0;i<16;i++){
			PORTB=rows[i][0];
			PORTA=rows[i][1];


			DDRD=0XFF;
			PORTD=arr[i];

			if(wait==0 && halt==0){

				DDRD=0X00;// set d as input
				if(PINC&0b00000001 && play_arr[0][0]==0){
					play_arr[0][0]=1+turn%2;
					sign(0,turn%2);
					turn++;
				}else if(PINC&0b00000010&& play_arr[0][1]==0){
					play_arr[0][1]=1+turn%2;
					sign(1,turn%2);
					turn++;
				}
				else if(PINC&0b00000100 && play_arr[0][2]==0){

					play_arr[0][2]=1+turn%2;
					sign(2,turn%2);
					turn++;
				}
				else if(PINC&0b00001000 && play_arr[1][0]==0){
					play_arr[1][0]=1+turn%2;
					sign(3,turn%2);
					turn++;
				}
				else if(PINC&0b00010000 && play_arr[1][1]==0){
					play_arr[1][1]=1+turn%2;
					sign(4,turn%2);
					turn++;
				}
				else if(PINC&0b00100000 && play_arr[1][2]==0){
					play_arr[1][2]=1+turn%2;
					sign(5,turn%2);
					turn++;
				}
				else if(PINC&0b01000000 && play_arr[2][0]==0){
					play_arr[2][0]=1+turn%2;
					sign(6,turn%2);
					turn++;
				}
				else if(PINC&0b10000000 && play_arr[2][1]==0){
					play_arr[2][1]=1+turn%2;
					sign(7,turn%2);
					turn++;
				}
				else if(PIND&0b00000001 && play_arr[2][2]==0){
					play_arr[2][2]=1+turn%2;
					sign(8,turn%2);
					turn++;
				}
				check_result();
				//PORTA=PIND&0b00000001;
			}
			else if(halt==1){
				halt_looper++;
				int l=0;

				if(halt_looper>5000){

					//if(new_winner>2)wdt_enable(WDTO_15MS);
					halt_looper=0;

					halt=0;
					wait=1;
					winner(new_winner);

					//wait=1;

				}

			}
			else if(wait==1) {
				wait_looper++;



				if(wait_looper>5000){
					wdt_enable(WDTO_2S);
					//set_game();
					//winner(new_winner);
					wait_looper=0;
					wait=0;
					turn=0;
					//new_winner=0;

					//set_game();
					wait=0;halt=0;
					wdt_enable(WDTO_15MS);
				//	if(new_winner!=3)wdt_enable(WDTO_15MS);
				//	else {set_game();wdt_enable(WDTO_15MS);}WDTO_15MS
				}
			}//*/

			_delay_ms(1);



		}

	}
}
void set_zero(){
	int i,j=0;
	for (i=0;i<3;i++){
		for(j=0;j<3;j++){
			play_arr[i][j]=0;
		}
	}
}
void set_game(){
	int a,b;
	for(a=0;a<16;a++){
		    rows[a][0]=0X00;
		    rows[a][1]=0X00;
			rows[a][0]=rows_saver[a][0];
			rows[a][1]=rows_saver[a][1];

	}
	//set_zero();
}
check_result(){

	// horizontal match
	if(play_arr[0][0]==play_arr[0][1] && play_arr[0][0]==play_arr[0][2] &&play_arr[0][0]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[0][0];
	}
	else if(play_arr[1][0]==play_arr[1][1] && play_arr[1][0]==play_arr[1][2]&&play_arr[1][0]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[1][0];
	}
	else if(play_arr[2][0]==play_arr[2][1] && play_arr[2][0]==play_arr[2][2] &&play_arr[2][0]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[2][0];
	}

	// vartical match
	else if(play_arr[0][0]==play_arr[1][0] && play_arr[0][0]==play_arr[2][0]&&play_arr[0][0]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[0][0];
	}
	else if(play_arr[0][1]==play_arr[1][1] && play_arr[0][1]==play_arr[2][1]&&play_arr[0][1]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[0][1];
	}
	else if(play_arr[0][2]==play_arr[1][2] && play_arr[0][2]==play_arr[2][2]&&play_arr[0][2]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[0][2];
	}

	// cross match

	else if(play_arr[0][0]==play_arr[1][1] && play_arr[0][0]==play_arr[2][2]&&play_arr[0][0]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[0][0];

	}
	else if(play_arr[0][2]==play_arr[1][1] && play_arr[0][2]==play_arr[2][0]&&play_arr[0][2]!=0){
		halt=1;
		delay=5;
		new_winner=play_arr[0][2];

	}

	else{// check for draw
		int i,j=0;
		int empty=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(play_arr[i][j]==0){
					new_winner=3;
				//	wdt_enable(WDTO_15MS);
					empty++;break;
				}

			}
		}
		if(empty==0){
			//set_game();
			//set_zero();
			//wait=1;
			//for()
			//wdt_enable(WDTO_15MS);
			halt=1;
			//wdt_enable(WDTO_15MS);
			new_winner=3;
		}

	}

}
void winner(int pl_no){
	//halt=0;
	set_game();
	if(pl_no==3){
		//	wdt_enable(WDTO_15MS);
			sign(0,1);
			sign(1,1);
			sign(2,1);

					sign(6,0);
			        sign(7,0);
					sign(8,0);
		}
	//set_zero();
	if(pl_no==1){
		sign(0,0);
		sign(1,0);
		sign(2,0);
		sign(3,0);
		sign(4,0);
		sign(5,0);
		sign(6,0);
		sign(7,0);
		sign(8,0);

	}else if(pl_no==2){
		sign(0,1);
		sign(1,1);
		sign(2,1);
		sign(3,1);
		sign(4,1);
		sign(5,1);
		sign(6,1);
        sign(7,1);
		sign(8,1);

	}
	//wdt_enable(WDTO_15MS);

}
void sign(int no, int type){//0 for box 1 for /
	int r_no=no/3;
	int c_no=no%3;
	int r_index=2+r_no*5;
	if (type==0){
		if (c_no==0){
		    	rows[r_index][0]=rows[r_index][0]|0b00110000;
			rows[r_index+1][0]=rows[r_index+1][0]|0b00110000;

		}
		else if (c_no==2){
			rows[r_index][1]=rows[r_index][1]|0b00001100;
			rows[r_index+1][1]=rows[r_index+1][1]|0b00001100;

		}
		else{
			rows[r_index][0]=rows[r_index][0]|0b00000001;
			rows[r_index+1][0]=rows[r_index+1][0]|0b00000001;

			rows[r_index][1]=rows[r_index][1]|0b10000000;
			rows[r_index+1][1]=rows[r_index+1][1]|0b10000000;

		}
	}
	else{
		if (c_no==0){


					rows[r_index+1][0]=rows[r_index+1][0]|0b0100000;//0b01100000
				    	rows[r_index][0]=rows[r_index][0]|0b00010000;

				}
				else if (c_no==2){

					rows[r_index+1][1]=rows[r_index+1][1]|0b00001000;
					    rows[r_index][1]=rows[r_index][1]|0b00000100;

				}
				else{
					rows[r_index+1][0]=rows[r_index+1][0]|0b00000001;
					//rows[r_index+1][0]=rows[r_index+1][0]|0b00000001;

					//rows[r_index][1]=rows[r_index][0]|0b10000000;
					rows[r_index][1]=rows[r_index][1]|0b10000000;

		}
	}


}

