#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	uint8_t bits;
	uint32_t speed;
	uint8_t mode;
	uint16_t delay;
}tConnection;