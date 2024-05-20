
#include <Arduino.h>
#include <Servo.h>


//Deklarasi variabel servo
Servo myServo; 
//Menetapkan pin yang digunakan pada untuk koneksi
int trigPin = D1; 
int echoPin = D2;

long duration; //Variabel menyimpan waktu yang dibubtuhkan sensor jarak untuk kembali
int distance; //Variabel menyimpan jarak yang dihitung dari waktu tersebut

void setup()
{
  myServo.attach(D0); //Menghubungkan objek servo ke pin yang sesuai 
  pinMode(trigPin, OUTPUT); //Menetapkan trigPin sebagai output 
  pinMode(echoPin, INPUT); //Menetapkan echoPin sebagai input 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  
  if (distance <= 50)
  {
    myServo.write(90);
    delay(1000);
  }
  else if (distance > 50)
  {
    myServo.write(0);
    delay(1000);
  }
}


/***
Sebuah sistem yang memiliki servo motor dan sensor jarak. Ketika jarak yang diukur oleh sensor jarak kurang dari atau sama dengan  50 cm, 
servo motor akan bergerak sejauh 90 derajat, dan kemudian akan dijeda seama 1000 ms sebelum melakukan pengukuran dan kontrol berikutnya.

Pertama, sinyal ultrasonik dikirimkan dengan menurunkan dan menaikkan sinyal pada pin trigPin untuk menghasilkan gelombang ultrasonik.
Setelah itu, program menunggu gelombang kembali dan mengukur waktu yang dibutuhkan untuk gelombang tersebut kembali ke sensor menggunakan fungsi pulseIn().
Durasi waktu kemudian diubah menjadi jarak dalam satuan cm degan menggunakan rumus "0.034 * duration / 2".  
Selanjutnya, program memeriksa apakah jarak yang diukur kurang dari atau sama dengan 50 cm. Jika ya, maka servo akan diposisikan pada sudut 90 derajat agar bergerak, 
jika tidak, servo akan diposisikan kembali ke sudut 10 derajat. Setelah melakukan tindakan yang sesuai, akan ada jeda selama 1 detik sebelum melakukan pengukuran dan kontrol berikutnya.
***/