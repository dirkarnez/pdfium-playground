pdfium-playground
=================
Based on [ikuokuo/pdfium-reader: PDFium Reader](https://github.com/ikuokuo/pdfium-reader)

### Using
- [bblanchon/pdfium-binaries: 📰 Binary distribution of PDFium](https://github.com/bblanchon/pdfium-binaries)

### Compiling pdfium
- [PDFium - Getting Started with PDFium](https://pdfium.googlesource.com/pdfium/+/refs/heads/main/docs/getting-started.md)
  - ```sh
    PDF_LIBS="-lpdfium -lfpdfapi -lfxge -lfpdfdoc -lfxcrt -lfx_agg \
    -lfxcodec -lfx_lpng -lfx_libopenjpeg -lfx_lcms2 -lfx_freetype -ljpeg \
    -lfdrm -lpwl -lbigint -lformfiller -ljavascript -lfxedit"
    PDF_DIR=<path/to/pdfium>

    clang -I $PDF_DIR/public -o init init.c -L $PDF_DIR/out/Debug -lstdc++ -framework AppKit $PDF_LIBS
    ```
### Reference
- [PDFium 渲染 - SegmentFault 思否](https://segmentfault.com/a/1190000041060780)
