#include"des.h"

int main(){
    initialize();

    
    long key = 0x133457799BBCDFF1;
    generate_subkeys(key);
    long message = 0x0123456789abcdef;
    memcpy(plaintext,&message,8);
    encryption_block(plaintext,ciphertext);
    printf("cipher:%#lx\n",*((long*)ciphertext));

    
    key = ~0x133457799BBCDFF1;
    generate_subkeys(key);
    message = ~0x0123456789abcdef;
    memcpy(plaintext,&message,8);
    encryption_block(plaintext,ciphertext);
    printf("cipher:%#lx\n",~(*((long*)ciphertext)));
    
    
}
