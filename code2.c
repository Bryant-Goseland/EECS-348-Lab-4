#include <stdio.h>
#include <stdlib.h>

// conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

// temperature categories
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature Category: Freezing\n");
        printf("Weather advisory: Too cold, stay indoors!\n");
    } else if (celsius < 10) {
        printf("Temperature Category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Temperature Category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius < 35) {
        printf("Temperature Category: Hot\n");
        printf("Weather advisory: Stay hydrated, it's getting hot!\n");
    } else {
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather advisory: Too hot, stay indoors!\n");
    }
}

// only way i could find to get characters to stop my program from
// infinetely looping
int safe_scanf_int(int *var) {
    char c;
    int result = scanf("%d", var);
    
    // clears buffer
    while ((c = getchar()) != '\n' && c != EOF);
    
    return result == 1;
}

int main() {
    float temperature, converted_temp;
    int scale, conversion;

    // loops for temperature and scale
    while (1) {
        printf("\nEnter the temperature: ");
        if (!safe_scanf_int((int*)&temperature)) {
            printf("Invalid input. Please enter a valid integer temperature.\n");
            continue; // prompts user again
        }

        printf("Choose the current scale Celsius(1), Fahrenheit(2), or Kelvin(3): ");
        if (!safe_scanf_int(&scale)) {
            printf("Invalid input. Please enter 1 for Celsius, 2 for Fahrenheit, or 3 for Kelvin.\n");
            continue; 
        }

        // makes sure that Kelvin isn't negative
        if (scale == 3 && temperature < 0) {
            printf("Error: Kelvin temperature cannot be negative. Please enter a valid temperature.\n");
            continue; 
        }

        if (scale == 1 || scale == 2 || scale == 3) {
            break; // exits loop if valid
        } else {
            printf("Invalid scale. Please enter 1 for Celsius, 2 for Fahrenheit, or 3 for Kelvin.\n");
        }
    }

    // loops for conversion
    while (1) {
        printf("Convert to Celsius(1), Fahrenheit(2), or Kelvin(3): ");
        if (!safe_scanf_int(&conversion)) {
            printf("Invalid input. Please enter 1 for Celsius, 2 for Fahrenheit, or 3 for Kelvin.\n");
            continue; 
        }

        if (conversion == scale) {
            printf("Error: Conversion to the same scale is not allowed. Please choose a different conversion scale.\n");
        } else if (conversion == 1 || conversion == 2 || conversion == 3) {
            break;
        } else {
            printf("Invalid input. Please enter 1 for Celsius, 2 for Fahrenheit, or 3 for Kelvin.\n");
        }
    }

    // conversions
    if (scale == 1) { // Celsius
        if (conversion == 2) {
            converted_temp = celsius_to_fahrenheit(temperature);
            printf("\nConverted temperature: %.2f°F\n", converted_temp);
        } else {
            converted_temp = celsius_to_kelvin(temperature);
            printf("\nConverted temperature: %.2fK\n", converted_temp);
        }
    } else if (scale == 2) { // Fahrenheit
        if (conversion == 1) {
            converted_temp = fahrenheit_to_celsius(temperature);
            printf("\nConverted temperature: %.2f°C\n", converted_temp);
        } else {
            converted_temp = fahrenheit_to_kelvin(temperature);
            printf("\nConverted temperature: %.2fK\n", converted_temp);
        }
    } else { // Kelvin
        if (conversion == 1) {
            converted_temp = kelvin_to_celsius(temperature);
            printf("\nConverted temperature: %.2f°C\n", converted_temp);
        } else {
            converted_temp = kelvin_to_fahrenheit(temperature);
            printf("\nConverted temperature: %.2f°F\n", converted_temp);
        }
    }

    // categorizes the temperatures based on the celcius equilvilent
    if (scale == 1) {
        categorize_temperature(temperature); 
    } else if (scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(temperature)); 
    } else {
        categorize_temperature(kelvin_to_celsius(temperature));
    }

    return 0;
}
