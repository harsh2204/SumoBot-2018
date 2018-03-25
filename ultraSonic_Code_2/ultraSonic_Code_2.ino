
//Instantiate a new advanced serial object with 500 transmit slots


#define trigPin 2// GREY
#define echoPin 3// PURPLE
#define trigPin2 7
#define echoPin2 8

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


int prevDist = 0;
int prevDist2 = 0;
int prevLeftAngle = 0;
int prevRightAngle = 0;
int prevFarAngle = 0;
int update = 0;
int update2 = 0;


void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
//  distance = (duration/2) / 29.1;
  distance = (duration*.0343)/2;
   
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);  
//  distance2 = (duration2/2) / 29.1;
  distance2 = (duration2*.0343)/2; 
//  Serial.print(" Distance 1 ");
//  Serial.print(distance);
//  Serial.print("  Distance 2 ");
//  Serial.println(distance2);
  //Set up the distances to evaluate at intervals greater than 1
  if(abs(prevDist - distance) > 1 & distance < 50){
    prevDist = distance;
    update = 1;
  }

  if(abs(prevDist2 - distance2) > 1 & distance2 < 50){
    prevDist2 = distance2;
    update2 = 1;
  }
  
//  Print X and Y
  if(update or update2){
    float x = calcX(prevDist, prevDist2);
    float y = calcY(prevDist, prevDist2);
    Serial.println(x);
    Serial.println(y);
  }
  update = 0;
  update2 = 0;
  
  
  
}

float calcX(float distLeft, float distRight){
  float x = 20;
  float thetaLeft = acos((sq(distRight) + sq(4) - sq(distLeft))/(2*distRight*4));
  float thetaRight = acos((sq(distLeft) + sq(4) - sq(distRight))/(2*distLeft*4));
  if(distRight > distLeft){
    //float y = distRight*sin(thetaRight);
    x = distRight*cos(thetaRight);
    
  }
 
  else{
    //float y = distLeft*sin(thetaLeft);
    x = -distLeft*cos(thetaLeft);
  }
  return x;
  
}

float calcY(float distLeft, float distRight){
  float y = 10;
  float thetaLeft = acos((sq(distRight) + sq(4) - sq(distLeft))/(2*distRight*4));
  float thetaRight = acos((sq(distLeft) + sq(4) - sq(distRight))/(2*distLeft*4));
  if(distRight > distLeft){
    y = distRight*sin(thetaRight);
    //float x = distRight*cos(thetaRight);
  }
 
  else{
    y = distLeft*sin(thetaLeft);
    //float x = distLeft*cos(thetaLeft);
  }
  return y;
  
}
