void setup() {
  //set up
  Serial.begin(9600);
  // put your setup code here, to run once:



//
}
  int shiftRight(int num, int n){
    num=num>>n;
    return num;
}

int shiftLeft(int num, int n){
    num=num<<n;
    return num;
}

// Fix the following functions, using only the bitwise and Boolean operators
int hasAOne(int num) {
  
  int val=(num||num);
  return val;
  }


int hasAZero(int num) {
 
  int val=~num;
  int one=(val||val);
  return one;
}

int leastSigHasAOne(int num) {
  num=num<<8;
  int val=(num||num);
  return val;
}

int isNegativeInt(int num) {
  int n=num>>15;
  int val=n||n;
  return val;
}

int isNegativeLong(long num) {
  long n=num>>31;
  long val=n||n;
  return val;
}

int isNegativeChar(char num) {
  char n=num>>15;
  char val=n||n;
  return val;
}

int negate(int num) {
  num=~num+1;
  return num;
}


void loop() {
  
  // put your main code here, to run repeatedly:

 //Test:
Serial.println();
Serial.print("shiftRight(5,1) should return 2:          ");
Serial.println(shiftRight(5,1));
Serial.print("shiftRight(7,4) should return 0:          ");
Serial.println(shiftRight(7,4));

Serial.println();
Serial.print("shiftLeft(5,2) should return 20:          ");
Serial.println(shiftLeft(5,2));
Serial.print("shiftLeft(-1,1) should return -2:        ");
Serial.println(shiftLeft(-1,1));

Serial.println();
Serial.print("hasAOne(4) should return 1:               ");
Serial.println(hasAOne(4));
Serial.print("hasAOne(0) should return 0:               ");
Serial.println(hasAOne(0));

Serial.println();
Serial.print("hasAZero(5) should return 1:              ");
Serial.println(hasAZero(5));
Serial.print("hasAZero(-1) should return 0:             ");
Serial.println(hasAZero(-1));
   
Serial.println();
Serial.print("leastSigHasAOne(255) should return 1:     ");
Serial.println(leastSigHasAOne(255));
Serial.print("leastSigHasAOne(256) should return 0:     ");
Serial.println(leastSigHasAOne(256));

Serial.println();
Serial.print("isNegativeInt(-500) should return 1:      ");
Serial.println(isNegativeInt(-500));
Serial.print("isNegativeInt(500) should return 0:       ");
Serial.println(isNegativeInt(500));

Serial.println();
Serial.print("isNegativeLong(-40000) should return 1:   ");
Serial.println(isNegativeLong(-40000));
Serial.print("isNegativeLong(40000) should return 0:    ");
Serial.println(isNegativeLong(40000));

Serial.println();
Serial.print("isNegativeChar(-5) should return 1:       ");
Serial.println(isNegativeChar(-5));
Serial.print("isNegativeChar(1) should return 0:        ");
Serial.println(isNegativeChar(1));

Serial.println();
Serial.print("negate(-500) should return 500:           ");
Serial.println(negate(-500)); 
Serial.print("negate(500) should return -500:          ");
Serial.println(negate(500));


}


