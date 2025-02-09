#include <stdio.h>
#include "pico/stdlib.h"
#include "hx711.h"

// Definições de GPIO
#define LED_RED 19
#define LED_GREEN 18
#define BUZZER 20
#define HX711_DT 2
#define HX711_SCK 3

float peso_referencia = 0.0; // Peso de referência
hx711_t balanca;

// Variável para rastrear o estado atual (1 = tudo ok, 0 = alerta)
int estado_atual = -1;

// Inicializar LEDs e Buzzer
void init_alertas() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
}

// Função de Alerta
void alerta_falta_item() {
    gpio_put(LED_RED, 1);   // Acende LED vermelho
    gpio_put(LED_GREEN, 0); // Apaga LED verde
    gpio_put(BUZZER, 1);    // Ativa buzzer
    sleep_ms(500);
    gpio_put(BUZZER, 0);    // Desativa buzzer
    printf("Peso insuficiente! Adicione itens.\n");
}

// Função de Status OK
void status_ok() {
    gpio_put(LED_GREEN, 1); // Acende LED verde
    gpio_put(LED_RED, 0);   // Apaga LED vermelho
    printf("Tudo OK! Peso suficiente.\n");
}

// Verificar peso
void verificar_peso(float peso_em_gramas) {
    if (peso_referencia == 0.0) {
        peso_referencia = peso_em_gramas; // Primeira leitura define referência
        printf("Peso de referência registrado: %.2f g\n", peso_referencia);
    }

    if (peso_em_gramas >= peso_referencia) {
        if (estado_atual != 1) { // Evita repetição do "Tudo OK!"
            estado_atual = 1;
            status_ok();
        }
    } else {
        if (estado_atual != 0) { // Reinicia o estado para alerta contínuo
            estado_atual = 0;
        }
        alerta_falta_item();
    }
}

int main() {
    stdio_init_all();
    sleep_ms(2000); // Aguarde estabilizar USB
    printf("Sistema iniciado.\n");

    init_alertas();

    hx711_init(&balanca, HX711_DT, HX711_SCK);
    hx711_set_gain(&balanca, 128);

    while (true) {
        int32_t leitura_peso = hx711_get_value(&balanca);

        if (leitura_peso == 0) {
            printf("Nenhum peso detectado ou erro de leitura.\n");
        } else {
            float peso_em_gramas = (float)leitura_peso / 100.0; // Ajuste conforme necessário
            verificar_peso(peso_em_gramas);
        }

        sleep_ms(1000);
    }

    return 0;
}
