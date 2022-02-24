#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

// Shamelessly copied a lot from
// https://github.com/embeddedartistry/embedded-resources/blob/master/examples/c/circular_buffer/circular_buffer.h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// struct not directly accessed by user
typedef struct ringbuf_t ringbuf_t;

// Handle type, what user will use to work with a ringbuf
typedef ringbuf_t* ringbuf_handle_t;

// create a buffer of size bytes len, retrun handle
ringbuf_handle_t ringbuf_init(size_t buffersize);

// free data buffer and struct (aka destroy)
void ringbuf_free(ringbuf_handle_t me);

// reset all pointers, keep allocated memory
void ringbuf_reset(ringbuf_handle_t me);

// put a char in ring if still space left, return 0 on success, -1 on fail i.e. ring full
int ringbuf_put(ringbuf_handle_t me, uint8_t c);

// get a char from ring, if available, return 0 on success, -1 on fail, i.e. ring empty
int ringbuf_get(ringbuf_handle_t me, uint8_t c);

// get number of available bytes currently in ring
size_t ringbuf_size(ringbuf_handle_t me);

#endif // RING_BUFFER_H_