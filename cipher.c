#include<stdio.h> 
#include<string.h>
#include<stdlib.h>


char inputdata[500];
char matrix[500][500];

void errorMsg(char *msg){
	puts(msg);
	puts("Program syntax:\n./cipher SWITCH KEY LENGTH < FILENAME\n");
	puts("Legal usage examples:\n./cipher -e 10 100 < filename.txt");
	puts("./cipher -d 10 200 < filename.e\n");
}

void encrypt(int key, int length){
                char character;
                int counter= 0;

                for(int x = 0; x < length; x++){
                        character = getc(stdin);
                        inputdata[x] = character;
                        counter++;
                }

                double numRows = counter/key;
		if (counter%key!=0){
			int numRow = numRows + 1;
		}
		else{
			int numRow = numRows;
		}
		int v = 0;

                for(int y = 0; y < numRows+1; y++){
                        for(int z = 0; z < key; z++){

                                matrix[y][z] = inputdata[v];
				v++;
                        }
                }

                for(int p = 0; p < key; p++){
			for(int m = 0; m < numRows+1; m++){
                                printf("%c", matrix[m][p]);
                        }
		}
}

void decrypt(int key, int length){
	char character;
        int counter= 0;
	
	int range = key - length%key;
	for(int x = 0; x < length+range; x++){
        	character = getc(stdin);
               	inputdata[x] = character;
                counter++;
	}
	
	double numRows = counter/key;
        if (counter%key!=0){
        	int numRow = numRows + 2;
        }
        else{
                int numRow = numRows+1;
        }

	int v = 0;
        for(int z = 0; z < key; z++){
		for(int y = 0; y < numRows; y++){
			matrix[y][z] = inputdata[v];
			v++;
		}
	}

	for(int m = 0; m < numRows; m++){
        	for(int p = 0; p < key; p++){
			if(m == numRows-1){
				if(p < key - range){
					printf("%c", matrix[m][p]);
				}
			}
			else{
				printf("%c", matrix[m][p]);
			}
		}
	}
}

int main(int argc, char *argv[]){

	//printf("%s",argv[2]);
	//puts("\n");
	//printf("%s",argv[3]);
	//puts("\n");

	if (argc != 4){
	       	errorMsg("Incorrect number of arguments");
		return 1;}
	if ((strcmp(argv[1],"-d") != 0) && (strcmp(argv[1],"-e") != 0)){
	       	errorMsg("Invalid switch");
		return 1;}
	int u = atoi(argv[3]);
	if (u  >= 500){
	       	errorMsg("Length must be less than 500");
		return 1;} 
	if (u == 0 ){
		errorMsg("Length cannot be 0");
		return 1;
	}
	int c = atoi(argv[2]);
	if (c >= u){
	       	errorMsg("Key must be less than length");
		return 1;}
	
	if (c == 0){
		errorMsg("Key cannot be 0");
		return 1;
	}

	if(strcmp(argv[1],"-e") == 0){
		encrypt(c, u);
	}

	if(strcmp(argv[1],"-d") == 0){
		decrypt(c, u);
	}

return 0;
}
