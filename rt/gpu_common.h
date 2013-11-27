/* -*- c++ -*-
  Code that gets included in both the CPU and GPU code. This is mostly
  basic data structures.
 */

#pragma once

typedef unsigned int region_ptr;

// We use our own bool type because OpenCL doesn't let you pass bools
// between host and kernel code.
typedef int bool_t;

// This is mostly opaque to the GPU.
struct region_ {
    unsigned int magic;

    // Size of this header + the stuff
    unsigned int size;

    // This is the next thing to allocate
    region_ptr alloc_ptr;

    // This is actually a cl_mem
    void *cl_buffer;

};

typedef struct region_ region;

// Extract the tag from an ADT
#define extract_tag(x) ((x).tag)


#define harlan_sqrt(x) (sqrt(((float)(x))))
