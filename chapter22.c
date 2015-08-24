#include <stdio.h>
#include <string.h>

int main()
{
    //int a[10];
    char *a = "test data 12345678";
    char b[60];
    FILE *fp;
    if((fp = fopen("test.dat","rw")) == NULL)
    {
        printf("test.dat cannot be opened\n");
        return 0;
    }
/*
    for(int i = 0;i < 10;i++)
    {
        a[0] = i;
    }
*/
    fwrite(a,sizeof(a[0]),strlen(a),fp);

    fread(b,sizeof(a[0]),strlen(a),fp);
    //fputs(a,fp);
    //fgets(b,strlen(a),fp);
    printf("s = %s\n",b);
    return 0;
}
