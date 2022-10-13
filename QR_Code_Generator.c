/*
	A program to generate QR code
	Given a URL as input and output the QR in terminal
*/
#include <stdio.h>
#include <string.h>

//declare functions
int binarycon(int input,int colour);
int square(int colour);
int main(int argc,char* argv[])
{
	int col; //declare variables
	//set the command line arguments
	if(argc==1){
		col=40;	//if no argument is given set black and white as default
	}
	else {
		//-c flag is used to assign a color when printing
		if((argv[1][0]=='-')&&(argv[1][1]=='c')&&(argc==3)){
			
			if (((argv[2][0]=='r')||(argv[2][0]=='R'))&&((argv[2][1]=='e')||(argv[2][1]=='E'))&&((argv[2][2]=='d')||(argv[2][2]=='D'))&&(argv[2][3]=='\0')){
				col=41;
			}
			else if (((argv[2][0]=='b')||(argv[2][0]=='B'))&&((argv[2][1]=='l')||(argv[2][1]=='L'))&&((argv[2][2]=='u')||(argv[2][2]=='U'))&&((argv[2][3]=='e')||(argv[2][3]=='E'))&&(argv[2][4]=='\0')){
				col=44;
			}				
			else if (((argv[2][0]=='g')||(argv[2][0]=='G'))&&((argv[2][1]=='r')||(argv[2][1]=='R'))&&((argv[2][2]=='e')||(argv[2][2]=='E'))&&((argv[2][3]=='e')||(argv[2][3]=='E'))&&((argv[2][4]=='n')||(argv[2][4]=='N'))&&(argv[2][5]=='\0')){
				col=42;
			}
			else if (((argv[2][0]=='y')||(argv[2][0]=='Y'))&&((argv[2][1]=='e')||(argv[2][1]=='E'))&&((argv[2][2]=='l')||(argv[2][2]=='L'))&&((argv[2][3]=='l')||(argv[2][3]=='L'))&&((argv[2][4]=='o')||(argv[2][4]=='O'))&&((argv[2][5]=='w')||(argv[2][5]=='W'))&&(argv[2][6]=='\0')){
				col=43;
			}
			else if (((argv[2][0]=='m')||(argv[2][0]=='M'))&&((argv[2][1]=='a')||(argv[2][1]=='A'))&&((argv[2][2]=='g')||(argv[2][2]=='G'))&&((argv[2][3]=='e')||(argv[2][3]=='E'))&&((argv[2][4]=='n')||(argv[2][4]=='N'))&&((argv[2][5]=='t')||(argv[2][5]=='T'))&&((argv[2][6]=='a')||(argv[2][6]=='A'))&&(argv[2][7]=='\0')){
				col=45;
			}
			else if (((argv[2][0]=='b')||(argv[2][0]=='B'))&&((argv[2][1]=='l')||(argv[2][1]=='L'))&&((argv[2][2]=='a')||(argv[2][2]=='A'))&&((argv[2][3]=='c')||(argv[2][3]=='C'))&&((argv[2][4]=='k')||(argv[2][4]=='K'))&&(argv[2][5]=='\0')){
				col=40;
			}
			else if (((argv[2][0]=='c')||(argv[2][0]=='C')) && ((argv[2][1]=='y')||(argv[2][1]=='Y')) &&((argv[2][2]=='a')||(argv[2][2]=='A'))&& ((argv[2][3]=='n')||(argv[2][3]=='N'))&&(argv[2][4]=='\0')){
				col=46;
			}
			
			//when color does not support with the QR
			else{
				printf("Invalid argument for color.\n");
				printf("usage :\n");
				printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
				printf("%s -h for the help about the program\n",argv[0]);
				return -1;	
			}
			
		}
		//-h flag is given for print the usage of the program 
		else if((argv[1][0]=='-')&&(argv[1][1]=='h')&&(argc==2)&&(argv[1][2]=='\0')){
			printf("usage :\n");
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
			printf("%s -h for the help about the program\n",argv[0]);
			return -1;
		}
		// when arguments are incorrect
		else{
			printf("Incorrect usage of arguments.\n");
			printf("usage :\n");
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
			printf("%s -h for the help about the program\n",argv[0]);
			return -1;
		}
	}
	//create the hashed string for smaller versions of QR
	char str[130];//declare array to input string
	int urlen;
	printf("Enter the URL: ");
	scanf("%s",str);//input the standard URL that we want to generate as QR
	urlen=strlen(str);//get the length of given URL
	//when URL length smaller than 3 characters 
	if(urlen<=3){
		printf("String is too short.Not supported by available QR versions.\n");
	}
	//to get the QR when 3<URL length<=20
	else if(urlen<=20){
		int i,x,y,z;
		char hashstr[24];//array to store hashed string characters when URL length smaller than 20
		char news[24];// new array to store final hashed string
		hashstr[0]=urlen+50;//to obtain first character of the hashed string
		for(i=1;i<=urlen;++i){
			hashstr[i]=str[i-1];//to obtain next L characters(equal to the string length) of hashed string
		}
		//to obtain next (24-L-1) characters of hashed string
		for(i=(urlen+1);i<24;++i){
			if(i<=(2*urlen)){
				hashstr[i]=str[i-urlen-1]+1;
			}
			else if((i>(2*urlen))&&(i<=(3*urlen))){
				hashstr[i]=str[i-(2*urlen)-1]+2;
			}
			else if((i>(3*urlen))&&(i<=(4*urlen))){
				hashstr[i]=str[i-(3*urlen)-1]+3;
			}
			else if((i>(4*urlen))&&(i<=(5*urlen))){
				hashstr[i]=str[i-(4*urlen)-1]+4;
			}
			else{
				hashstr[i]=str[i-(5*urlen)-1]+5;
			}
		}
		//to create final hasheed string
		for(int j=0;j<=23;++j){
			if(j<=urlen){
				news[j]=hashstr[j];
			}
			else{
				news[j]=hashstr[24-j+urlen];//reverse the (24-L-1) charcters of hashed array
			
			}
		}

		news[24]='\0';
		
		printf("\x1b[2J");
		printf("\x1b[2;3H");
		square(col);// to print position identification square at top left corner in QR
		//to print the hashed string characters from 17 to 20
		x=16;
		while(x<=19){
			for (int l=1;l<=2;l++){
				for(int k=1;k<=2;k++){
					binarycon(news[x],col);
					++x;
				}
				if(l<2){
					printf("\x1b[12D");
					printf("\x1b[3B");	
		
				}
				else{
					printf("\x1b[2B");
				}
		
			}
		}
		printf("\x1b[5A");//set the cursor to print next position identification square
		square(col);// to print position identification square at top right corner in QR 
		printf("\x1b[36D");
		printf("\x1b[6B");
		//to print the hashed string characters from 21 to 24
		y=20;
		while(y<=23){
			for (int l=1;l<=2;l++){
				for(int k=1;k<=2;k++){
					binarycon(news[y],col);
					++y;
				}
				if(l<2){
					printf("\x1b[12D");
					printf("\x1b[3B");	
		
				}
				else{
					printf("\x1b[2B");
				}
		
			}
		}
		printf("\x1b[5A");
		//to print the hashed string characters from 1 to 16
		z=0;
		while(z<=15){
			for (int l=1;l<=4;l++){
				for(int k=1;k<=4;k++){
					binarycon(news[z],col);
					++z;
				}
				if(l<4){
					printf("\x1b[24D");
					printf("\x1b[3B");	
		
				}
				else{
					printf("\x1b[2B");
				}
		
			}
		}
		printf("\x1b[36D");
		printf("\x1b[5A");
		square(col);// to print position identification square at bottom left corner in QR
		printf("\x1b[6B");
		printf("\x1b[14D");
		//to print the border in QR
		for(int i=1;i<=20;++i){
			printf("\x1b[47m  \x1b[0m");
		}
		printf("\x1b[19A");
		printf("\x1b[40D");
		for(int i=1;i<=20;++i){
			printf("\x1b[47m  \x1b[0m");
		}
		printf("\x1b[2D");
		printf("\x1b[1B");
		for(int i=1;i<=18;++i){
			printf("\x1b[47m  \x1b[0m");
			if(i<18){
				printf("\x1b[2D");
				printf("\x1b[1B");
			}
		}
		printf("\x1b[40D");
		printf("\x1b[17A");
		for(int i=1;i<=18;++i){
			printf("\x1b[47m  \x1b[0m");
			if(i<18){
				printf("\x1b[2D");
				printf("\x1b[1B");
			}
		}
		printf("\x1b[2D");
		printf("\x1b[3B");
		
	}
	//to get the QR when 20<URL length<=120
	else if(urlen<=120){
		int i,j,x,y,z;
		unsigned char hashstr[132];//array to store hashed string characters when URL length greater than 20
		unsigned char news[132];// new array to store final hashed string
		hashstr[0]=urlen+50;//to obtain the first character of the hashed string
		for(i=1;i<=urlen;++i){
			hashstr[i]=str[i-1];//to obtain next L characters(equal to the string length) of hashed string
		}
		//to obtain next (132-L-1) characters of hashed string
		for(i=(urlen+1);i<132;++i){
			if(i<=(2*urlen)){
				hashstr[i]=str[i-urlen-1]+1;
			}
			else if((i>(2*urlen))&&(i<=(3*urlen))){
				hashstr[i]=str[i-(2*urlen)-1]+2;
			}
			else if((i>(3*urlen))&&(i<=(4*urlen))){
				hashstr[i]=str[i-(3*urlen)-1]+3;
			}
			else if((i>(4*urlen))&&(i<=(5*urlen))){
				hashstr[i]=str[i-(4*urlen)-1]+4;
			}
			else{
				hashstr[i]=str[i-(5*urlen)-1]+5;
			}
		}
		//to create the final hahsed string
		for(j=0;j<=132;++j){
			if(j<=urlen){
				news[j]=hashstr[j];
			}
			else{
				news[j]=hashstr[132-j+urlen];
			}
		}

		news[132]='\0';
		printf("\x1b[2J");
		printf("\x1b[2;3H");
		square(col);// to print position identification square at top left corner in QR
		//to print the hashed string characters from 101 to 116
		x=100;
		while(x<=115){
			for (int l=1;l<=2;l++){
				for(int k=1;k<=8;k++){
					binarycon(news[x],col);
					++x;
				}
				if(l<2){
					printf("\x1b[48D");
					printf("\x1b[3B");	
		
				}
				else{
					printf("\x1b[2B");
				}
		
			}
		}
		printf("\x1b[5A");
		square(col);// to print position identification square at top right corner in QR
		printf("\x1b[72D");
		printf("\x1b[6B");
		//to print the hashed string characters from 117 to 132
		y=116;
		while(y<=131){
			for (int l=1;l<=8;l++){
				for(int k=1;k<=2;k++){
					binarycon(news[y],col);
					++y;
				}
				if(l<8){
					printf("\x1b[12D");
					printf("\x1b[3B");	
		
				}
				else{
					printf("\x1b[2B");
				}
		
			}
		}
		printf("\x1b[23A");
		//to print the hashed string characters from 1 to 100
		z=0;
		while(z<=99){
			for (int l=1;l<=10;l++){
				for(int k=1;k<=10;k++){
					binarycon(news[z],col);
					++z;
				}
				if(l<10){
					printf("\x1b[60D");
					printf("\x1b[3B");	
		
				}
				else{
					printf("\x1b[2B");
				}
		
			}
		}
		printf("\x1b[72D");
		printf("\x1b[5A");
		square(col);// to print position identification square at bottom left corner in QR
		printf("\x1b[6B");
		printf("\x1b[14D");
		//to print the border in QR
		for(int i=1;i<=38;++i){
			printf("\x1b[47m  \x1b[0m");
		}
		printf("\x1b[37A");
		printf("\x1b[76D");
		for(int i=1;i<=38;++i){
			printf("\x1b[47m  \x1b[0m");
		}
		printf("\x1b[2D");
		printf("\x1b[1B");
		for(int i=1;i<=36;++i){
			printf("\x1b[47m  \x1b[0m");
			if(i<36){
				printf("\x1b[2D");
				printf("\x1b[1B");
			}
		}
		printf("\x1b[76D");
		printf("\x1b[35A");
		for(int i=1;i<=36;++i){
			printf("\x1b[47m  \x1b[0m");
			if(i<36){
				printf("\x1b[2D");
				printf("\x1b[1B");
			}
		}
		printf("\x1b[2D");
		printf("\x1b[3B");
		
	}
	//when URL length gteater than 120 characters 
	else{
		printf("String is too long.Not supported by available QR versions.\n");
	}
	return 0;
}
// a function to create position identification square
int square(int colour)
{
	int l,k;
	//to create 6*6 square
	for(l=1;l<=6;++l){
		for(k=1;k<=6;++k){
			if((l==1 || l==6 || k==1 || k==6) || ((l>=3 && l<=4 && k>=3 && k<=4) && (l==3 || l==4 || k==3 || k==4))){
				printf("\x1b[%dm  \x1b[0m",colour);
			}
			
			else{
				printf("\x1b[47m  \x1b[0m");
			}
			
		}
		if(l<6){
			printf("\x1b[12D");//set the cursor at next line
			printf("\x1b[1B");
		}
		else{
			printf("\x1b[5A");//set the cursor at top right corner in square
		}
	}
	return 0;
}
// a function to create a character square
int binarycon(int input,int colour){
	int i=0,j,k,l,r;
	int binary[9]={};// array for store binary value in 9 bits of ASCII value of character
	int newbinary[9];
	//to obtain binary value of the character in 9 bits
	while(input>0){
		r=input%2;
		binary[i]=r;
		input=input/2;
		i++;
	}
	for(j=8;j>=0;j--){
		newbinary[j]=binary[j];
	
	}

	//to create 3*3 square for 9 bits binary value
	j=8;
	for(l=1;l<=3;++l){
		for(k=1;k<=3;++k){
			
			if(newbinary[j]==0){
				printf("\x1b[47m  \x1b[0m");
			}
			else{
				printf("\x1b[%dm  \x1b[0m",colour);
			}
			j--;
		}
		if(l<3){
			printf("\x1b[6D");//set the cursor at next line
			printf("\x1b[1B");
		}
		else{
			printf("\x1b[2A");//set the cursor at top rigth corner in square
		}
		
	}
	return 0;
}
