#include "base64.h"
AF1 af;
inline AF1 getAlen(const char *str, int len) {
    int base64len = 0;

    int times = 0;
    if (len % 3 == 0) {
        af.base64len = (len / 3) << 2;
        af.times = len / 3;
    } else {
        af.base64len = ((len + 2)/ 3) << 2;
        af.times = (len / 3) + 1;
    }
    return af;
}
inline int getBase64Length(int len) {
    return ((len + 2) / 3) * 4;
}

unsigned char *base64Encode(const char *str, int len) {
    AF1 re = getAlen(str, len);
    int times = re.times;
    int base64len = re.base64len;
//    printf("%d\n",len);
//    for (int i =0; str[i] != '\0'; i++){
//
//        printf("%c",str[i]);
//    }


    unsigned char *out = (unsigned char *) malloc(base64len + 1);

    int last_len = len;

    char ibuff[3] = {0};
    char obuff[4] = {0};

    int start = 0;

    for (int i = 0; i < times; i++) {

        if (last_len == 1) {

            memcpy(ibuff, str + strlen(str) - 1, 3);
//            printf("%d\n",ibuff[0]);
            int first = (ibuff[0] & (unsigned char) 0xfc) >> 2;
            int second = ((ibuff[0] & (unsigned char) 0x03) << 4) | (ibuff[1] & (unsigned char) 0xf0) >> 4;
            obuff[0] = data[(int) first];
            obuff[1] = data[(int) second];
            obuff[2] = '=';
            obuff[3] = '=';
            memcpy(out + (start * 4), obuff, 4);
            memset(ibuff, '\0', sizeof(ibuff));
            memset(obuff, '\0', sizeof(obuff));
            return out;

        } else if (last_len == 2) {
//            printf("last_len  :  %d\n", last_len);
            memcpy(ibuff, str + strlen(str) - 2, 3);
            int first = (ibuff[0] & (unsigned char) 0xfc) >> 2;
            int second = ((ibuff[0] & (unsigned char) 0x03) << 4) | (ibuff[1] & (unsigned char) 0xf0) >> 4;
            int third = (ibuff[1] & (unsigned char) 0xF) << 2 | (ibuff[2] & (unsigned char) 0xc0 >> 6);
            obuff[0] = data[(int) first];
            obuff[1] = data[(int) second];
            obuff[2] = data[(int) third];
            obuff[3] = '=';
            memcpy(out + (start * 4), obuff, 4);

            memset(ibuff, '\0', sizeof(ibuff));
            memset(obuff, '\0', sizeof(obuff));
            return out;
        } else {
            memcpy(ibuff, str, 3);
//            printf("%d=====%X\n",ibuff[0],ibuff[0]);
            int first = (ibuff[0] & (unsigned char) 0xfc) >> 2;
            int second = ((ibuff[0] & (unsigned char) 0x03) << 4) | (ibuff[1] & (unsigned char) 0xf0) >> 4;
            int third = (ibuff[1] & (unsigned char) 0x0F) << 2 | (ibuff[2] & (unsigned char) 0xc0) >> 6;
            int fouth = (ibuff[2] & (unsigned char) 0x3F);
            obuff[0] = data[(int) first];
            obuff[1] = data[(int) second];
            obuff[2] = data[(int) third];
            obuff[3] = data[(int) fouth];
            memcpy(out + (start * 4), obuff, 4);
            start++;
            str = str + 3;
            memset(ibuff, '\0', sizeof(ibuff));
            memset(obuff, '\0', sizeof(obuff));
            last_len = last_len - 3;
        }


    }

    return out;

}


    unsigned char *base64Encodenew(const char *str, int len) {
        int base64Len = getBase64Length(len);
        unsigned char *out = (unsigned char *) malloc(base64Len + 1);
        if (out == NULL)
            return NULL;
        int i = 0, j = 0;
        char ibuff[3] = {0};
        char obuff[4] = {0};

        while (i < len) {
            ibuff[0] = str[i++];
            ibuff[1] = (i < len) ? str[i++] : 0;
            ibuff[2] = (i < len) ? str[i++] : 0;

            obuff[0] = data[(ibuff[0] & 0xfc) >> 2];
            obuff[1] = data[((ibuff[0] & 0x03) << 4) | ((ibuff[1] & 0xf0) >> 4)];
            obuff[2] = (ibuff[1] != 0) ? data[((ibuff[1] & 0x0f) << 2) | ((ibuff[2] & 0xc0) >> 6)] : '=';
            obuff[3] = (ibuff[2] != 0) ? data[ibuff[2] & 0x3f] : '=';

            out[j++] = obuff[0];
            out[j++] = obuff[1];
            out[j++] = obuff[2];
            out[j++] = obuff[3];
        }

        out[base64Len] = '\0';
        return out;

    }