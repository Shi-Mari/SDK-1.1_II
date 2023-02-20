/*
 * regmap.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Мария
 */

#ifndef REGMAP_H_
#define REGMAP_H_

//Адреса регистров контроллера
// NVIC
#define NVIC_ISER0_REG            0xE000E100
#define NVIC_ISER1_REG            0xE000E104
#define NVIC_ISER2_REG            0xE000E108

// RCC
#define RCC_REG             0x40023800
#define RCC_CR_OFFSET       0x0
#define RCC_CFGR_OFFSET     0x08
#define RCC_AHB1ENR_OFFSET  0x30
#define RCC_APB1ENR_OFFSET  0x40
#define RCC_APB2ENR_OFFSET  0x44

// GPIOD
#define GPIOD_REG             0x40020C00
#define GPIO_MODER_OFFSET    0x0
#define GPIO_OSPEEDR_OFFSET      0x8
#define GPIO_IDR_OFFSET      0x10
#define GPIO_ODR_OFFSET      0x14
#define GPIO_PUPDR_OFFSET      0x0C
#define GPIO_AFRL_OFFSET      0x20
#define GPIO_AFRH_OFFSET      0x24

//GPIOA
#define GPIOA_REG             0x40020000

//GPIOB
#define GPIOB_REG             0x40020400

//GPIOB
#define GPIOC_REG             0x40020800

// Timer2
#define TIMER2_REG           0x40000000
#define TIMER_CR1_OFFSET    0x0
#define TIMER_SR_OFFSET     0x10
#define TIMER_ARR_OFFSET    0x2C
#define TIMER_DIER_OFFSET   0x0C
#define TIMER_PSC_OFFSET    0x28
#define TIMER_CNT_OFFSET    0x24

// Timer3
#define TIMER3_REG           0x40000400

// Timer5
#define TIMER5_REG           0x40000C00

// Timer6
#define TIMER6_REG           0x40001000

// USART 1
#define USART1_REG         0x40011000

// USART 2
#define USART2_REG         0x40004400
#define USART_SR_OFFSET    0x00
#define USART_DR_OFFSET    0x04
#define USART_BRR_OFFSET   0x08
#define USART_CR1_OFFSET   0x0C

// USART 3
#define USART3_REG         0x40004800

// USART 6
#define USART6_REG         0x40011400



// /* basic bit ops */
// /*
// you can choose macro
// SET_BIT((RCC + RCC_AHB1ENR_OFFSET), (1 << 3));
// or
// *(uint32_t*)(RCC + RCC_AHB1ENR_OFFSET) = (1 << 3)
//  */
#define SET_BIT(REG, BIT) ((*(uint32_t*)REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((*(uint32_t*)REG) &= ~(BIT))
#define READ_BIT(REG, BIT) ((*(uint32_t*)REG) & (BIT))
#define CLEAR_REG(REG) ((*(uint32_t*)REG) = (0x0))
#define WRITE_REG(REG, VAL) ((*(uint32_t*)REG) = (VAL))
#define READ_REG(REG) ((*(uint32_t*)REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))


#endif /* REGMAP_H_ */
