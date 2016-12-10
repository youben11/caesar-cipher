#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc,char** argv){

	if(argc!=1){
		printf("Usage: %s\n",argv[0]);
		return 0;
	}

	char c,*message;
	int key,typechar,size=0;

	printf("[*]Message to bruteforce : ");

	while((c=getchar())!='\n'){
		message=realloc(message,(size+1)*sizeof(char));
		message[size]=c;
		size++;
	}

	for(int i=1;i<26;i++){
		key=i;
		for(int j=0;j<size;j++){
			
			c=message[j];
		
			if (isalpha(c)){

				typechar=(c<=90)? 65:97;
				c=c-typechar;
				c=(c+26-key)%26;
				printf("%c",c+65);
			
			}else printf("%c",c);
		}
		puts("");
	}

	return 0;
}