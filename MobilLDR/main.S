#define __SFR_OFFSET 0
#include <avr/io.h>

.global LDR_DigitalRead
.global LDR2_DigitalRead

; =====================================================
; FUNCTION : uint8_t LDR_DigitalRead(void)
; READ PB1
; RETURN:
; r24 = 1 -> HIGH
; r24 = 0 -> LOW
; =====================================================

LDR_DigitalRead:

    in   r24, PINB        ; baca PORTB

    sbrs r24, 1           ; skip jika bit PB1 = 1
    rjmp LDR_LOW

LDR_HIGH:
    ldi  r24, 1
    ret

LDR_LOW:
    ldi  r24, 0
    ret


; =====================================================
; FUNCTION : uint8_t LDR2_DigitalRead(void)
; READ PB2
; RETURN:
; r24 = 1 -> HIGH
; r24 = 0 -> LOW
; =====================================================

LDR2_DigitalRead:

    in   r24, PINB        ; baca PORTB

    sbrs r24, 2           ; skip jika bit PB2 = 1
    rjmp LDR2_LOW

LDR2_HIGH:
    ldi  r24, 1
    ret

LDR2_LOW:
    ldi  r24, 0
    ret