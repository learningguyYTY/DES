#include"des.h"
#include<unistd.h>

void menu(){
    puts("code by HIT Yi Tianyang");
    puts("-----------------------------");
    puts("0:input plain text in ASC II");
    puts("1:input plain text in hex");
    puts("2:input key in hex");
    puts("3:generate key by random");
    puts("4:encrypt");
    puts("5:decrypt");
    puts("6:show plaintext in ASC II");
    puts("7:show plaintext in hex");
    puts("8:show ciphertext in hex");
    puts("9:show key in hex");
    puts("10:exit");
}

int main(){
    initialize();
    long key = 0;
    int choice = -1;
    while(1){
        menu();
        fflush(stdin);
        puts("your choice:");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice){
        case 0:
            puts("input plaintext:");
            memset(plaintext,0,0x400);
            memset(ciphertext,0,0x400);
            read(0,plaintext,0x400);
            //gets_s(plaintext,0x400);
            fflush(stdin);
            break;
        case 1:
            puts("input plaintext in hex");
            puts("your input should be like:");
            puts("0123456789abcdef");
            memset(plaintext,0,0x400);
            memset(ciphertext,0,0x400);
            //gets_s(ciphertext,0x400);
            fflush(stdin);
            char* ptr = ciphertext;
            char block[20] = {0};
            int i = 0;
            while(1){
                memset(block,0,20);
                puts("input -1 to finish");
                printf("block%d:\n",i);
                read(0,block,20);
                //gets_s(block,16);
                fflush(stdin);
                if((block[0]=='-' && block[1]=='1') || i >= 0x80) break;
                long p = strtoll(block,(char**)(block+16),16);
                memcpy(plaintext + i*8,&p,8);
                i++;
            }
            break;
        case 2:
            key = 0;
            puts("input your 64-bit key in hex");
            puts("your input should be like:");
            puts("0123456789abcdef");
            char k[16] = {0};
            read(0,k,16);
            //gets_s(k,16);
            fflush(stdin);
            key = strtoll(k,(char**)(k+16),16);
            generate_subkeys(key);
            break;
        case 3:
            key = 0;
            srand(time(NULL));
            for(int i = 0; i < 8; i++){
                long r = rand() & 0xff;
                key |= (r << (8*i));
            }
            puts("key generated");
            break;
        case 4:
            encrypt();
            puts("plaintext encrypted");
            break;
        case 5:
            decrypt();
            puts("ciphertext decrypted");
            break;
        case 6:
            puts("plaintext:");
            puts(plaintext);
            break;
        case 7:
            puts("plaintext in hex:");
            long* ptr1 = (long*)plaintext;
            while(*ptr1){
                printf("%#018lx\n",*ptr1);
                ptr1++;
            }
            break;
        case 8:
            puts("ciphertext in hex:");
            long* ptr2 = (long*)ciphertext;
            while(*ptr2){
                printf("%#018lx\n",*ptr2);
                ptr2++;
            }
            break;
        case 9:
            puts("key:");
            printf("%#018lx\n",key);
            break;
        case 10:
            return 0;
        default:
            puts("wrong choice");
            break;
        }
    }

}
