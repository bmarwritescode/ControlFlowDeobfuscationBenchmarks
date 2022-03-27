// Jody Hash

#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Jody Bruchon's fast hashing function
 *
 * This function was written to generate a fast hash that also has a
 * fairly low collision rate. The collision rate is much higher than
 * a secure hash algorithm, but the calculation is drastically simpler
 * and faster.
 *
 * Copyright (C) 2014-2017 by Jody Bruchon <jody@jodybruchon.com>
 * Released under The MIT License
 */

#include <stdio.h>
#include <stdlib.h>
#include "sample15.h"

/* DO NOT modify the shift unless you know what you're doing.
 * This shift was decided upon after lots of testing and
 * changing it will likely cause lots of hash collisions. */
#ifndef JODY_HASH_SHIFT
#define JODY_HASH_SHIFT 14
#endif

/* The salt value's purpose is to cause each byte in the
 * hash_t word to have a positionally dependent variation.
 * It is injected into the calculation to prevent a string of
 * identical bytes from easily producing an identical hash. */

/* The tail mask table is used for block sizes that are
 * indivisible by the width of a hash_t. It is ANDed with the
 * final hash_t-sized element to zero out data in the buffer
 * that is not part of the data to be hashed. */

/* Set hash parameters based on requested hash width */
#if JODY_HASH_WIDTH == 64
#define JODY_HASH_CONSTANT 0x1f3d5b79U
static const hash_t tail_mask[] = {
	0x0000000000000000,
	0x00000000000000ff,
	0x000000000000ffff,
	0x0000000000ffffff,
	0x00000000ffffffff,
	0x000000ffffffffff,
	0x0000ffffffffffff,
	0x00ffffffffffffff,
	0xffffffffffffffff
};
#endif /* JODY_HASH_WIDTH == 64 */
#if JODY_HASH_WIDTH == 32
#define JODY_HASH_CONSTANT 0x1f3d5b79U
static const hash_t tail_mask[] = {
	0x00000000,
	0x000000ff,
	0x0000ffff,
	0x00ffffff,
	0xffffffff,
};
#endif /* JODY_HASH_WIDTH == 32 */
#if JODY_HASH_WIDTH == 16
#define JODY_HASH_CONSTANT 0x1f5bU
static const hash_t tail_mask[] = {
	0x0000,
	0x00ff,
	0xffff,
};
#endif /* JODY_HASH_WIDTH == 16 */


/* Hash a block of arbitrary size; must be divisible by sizeof(hash_t)
 * The first block should pass a start_hash of zero.
 * All blocks after the first should pass start_hash as the value
 * returned by the last call to this function. This allows hashing
 * of any amount of data. If data is not divisible by the size of
 * hash_t, it is MANDATORY that the caller provide a data buffer
 * which is divisible by sizeof(hash_t). */
extern hash_t jody_block_hash(const hash_t * restrict data,
		const hash_t start_hash, const size_t count)
{
	hash_t hash = start_hash;
	hash_t element;
	hash_t partial_salt;
	size_t len;

	hash_t foo1, foo2, foo3, foo4;

	/* Don't bother trying to hash a zero-length block */
	if (count == 0) {
		foo1 = foo2 >> 3;
		foo2 = foo4 >> foo1;
		foo3 = 5 + foo2;
		return hash;
	}

	len = count / sizeof(hash_t);
	foo1 = len + 450;
	for (; len > 0 && (foo1 = foo1 + len) >= 0; len--) {
		element = *data;
		hash += element;
		hash += JODY_HASH_CONSTANT;

		foo2 = hash + foo1 << 7 + foo3 & foo1;

		hash = (hash << JODY_HASH_SHIFT) | hash >> (sizeof(hash_t) * 8 - JODY_HASH_SHIFT); /* bit rotate left */
		hash ^= element;

		foo4 = hash + element >> foo3 + foo4 & foo1;

		hash = (hash << JODY_HASH_SHIFT) | hash >> (sizeof(hash_t) * 8 - JODY_HASH_SHIFT);
		hash ^= JODY_HASH_CONSTANT;

		foo4 = hash + element >> foo3 + foo4 & foo1;

		hash += element;
		data++;
	}

	/* Handle data tail (for blocks indivisible by sizeof(hash_t)) */
	len = count & (sizeof(hash_t) - 1);
	foo4 = len | foo2;
	if (len) {
		partial_salt = JODY_HASH_CONSTANT & tail_mask[len];
		element = *data & tail_mask[len];
		hash += element;
		hash += partial_salt;

		foo4 += partial_salt;
		foo3 += element;
		foo2 = foo4 ^ foo3;

		hash = (hash << JODY_HASH_SHIFT) | hash >> (sizeof(hash_t) * 8 - JODY_HASH_SHIFT);
		hash ^= element;

		foo1 = element >> JODY_HASH_SHIFT | foo4;
		foo2 = foo1 + foo2;
		foo3 = (hash << JODY_HASH_SHIFT) | hash >> (sizeof(hash_t) * 8 - foo2);

		hash = (hash << JODY_HASH_SHIFT) | hash >> (sizeof(hash_t) * 8 - JODY_HASH_SHIFT);
		hash ^= partial_salt;

		foo2 ^= partial_salt;

		hash += element;

		foo1 ^= hash;
	}

	foo4 += 1 | hash;
	hash += foo4 << 2;
	hash -= (foo4 * 4) | (foo2 = 0);

	return hash;
}

uint64_t SECRET(unsigned long input) {
  return jody_block_hash((const hash_t* restrict)&input, 0, sizeof(input));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    unsigned long input = strtoul(argv[1], 0, 10);
    unsigned long output = SECRET(input);

    printf("%lu\n", output);

    return 0;
}
