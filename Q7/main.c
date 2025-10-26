#include <stdio.h>
#include "conversoes.h"

float fahrenheitParaCelsius(float temp) {
    float celsius = (temp - 32) / 1.8;
    return celsius;
}

float celsiusParaFahrenheit(float temp) {
    float fahrenheit = 1.8 * temp + 32;
    return fahrenheit;
}

int main() {
    float cel, fah;

    printf("Digite uma temperatura em °C: ");
    scanf("%f", &cel);

    printf("Digite uma temperatura em °F: ");
    scanf("%f", &fah);

    printf("%.1f°C em fahrenheit: %.1f\n", cel, celsiusParaFahrenheit(cel));
    printf("%.1f°F em celsius: %.1f\n", fah, fahrenheitParaCelsius(fah));

    return 0;
}