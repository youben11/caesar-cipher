#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char** argv){

	if(argc!=2 || argv[1][0]!='-'){
		printf("Usage: %s -n  (0<n<26)\n",argv[0]);
		return 0;
	}

	char k[10],c;
	strcpy(k,&argv[1][1]);
	int key=atoi(k),typechar;

	if(key<1 || key>25){
		printf("Usage: %s -n  (0<n<26)\n",argv[0]);
		return 0;	
	} 

	printf("[*]Message to encrypt : ");

	while((c=getchar())!='\n'){
		
		if(isalpha(c)){

			typechar=(c<=90)? 65:97;
			c=c-typechar;
			c=(c+key)%26;
			printf("%c",c+65);
		
		}else printf("%c",c);

	}
	puts("");

	return 0;
}