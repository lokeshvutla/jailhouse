/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Copyright (c) ARM Limited, 2014
 * Copyright (c) Siemens AG, 2014
 *
 * Authors:
 *  Jean-Philippe Brucker <jean-philippe.brucker@arm.com>
 *  Jan Kiszka <jan.kiszka@siemens.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */
#include <asm/uart-8250-dw.h>
#include <mach/uart.h>

void uart_chip_init(struct uart_chip *chip)
{
	chip->virt_base = UART_BASE;
	chip->wait = uart_wait;
	chip->write = uart_write;
	chip->busy = uart_busy;
	chip->clock_reg = UART_CLOCK_REG;
	chip->gate_nr = UART_GATE_NR;
	uart_init(chip);
}