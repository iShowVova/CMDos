// idt.h
#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// Структура дескриптора прерывания
struct IDTDescr {
    uint16_t offset_1;   // Нижние 16 бит адреса обработчика
    uint16_t selector;   // Селектор сегмента кода
    uint8_t zero;        // Должен быть равен 0
    uint8_t type_attr;   // Атрибуты типа
    uint16_t offset_2;   // Верхние 16 бит адреса обработчика
} __attribute__((packed));

// Структура таблицы дескрипторов прерываний
struct IDT {
    struct IDTDescr table[256];
} __attribute__((packed));

extern struct IDT idt;

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);
void idt_init(void);

#endif // IDT_H