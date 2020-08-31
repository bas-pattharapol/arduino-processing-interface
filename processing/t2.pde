import processing.serial.*;
import controlP5.*;
import g4p_controls.*;
ControlP5 cp5;

Serial myPort;

int current_1;
float inByte_1;

PImage img,img2;
int cl_i = 0;
int le_i = 0;
int vl_i = 0;
int ll_i = 0;
int tl_i = 0;
int st_i = 0;
int sp_i = 0;
int ta_i = 0;
int tm_i = 0;

int menu_i = 0;
int id =0;
 
int[] yValues_1;
int w_1;
int width_1 = 1570;
int height_1 = 500;
int step_i = 0;
//------------------------------------------
String step[] = {"CLEAR","LEAK","VL","LL","TL"};

//----------------------------------------------

int current_2;
float inByte_2;
 
int[] yValues_2;
int w_2;
int width_2 = 1570;
int height_2 = 500;
//----------------------------------------------

int current_3;
float inByte_3;
 
int[] yValues_3;
int w_3;
int width_3 = 1570;
int height_3 = 500;

//-----------------------------------------------

int current_4;
float inByte_4;
 
int[] yValues_4;
int w_4;
int width_4 = 1570;
int height_4 = 500;

//-----------------------------------------------

int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v5 = 0;
int v6 = 0;
int v7 = 0;
int v8 = 0;
int v100 =0;

//-----------------------------------------------
int Pulse[][] = { {830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830},
                  {830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830},
                  {830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830,830},
                  {1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300},
                  {1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700}
    };



int Pressure[][] = {{75,10,20,110,40,50,60,70,80,90,100,101,71,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                    {75,10,20,110,40,50,60,70,80,90,100,101,71,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                    {75,10,20,110,40,50,60,70,80,90,100,101,71,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                    {45,11,21,90,40,50,60,70,80,90,100,101,62,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                    {40,14,24,60,40,50,60,70,80,90,100,101,36,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101}

};


int Inject_Oil[][] = {{100,10,20,120,40,50,60,70,80,90,100,101,120,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {100,10,20,120,40,50,60,70,80,90,100,101,120,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {100,10,20,120,40,50,60,70,80,90,100,101,120,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {40,11,21,76,40,50,60,70,80,90,100,101,60,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {46,14,24,58,40,50,60,70,80,90,100,101,26,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101}
    

};

int Return_Oil[][] = {{16,10,20,30,40,50,60,70,80,90,100,101,10,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {16,10,20,30,40,50,60,70,80,90,100,101,10,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {16,10,20,30,40,50,60,70,80,90,100,101,10,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {10,11,21,20,40,50,60,70,80,90,100,101,10,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                      {10,14,24,12,40,50,60,70,80,90,100,101,6,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101}

};

String[]  Model = {"ISUZU 3.0",      "ISUZU 2.5",       "ISUZU 2.5",    "ISUZU 3.0",   "ISUZU 2.5"   ,"ISUZU 3.0"   ,"ISUZU 2.5"   ,"VIGO3.0"    ,"VIGO2.5"    ,"VIGO3.0"     ,"VIGO2.5"     ,"VIGO2.5"    , "TRITON"   , "D4D2.5"   ,"D4D3.0", "BT50 3.0"   , "BT50 2.5"  , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"    , "13"   , "13"   , "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13"};
String[]  Brand = {"DENSO 862",      " DENSO 879",      "DENSO 879",    "DENSO 1071",  "DENSO 1072"   ,"DENSO 980"  ,"DENSO 981"   ,"DENSO 863"  ,"DENSO 864"   ,"DENSO S006" ,"DENSO S033"  ,"DENSO S071" , "DENSO 870"   , "DENSO 788"   ,  "DENSO 807"   ,"BOSCH 1514"   , "BOSCH 1493"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"  , "13"   , "13"   , "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13"};
String[]  Drived = {"12V"            ,"12V"              , "12V"        , "12V"     ,  "12V"          ,"12V",         "12V"        ,"12V"         ,"12V"      ,  "12V"       ,   "12V",       "12V"        , "12V"   , "14V"   , "14V"   , "14V"   , "14V"   , "14V"   , "14V"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"   , "13"    , "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13", "13"};



///----------------------------------------------///////////////////////////////////////////////////

 
void setup()
{
  
  size(1600, 900,JAVA2D);
  delay(2000);
 // createGUI();
  customGUI();
  w_1 = width_1-10;
  w_2 = width_2-10;
  w_3 = width_3-10;
  w_4 = width_4-10;
  strokeWeight(3);
  smooth(); // or noSmooth();
  cp5 = new ControlP5(this);
  cp5.addKnob(".").setSize(200,400)
     .setPosition(500,10)
     .setMax(255)
     .setMin(0)
     .setValue(100)
     .setFont(createFont("Agency",20))
               .setNumberOfTickMarks(10)
               .setTickMarkLength(10)
     ;
  cp5.addKnob("..").setSize(200,400)
     .setPosition(750,10)
     .setMax(255)
     .setMin(0)
     .setValue(100)
     .setFont(createFont("Agency",20))
     .setNumberOfTickMarks(10)
               .setTickMarkLength(10)
     ; 
     
  cp5.addSlider("...").setSize(20,150)
      .setRange(0,100)
      .setPosition(1020,30).setFont(createFont("Agency",1))
      .setColorValue(color(255,0,0))
      .setColorActive(color(255,0,0))
      .setColorForeground(color(255,0,0))
      .setColorBackground(color(100,0, 0))
      ;
      
    cp5.addSlider("....").setSize(20,150)
      .setRange(0,100)
      .setPosition(1100,30).setFont(createFont("Agency",1))
      .setColorValue(color(255,0,0))
      .setColorActive(color(255,0,0))
      .setColorForeground(color(255,0,0))
      .setColorBackground(color(100,0, 0))
      ;
      
   cp5.addSlider("!").setSize(800,30)
      .setRange(0,100)
      .setPosition(280,760).setFont(createFont("Agency",24))
      .setColorValue(color(0,0,0))
      .setColorActive(color(0,255,0))
      .setColorForeground(color(0,255,0))
      .setColorBackground(color(0,100, 0))
      ;
      
  cp5.addButton("CLEAR")
     .setValue(0)
     .setPosition(25,320)
     .setSize(200, 60)
     .setFont(createFont("Agency",24))
     .setOn() 
     ;
     
   
  cp5.addButton("LEAK")
     .setValue(0)
     .setPosition(25,400)
     .setSize(200, 60)
     .setFont(createFont("Agency",24))
     ;
  cp5.addButton("VL")
     .setValue(0)
     .setPosition(25,480)
     .setSize(200, 60)
     .setFont(createFont("Agency",24))
     ;
  cp5.addButton("LL")
     .setValue(0)
     .setPosition(25,560)
     .setSize(200, 60)
     .setFont(createFont("Agency",24))
     ;
  cp5.addButton("TL")
     .setValue(0)
     .setPosition(25,640)
     .setSize(200, 60)
     .setFont(createFont("Agency",24))
     ;

   //---------------------------------------------
   cp5.addButton("MENU")
     .setValue(0)
     .setPosition(25,815)
     .setSize(150, 70)
     .setFont(createFont("Agency",24))
     ;
     
   cp5.addButton("START")
     .setValue(0)
     .setPosition(225,815)
     .setSize(150, 70)
     .setFont(createFont("Agency",24))
     ;
     
    cp5.addButton("STOP")
     .setValue(0)
     .setPosition(425,815)
     .setSize(150, 70)
     .setFont(createFont("Agency",24))
     ;
     
    cp5.addButton("TEST_AUTO")
     .setValue(0)
     .setPosition(625,815)
     .setSize(150, 70)
     .setFont(createFont("Agency",24))
     ;
     
    cp5.addButton("TEST_MOED")
     .setValue(0)
     .setPosition(825,815)
     .setSize(150, 70)
     .setFont(createFont("Agency",24))
     ;
     
    cp5.addButton("PRINT")
     .setValue(0)
     .setPosition(1025,815)
     .setSize(150, 70)
     .setFont(createFont("Agency",24))
     ;
   //-------------------------------------------------
  img = loadImage("1102.jpg");
  img2 = loadImage("55555.png");
  yValues_1 = new int[w_1];
  yValues_2 = new int[w_2];
  yValues_3 = new int[w_3];
  yValues_4 = new int[w_4];
 // String portName = Serial.list()[0];
 //printArray(Serial.list());
  myPort = new Serial(this, "COM6", 115200);
  myPort.bufferUntil('\n');  
  background(230);
}
void serialEvent(Serial myPort) {  
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  myString = trim(myString);                          // if you got any bytes other than the linefeed:
  println(myString);
  int values[] = int(split(myString, ','));                 // split the string at the commas// and convert the sections into integers:
  if (values.length == 8) {
    v1 = values[0];
    v2 = values[1];
    v3 = values[2];
    v4 = values[3];
    v5 = values[4];
    v6 = values[5];
    v7 = values[6];
    v8 = values[7];
    
  }else if(values.length == 1){
    if(values[0] == 1000){
      v100 = 0;
      step_i = 0;
    }else{
      v100 = values[0];
    }
    
  }else if(values.length == 2){
    step_i++;

  }
}
 
void draw()
{
  background(230);
  cp5.getController(".").setValue(int(v1));
  cp5.getController("..").setValue(int(v2));
  cp5.getController("...").setValue(int(v3));
  cp5.getController("....").setValue(int(v4));
  cp5.getController("!").setValue(int(v100));
  G_1();
  G_2();
  G_3();
  G_4();
  image(img, 1209, 805, 400, 95);
   textSize(24);
    fill(0, 0, 0);
    text("Pressure (Mpa)", 520, 235);
    text("RPM", 830, 235);
    text(v3 + " c", 1010, 235);
  stroke(0, 0, 0);
  //-----------------------------
  line(470, 0,470, 250);
  line(0, 250, 465, 250);
  //----------------------------
  line(465, 0, 465, 250);
   line(1205, 0, 1205, 250);
    line(470, 250, 1205, 250);
    //------------------------------
    line(0, 255, 1205, 255);
    line(1205, 255, 1205, 900);
    //----------------------------
    textSize(28);
    text("INJECTOR", 150, 40);
    line(0, 60, 465, 60);
    textSize(24);
    text("Model", 20, 100);
    line(0, 120, 465, 120);
    text("Brand", 20, 160);
    line(0, 180, 465, 180);
    text("Drived Model", 20, 220);
    line(200, 70, 200, 240);
    
    
    //----------------------------
    fill(255, 255, 255);
    rect(210,70, 245, 40);
    rect(210,130, 245, 40);
    rect(210,190, 245, 40);
    
    //---------Test Step----------------------
    fill(0);
    text("TEST STEP", 70, 290);
    line(0, 280, 65, 280);
    line(190, 280, 250, 280);
    line(250, 280, 250, 795);
    line(0, 795, 250, 795);
    //------------------------------------------
    line(0,800,1205,800); 
    //---------------------------------------
    line(255, 280, 255, 795);
    text("MEASURE",290, 290);
    line(255, 280, 285, 280);
    line(400, 280, 1200, 280);
    line(1200, 280, 1200, 795);
    line(255, 795, 1200, 795);
    //----------------------------------------------
    text("LOAD",1100, 780);
    //------------------------------------------
    fill(255,0,0);
    circle(1030, 178, 35);
    //-------------------------------------------
    fill(0,0,0);
    textSize(30);
    text("Detect Step ",290, 360);
    text("Pulse Wide  ",290, 440);
    text("Pressured   ",290, 520);
    text("Inject Oil  ",290, 600);
    text("Return Oil  ",290, 680);
    line(500, 320, 500, 730);
    //-------------------------------------
    fill(255,255,255);
    rect(520,325, 200, 50);
    rect(520,405, 200, 50);
    rect(520,485, 200, 50);
    rect(520,565, 200, 50);
    rect(520,645, 200, 50);
    
     rect(830,565, 200, 50);
    rect(830,645, 200, 50);
    //--------------------------------------
    fill(0,0,0);
    text("us",750, 440);
    text("Mpa",750, 520);
    text(" + ",750, 600);
    text(" _ ",755, 600);
    text(" + ",750, 680);
    text(" _ ",755, 680);
    text("mm3/H",1050, 600);
    text("mm3/H",1050, 680);
    
    //---------------------------------------------
    fill(0,0,0);
    textSize(24);
    text("E",1155,40);
    text("F",1155,190);
    text(v4 + " %",1100,235);
    line(1125,30 , 1125, 180);
    line(1125,30 , 1145, 30);
    line(1125,35 , 1135, 35);
    line(1125,40 , 1135, 40);
    line(1125,45 , 1135, 45);
    line(1125,50 , 1135, 50);
    line(1125,55 , 1140, 55);
    
    line(1125,60 , 1135, 60);
    line(1125,65 , 1135, 65);
    line(1125,70 , 1135, 70);
    line(1125,75 , 1135, 75);
    line(1125,80 , 1140, 80);
    
    line(1125,85 , 1135, 85);
    line(1125,90 , 1135, 90);
    line(1125,95 , 1135, 95);
    line(1125,100 , 1135, 100);
    line(1125,105 , 1140, 105);

     line(1125,110 , 1135, 110);
    line(1125,115 , 1135, 115);
    line(1125,120 , 1135, 120);
    line(1125,125 , 1135, 125);
    line(1125,130 , 1140, 130);
    
    line(1125,135 , 1135, 135);
    line(1125,140 , 1135, 140);
    line(1125,145 , 1135, 145);
    line(1125,150 , 1135, 150);
    line(1125,155 , 1140, 155);
    
     line(1125,160 , 1135, 160);
    line(1125,165 , 1135, 165);
    line(1125,170 , 1135, 170);
    line(1125,175 , 1135, 175);
    line(1125,180 , 1145, 180);
    //--------------------------------------------
    textSize(28);
    text(step[step_i],550, 360);
    text(Pulse[step_i][id],550, 440);
    text(Pressure[step_i][id],550, 520);
    text(Inject_Oil[step_i][id],550, 600);
    text(Return_Oil[step_i][id],550, 680);
    
    text(10,900, 600);
    text(10,900, 680);
    
    text(Model[id], 230, 100);
    text(Brand[id], 230, 160);
    text(Drived[id], 230, 220);
    //-----------------------------------------
   // image(img2, 500, 0, 600, 250);
}

void G_1 (){
   inByte_1 = float(v5);
    current_1 = int(map(inByte_1,200, 0, 40, 190));
       
    
    stroke(0, 0, 0);
    line(1210, 10, 1210, 200);
    
    line(1210, 200, 1580, 200);
    
    
    stroke(150, 150, 150);
    fill(255, 255, 200);
    strokeWeight(2);  
    rect(1290, 40, 280, 150);
    stroke(0, 0, 0);
    line(1285, 40, 1285, 190);
    strokeWeight(2);  
    line(1265, 40, 1285, 40);
    line(1265, 77, 1285, 77);
    line(1265, 114, 1285, 114);
    line(1265, 151, 1285, 151);
    line(1265, 188, 1285, 188);
    
    line(1275, 47.5, 1285, 47.5);
    line(1275, 55, 1285, 55);
    line(1275, 62.5, 1285, 62.5);
    line(1275, 70, 1285, 70);

    line(1275, 84.5, 1285, 84.5);
    line(1275, 92, 1285, 92);
    line(1275, 99.5, 1285, 99.5);
    line(1275, 107, 1285, 107);
    
    line(1275, 121.5, 1285, 121.5);
    line(1275, 129, 1285, 129);
    line(1275, 136.5, 1285, 136.5);
    line(1275, 144, 1285, 144);
    
    line(1275, 158.5, 1285, 158.5);
    line(1275, 166, 1285, 166);
    line(1275, 173.5, 1285, 173.5);
    line(1275, 181, 1285, 181);
    
    strokeWeight(1);  
    
    stroke(150, 150, 150);
    line(1290, 77, 1570, 77);
    line(1290, 114, 1570, 114);
    line(1290, 151, 1570, 151);
    line(1290, 188, 1570, 188);
    
    textSize(20);
    fill(0, 0, 0);
    text("Inject", 1300, 30);
     
     text(v5, 1450, 30);
     
     text("ml", 1500, 30);
    
    textSize(16);
    text("200", 1230, 45);
    text("150", 1230, 82);
    text("100", 1230, 119);
    text("50", 1240, 156);
    text("0", 1249, 193);

   
    for(int i = 1300; i < w_1; i++) {
      yValues_1[i-1] = yValues_1[i];
    }
 
    yValues_1[w_1-1] = current_1;
   
    stroke(255, 200, 0);
    line(w_1, current_1, width_1, current_1);
    strokeWeight(1);
    //line(0, current, width, current);
    strokeWeight(2);
 
    for(int i=1; i<w_1; i++) {
      stroke(220, 75, yValues_1[i]);
      point(i, yValues_1[i]);
    }
    noFill();
    stroke(0, 0, 0);
    strokeWeight(2);
    rect(0, 0, 1600, 900);
}


void G_2 (){
    inByte_2 = float(v6);
    current_2 = int(map(inByte_2,200, 0, 240, 390));
       
    
    stroke(0, 0, 0);
    line(1210, 210, 1210, 400);
    
    line(1210, 400, 1580, 400);
    
    stroke(150, 150, 150);
    fill(255, 255, 200);
    strokeWeight(2);  
    rect(1290, 240, 280, 150);
    stroke(0, 0, 0);
    line(1285, 240, 1285, 390);
    strokeWeight(2);  
    line(1265, 240, 1285, 240);
    line(1265, 277, 1285, 277);
    line(1265, 314, 1285, 314);
    line(1265, 351, 1285, 351);
    line(1265, 388, 1285, 388);
    
    line(1275, 247.5, 1285, 247.5);
    line(1275, 255, 1285, 255);
    line(1275, 262.5, 1285, 262.5);
    line(1275, 270, 1285, 270);

    line(1275, 284.5, 1285, 284.5);
    line(1275, 292, 1285, 292);
    line(1275, 299.5, 1285, 299.5);
    line(1275, 307, 1285, 307);
    
    line(1275, 321.5, 1285, 321.5);
    line(1275, 329, 1285, 329);
    line(1275, 336.5, 1285, 336.5);
    line(1275, 344, 1285, 344);
    
    line(1275, 358.5, 1285, 358.5);
    line(1275, 366, 1285, 366);
    line(1275, 373.5, 1285, 373.5);
    line(1275, 381, 1285, 381);
    
    strokeWeight(1);  
    
    stroke(150, 150, 150);
    line(1290, 277, 1570, 277);
    line(1290, 314, 1570, 314);
    line(1290, 351, 1570, 351);
    line(1290, 388, 1570, 388);
    
    strokeWeight(1);  
    textSize(20);
    fill(0, 0, 0);
    text("Return", 1300, 230);
     
     text(v6, 1450, 230);
     
     text("ml", 1500, 230);
    
    textSize(16);
    text("200", 1230, 245);
    text("150", 1230, 282);
    text("100", 1230, 319);
    text("50", 1240, 356);
    text("0", 1249, 393);

    
   
    for(int i = 1300; i < w_2; i++) {
      yValues_2[i-1] = yValues_2[i];
    }
 
    yValues_2[w_2-1] = current_2;
   
    stroke(255, 200, 0);
    line(w_2, current_2, width_2, current_2);
    strokeWeight(1);
    //line(0, current, width, current);
    strokeWeight(2);
 
    for(int i=1; i<w_2; i++) {
      stroke(220, 75, yValues_2[i]);
      point(i, yValues_2[i]);
    }
    noFill();
    stroke(0, 0, 0);
    strokeWeight(2);
    rect(0, 0, 1600, 900);
}

void G_3 (){
    inByte_3 = float(v7);
    current_3 = int(map(inByte_3,200, 0, 440, 590));
       
    
    stroke(0, 0, 0);
    line(1210, 410, 1210, 600);
    
    line(1210, 600, 1580, 600);
    
    stroke(150, 150, 150);
    fill(255, 255, 200);
    strokeWeight(2);  
    rect(1290, 440, 280, 150);
    stroke(0, 0, 0);
    line(1285, 440, 1285, 590);
    strokeWeight(2);  
    line(1265, 440, 1285, 440);
    line(1265, 477, 1285, 477);
    line(1265, 514, 1285, 514);
    line(1265, 551, 1285, 551);
    line(1265, 588, 1285, 588);
    
    line(1275, 447.5, 1285, 447.5);
    line(1275, 455, 1285, 455);
    line(1275, 462.5, 1285, 462.5);
    line(1275, 470, 1285, 470);

    line(1275, 484.5, 1285, 484.5);
    line(1275, 492, 1285, 492);
    line(1275, 499.5, 1285, 499.5);
    line(1275, 507, 1285, 507);
    
    line(1275, 521.5, 1285, 521.5);
    line(1275, 529, 1285, 529);
    line(1275, 536.5, 1285, 536.5);
    line(1275, 544, 1285, 544);
    
    line(1275, 558.5, 1285, 558.5);
    line(1275, 566, 1285, 566);
    line(1275, 573.5, 1285, 573.5);
    line(1275, 581, 1285, 581);
    
    strokeWeight(1);  
    
    stroke(150, 150, 150);
    line(1290, 477, 1570,477);
    line(1290, 514, 1570, 514);
    line(1290, 551, 1570, 551);
    line(1290, 588, 1570, 588);
    
    strokeWeight(1);  
    textSize(20);
    fill(0, 0, 0);
    text("Current", 1300, 430);
     
     text(v7, 1450, 430);
     
     text("A", 1500, 430);
    
    textSize(16);
    text("200", 1230, 445);
    text("150", 1230, 482);
    text("100", 1230, 519);
    text("50", 1240, 556);
    text("0", 1249, 593);

    
   
    for(int i = 1300; i < w_3; i++) {
      yValues_3[i-1] = yValues_3[i];
    }
 
    yValues_3[w_3-1] = current_3;
   
    stroke(255, 200, 0);
    line(w_3, current_3, width_3, current_3);
    strokeWeight(1);
    //line(0, current, width, current);
    strokeWeight(2);
 
    for(int i=1; i<w_3; i++) {
      stroke(220, 75, yValues_3[i]);
      point(i, yValues_3[i]);
    }
    noFill();
    stroke(0, 0, 0);
    strokeWeight(2);
    rect(0, 0, 1600, 900);
}

void G_4 (){
    inByte_4 = float(v8);
    current_4 = int(map(inByte_4,200, 0, 640, 790));
       
    
    stroke(0, 0, 0);
    line(1210, 610, 1210, 800);
    
    line(1210, 800, 1580, 800);
   
    stroke(150, 150, 150);
    fill(255, 255, 200);
    strokeWeight(2);  
    rect(1290, 640, 280, 150);
    stroke(0, 0, 0);
    line(1285, 640, 1285, 790);
    strokeWeight(2);  
    line(1265, 640, 1285, 640);
    line(1265, 677, 1285, 677);
    line(1265, 714, 1285, 714);
    line(1265, 751, 1285, 751);
    line(1265, 788, 1285, 788);
    
    line(1275, 647.5, 1285, 647.5);
    line(1275, 655, 1285, 655);
    line(1275, 662.5, 1285, 662.5);
    line(1275, 670, 1285, 670);

    line(1275, 684.5, 1285, 684.5);
    line(1275, 692, 1285, 692);
    line(1275, 699.5, 1285, 699.5);
    line(1275, 707, 1285, 707);
    
    line(1275, 721.5, 1285, 721.5);
    line(1275, 729, 1285, 729);
    line(1275, 736.5, 1285, 736.5);
    line(1275, 744, 1285, 744);
    
    line(1275, 758.5, 1285, 758.5);
    line(1275, 766, 1285, 766);
    line(1275, 773.5, 1285, 773.5);
    line(1275, 781, 1285, 781);
    
     strokeWeight(1);  
    
    stroke(150, 150, 150);
    line(1290, 677, 1570,677);
    line(1290, 714, 1570, 714);
    line(1290, 751, 1570, 751);
    line(1290, 788, 1570, 788);
    
    
    strokeWeight(1);  
    textSize(20);
    fill(0, 0, 0);
    text("Current Piezo", 1300, 630);
     
     text(v8, 1450, 630);
     
     text("A", 1500, 630);
   
    textSize(16);
    text("200", 1230, 645);
    text("150", 1230, 682);
    text("100", 1230, 719);
    text("50", 1240, 756);
    text("0", 1249, 793);
   
    for(int i = 1300; i < w_4; i++) {
      yValues_4[i-1] = yValues_4[i];
    }
 
    yValues_4[w_4-1] = current_4;
   
    stroke(255, 200, 0);
    line(w_4, current_4, width_4, current_4);
    strokeWeight(1);
    //line(0, current, width, current);
    strokeWeight(2);
 
    for(int i=1; i<w_4; i++) {
      stroke(220, 75, yValues_4[i]);
      point(i, yValues_4[i]);
    }
    noFill();
    stroke(0, 0, 0);
    strokeWeight(2);
    rect(0, 0, 1600, 900);
}

public void CLEAR() {
  
  if(cl_i == 0 ){
    cl_i++;
  }else{
   println("a button event from CLEAR: ");
  step_i=0;
  myPort.write('1');
  
  }
  
}

public void LEAK() {
  
  if(le_i == 0 ){
    le_i++;
  }else{
   println("a button event from LEAK: ");
  step_i=1;
  myPort.write('2');
  }
  
}

public void VL() {
  
  if(vl_i == 0 ){
    vl_i++;
  }else{
   println("a button event from VL: ");
  step_i=2;
  myPort.write('3');
  }
  
}
public void LL() {
  
  if(ll_i == 0 ){
    ll_i++;
  }else{
   println("a button event from LL: ");
  step_i=3;
  myPort.write('4');
  }
  
}

public void TL() {
  
  if(tl_i == 0 ){
    tl_i++;
  }else{
   println("a button event from TL: ");
  step_i=4;
  myPort.write('5');
  }
  
}

public void START() {
  
  if(st_i == 0 ){
    st_i++;
  }else{
    myPort.write('6');
   println("a button event from START: ");

  }
  
}

public void STOP() {
  
  if(sp_i == 0 ){
    sp_i++;
  }else{
   println("a button event from STOP: ");
 
  myPort.write('7');
  }
  
}

public void TEST_AUTO() {
  
  if(ta_i == 0 ){
    ta_i++;
  }else{
   println("a button event from TEST_AUTO: ");
 myPort.write('8');
  
  }
  
}

public void TEST_MODE(){
  
  if(tm_i == 0 ){
    tm_i++;
  }else{
   println("a button event from TEST_MODE: ");
 
  myPort.write('9');
  }
  
}

public void MENU() {
  
  if(menu_i == 0 ){
    menu_i++;
  }else{
   println("a button event from MENU");
   createGUI();
  
  }
  
}

public void customGUI(){

}
