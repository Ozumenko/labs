
#ifndef OAIP_LAB_BMP_H
typedef struct
{
    unsigned char signature[2];
    unsigned int size;
    unsigned short reverse;
    unsigned int ofset;
}BMPheader;
typedef struct
{
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsperpixel;
    unsigned int compression;
    unsigned int imagesize;
    int XPixelPerM;
    int yPixelPerM;
    unsigned int colorUsed;
    unsigned int importantcolors;
}BMPinfoHeader;
typedef struct{
    unsigned char b;//blue
    unsigned char g;//green
    unsigned char r;//red
}Pixel;
void initBMP(char*filename,int width,int height,Pixel*data){
    BMPheader header ;
    BMPinfoHeader infoHeader;
    FILE *fp;
    Pixel *rowBuffer;
    int rowSize,paddingSize,i,j;
}
#endif //OAIP_LAB_BMP_H
