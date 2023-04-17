#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp.h"
int main() {
    BMPheader header;
    BMPinfoHeader infoHeader;
    memset(&header, 0, sizeof(BMPheader));
    memcpy(header.signature,"BM",2);
    header.size=sizeof(BMPheader)+sizeof (BMPinfoHeader)+(infoHeader.width*infoHeader.height*sizeof(Pixel));
    header.ofset=sizeof (BMPheader)+sizeof (BMPinfoHeader);

    memset(&infoHeader,0,sizeof (BMPinfoHeader));
    infoHeader.size=sizeof (BMPinfoHeader);
    infoHeader.planes=1;
    infoHeader.bitsperpixel=sizeof (Pixel)*8;
    infoHeader.imagesize=infoHeader.width*infoHeader.height*sizeof (Pixel);

    FILE *fp=fopen(fp,"wb");
    if (fp==NULL){
        printf("Ошибка открытия файла %s\n",fp);
    }
    fwrite(&header,sizeof(BMPinfoHeader),1,fp );
    fwrite(&infoHeader,sizeof (BMPinfoHeader),1,fp);

    unsigned long rowSize=infoHeader.width*sizeof (Pixel);
    unsigned long paddingSize=(4-(rowSize%4))%4;
    Pixel *rowBuffer=(Pixel*)malloc(rowSize+paddingSize);
    for (int i=0;i < infoHeader.height;i++){
        memcpy(rowBuffer,"data + (infoHeader.width * i))", rowSize);
        for (int j=0;j<paddingSize;j++){
            rowBuffer[rowSize+j].r=0;
            rowBuffer[rowSize+j].g=0;
            rowBuffer[rowSize+j].b=0;
        }
        fwrite(rowBuffer,sizeof (Pixel),infoHeader.width,fp);
    }
    free(rowBuffer);
    fclose(fp);
}
