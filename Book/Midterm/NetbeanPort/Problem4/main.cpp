/*

 A company wants to transmit data over the telephone, but they are 
concerned that their phones may be tapped. All of their data is 
transmitted as four-digit integers. However, they utilize the digits 
0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
will encrypt their data so that it may be transmitted more securely.

Your application should read a four-digit integer with the numbers 
0 to 7 entered by the user in an input dialog and encrypt it as 
follows: 
    Replace each digit by (the sum of that digit plus 5 modulus 8. 
    Then swap the first digit with the third, 
    and swap the second digit with the fourth. 


Then print the encrypted integer. 
Write a separate application that inputs an encrypted four-digit integer and decrypts.

If you encrypt a number, you should be able to get the same numberdecrypted back when the user does this.

Note:  sometimes errors occur and the digits 8, and 9 might appear.  
Detect this condition and flag the error.  Can't read in numbers 
individually.  All the digits must be read with one cin statement.

*/

#include <string>
#include <iostream>
#include <algorithm>

void getData(int (&out)[4]){
    std::string valRaw;
    std::cin >> valRaw;

    out[0] = (int)valRaw[0]-48;
    out[1] = (int)valRaw[1]-48;
    out[2] = (int)valRaw[2]-48;
    out[3] = (int)valRaw[3]-48;


}

void encrypt(int (&data)[4]){
    //Replace each digit by (the sum of that digit plus 5 modulus 8. 
    for(int i=0;i<4;i++){
        data[i] = data[i] + (5%8);
    }
    //Then swap the first digit with the third, 
    int temp = data[0];
    data[0] = data[2];
    data[2] = temp;

    //swap the second digit with the fourth
    temp = data[1];
    data[1] = data[3];
    data[3] = temp;
}

void decrypt(int (&data)[4]){
    
    //Then swap the first digit with the third, 
    int temp = data[0];
    data[0] = data[2];
    data[2] = temp;

    //swap the second digit with the fourth
    temp = data[1];
    data[1] = data[3];
    data[3] = temp;

    //Replace each digit by (the sum of that digit plus 5 modulus 8. 
    for(int i=0;i<4;i++){
        data[i] = data[i] - (5%8);
    }
}


int main(){


    int values[4];
    std::cout << "Enter code: " << std::endl;
    getData(values);

    std::cout << "Code Before Encryption: ";
    for(int i=0;i<4;i++){
        std::cout << values[i] << " ";
        if(values[i] > 7){
            std::cout << "ERROR, NON VALID RANGE (0-7) DETECTED! Canceling operation.";
            return 1;
        }
    }

    std::cout << std::endl;

    encrypt(values);
    std::cout << "Code After Encryption: ";
    for(int i=0;i<4;i++){
        std::cout << values[i] << " ";;
    }

    std::cout << std::endl;

    decrypt(values);
    std::cout << "Code After Decryption: ";
    for(int i=0;i<4;i++){
        std::cout << values[i] << " ";

        if(values[i] > 7){
            std::cout << "ERROR, NON VALID RANGE (0-7) DETECTED! Canceling operation.";
            return 1;
        }
    }

    std::cout << std::endl;

    return 0;
}