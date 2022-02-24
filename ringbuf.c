#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

// #define NDEBUG // remove comment to not use assertions

#include "ringbuf.h"
// Shamelessly copied a lot from
// https://github.com/embeddedartistry/embedded-resources/blob/master/examples/c/circular_buffer/circular_buffer.c

// The definition is in this file, because users use the handle, not this struct directly
struct ringbuf_t
{
	uint8_t* data;
	size_t write_index;
	size_t read_index;
	size_t max_size; // of the buffer
	bool full;
};

// create a buffer of size bytes len, retrun handle
ringbuf_handle_t ringbuf_init(size_t buffersize) {

    assert( buffersize > 0 );

    int *data; 

    ringbuf_handle_t ringbuf = malloc(sizeof(ringbuf_t));
    assert(ringbuf);

    data = (int *) malloc(buffersize * sizeof(uint8_t));
    assert(data);

    ringbuf->data = data;
    ringbuf->max_size = buffersize;

    ringbuf_reset(ringbuf);

    return ringbuf;
};

// free data buffer and struct (aka destroy)
void ringbuf_free(ringbuf_handle_t me) {

};

// reset all pointers, keep allocated memory
void ringbuf_reset(ringbuf_handle_t me) {

};

// put a char in ring if still space left, return 0 on success, -1 on fail i.e. ring full
int ringbuf_put(ringbuf_handle_t me, uint8_t c) {

};

// get a char from ring, if available, return 0 on success, -1 on fail, i.e. ring empty
int ringbuf_get(ringbuf_handle_t me, uint8_t c) {

};

// get number of available bytes currently in ring
size_t ringbuf_size(ringbuf_handle_t me) {

};


