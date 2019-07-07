#define echoPin 6 //Ultrasonik sensörün echo pini Arduino'nun 11.pinine
#define trigPin 7 //Ultrasonik sensörün trig pini Arduino'nun 12.pinine tanımlandı.

long sure, uzaklik; //süre ve uzaklık diye iki değişken tanımlıyoruz.
long randNumber;

const int in1 = 3;     // sag Motor sürücüleri
const int in2 = 2;
const int in3 = 4;     // sol motor sürücüleri
const int in4 = 5;
const int enA = 9;  //Enable pinlerini arduino 9,10 pwm pinlerine bağladık.
const int enB = 10;



void setup() {

  pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin, INPUT); /* echo pini giriş olarak ayarlandı */

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW); //sensör pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi

  sure = pulseIn(echoPin, HIGH, 12000); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  uzaklik = sure / 58.2; //ölçülen süre uzaklığa çevriliyor

  //Serial.println(uzaklik); /* hesaplanan uzaklık bilgisayara aktarılıyor */

  if (uzaklik > 20 )
    motor_ileri();
  if (uzaklik <= 20 ) {

    randNumber = random(2);
    //Serial.println(randNumber);

    if (randNumber == 1 )
      motor_sag();
    if (randNumber == 0)
      motor_sol(); 
  }


}

void motor_ileri()

{
  // motor 1 SAG
  analogWrite(enA,  90);
  digitalWrite(in1, LOW);
  digitalWrite(in2,  HIGH);

  // motor 2 SOL
  analogWrite(enB,  90);
  digitalWrite(in3, HIGH);
  digitalWrite(in4,  LOW);
}



void motor_sag() // Robotun SAGA dönme hareketi için fonksiyon tanımlıyoruz.
{
  // motor 1 SAG
  analogWrite(enA,  90);
  digitalWrite(in1, HIGH);
  digitalWrite(in2,  LOW);

  // motor 2 SOL
  analogWrite(enB,  90);
  digitalWrite(in3, HIGH);
  digitalWrite(in4,  LOW);

}


void motor_sol()// Robotun SOLA dönme hareketi için fonksiyon tanımlıyoruz.
{
  // motor 1 SAG
  analogWrite(enA,  90);
  digitalWrite(in1, LOW);
  digitalWrite(in2,  HIGH);

  // motor 2 SOL
  analogWrite(enB,  90);
  digitalWrite(in3, HIGH);
  digitalWrite(in4,  LOW);


}
