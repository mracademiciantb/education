// image_processor.c
#include "image_processor.h"
#include <stdio.h>
#include <jpeglib.h>
#include <stdlib.h>

void open_jpeg(char *filename, char *dataPath) {
    char fullPath[1024];
    snprintf(fullPath, sizeof(fullPath), "%s/%s", dataPath, filename);
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    JSAMPARRAY pJpegBuffer;
    
    int row_stride;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", filename);
        return;
    }
   
   cinfo.err = jpeg_std_error(&jerr);
   jpeg_create_decompress(&cinfo);
   jpeg_stdio_src(&cinfo, infile);
   (void) jpeg_read_header(&cinfo, TRUE);
   (void) jpeg_start_decompress(&cinfo);

   row_stride = cinfo.output_width * cinfo.output_components;
   pJpegBuffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    while (cinfo.output_scanline < cinfo.output_height) {
        (void) jpeg_read_scanlines(&cinfo, pJpegBuffer, 1);
        //!! Here you can process each line from the pJpegBuffer
    }
    (void) jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
}