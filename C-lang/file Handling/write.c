#include<stdio.h>

int main() {
    // writing a file------------------------------------
    FILE *fp;
    fp = fopen("file22.txt", "w");
    fprintf(fp, "My name is Vishal Kushwaha");
    fclose(fp);

    // reading file ------------------------------------
    // FILE *fp;
    // char arr;
    // fp = fopen("file22.txt", "r");

    // while ((arr = fgetc(fp)) !=EOF) {
    //     printf("%c ", arr);
    // }
    // rewind(fp);
    // while ((arr = fgetc(fp)) !=EOF) {
    //     printf("%c ", arr);
    // }
    // rewind(fp);
    // while ((arr = fgetc(fp)) !=EOF) {
    //     printf("%c ", arr);
    // }

    // FILE *fp;
    // fp = fopen("file33.txt", "w");
    // fputs("C Programming", fp);

    // fseek(fp,3,SEEK_SET);
    // fputs("practical", fp);

    // fclose(fp);

    // FILE *fp;
    // int length;
    // fp = fopen("file22.txt", "r");

    // fseek(fp, 0, SEEK_END);

    // length = ftell(fp);
    // printf("The Length of file is %d bytes", length);
    // fclose(fp);


    
}