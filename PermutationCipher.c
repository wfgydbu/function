/* Permutation Cipher
 * Say Cipher is {2,5,1,4,6,3}
 * PlainText: CIPHER
 * Mode 1:
 * 	Put i-th PlainText in Cipher[i]-th position in CipherText.
 * 	Result: PCRHIE
 * Mode 2:
 * 	Put Cipher[i]-th PlainText in i-th position in CipherText.
 * 	Result: IECHRP 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode(int cipher[], int cipher_size, char* plaintext)
{	
	char *ciphertext = (char*)malloc(strlen(plaintext)+1);
	
	char *c = ciphertext;
	char *s = plaintext;
	int i;
	
	memset(ciphertext,'a',strlen(plaintext)+1);
	*(c+strlen(plaintext)) = '\0';
	
	while(*c != '\0'){
		/* Moed 1 */
		for(i = 0; i < cipher_size; i++){
			*(c+cipher[i]-1) = *s++;
		}

		c = c + cipher_size;
		
		/* Moed 2 */
		// for(i = 0; i < cipher_size; i++){
		//		*(c+i) = *(s + cipher[i] - 1);
		// }
		
		// s = s + cipher_size;
		// c = c + cipher_size;
		
	}
	
	return ciphertext;	
}

char* decode(int cipher[], int cipher_size, char* ciphertext)
{
	/* calculate cipher inverse */
	int i,j;
	int* anti_cipher = (int*)malloc(cipher_size * sizeof(int));
	
	for(i = 0; i < cipher_size; i++){
		j = cipher[i] - 1;
		*(anti_cipher + j) = i+1;
	}	
	
	return encode(anti_cipher, cipher_size, ciphertext);
}


int main(){
	char* plaintext = "LOVEISTHEONLYMEDICINEFORABROKENHEART";
	int cipher[] = {2,5,1,4,6,3};
	
	char* ciphertext = encode(cipher, 6, plaintext);
	printf("Encrypted:\t%s\n", ciphertext);
	printf("Decrypted:\t%s\n", decode(cipher,6,ciphertext));
	
}