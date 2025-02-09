#ifndef HX711_H
#define HX711_H

#include "hardware/gpio.h"
#include "pico/stdlib.h"

typedef struct {
    uint gpio_dt;  // Pino Data
    uint gpio_sck; // Pino Clock
    int gain;      // Ganho configurado
} hx711_t;

// Inicializa o HX711
void hx711_init(hx711_t *hx, uint dt, uint sck) {
    hx->gpio_dt = dt;
    hx->gpio_sck = sck;
    gpio_init(dt);
    gpio_set_dir(dt, GPIO_IN);
    gpio_init(sck);
    gpio_set_dir(sck, GPIO_OUT);
    hx->gain = 128; // Ganho padrão
}

// Define o ganho do HX711
void hx711_set_gain(hx711_t *hx, int gain) {
    hx->gain = gain;
}

// Lê dados brutos do HX711
int32_t hx711_get_value(hx711_t *hx) {
    int32_t value = 0;

    // Espera por dados prontos
    while (gpio_get(hx->gpio_dt)) {
        tight_loop_contents();
    }

    // Lê os dados (24 bits)
    for (int i = 0; i < 24; i++) {
        gpio_put(hx->gpio_sck, 1);
        tight_loop_contents();
        value = (value << 1) | gpio_get(hx->gpio_dt);
        gpio_put(hx->gpio_sck, 0);
    }

    // Ajusta o ganho
    for (int i = 0; i < hx->gain; i++) {
        gpio_put(hx->gpio_sck, 1);
        tight_loop_contents();
        gpio_put(hx->gpio_sck, 0);
    }

    // Ajusta para valores negativos
    if (value & 0x800000) {
        value |= ~0xFFFFFF;
    }

    return value;
}

#endif // HX711_H
