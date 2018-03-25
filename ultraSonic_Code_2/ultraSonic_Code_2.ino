
//Instantiate a new advanced serial object with 500 transmit slots


#define trigPin 2 // GREY
#define echoPin 3 // PURPLE
#define trigPin2 7
#define echoPin2 8
#define trigPinL 11
#define echoPinL 12
#define trigPinR 0
#define echoPinR 1

//5 & 6 are free

// ULTRASONICS
// BACK:
// 6 Grey, 7 Purple

//Front Right:
// 2 Grey, 3 Purple


//Front Left:cd p
// 4 Grey, 5 Purple

//LEFT:
// 9 Grey, 8 Purple

//RIGHT:


//int prevDist = 0;
//int prevDist2 = 0;
//int prevLeftAngle = 0;
//int prevRightAngle = 0;
//int prevFarAngle = 0;
//int update = 0;
//int update2 = 0;
long distance, distance2, distanceR, distanceL;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
  
}


long pingUltra(int tPin, int ePin){
  long duration, distance;
  digitalWrite(tPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(tPin, HIGH);
  delayMicroseconds(2); 
  digitalWrite(tPin, LOW);
  duration = pulseIn(ePin, HIGH);  
  distance = (duration*.0343)/2;
  return distance;
}
void printDist(){
  Serial.print(" Distance Front Left ");
  Serial.print(distance);
  Serial.print("  Distance Front Right  ");
  Serial.print(distance2);
  Serial.print(" Distance Left ");
  Serial.print(distanceL);
  Serial.print("  Distance Right  ");
  Serial.println(distanceR);
}
void printView(){
  Serial.print("Peripheral Vision Left: ");
  Serial.println(peripheralView(0));
//  Serial.print("Peripheral Vision Right: ") //Dont work as of now.
//  Serial.print(peripheralView(1)) 
}
boolean peripheralView(int side){
  //Left = 0, Right = 1
  if(side){ //right
    return (distanceR>=7 && distanceR<=80);
  }else{
    return (distanceL>=7 && distanceL<=80);
  }
}

void loop() {
//  boolean test = 3<5;
//  Serial.println(test);
  distance = pingUltra(trigPin, echoPin);
  distance2 = pingUltra(trigPin2, echoPin2);
  distanceL = pingUltra(trigPinL, echoPinL);
  distanceR = pingUltra(trigPinR, echoPinR);
  printDist();
//  printView();
  
}

//float calcX(float distLeft, float distRight){
//  float x = 20;
//  float thetaLeft = acos((sq(distRight) + sq(4) - sq(distLeft))/(2*distRight*4));
//  float thetaRight = acos((sq(distLeft) + sq(4) - sq(distRight))/(2*distLeft*4));
//  if(distRight > distLeft){
//    //float y = distRight*sin(thetaRight);
//    x = distRight*cos(thetaRight);
//    
//  }
// 
//  else{
//    //float y = distLeft*sin(thetaLeft);
//    x = -distLeft*cos(thetaLeft);
//  }
//  return x;
//  
//}
//
//float calcY(float distLeft, float distRight){
//  float y = 10;
//  float thetaLeft = acos((sq(distRight) + sq(4) - sq(distLeft))/(2*distRight*4));
//  float thetaRight = acos((sq(distLeft) + sq(4) - sq(distRight))/(2*distLeft*4));
//  if(distRight > distLeft){
//    y = distRight*sin(thetaRight);
//    //float x = distRight*cos(thetaRight);
//  }
// 
//  else{
//    y = distLeft*sin(thetaLeft);
//    //float x = distLeft*cos(thetaLeft);
//  }
//  return y;
//  
//}
