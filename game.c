#include<stdio.h>
#include<stdlib.h>

int main(){
	
	
	int playerX;
	int playerO;
	int i;
	char data[9] = {'1','2','3','4','5','6','7','8','9'};
	int choice,maxchance=9,count=0;
	int win = 0;
	
	while(maxchance != count){
	
	printf("\n                tic tac toe        \ncount => |%d| \n",count+1);
	printf("                player 1 (X) - player 2 (0)             \n\n");
	printf("  %c  |  %c  |  %c  \n",data[0],data[1],data[2]);
	printf("_____|_____|_____\n");
	printf("  %c  |  %c  |  %c  \n",data[3],data[4],data[5]);
	printf("_____|_____|_____\n");
	printf("  %c  |  %c  |  %c  \n",data[6],data[7],data[8]);
	printf("     |     |     \n");
	
	printf("Enter your box number : ");
	scanf("%d",&choice);
	if(choice>0 && choice<10){
		count++;
		if(count%2 != 0){
			data[choice-1] = 'X';
		}
		else{
			data[choice-1] = '0';
		}
	}
	else{
		printf("wrong input");
	}
	
	  if ((data[0]==data[1] && data[1]==data[2]) ||
            (data[3]==data[4] && data[4]==data[5]) ||
            (data[6]==data[7] && data[7]==data[8]) ||
            (data[0]==data[3] && data[3]==data[6]) ||
            (data[1]==data[4] && data[4]==data[7]) ||
            (data[2]==data[5] && data[5]==data[8]) ||
            (data[0]==data[4] && data[4]==data[8]) ||
            (data[2]==data[4] && data[4]==data[6])) {
            win = 1;
        }

        
        if (win == 1) {
            printf("\n?? Player %d Wins! ??\n", (count % 2 == 0) ? 1 : 2);
            break;
        }

        
        if (count == 9 && win == 0) {
            printf("\n?? Game Draw!\n");
            break;
        }
    }
	
	
		
	}

	




		

