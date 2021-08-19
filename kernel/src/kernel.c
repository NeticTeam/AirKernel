/*
* Filename: kernel.c
* Author: corruptmemory (zmemory)
* Description: Kernel main file
*/

#include <memory/heap.h>
#include <video/gop.h>
#include <hardware/IO.h>
#include <debug/panic.h>
#include <hardware/pci.h>
#include <stdbool.h>
typedef struct{
  	int height;
  	int width;
    uint64_t kernelEnd;
} kernelData;

void _initkernel(Framebuffer* framebuffer, PSF1_FONT* psf1_font, kernelData KernelInfo){
    CursorPosition.X = 10; /* Set default cursor position */
    CursorPosition.Y = 10;
    Print(framebuffer,psf1_font, 0xFFFFFF, "AirKernel 0.2-indev_beta");
    newline();
    newline();
    kprint("[heap] Initializing heap...", 0xFFFFFF);
    newline();
    kprint("[heap] kernelEnd: 0x", 0xFFFFFF);
    kprint(to_hstring64(KernelInfo.kernelEnd), 0xFFFFFF);
    newline();
    mm_init(KernelInfo.kernelEnd);
    pci_init();
    kprint("Loaded.", 0xFFFFFF);
}


void _start(Framebuffer* framebuffer, PSF1_FONT* psf1_font, kernelData KernelInfo){
    _initkernel(framebuffer, psf1_font, KernelInfo);
    while(1);
}
