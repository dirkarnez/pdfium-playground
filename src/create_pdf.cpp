#include <fpdfview.h>
#include <fpdf_edit.h>
#include <cstring>

void AddMultilineTextToPdf(const char* filename, const char* text) {
  // Create a new PDF document
  FPDF_DOCUMENT document = FPDF_CreateNewDocument();
  if (!document) {
    printf("Failed to create new PDF document\n");
    return;
  }

  // Add a new page to the document
  FPDF_PAGE page = FPDFPage_New(document, 0, 595, 842);
  if (!page) {
    printf("Failed to create new PDF page\n");
    FPDF_CloseDocument(document);
    return;
  }

  // Add a new text object to the page
  FPDF_PAGEOBJECT text_object = FPDFPageObj_NewTextObj(document);
  if (!text_object) {
    printf("Failed to create new text object\n");
    FPDF_ClosePage(page);
    FPDF_CloseDocument(document);
    return;
  }

  // Set the text object's font and size
  FPDF_Font font = FPDF_GetFont(document, "Arial", nullptr);
  FPDFText_SetFont(text_object, font, 12);

  // Set the text object's text
  FPDFText_SetText(text_object, text);

  // Set the text object's position and dimensions
  FPDF_Rect rect = {100.0, 100.0, 400.0, 600.0};
  FPDFPageObj_SetRect(text_object, &rect);

  // Add the text object to the page
  FPDFPage_InsertObject(page, text_object);

  // Save the document to file
  FPDF_SaveAsCopy(document, filename, FPDF_NO_INCREMENTAL);

  // Clean up
  FPDF_ClosePage(page);
  FPDF_CloseDocument(document);

  printf("PDF saved to %s\n", filename);
}
