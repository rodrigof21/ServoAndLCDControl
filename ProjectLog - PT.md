
# Log do Projeto

O Objetivo Inicial do projeto era experimentar as funcionalidades do ecrã LCD. Rapidamente evolui para controlar um motor Servo com um potenciómetro num programa com duas funcionalidades e de seguida um jogo.

## 10-08-2024
#### 19:48
Primeiro sistema básico de controlo de números num LCD com um potenciómetro. 
#### 20:21
Controlar o Motor Servo com o potenciómetro e mostrar o seu valor no LCD.

#### 23:56
Adicionou se um botão para funcionalidades extra. Agora é permitido escolher o ângulo com o potenciómetro e só depois de carregar no botão é que o motor se move.

## 11-08-2024

#### 01:15
Cria-se um menu para se poder escolher se queremos que o motor se mova ao mesmo tempo que o potenciómetro ou só depois de se clicar no botão com recurso ao seguinte código

#### 02:12
Versão final do Circuito. Esquema feito no TinkerCad.   

#### 19:13
Primeira versão do Jogo.
O ecra mostra o texto "Acerta no ângulo" durante $x$ segundos e de seguida um número entre 0 e 179, correspondente a um ângulo. O objetivo é rodar cegamente o servo de forma a ficar o mais próximo possível do ângulo dito. É definida uma tolerância e o ecrã reage se ficar dentro ou fora da tolerancia e de forma diferente se se acertar exatamente no ângulo pedido.

## 12-08-2024

#### 00:30
Foi adicionado um piezo para que o jogo tenha efeitos sonoros simples. Apita de cada vez que o botão é clicado e reage de forma diferente.

#### 10:30

>[!warning]
>O Piezo estava a interferir com o sinal do LCD por isso a primeira tentativa foi afastar ambos os componentes, o que levava a uma breadboard confusa e pouco estável, dado que os cabos de desmontavam facilmente. O problema foi resolvido adicionando uma resistência de 220 Ohm ao circuito do Piezo.

Adicionou-se também algum texto para ficar mais interativo, como se vê nas figuras abaixo.
