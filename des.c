#include"des.h"

int PC_1[56] = {57,   49,    41,   33,    25,    17,    9,
                 1,   58,    50,   42,    34,    26,   18,
                10,    2,    59,   51,    43,    35,   27,
                19,   11,     3,   60,    52,    44,   36,
                63,   55,    47,   39,    31,    23,   15,
                 7,   62,    54,   46,    38,    30,   22,
                14,    6,    61,   53,    45,    37,   29,
                21,   13,     5,   28,    20,    12,    4};

int LShift[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

int PC_2[48] = {14,    17,   11,    24,     1,    5,
                 3,    28,   15,     6,    21,   10,
                23,    19,   12,     4,    26,    8,
                16,     7,   27,    20,    13,    2,
                41,    52,   31,    37,    47,   55,
                30,    40,   51,    45,    33,   48,
                44,    49,   39,    56,    34,   53,
                46,    42,   50,    36,    29,   32};

int IP[64] = {58,    50,   42,    34,    26,   18,    10,    2,
              60,    52,   44,    36,    28,   20,    12,    4,
              62,    54,   46,    38,    30,   22,    14,    6,
              64,    56,   48,    40,    32,   24,    16,    8,
              57,    49,   41,    33,    25,   17,     9,    1,
              59,    51,   43,    35,    27,   19,    11,    3,
              61,    53,   45,    37,    29,   21,    13,    5,
              63,    55,   47,    39,    31,   23,    15,    7};

int IP_1[64] = {40,     8,   48,    16,    56,   24,    64,   32,
                39,     7,   47,    15,    55,   23,    63,   31,
                38,     6,   46 ,   14,    54,   22,    62,   30,
                37,     5,   45,    13,    53,   21,    61,   29,
                36,     4,   44,    12,    52,   20,    60,   28,
                35,     3,   43,    11,    51,   19,    59,   27,
                34,     2,   42,    10,    50,   18,    58,   26,
                33,     1,   41,     9,    49,   17,    57,   25};

int E[48] = {32,     1,    2,     3,     4,    5,
              4,     5,    6,     7,     8,    9,
              8,     9,   10,    11,    12,   13,
             12,    13,   14,    15,    16,   17,
             16,    17,   18,    19,    20,   21,
             20,    21,   22,    23,    24,   25,
             24,    25,   26,    27,    28,   29,
             28,    29,   30,    31,    32,    1};

char S_box[0x200] = {
    //Sbox 1
     14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7,
      0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8,
      4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0,
     15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13, 
    //Sbox2        
     15,  1,   8, 14,   6, 11,   3,  4,   9,  7,   2, 13,  12,  0,   5, 10,
      3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5,
      0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15,
     13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9,
    //Sbox3     
     10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8,
     13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1,
     13,  6,   4,  9,   8, 15,   3,  0,  11,  1,   2, 12,   5, 10,  14,  7,
      1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12,
    //Sbox4      
      7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15,
     13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9,
     10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4,
      3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14,
    //Sbox5
      2, 12,   4,  1,   7, 10,  11,  6,   8,  5,   3, 15,  13,  0,  14,  9,
     14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6,
      4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3,   0, 14,
     11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3,
    //Sbox6
     12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11,
     10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8,
      9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6,
      4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13,      
    //Sbox7
      4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7,   5, 10,   6,  1,
     13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6,
      1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5,   9,  2,
      6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12,
    //Sbox8
     13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7,
      1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14,   9,  2,
      7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8,
      2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11,
};

void initialize(){
    plaintext = (char*)malloc(0x400);
    ciphertext = (char*)malloc(0x400);
    subkey = (char*)malloc(0x60); //48 bits of each sub key; 16 sub keys;
}

//get the bth bit of a
int getbit(char* a, int b){
    a += (b >> 3);
    b = b & 7;
    return ((*a) >> b) & 1;
}

//write the bth bit of a
void writebit(char* a, int b, int c){
    a += (b >> 3);
    b = b & 7; 
    char ch1 = 1 << b;
    char ch2 = 0xff - ch1;
    *a = c? ((*a) | ch1) : ((*a) & ch2);
}

//used just for debug
void print_binary(long a,int len){
    for(int i = 0; i < len; i++){
        printf("%d",getbit((char*)&a,i));
    }
    printf("\n");
}

void permutation(char* input,char* output,int output_len,int* table){
    for(int i = 0; i < output_len; i++){
        writebit(output, i, getbit(input,table[i]-1));
    }
}

void left_shift(char* input, char* output, int l){
    int a = (*((int*)input)) << l;
    for(int i = 0; i < l; i++){
        writebit((char*)&a,i,getbit((char*)&a,28+i));
    }
    a &= 0x0fffffff;
    memcpy(output,&a,4);
}

//generate subkeys from the 64-bit key
void generate_subkeys(long key){
    char key_56bit[8];
    char* key_left_right = (char*)malloc(0x88);
    permutation((char*)&key,key_56bit,28,PC_1);
    permutation((char*)&key,key_56bit+4,28,PC_1+28);
    memcpy(key_left_right,key_56bit,8);
    //left shift the subkeys
    for(int i = 1; i <= 16; i++){
        left_shift(key_left_right+(i-1)*8,key_left_right+i*8,LShift[i-1]);      //left half
        left_shift(key_left_right+(i-1)*8+4,key_left_right+i*8+4,LShift[i-1]);  //right half
    }
    //generate final subkeys
    for(int i = 1; i <= 16; i++){
        char* kl = key_left_right+i*8;
        char* kr = kl + 4;
        int a1 = *((int*)kl);
        int a2 = *((int*)kr);
        long a = a1 + (a2 << 28);
        permutation((char*)&a,subkey+(i-1)*6,48,PC_2);
    }
    //free(key_left_right);
}

//check S-box
char sbox(char* input,int index){
    int i = (((*((int*)input))>>4) + (*input & 1)) & 3;
    int j = ((*((int*)input))>>1) & 0xf;
    return S_box[64*index + 16*i + j];
}

//core function of the Feistel networks
int mangler(char* input, char* key){
    char expand[6];
    permutation(input,expand,48,E);
    for(int i = 0; i < 6; i++){
        expand[i] ^= *(key+i);
    }
    char result[4];
    for(int i = 0; i < 4; i++){
        char sbox_input[2];
        *((short*)sbox_input) = *((long*)expand) >> (12*i);
        result[i] = sbox(sbox_input,i*2);
        *((short*)sbox_input) = *((long*)expand) >> (12*i + 6);
        result[i] += sbox(sbox_input,i*2+1)<<4;
    }
    return *((int*)result);
}

//encrypt 1 single plaintext block of 64 bits
void encryption_block(char* plain_block, char* cipher_block){
    char pre_block[8];
    char this_block[8];
    permutation(plain_block,pre_block,64,IP);
    for(int i = 0; i < 16; i++){
        memcpy(this_block,pre_block+4,4);
        char ch[4];
        *((int*)(this_block+4)) = (*((int*)pre_block)) ^ mangler(pre_block+4, subkey+i*6);
        memcpy(pre_block,this_block,8);
    }
    permutation(this_block, cipher_block, 64, IP_1);
}

//decrypt 1 single ciphertext block of 64 bits
void decryption_block(char* cipher_block, char* plain_block){
    char pre_block[8];
    char this_block[8];
    permutation(cipher_block,pre_block,64,IP);
    for(int i = 0; i < 16; i++){
        memcpy(this_block+4,pre_block,4);
        char ch[4];
        *((int*)(this_block)) = (*((int*)(pre_block+4))) ^ mangler(this_block+4, subkey+i*6);
        memcpy(pre_block,this_block,8);
    }
    permutation(this_block, plain_block, 64, IP_1);
}

void encrypt(){
    memset(ciphertext,0,0x400);
    char* this_plain_block = plaintext;
    char* this_cipher_block = ciphertext;
    while(*((long*)this_plain_block)){
        encryption_block(this_plain_block,this_cipher_block);
        this_plain_block += 8;
        this_cipher_block += 8;
    }
}

void decrypt(){
    memset(plaintext,0,0x400);
    char* this_plain_block = plaintext;
    char* this_cipher_block = ciphertext;
    while(*((long*)this_cipher_block)){
        decryption_block(this_cipher_block,this_plain_block);
        this_plain_block += 8;
        this_cipher_block += 8;
    }
}