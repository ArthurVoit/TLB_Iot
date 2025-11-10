void setup() {
  // put your setup code here, to run once:
    const int RGBr   = 14;
    const int RGBg   = 26;
    const int RGBb   = 25;
}

  Vermelho(){
  digitalWrite(RGBr, HIGH);
  };//Função para acionamento na cor vermelha
  Verde(){ 
    digitalWrite(RGBg, HIGH);};//Função para acionamento na cor verde
  Azul(){
     digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor azul
  Branco(){
  digitalWrite(RGBr, HIGH);
  digitalWrite(RGBg, HIGH);
  digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor branca
  Magenta(){
  digitalWrite(RGBr, HIGH);
  digitalWrite(RGBg, LOW);
  digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor magenta
  Amarelo(){
  digitalWrite(RGBr, HIGH);
  digitalWrite(RGBg, HIGH);
  digitalWrite(RGBb, HIGH);
  };//Função para acionamento na cor amarela
  Ciano(){
  digitalWrite(RGBg, HIGH);
  digitalWrite(RGBb, HIGH);  
  };//Função para acionamento na cor ciano
  Desligado(){
  digitalWrite(RGBr, LOW);
  digitalWrite(RGBg, LOW);
  digitalWrite(RGBb, LOW);
  }