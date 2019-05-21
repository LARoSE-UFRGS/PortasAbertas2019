// @author Carlos Felipe Emygdio de Melo <cfemelo@gmail.com>
// @author Maik Basso <maik@maikbasso.com.br>

/*

Código de exemplo utilizado para a demonstração do Edubot no Portas Abertas 2019

*/

#include <Edubot.h>
#include <LibMotor.h>
#include <Encoder.h>
#include <LibSonar.h>
#include <Controller.h>
Sonar sonarRight(TRIGR, ECHOR);
Sonar sonarFront(TRIGF, ECHOF);
Sonar sonarLeft(TRIGL, ECHOL);

void setup() {
  
  Serial.begin(9600);
  edu_setup();

}


void loop() {

  edu_moveReto(0.3*EDU_VMAX);
  delay(100);

  if(sonarRight.medeDistancia() < 3){
    edu_rotaciona(-35);
  }
  if(sonarLeft.medeDistancia() < 3){
    edu_rotaciona(35);
  }
  if(sonarFront.medeDistancia() < 7){
    if(sonarRight.medeDistancia() < sonarLeft.medeDistancia()){
      edu_rotaciona(-90);
    }
    else{
      edu_rotaciona(90);
    }
  }

  if(digitalRead(FCFD)==LOW && digitalRead(FCFE)==LOW){
    edu_para();
    edu_moveReto(-0.3*EDU_VMAX);
    delay(500);
    if(sonarRight.medeDistancia() < sonarLeft.medeDistancia()){
      edu_rotaciona(-45);
    }
    else{
      edu_rotaciona(45);
    }
  }else if(digitalRead(FCFD)==LOW && digitalRead(FCFE)==HIGH){
    edu_para();
    edu_moveReto(-0.3*EDU_VMAX);
    delay(500);
    edu_rotaciona(-35);
  }else if(digitalRead(FCFD)==HIGH && digitalRead(FCFE)==LOW){
    edu_para();
    edu_moveReto(-0.3*EDU_VMAX);
    delay(500);
    edu_rotaciona(35);
  }
}
