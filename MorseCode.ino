using namespace std;
#include <stdio.h>
#include <string.h>

char  sen[] = "titties ";
String temp;
int len = sizeof(sen)/sizeof(char);
const int ledPin = 9;


String morseEncode(char x){
  switch(x){
    case 'a':
      return "1011100";
    break;
    case 'b':
      return "11101010100";
    break; 
    case 'c':
      return "1110101110100";
    break;
    case ' ':
      return "0000000";
    break;
    case 'l':
      return "10111010100";
    break;
    case 's':
      return "1010100";
    break;
    case 't':
      return "1110";
    break;
    case 'i':
      return "10100";
    break;
    case 'e':
      return "100";
    break;
  }   
}

String morseFunction(String y){
  int lenb = sizeof(temp)/sizeof(String);
  for (byte i = 0; i < lenb-1; i++){
    return temp[i];
    delay(2000);  
  }

}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

 // Serial.print(morseEncode('c'));
 // delay(1000);
 
 
 
  for (byte loop = 0; loop < len-1; loop++){ 
    //char temp[];   
    temp = morseEncode(sen[loop]);
    int str_len = temp.length() + 1;
    char newArr[str_len];
    temp.toCharArray(newArr, str_len);
    int lenb = sizeof(newArr)/sizeof(char);
    for(byte i = 0; i < lenb-1; i++){
      Serial.print(newArr[i]);
     // delay(1000);
      if(newArr[i] == '1'){
        digitalWrite(ledPin, HIGH);
        delay(250);
      }
      else if(newArr[i] == '0') {
        digitalWrite(ledPin, LOW);
        delay(500);  
      }
    }
  //  Serial.print(morseFunction(temp));         
  }
  
  
}
