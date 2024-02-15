#include <stdio.h>
#include <math.h>

//OMER BIRCAN SAHIN 02200 2010 75 ORGUN OGRETIM

void detectAxRegister(int num);

void detectBxRegister(int num);

void detectCxRegister(int num);

void detectDxRegister(int num);

void RUN();

void clear();

void seeArray();

void HRK();

void TOP();

void CRP();

void CIK();

void BOL();

void DEG();

void VE();

void VEYA();

void MATH(int *arr1, int *arr2, char operator);

void charToIntConvert();

int isNumber(int num);

void fix1();

void fillInArray(int num1, int num2, char operand, int *arr1);

int findDecimalValue(int *array);

void decimalToBinaryConvert(int *array, int decimalValue);

void fillRegisterWithNumber(char *array, int numberOfDigit, int org);

void ifIsNumber(int number, int *array, char operation);

void ifIsNumberForLogicAndOperation(int number, int *array);

void ifIsNumberForLogicOrOperation(int number, int *array);

char arr[255];
int size = (sizeof(arr) / sizeof(arr[0]));
int isA, isB, isC, isD, isNum = 0;

char aXArr[8]; //ax'in  8 bitlik veri tutabilen bir char dizisi
char bXArr[8]; //bx'in  8 bitlik veri tutabilen bir char dizisi
char cXArr[8]; //cx'in  8 bitlik veri tutabilen bir char dizisi
char dXArr[8]; //dx'in  8 bitlik veri tutabilen bir char dizisi

int aXArrInt[8] = {0}; //ax'in  8 bitlik veri tutabilen bir int dizisi
int bXArrInt[8] = {0}; //bx'in  8 bitlik veri tutabilen bir int dizisi
int cXArrInt[8] = {0}; //cx'in  8 bitlik veri tutabilen bir int dizisi
int dXArrInt[8] = {0}; //dx'in  8 bitlik veri tutabilen bir int dizisi

int main() {

    FILE *file;

    file = fopen("C:\\Users\\OmerPC\\CLionProjects\\assembler\\test.txt", "r"); // KENDI TEXT DOSYANIZ EKLEYINIZ

    if (file != NULL) {

        int codes, i = 0;

        while ((codes = fgetc(file)) != EOF) arr[i++] = codes; //dizinin içine char'ları atamak


        RUN();//ASSEMBLER'IN calismasina yariyan kod


        fclose(file); //dosyayi kapatmak

    } else printf("file couldn't found ");

    return 0;

}

void seeArray() {

    printf("\nINDEX|7 6 5 4 3 2 1 0|\n");

    printf("\nAX = [%d,%d,%d,%d,%d,%d,%d,%d]\n", aXArrInt[7], aXArrInt[6], aXArrInt[5], aXArrInt[4], aXArrInt[3],
           aXArrInt[2], aXArrInt[1], aXArrInt[0]);
    printf("BX = [%d,%d,%d,%d,%d,%d,%d,%d]\n", bXArrInt[7], bXArrInt[6], bXArrInt[5], bXArrInt[4], bXArrInt[3],
           bXArrInt[2], bXArrInt[1], bXArrInt[0]);
    printf("CX = [%d,%d,%d,%d,%d,%d,%d,%d]\n", cXArrInt[7], cXArrInt[6], cXArrInt[5], cXArrInt[4], cXArrInt[3],
           cXArrInt[2], cXArrInt[1], cXArrInt[0]);
    printf("DX = [%d,%d,%d,%d,%d,%d,%d,%d]\n", dXArrInt[7], dXArrInt[6], dXArrInt[5], dXArrInt[4], dXArrInt[3],
           dXArrInt[2], dXArrInt[1], dXArrInt[0]);


}

void HRK() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'H' && arr[i + 1] == 'R' && arr[i + 2] == 'K' && arr[i + 5] == 'X' && arr[i + 6] == ',') {

            switch (arr[i + 4]) {//ilk register kontrolu

                case 'A':
                    isA++;
                    if (isNumber(i + 7) == 1) isNum++; // 2. alan sabit mi yoksa register mi kontrolu
                    detectAxRegister(i + 6);
                    break;
                case 'B':
                    isB++;
                    if (isNumber(i + 7) == 1) isNum++; // 2. alan sabit mi yoksa register mi kontrolu
                    detectBxRegister(i + 6);
                    break;
                case 'C':
                    isC++;
                    if (isNumber(i + 7) == 1) isNum++; // 2. alan sabit mi yoksa register mi kontrolu
                    detectCxRegister(i + 6);
                    break;
                case 'D':
                    isD++;
                    if (isNumber(i + 7) == 1) isNum++; // 2. alan sabit mi yoksa register mi kontrolu
                    detectDxRegister(i + 6);
                    break;
                default:
                    break;
            }

        }

    }

}

void detectAxRegister(int num) {

    //num , den sonraki  max 8 bitlik veri için gerekli olan index değeri başlangici


    if (isA != 0 && isNum != 0) {

        int numberOfDigit = 0;

        for (int i = num; i < num + 9; ++i)
            if (arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' ||
                arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
                numberOfDigit++;

        fillRegisterWithNumber(aXArr, numberOfDigit, num);

        isNum--;

    } else { // 2. deger registerse

        switch (arr[num + 1]) {

            case 'B':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) aXArrInt[i] = bXArrInt[i];

                break;
            case 'C':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) aXArrInt[i] = cXArrInt[i];

                break;
            case 'D':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) aXArrInt[i] = dXArrInt[i];

                break;
            default:
                break;

        }

    }

}

void detectBxRegister(int num) {

    //num , den sonraki max 8 bitlik veri için gerekli olan index değeri başlangici

    if (isA != 0 && isNum != 0) {

        int numberOfDigit = 0;

        for (int i = num; i < num + 9; ++i)
            if (arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' ||
                arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
                numberOfDigit++;

        fillRegisterWithNumber(bXArr, numberOfDigit, num);

        isNum--;

    } else {

        switch (arr[num + 1]) {

            case 'A':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) bXArrInt[i] = aXArrInt[i];

                break;
            case 'C':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) bXArrInt[i] = cXArrInt[i];

                break;
            case 'D':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) bXArrInt[i] = dXArrInt[i];

                break;
            default:
                break;

        }

    }

}

void detectCxRegister(int num) {

    //num , den sonraki max 8 bitlik veri için gerekli olan index değeri başlangici

    if (isA != 0 && isNum != 0) {

        int numberOfDigit = 0;

        for (int i = num; i < num + 9; ++i)
            if (arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' ||
                arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
                numberOfDigit++;

        fillRegisterWithNumber(cXArr, numberOfDigit, num);

        isNum--;

    } else {

        switch (arr[num + 1]) {

            case 'A':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) cXArrInt[i] = aXArrInt[i];

                break;
            case 'B':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) cXArrInt[i] = bXArrInt[i];

                break;
            case 'D':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) cXArrInt[i] = dXArrInt[i];

                break;
            default:
                break;

        }

    }

}

void detectDxRegister(int num) {

    //num , den sonraki max 8 bitlik veri için gerekli olan index değeri başlangici

    if (isA != 0 && isNum != 0) {

        int numberOfDigit = 0;

        for (int i = num; i < num + 9; ++i)
            if (arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' ||
                arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
                numberOfDigit++;

        fillRegisterWithNumber(dXArr, numberOfDigit, num);

        isNum--;

    } else {

        switch (arr[num + 1]) {

            case 'A':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) dXArrInt[i] = aXArrInt[i];

                break;
            case 'B':

                for (int i = 0; i < 8; i++) dXArrInt[i] = bXArrInt[i];

                break;
            case 'C':

                for (int i = 0; i < 8 && arr[num + 2] == 'X'; i++) dXArrInt[i] = cXArrInt[i];

                break;
            default:
                break;

        }

    }

}

void TOP() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'T' && arr[i + 1] == 'O' && arr[i + 2] == 'P' && arr[i + 5] == 'X' && arr[i + 6] == ',') {

            switch (arr[i + 4]) {//işlemin ustune yazilacagi register kontrolu

                case 'A'://ilk register AX ise

                    if (isNumber(i + 7) == 1) ifIsNumber(i, aXArrInt, '+');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(aXArrInt, aXArrInt, '+');
                            break;
                        case 'B':
                            MATH(aXArrInt, bXArrInt, '+');
                            break;
                        case 'C':
                            MATH(aXArrInt, cXArrInt, '+');
                            break;
                        case 'D':
                            MATH(aXArrInt, dXArrInt, '+');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'B':// İLK REGİSTER BX İSE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, bXArrInt, '+');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(bXArrInt, aXArrInt, '+');
                            break;
                        case 'B':
                            MATH(bXArrInt, bXArrInt, '+');
                            break;
                        case 'C':
                            MATH(bXArrInt, cXArrInt, '+');
                            break;
                        case 'D':
                            MATH(bXArrInt, dXArrInt, '+');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'C'://ILK REGISTER CX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, cXArrInt, '+');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(cXArrInt, aXArrInt, '+');
                            break;
                        case 'B':
                            MATH(cXArrInt, bXArrInt, '+');
                            break;
                        case 'C':
                            MATH(cXArrInt, cXArrInt, '+');
                            break;
                        case 'D':
                            MATH(cXArrInt, dXArrInt, '+');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'D'://ILK REGISTER DX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, dXArrInt, '+');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu


                        case 'A':
                            MATH(dXArrInt, aXArrInt, '+');
                            break;
                        case 'B':
                            MATH(dXArrInt, bXArrInt, '+');
                            break;
                        case 'C':
                            MATH(dXArrInt, cXArrInt, '+');
                            break;
                        case 'D':
                            MATH(dXArrInt, dXArrInt, '+');
                            break;
                        default:
                            break;

                    }

                    break;
                default:
                    break;

            }

        }

    }

}

void CRP() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'C' && arr[i + 1] == 'R' && arr[i + 2] == 'P' && arr[i + 5] == 'X' && arr[i + 6] == ',') {

            switch (arr[i + 4]) {//işlemin ustune yazilacagi register kontrolu

                case 'A'://ilk register AX ise

                    if (isNumber(i + 7) == 1) ifIsNumber(i, aXArrInt, '*');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(aXArrInt, aXArrInt, '*');
                            break;
                        case 'B':
                            MATH(aXArrInt, bXArrInt, '*');
                            break;
                        case 'C':
                            MATH(aXArrInt, cXArrInt, '*');
                            break;
                        case 'D':
                            MATH(aXArrInt, dXArrInt, '*');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'B':// İLK REGİSTER BX İSE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, bXArrInt, '*');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(bXArrInt, aXArrInt, '*');
                            break;
                        case 'B':
                            MATH(bXArrInt, bXArrInt, '*');
                            break;
                        case 'C':
                            MATH(bXArrInt, cXArrInt, '*');
                            break;
                        case 'D':
                            MATH(bXArrInt, dXArrInt, '*');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'C'://ILK REGISTER CX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, cXArrInt, '*');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(cXArrInt, aXArrInt, '*');
                            break;
                        case 'B':
                            MATH(cXArrInt, bXArrInt, '*');
                            break;
                        case 'C':
                            MATH(cXArrInt, cXArrInt, '*');
                            break;
                        case 'D':
                            MATH(cXArrInt, dXArrInt, '*');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'D'://ILK REGISTER DX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, dXArrInt, '*');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu


                        case 'A':
                            MATH(dXArrInt, aXArrInt, '*');
                            break;
                        case 'B':
                            MATH(dXArrInt, bXArrInt, '*');
                            break;
                        case 'C':
                            MATH(dXArrInt, cXArrInt, '*');
                            break;
                        case 'D':
                            MATH(dXArrInt, dXArrInt, '*');
                            break;
                        default:
                            break;

                    }

                    break;
                default:
                    break;

            }

        }

    }

}

void CIK() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'C' && arr[i + 1] == 'I' && arr[i + 2] == 'K' && arr[i + 5] == 'X' && arr[i + 6] == ',') {

            switch (arr[i + 4]) {//işlemin ustune yazilacagi register kontrolu

                case 'A'://ilk register AX ise

                    if (isNumber(i + 7) == 1) ifIsNumber(i, aXArrInt, '-');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(aXArrInt, aXArrInt, '-');
                            break;
                        case 'B':
                            MATH(aXArrInt, bXArrInt, '-');
                            break;
                        case 'C':
                            MATH(aXArrInt, cXArrInt, '-');
                            break;
                        case 'D':
                            MATH(aXArrInt, dXArrInt, '-');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'B':// İLK REGİSTER BX İSE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, bXArrInt, '-');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(bXArrInt, aXArrInt, '-');
                            break;
                        case 'B':
                            MATH(bXArrInt, bXArrInt, '-');
                            break;
                        case 'C':
                            MATH(bXArrInt, cXArrInt, '-');
                            break;
                        case 'D':
                            MATH(bXArrInt, dXArrInt, '-');
                            break;
                        default:
                            break;
                    }

                    break;
                case 'C'://ILK REGISTER CX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, cXArrInt, '-');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(cXArrInt, aXArrInt, '-');
                            break;
                        case 'B':
                            MATH(cXArrInt, bXArrInt, '-');
                            break;
                        case 'C':
                            MATH(cXArrInt, cXArrInt, '-');
                            break;
                        case 'D':
                            MATH(cXArrInt, dXArrInt, '-');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'D'://ILK REGISTER DX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, dXArrInt, '-');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(dXArrInt, aXArrInt, '-');
                            break;
                        case 'B':
                            MATH(dXArrInt, bXArrInt, '-');
                            break;
                        case 'C':
                            MATH(dXArrInt, cXArrInt, '-');
                            break;
                        case 'D':
                            MATH(dXArrInt, dXArrInt, '-');
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

        }

    }

}

void BOL() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'B' && arr[i + 1] == 'O' && arr[i + 2] == 'L' && arr[i + 5] == 'X' && arr[i + 6] == ',') {

            switch (arr[i + 4]) {//işlemin ustune yazilacagi register kontrolu

                case 'A'://ilk register AX ise

                    if (isNumber(i + 7) == 1) ifIsNumber(i, aXArrInt, '/');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(aXArrInt, aXArrInt, '/');
                            break;
                        case 'B':
                            MATH(aXArrInt, bXArrInt, '/');
                            break;
                        case 'C':
                            MATH(aXArrInt, cXArrInt, '/');
                            break;
                        case 'D':
                            MATH(aXArrInt, dXArrInt, '/');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'B':// İLK REGİSTER BX İSE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, bXArrInt, '/');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(dXArrInt, aXArrInt, '/');
                            break;
                        case 'B':
                            MATH(dXArrInt, bXArrInt, '/');
                            break;
                        case 'C':
                            MATH(dXArrInt, cXArrInt, '/');
                            break;
                        case 'D':
                            MATH(dXArrInt, dXArrInt, '/');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'C'://ILK REGISTER CX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, cXArrInt, '/');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(cXArrInt, aXArrInt, '/');
                            break;
                        case 'B':
                            MATH(cXArrInt, bXArrInt, '/');
                            break;
                        case 'C':
                            MATH(cXArrInt, cXArrInt, '/');
                            break;
                        case 'D':
                            MATH(cXArrInt, dXArrInt, '/');
                            break;
                        default:
                            break;

                    }

                    break;
                case 'D'://ILK REGISTER DX ISE

                    if (isNumber(i + 7) == 1) ifIsNumber(i, dXArrInt, '/');

                    switch (arr[i + 7]) {//2. registerin ne oldugu kontrolu

                        case 'A':
                            MATH(dXArrInt, aXArrInt, '/');
                            break;
                        case 'B':
                            MATH(dXArrInt, bXArrInt, '/');
                            break;
                        case 'C':
                            MATH(dXArrInt, cXArrInt, '/');
                            break;
                        case 'D':
                            MATH(dXArrInt, dXArrInt, '/');
                            break;
                        default:
                            break;
                    }

                    break;
                default:
                    break;

            }

        }

    }

}

void MATH(int *arr1, int *arr2, char operator) {

    //arr1 değişen register

    switch (operator) {

        case '+':
            for (int i = 0; i < 8; ++i) {
                arr1[i] += arr2[i];
                if (arr1[i] >= 10) arr1[i] = arr1[i] % 10, arr1[i + 1]++;
            }
            break;
        case '-':
            for (int i = 0; i < 8; ++i) {
                arr1[i] -= arr2[i];
                if (arr1[i] < 0) arr1[i] += 10, arr1[i + 1]--;
            }
        case '*':
            fillInArray(findDecimalValue(arr1), findDecimalValue(arr2), '*', arr1);
            break;
        case '/':
            fillInArray(findDecimalValue(arr1), findDecimalValue(arr2), '/', arr1);
            break;

    }

}

void charToIntConvert() {

    for (int i = 0; i < 8; ++i)
        aXArrInt[i] = aXArr[i] - '0', bXArrInt[i] = bXArr[i] - '0', cXArrInt[i] = cXArr[i] - '0', dXArrInt[i] =
                dXArr[i] - '0';

}

void clear() {

    for (int i = 0; i < 8; ++i) aXArr[i] = '0', bXArr[i] = '0', cXArr[i] = '0', dXArr[i] = '0';

}

void RUN() {

    clear();//eger hic bir komut yazilmamissa registerleri elemanlarini sifirliyor

    HRK();

    charToIntConvert();//tum registerdeki verileri int dizisine aktarmaya yariyor

    fix1();

    DEG();

    VE();
    VEYA();

    TOP();
    CIK();
    BOL();
    CRP();

    seeArray(); // registerleri goruntulemeye yariyor

}

int isNumber(int num) {

    if (arr[num] == '0' || arr[num] == '1' || arr[num] == '2' || arr[num] == '3' || arr[num] == '4' ||
        arr[num] == '5' || arr[num] == '6' || arr[num] == '7' || arr[num] == '8' || arr[num] == '9')
        return 1;
    else return 0;

}

void DEG() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'D' && arr[i + 1] == 'E' && arr[i + 2] == 'G' && arr[i + 5] == 'X') {

            if (arr[i + 4] == 'A') {
                unsigned char number = findDecimalValue(aXArrInt);
                number = ~number;
                decimalToBinaryConvert(aXArrInt, number);
            }
            if (arr[i + 4] == 'B') {
                unsigned char number = findDecimalValue(bXArrInt);
                number = ~number;
                decimalToBinaryConvert(bXArrInt, number);
            }
            if (arr[i + 4] == 'C') {
                unsigned char number = findDecimalValue(cXArrInt);
                number = ~number;
                decimalToBinaryConvert(cXArrInt, number);
            }
            if (arr[i + 4] == 'D') {
                unsigned char number = findDecimalValue(dXArrInt);
                number = ~number;
                decimalToBinaryConvert(dXArrInt, number);
            }
        }
    }

}

void VE() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'V' && arr[i + 1] == 'E' && arr[i + 4] == 'X' && arr[i + 5] == ',') {

            switch (arr[i + 3]) {

                case 'A'://ilk register AX ise

                    decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                    if (isNumber(i + 6) == 1) ifIsNumberForLogicAndOperation(i, aXArrInt);

                    switch (arr[i + 6]) {

                        case 'A':
                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 0) aXArrInt[j] = 0;
                            break;
                        case 'B':

                            decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 0 || bXArrInt[j] == 0) aXArrInt[j] = 0;

                            break;
                        case 'C':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 0 || cXArrInt[j] == 0) aXArrInt[j] = 0;

                            break;
                        case 'D':

                            decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 0 || dXArrInt[j] == 0) aXArrInt[j] = 0;

                            break;
                        default:
                            break;
                    }

                    break;
                case 'B':

                    decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                    if (isNumber(i + 6) == 1) ifIsNumberForLogicAndOperation(i, bXArrInt);

                    switch (arr[i + 6]) {

                        case 'A':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 0 || aXArrInt[j] == 0) bXArrInt[j] = 0;

                            break;
                        case 'B':

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 0) bXArrInt[j] = 0;

                            break;
                        case 'C':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 0 || cXArrInt[j] == 0) bXArrInt[j] = 0;

                            break;
                        case 'D':

                            decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 0 || dXArrInt[j] == 0) bXArrInt[j] = 0;

                            break;
                        default:
                            break;
                    }

                    break;
                case 'C':

                    decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                    if (isNumber(i + 6) == 1) ifIsNumberForLogicAndOperation(i, cXArrInt);

                    switch (arr[i + 6]) {

                        case 'A':

                            decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 0 || aXArrInt[j] == 0) cXArrInt[j] = 0;

                            break;
                        case 'B':

                            decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 0 || bXArrInt[j] == 0) cXArrInt[j] = 0;

                            break;
                        case 'C':

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 0) cXArrInt[j] = 0;

                            break;
                        case 'D':

                            decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 0 || dXArrInt[j] == 0) cXArrInt[j] = 0;

                            break;
                        default:
                            break;
                    }

                    break;
                case 'D':

                    decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                    if (isNumber(i + 6) == 1) ifIsNumberForLogicAndOperation(i, dXArrInt);

                    switch (arr[i + 6]) {

                        case 'A':

                            decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 0 || aXArrInt[j] == 0) dXArrInt[j] = 0;

                            break;
                        case 'B':

                            decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 0 || bXArrInt[j] == 0) dXArrInt[j] = 0;

                            break;
                        case 'C':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 0 || cXArrInt[j] == 0) dXArrInt[j] = 0;

                            break;
                        case 'D':

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 0) dXArrInt[j] = 0;

                            break;
                        default:
                            break;
                    }

                    break;
                default:
                    break;
            }

        }
    }

}

void VEYA() {

    for (int i = 0; i < size; ++i) {

        if (arr[i] == 'V' && arr[i + 1] == 'E' && arr[i + 2] == 'Y' && arr[i + 3] == 'A' && arr[i + 6] == 'X' &&
            arr[i + 7] == ',') {

            switch (arr[i + 5]) {

                case 'A'://ilk registe AX ise

                    decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                    if (isNumber(i + 8) == 1) ifIsNumberForLogicOrOperation(i, aXArrInt);

                    switch (arr[i + 8]) {

                        case 'A':

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 0) aXArrInt[j] = 0;

                            break;
                        case 'B':

                            decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 1 || bXArrInt[j] == 1) aXArrInt[j] = 1;

                            break;
                        case 'C':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 1 || cXArrInt[j] == 1) aXArrInt[j] = 1;

                            break;
                        case 'D':

                            decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                            for (int j = 0; j < 8; ++j) if (aXArrInt[j] == 1 || dXArrInt[j] == 1) aXArrInt[j] = 1;

                            break;
                        default:
                            break;
                    }

                    break;
                case 'B':

                    decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                    if (isNumber(i + 8) == 1) ifIsNumberForLogicOrOperation(i, bXArrInt);

                    switch (arr[i + 8]) {

                        case 'A':

                            decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 1 || aXArrInt[j] == 1) bXArrInt[j] = 1;

                            break;
                        case 'B':

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 0) bXArrInt[j] = 0;

                            break;
                        case 'C':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 1 || cXArrInt[j] == 1) bXArrInt[j] = 1;

                            break;
                        case 'D':

                            decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                            for (int j = 0; j < 8; ++j) if (bXArrInt[j] == 1 || dXArrInt[j] == 1) bXArrInt[j] = 1;

                            break;
                        default:
                            break;
                    }

                    break;
                case 'C':

                    decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                    if (isNumber(i + 8) == 1) ifIsNumberForLogicOrOperation(i, cXArrInt);

                    switch (arr[i + 8]) {

                        case 'A':

                            decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 1 || aXArrInt[j] == 1) cXArrInt[j] = 1;

                            break;
                        case 'B':

                            decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 1 || bXArrInt[j] == 1) cXArrInt[j] = 1;

                            break;
                        case 'C':

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 0) cXArrInt[j] = 0;

                            break;
                        case 'D':

                            decimalToBinaryConvert(dXArrInt, findDecimalValue(dXArrInt));

                            for (int j = 0; j < 8; ++j) if (cXArrInt[j] == 1 || dXArrInt[j] == 1) cXArrInt[j] = 1;

                            break;
                        default:
                            break;
                    }

                    break;
                case 'D':

                    decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                    if (isNumber(i + 8) == 1) ifIsNumberForLogicOrOperation(i, dXArrInt);

                    switch (arr[i + 8]) {

                        case 'A':

                            decimalToBinaryConvert(aXArrInt, findDecimalValue(aXArrInt));

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 1 || aXArrInt[j] == 1) dXArrInt[j] = 1;

                            break;
                        case 'B':

                            decimalToBinaryConvert(bXArrInt, findDecimalValue(bXArrInt));

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 1 || bXArrInt[j] == 1) dXArrInt[j] = 1;

                            break;
                        case 'C':

                            decimalToBinaryConvert(cXArrInt, findDecimalValue(cXArrInt));

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 1 || cXArrInt[j] == 1) dXArrInt[j] = 1;

                            break;
                        case 'D':

                            for (int j = 0; j < 8; ++j) if (dXArrInt[j] == 0) dXArrInt[j] = 0;

                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

void ifIsNumber(int number, int *array, char operation) {

    char temporaryArray[8];
    int temporaryArrayInt[8];

    //number+7  VİRGULDEN SONRAKI INDEX

    switch (operation) {
        case '+':
            for (int j = 0; j < 8; ++j) temporaryArray[j] = arr[number + 7 + j];

            for (int j = 0; j < 8; ++j) temporaryArrayInt[j] = temporaryArray[j] - '0';

            for (int j = 0; j < 8; ++j) array[j] += temporaryArrayInt[j];
            break;
        case '-':
            for (int j = 0; j < 8; ++j) temporaryArray[j] = arr[number + 7 + j];

            for (int j = 0; j < 8; ++j) temporaryArrayInt[j] = temporaryArray[j] - '0';

            for (int j = 0; j < 8; ++j) array[j] -= temporaryArrayInt[j];
            break;
        case '*':
            for (int j = 0; j < 8; ++j) temporaryArray[j] = arr[number + 7 + j];

            for (int j = 0; j < 8; ++j) temporaryArrayInt[j] = temporaryArray[j] - '0';

            for (int j = 0; j < 8; ++j) array[j] *= temporaryArrayInt[j];
            break;
        case '/':
            for (int j = 0; j < 8; ++j) temporaryArray[j] = arr[number + 7 + j];

            for (int j = 0; j < 8; ++j) temporaryArrayInt[j] = temporaryArray[j] - '0';

            for (int j = 0; j < 8; ++j) array[j] /= temporaryArrayInt[j];
            break;
        default:
            break;
    }

}

void ifIsNumberForLogicAndOperation(int number, int *array) {

    char temporaryArray[8];

    int temporaryArrayInt[8];

    for (int j = 0; j < 8; ++j) temporaryArray[j] = arr[number + 6 + j];

    for (int j = 0; j < 8; ++j) temporaryArrayInt[j] = temporaryArray[j] - '0';

    for (int j = 0; j < 8; ++j) if (array[j] == 0 || temporaryArrayInt[j] == 0) array[j] = 0;

}

void ifIsNumberForLogicOrOperation(int number, int *array) {

    char temporaryArray[8];

    int temporaryArrayInt[8];

    for (int j = 0; j < 8; ++j) temporaryArray[j] = arr[number + 8 + j];

    for (int j = 0; j < 8; ++j) temporaryArrayInt[j] = temporaryArray[j] - '0';

    for (int j = 0; j < 8; ++j) if (array[j] == 1 || temporaryArrayInt[j] == 1) array[j] = 1;

}

void fix1() {
    //8 BİT HARİCİ YUKLEME DUZELTME
    for (int i = 0; i < 8; ++i) {
        if (aXArrInt[i] != 0 && aXArrInt[i] != 1 && aXArrInt[i] != 2 && aXArrInt[i] != 3 && aXArrInt[i] != 4 &&
            aXArrInt[i] != 5 && aXArrInt[i] != 6 && aXArrInt[i] != 7 && aXArrInt[i] != 8 && aXArrInt[i] != 9)
            aXArrInt[i] = 0;
        if (bXArrInt[i] != 0 && bXArrInt[i] != 1 && bXArrInt[i] != 2 && bXArrInt[i] != 3 && bXArrInt[i] != 4 &&
            bXArrInt[i] != 5 && bXArrInt[i] != 6 && bXArrInt[i] != 7 && bXArrInt[i] != 8 && bXArrInt[i] != 9)
            bXArrInt[i] = 0;
        if (cXArrInt[i] != 0 && cXArrInt[i] != 1 && cXArrInt[i] != 2 && cXArrInt[i] != 3 && cXArrInt[i] != 4 &&
            cXArrInt[i] != 5 && cXArrInt[i] != 6 && cXArrInt[i] != 7 && cXArrInt[i] != 8 && cXArrInt[i] != 9)
            cXArrInt[i] = 0;
        if (dXArrInt[i] != 0 && dXArrInt[i] != 1 && dXArrInt[i] != 2 && dXArrInt[i] != 3 && dXArrInt[i] != 4 &&
            dXArrInt[i] != 5 && dXArrInt[i] != 6 && dXArrInt[i] != 7 && dXArrInt[i] != 8 && dXArrInt[i] != 9)
            dXArrInt[i] = 0;
    }
}

void fillRegisterWithNumber(char *array, int numberOfDigit, int org) {

    if (numberOfDigit == 1) array[0] = arr[org + 1];
    else if (numberOfDigit > 1) for (int i = numberOfDigit; i > 0; --i) array[i - 1] = arr[org + 1], org++;

}

int findDecimalValue(int *array) {

    int result = 0;

    for (int i = 0; i < 8; ++i) {

        result += (array[i] * pow(10, i));

    }

    return result;

}

void decimalToBinaryConvert(int *array, int decimalValue) {

    for (int i = 0; i < 8; ++i) array[i] = decimalValue % 2, decimalValue /= 2;

}

void fillInArray(int num1, int num2, char operand, int *arr1) {

    int first1, second1, third1, mod, first2, second2, third2;

    switch (operand) {

        case '*':

            num1 *= num2; //num1 carpim sonucu

            first2 = num1 % 10;
            second2 = ((num1 - first2) / 10) % 10;
            third2 = (num1 - ((10 * second2) + first2)) / 100;

            arr1[0] = first2;
            arr1[1] = second2;
            arr1[2] = third2;

            break;
        case '/':

            mod = num1 % num2;

            first1 = mod % 10;
            second1 = ((mod - first1) / 10) % 10;
            third1 = (mod - ((10 * second1) + first1)) / 100;

            dXArrInt[0] = first1;
            dXArrInt[1] = second1;
            dXArrInt[2] = third1;

            num1 /= num2; //num1 bolum sonucu

            first2 = num1 % 10;
            second2 = ((num1 - first2) / 10) % 10;
            third2 = (num1 - ((10 * second2) + first2)) / 100;

            arr1[0] = first2;
            arr1[1] = second2;
            arr1[2] = third2;

            break;
        default:
            break;

    }

}