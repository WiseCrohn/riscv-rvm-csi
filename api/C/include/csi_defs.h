/*
 * General-Purpose Definitions for use in CSI code
 *
 * This file is included from rvm_csi.h prior to all other headers and contains
 * general-purpose definitions which may be used by subsequent headers.
 *
 * Copyright (c) RISC-V International 2022. Creative Commons License. Auto-
 * generated file: DO NOT EDIT
 */

#ifndef CSI_DEFS_H
#define CSI_DEFS_H

/*
 * Return type for functions indicating status
 */
typedef enum {
    CSI_SUCCESS = 0, /* Operation completed successfully */
    CSI_NOT_IMPLEMENTED = -1, /* Functionality not implemented */
    CSI_ERROR = -2, /* Generic error code */
    CSI_NOT_INITIALIZED = -3, /* Sub-system not correctly initialised, operation failed. */
    CSI_OUT_OF_MEM = -4, /* Out-of-memory error */
} csi_status_t;

/*
 * Enumerates all sources in the system that can give rise to a trap event.  This
 * enumeration should be treated as an integer which can have additional values
 * beyond those enumerated here.  A standard set of interrupt and exception sources
 * are enumerated here, which exclude external sources.  All external interrupt
 * sources should be enumerated by the BSP within csi_bsp_interrupts.h; and their
 * ennumerated values should follow on from CSI_NUM_STANDARD_TRAP_SOURCES.
 * csi_bsp_interrupts.h must also define CSI_TOTAL_BSP_TRAP_SOURCES to indicate the
 * total number of sources defined.  User applications may then use values above
 * this to enumerate user-defined software signals.  Note that the actual
 * enumerated values have no meaning beyond serving to uniquely identify the source
 * of a trap event.  They are not intended to map onto values in the mcause
 * register.
 */
typedef enum {
    CSI_ENUM_NMI = 0, /* Non-maskable exception (hardware error) */
    CSI_ENUM_MACHINE_SW_INTERRUPT, /* Machine mode software interrupt */
    CSI_ENUM_MACHINE_TIMER_INTERRUPT, /* Machine mode timer interrupt */
    CSI_ENUM_INSTRUCTION_ADDR_MISALIGNED_EXCEPTION, /* Instruction misaligned exception */
    CSI_ENUM_INSTRUCTION_ACCESS_FAULT_EXCEPTION, /* Instruction access fault exception */
    CSI_ENUM_ILLEGAL_INSTRUCTION_EXCEPTION, /* Illegal instruction exception */
    CSI_ENUM_BREAKPOINT_EXCEPTION, /* Breakpoint exception */
    CSI_ENUM_LOAD_ADDR_MISALIGNED_EXCEPTION, /* Load address misaligned exception */
    CSI_ENUM_LOAD_ACCESS_FAULT_EXCEPTION, /* Load access fault exception */
    CSI_ENUM_STORE_ADDR_MISALIGNED_EXCEPTION, /* Store address misaligned exception */
    CSI_ENUM_STORE_ACCESS_FAULT_EXCEPTION, /* Store access fault exception */
    CSI_ENUM_ECALL_FROM_UMODE, /* ECALL from User mode */
    CSI_ENUM_ECALL_FROM_MMODE, /* ECALL from Machine mode */
    CSI_ENUM_INST_PAGE_FAULT, /* Instruction page-fault */
    CSI_ENUM_LOAD_PAGE_FAULT, /* Load page-fault */
    CSI_ENUM_STORE_PAGE_FAULT, /* Store page-fault */
    CSI_NUM_STANDARD_TRAP_SOURCES, /* Must come last in this list */
} csi_trap_source_t;

/*
 * Interrupt enable bits in the mie CSR
 */
typedef enum {
    CSI_SW_INTERRUPTS_ENABLE = 8, /* Software interrupts enable bit index */
    CSI_TIMER_INTERRUPTS_ENABLE = 128, /* Timer interrupts enable bit index */
    CSI_EXT_INTERRUPTS_ENABLE = 2048, /* External interrupts enable bit index */
} csi_interrupt_enables_t;


#endif /* CSI_DEFS_H */ 
