#include<stdio.h>
#include<math.h>
#include<ctype.h>
void any_radix_to_dec(int digg[],int dig,int base) {
	int ans=0;
	for (int i=dig-1;i>=0;i--) {
		ans+=digg[dig-1-i]*(pow(base,i));
	}
	printf("The final answer is: %d\n",ans);
}
int dec_to_any_radix(int digg[],int dig,int ans[],int base) {
	int combine=0,j=0;
	for (int i=0;i<dig;i++) {
		combine=combine*10+digg[i];
	}
	while(combine>0) {
		ans[j]=combine%base;
		combine/=base;
		j++;
	}
	return j;
}
void bin_to_oct(int digg[],int dig,char bin_oct_res[]) {
	char oct[8]={'0','1','2','3','4','5','6','7'};
	int groupsiz=3;
	int group[100][3]={0};
	int g=0,k=0;
	for (int i=dig-1;i>=0;i--) {
		group[g][k]=digg[i];
		k++;
		if (k==groupsiz) {
			g++;
			k=0;
		}
	}
	int total=(dig+2)/3;
	for (int i=total-1;i>=0;i--) {
		int val=0;
		for (int j=0;j<groupsiz;j++) {
			val=val*2+group[i][groupsiz-1-j];
		}
		bin_oct_res[total-1-i]=oct[val];
	}
}
void oct_to_bin(int digg[],int dig,char* oct_bin_res[]) {
	char *bin[8]={"000","001","010","011","100","101","110","111"};
	for (int i=0;i<dig;i++) {
		oct_bin_res[i]=bin[digg[i]];
	}
}
void bin_to_hexadec(int digg[],int dig,char bin_hexadec_res[]) {
	char hexadec[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int groupsiz=4;
	int group[100][4]={0};
	int g=0,k=0;
	for (int i=dig-1;i>=0;i--) {
		group[g][k]=digg[i];
		k++;
		if (k==groupsiz) {
			g++;
			k=0;
		}
	}
	int total=(dig+3)/4;
	for (int i=total-1;i>=0;i--) {
		int val=0;
		for (int j=0;j<groupsiz;j++) {
			val=val*2+group[i][groupsiz-1-j];
	}
		bin_hexadec_res[total-1-i]=hexadec[val];
} 
}
void hexadec_to_bin(int digg[],int dig,char* hexadec_bin_res[]) {
	char *bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
	for (int i=0;i<dig;i++) {
		hexadec_bin_res[i]=bin[digg[i]];
	}
}
int main() {
	int n;
	while(1) {
		printf("List of Conversions");
		printf("\n1.Binary -> Decimal\n2.Octal -> Decimal\n3.Hexa Decimal -> Decimal\n");
		printf("4.Decimal -> Binary\n5.Decimal -> Octal\n6.Decimal -> Hexadecimal\n");
		printf("7.Binary -> Octal\n8.Octal -> Binary\n");
		printf("9.Binary -> Hexa Decimal\n10.Hexa Decimal -> Binary\n");
		printf("11.Octal -> Hexa Decimal\n12.Hexa Decimal -> Octal\n");
		printf("Enter number which Conversion you want - ");
		scanf("%d",&n);
		if (n==1) {
			printf("You selected Binary -> Decimal\n");
			int dig,base=2;
			printf("Enter how many digits of binary number: ");
			scanf("%d",&dig);
			int digg[dig];
			printf("Enter the digits of binary number: \n");
			for (int i=0;i<dig;i++) {
				while (1) {
				printf("%d number is: ",i+1);
				scanf("%d",&digg[i]);
				if (digg[i]==0 || digg[i]==1) {
					break;
				}
				else {
					printf("the binary number should be 0 or 1 only\n");
				}
			}
		}
			any_radix_to_dec(digg,dig,base);
		}
		if (n==2) {
			printf("You selected Octal -> Decimal\n");
			int dig,base=8;
			printf("Enter how many digits of Octal number: ");
			scanf("%d",&dig);
			int digg[dig];
			printf("Enter the digits of Octal number: \n");
			for (int i=0;i<dig;i++) {
				while (1) {
				printf("%d number is: ",i+1);
				scanf("%d",&digg[i]);
				if (digg[i]>=0 && digg[i]<=7) {
					break;
				}
				else {
					printf("the Octal number should be between 0 to 7 only\n");
				}
			}
		}
			any_radix_to_dec(digg,dig,base);
		}
		if (n==3) {
			printf("You selected Hexa Decimal -> Decimal\n");
			int dig,base=16;
			printf("Enter how many digits of Hexa Decimal number: ");
			scanf("%d",&dig);
			int digg[dig];
			char alpha;
			printf("Enter the digits of Hexa Decimal number: \n");
			for (int i=0;i<dig;i++) {
				int digoralp;
				while (1) {
				printf("%d number is 1.Digit or 2.Alphabet: ",i+1);
				scanf("%d",&digoralp);
				if (digoralp==1) {
					printf("Enter digit: ");
					scanf("%d",&digg[i]);
				if (digg[i]>=0 && digg[i]<=9) {
						break;
				}
				else {
					printf("the Hexa Decimal number numbers should be between 0 to 9 only or try alphabets\n");
				}
			}
			if (digoralp==2) {
				printf("Enter Alphabet: ");
					scanf(" %c",&alpha);
					alpha=tolower(alpha);
					if (alpha>='a' && alpha<='f') {
						digg[i]=10+(alpha-'a');
						break;
					}
					else {
						printf("the Hexa Decimal number Alphabets should be between a to f only or try numbers\n");
					}
				}
				else {
					printf("You need to select only 1.digit or 2.Alphabet only");
					break;
				}
				}
		}
		    any_radix_to_dec(digg,dig,base);
		}
		if (n==4) {
			printf("You selected Decimal -> Binary\n");
			int dig;
			printf("Enter how many digits of Decimal number: ");
			scanf("%d",&dig);
			int digg[dig];
			printf("Enter the digits of Decimal number: \n");
			for (int i=0;i<dig;i++) {
				while(1) {
					printf("%d number is: ",i+1);
					scanf("%d",&digg[i]);
					if (digg[i]>=0 && digg[i]<=9) {
						break;
					}
					else {
						printf("The decimal number should be between 0 to 9 only\n");
					}
				}
			}
			int ans[32],base=2;
			int j=dec_to_any_radix(digg,dig,ans,base);
			printf("The final answer is: ");
	        for (int k=j-1;k>=0;k--) {
		    printf("%d ",ans[k]);
           	}
	         printf("\n"); 
		}
		if (n==5) {
			printf("You selected Decimal -> Octal\n");
			int dig;
			printf("Enter how many digits of Decimal number: ");
			scanf("%d",&dig);
			int digg[dig];
			printf("Enter the digits of Decimal number: \n");
			for (int i=0;i<dig;i++) {
				while(1) {
					printf("%d number is: ",i+1);
					scanf("%d",&digg[i]);
					if (digg[i]>=0 && digg[i]<=9) {
						break;
					}
					else {
						printf("The decimal number should be between 0 to 9 only\n");
					}
				}
			}
			int ans[32],base=8;
			int j=dec_to_any_radix(digg,dig,ans,base);
			printf("The final answer is: ");
	        for (int k=j-1;k>=0;k--) {
		    printf("%d",ans[k]);
        	}
         	printf("\n");
		}
		if (n==6) {
			printf("You selected Decimal -> Hexa Decimal\n");
			int dig;
			printf("Enter how many digits of Decimal number: ");
			scanf("%d",&dig);
			int digg[dig];
			printf("Enter the digits of Decimal number: \n");
			for (int i=0;i<dig;i++) {
				while(1) {
					printf("%d number is: ",i+1);
					scanf("%d",&digg[i]);
					if (digg[i]>=0 && digg[i]<=9) {
						break;
					}
					else {
						printf("The decimal number should be between 0 to 9 only\n");
					}
				}
			}
			int ans[32],base=16;
			int j=dec_to_any_radix(digg,dig,ans,base);
			printf("The final answer is: ");
           	for (int k=j-1;k>=0;k--) {
	       	if (ans[k]>=10 && ans[k]<=16) {
	       		printf("%c",'A'+(ans[k]-10));
			   }
			   else {
			   printf("%d",ans[k]);
			   }
	        }
	        printf("\n");
		}
			if (n==7) {
			printf("You selected Binary -> Octal\n");
			int dig;
			while (1) {
			printf("Enter how many digits of binary number: ");
			scanf("%d",&dig);
			if (dig>=3) {
				break;
			}
			else {
				printf("the binary number should be >=3 to covert into Octal\n");
			}
			}
			int digg[dig];
			printf("Enter the digits of binary number: \n");
			for (int i=0;i<dig;i++) {
				while (1) {
				printf("%d number is: ",i+1);
				scanf("%d",&digg[i]);
				if (digg[i]==0 || digg[i]==1) {
					break;
				}
				else {
					printf("the binary number should be 0 or 1 only\n");
				}
			}
		}
		    char bin_oct_res[(dig+2)/3];
			bin_to_oct(digg,dig,bin_oct_res);
			printf("The final answer is: ");
			for (int j=0;j<(dig+2)/3;j++) {
				printf("%c ",bin_oct_res[j]);
			}
			printf("\n");
		}
		if(n==8) {
			printf("You selected Octal -> Binary\n");
			int dig;
			printf("Enter how many digits of Octal number: ");
			scanf("%d",&dig);
			int digg[dig];
			char* oct_bin_res[dig];
			for (int i=0;i<dig;i++) {
				while (1) {
					printf("%d number is: ",i+1);
					scanf("%d",&digg[i]);
					if (digg[i]>=0 && digg[i]<=7) {
						break;
					}
					else {
						printf("The Octal number should be between 0 and 7 only\n");
					}
				}
			}
			oct_to_bin(digg,dig,oct_bin_res);
	        printf("The final answer is: ");
			for (int j=0;j<dig;j++) {
				printf("%s ",oct_bin_res[j]);
			}
			printf("\n");
		}
		if (n==9) {
			printf("You selected Binary -> Hexa Decimal\n");
			int dig;
			while (1) {
			printf("Enter how many digits of binary number: ");
			scanf("%d",&dig);	
			if (dig>=4) {
				break;
			}
			else {
				printf("the binary number should be >=4 to convert into Hexa decimal\n");
			}
			}
			int digg[dig];
			printf("Enter the digits of binary number: \n");
			for (int i=0;i<dig;i++) {
				while (1) {
				printf("%d number is: ",i+1);
				scanf("%d",&digg[i]);
				if (digg[i]==0 || digg[i]==1) {
					break;
				}
				else {
					printf("the binary number should be 0 or 1 only\n");
				}
			}
		}
		    char bin_hexadec_res[(dig+3)/4];
			bin_to_hexadec(digg,dig,bin_hexadec_res);
			printf("The final answer is: ");
			for (int j=0;j<(dig+3)/4;j++) {
				printf("%c",bin_hexadec_res[j]);
			}
			printf("\n");
		}
		if (n==10) {
			printf("You selected Hexa Decimal -> Binary\n");
			int dig;
			printf("Enter how many digits of Hexa Decimal number: ");
			scanf("%d",&dig);
			int digg[dig];
			char alpha;
			printf("Enter the digits of Hexa Decimal number: \n");
			for (int i=0;i<dig;i++) {
				int digoralp;
				while (1) {
				printf("%d number is 1.Digit or 2.Alphabet: ",i+1);
				scanf("%d",&digoralp);
				if (digoralp==1) {
					printf("Enter digit: ");
					scanf("%d",&digg[i]);
				if (digg[i]>=0 && digg[i]<=9) {
						break;
				}
				else {
					printf("the Hexa Decimal number numbers should be between 0 to 9 only or try alphabets\n");
				}
			}
			if (digoralp==2) {
				printf("Enter Alphabet: ");
					scanf(" %c",&alpha);
					alpha=tolower(alpha);
					if (alpha>='a' && alpha<='f') {
						digg[i]=10+(alpha-'a');
						break;
					}
					else {
						printf("the Hexa Decimal number Alphabets should be between a to f only or try numbers\n");
					}
				}
				else {
					printf("You need to select only 1.digit or 2.Alphabet only");
					break;
				}
				}
				 
		}
		    char* hexa_bin_res[dig];
		    hexadec_to_bin(digg,dig,hexa_bin_res);
		    printf("The final answer is: ");
		    for (int j=0;j<dig;j++) {
		    	printf("%s ",hexa_bin_res[j]);
			}
			printf("\n");
	}
	if(n==11) {
	printf("You selected Octal -> Hexa Decimal\n");
			int dig;
			printf("Enter how many digits of Octal number: ");
			scanf("%d",&dig);
			int digg[dig];
			printf("Enter the digits of Octal number: \n");
			for (int i=0;i<dig;i++) {
				while (1) {
				printf("%d number is: ",i+1);
				scanf("%d",&digg[i]);
				if (digg[i]>=0 && digg[i]<=7) {
					break;
				}
				else {
					printf("the Octal number should be between 0 to 7 only\n");
				}
			}
		}
		    int oct_bin_res[dig*3];
			int n=0;
			for (int i=0;i<dig;i++) {
				int oct_bin_res_arr=digg[i];
				oct_bin_res[n+2]= oct_bin_res_arr%2; oct_bin_res_arr/=2;
				oct_bin_res[n+1]= oct_bin_res_arr%2; oct_bin_res_arr/=2;
				oct_bin_res[n]= oct_bin_res_arr%2;
				n+=3;
			}
			int total=(dig*3+3)/4;
			char bin_hexadec_res[total];
			bin_to_hexadec(oct_bin_res,dig*3,bin_hexadec_res);
			printf("The final answer is: ");
			for (int j=0;j<total;j++) {
				printf("%c",bin_hexadec_res[j]);
			}
			printf("\n");
}
   if (n==12) {
   	printf("You selected Hexa Decimal -> Octal\n");
			int dig;
			printf("Enter how many digits of Hexa Decimal number: ");
			scanf("%d",&dig);
			int digg[dig];
			char alpha;
			printf("Enter the digits of Hexa Decimal number: \n");
			for (int i=0;i<dig;i++) {
				int digoralp;
				while (1) {
				printf("%d number is 1.Digit or 2.Alphabet: ",i+1);
				scanf("%d",&digoralp);
				if (digoralp==1) {
					printf("Enter digit: ");
					scanf("%d",&digg[i]);
					printf("%d number is %d\n",i+1,digg[i]);
				if (digg[i]>=0 && digg[i]<=9) {
						break;
				}
				else {
					printf("the Hexa Decimal number numbers should be between 0 to 9 only or try alphabets\n");
				}
			}
			if (digoralp==2) {
				printf("Enter Alphabet: ");
					scanf(" %c",&alpha);
					printf("%d number is %c\n",i+1,alpha);
					if (alpha>='a' && alpha<='f') {
						digg[i]=10+(alpha-'a');
						break;
					}
					else {
						printf("the Hexa Decimal number Alphabets should be between a to f only or try numbers\n");
					}
				}
				else {
					printf("You need to select only 1.digit or 2.Alphabet only");
					break;
				}
				}
			}
		int hexadec_bin_res[dig*4];
		int n=0;
		for (int i=0;i<dig;i++) {
			int hexadec_bin_res_arr=digg[i];
			hexadec_bin_res[n+3]=hexadec_bin_res_arr%2; hexadec_bin_res_arr/=2;
			hexadec_bin_res[n+2]=hexadec_bin_res_arr%2; hexadec_bin_res_arr/=2;
			hexadec_bin_res[n+1]=hexadec_bin_res_arr%2; hexadec_bin_res_arr/=2;
			hexadec_bin_res[n]=hexadec_bin_res_arr%2;
			n+=4;
		}
		int total=(dig*4+2)/3;
		char bin_oct_res[total];
		bin_to_oct(hexadec_bin_res,dig*4,bin_oct_res);
		printf("The final answer is: ");
			for (int j=0;j<total;j++) {
				printf("%c",bin_oct_res[j]);
			}
			printf("\n");
}
}
}