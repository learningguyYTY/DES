#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char* plaintext;
char* ciphertext;
char* subkey;

void initialize();

int getbit(char* a, int b);

void writebit(char* a, int b, int c);

void print_binary(long a,int len);

void permutation(char* input,char* output,int output_len,int* table);

void left_shift(char* input, char* output, int l);

void generate_subkeys(long key);

char sbox(char* input,int index);

int mangler(char* input, char* output);

void encryption_block(char* plain_block, char* cipher_block);

void decryption_block(char* cipher_block, char* plain_block);