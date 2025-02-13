## 🎒 Bmart – Smart Backpack System  
This project uses a **Raspberry Pi Pico** and an **HX711 load sensor** to monitor the weight of items inside the backpack. If an essential item is removed, a sound and visual alert will be triggered! 🚨  

## 🚀 Features  

✅ **Weight Monitoring**: Detects if essential items are in the backpack.  
🔴 **Visual and Sound Alert**: If an item is missing, a red LED lights up, and a buzzer sounds.  
🟢 **Status Indication**: If everything is correct, a green LED lights up.  
⚖️ **Automatic Calibration**: The system sets a reference weight on the first reading.  

## 🛠️ Required Components  

- 🖥️ **Raspberry Pi Pico**  
- ⚖️ **HX711** (Load cell amplifier module)  
- 🟥 **Red LED** (GPIO 19)  
- 🟩 **Green LED** (GPIO 18)  
- 🔊 **Buzzer** (GPIO 20)  
- 🔌 **Wires and breadboard**  

## 📝 How It Works?  

1. **Initialization**: The system starts and sets the reference weight based on the initial items in the backpack.  
2. **Continuous Measurement**: Every second, the current weight is compared to the reference weight.  
3. **Missing Item Alert**: If the weight decreases, the red LED lights up, and the buzzer sounds.  
4. **Normal Status**: If the weight is correct, the green LED lights up.  

## 🔧 How to Use?  

1. **Assemble the circuit** according to the wiring diagram.  
2. **Upload the code to the Raspberry Pi Pico**.  
3. **Place the items in the backpack and turn on the system**.  
4. **Let the system automatically calibrate** (first reading).  
5. **Remove or add items and see the alert in action!**  

## 📜 Source Code  

The main code is in the `main.c` file and can be uploaded directly to the Raspberry Pi Pico.  

---  
🛠️ *Designed to help you never forget essential items in your backpack again!* 🎒🔥  

## 🎒 Bmart – Sistema de mochila inteligente *(PT/BR)*
Este projeto usa um **Raspberry Pi Pico** e um **sensor de carga HX711** para monitorar o peso dos itens dentro da mochila. Se algum item essencial for retirado, um alerta sonoro e visual será acionado! 🚨  

## 🚀 Funcionalidades  

✅ **Monitoramento de peso**: Detecta se os itens essenciais estão na mochila.  
🔴 **Alerta visual e sonoro**: Se um item estiver faltando, um LED vermelho acende e um buzzer dispara.  
🟢 **Indicação de status**: Se tudo estiver certo, um LED verde acende.  
⚖️ **Calibração automática**: O sistema define o peso de referência na primeira leitura.  

## 🛠️ Componentes necessários  

- 🖥️ **Raspberry Pi Pico**  
- ⚖️ **HX711** (Módulo conversor de carga)  
- 🟥 **LED vermelho** (GPIO 19)  
- 🟩 **LED verde** (GPIO 18)  
- 🔊 **Buzzer** (GPIO 20)  
- 🔌 **Fios e protoboard**  

## 📝 Como funciona?  

1. **Inicialização**: O sistema inicia e define o peso de referência com base nos itens iniciais na mochila.  
2. **Medição contínua**: A cada segundo, o peso atual é comparado com o peso de referência.  
3. **Alerta de item ausente**: Se o peso diminuir, o LED vermelho acende e o buzzer toca.  
4. **Status normal**: Se o peso estiver correto, o LED verde acende.  

## 🔧 Como usar?  

1. **Monte o circuito** conforme o esquema elétrico.  
2. **Carregue o código no Raspberry Pi Pico**.  
3. **Coloque os itens na mochila e ligue o sistema**.  
4. **Deixe o sistema calibrar automaticamente** (primeira leitura).  
5. **Remova ou adicione itens e veja o alerta em ação!**  

## 📜 Código-fonte  

O código principal está no arquivo `main.c` e pode ser carregado diretamente no Raspberry Pi Pico.  

---
🛠️ *Desenvolvido para ajudar você a nunca mais esquecer itens essenciais na sua mochila!* 🎒🔥  

