#ifndef BOOK_H
#define BOOK_H
PHP_METHOD(book, open);
PHP_METHOD(book, turnPage);
PHP_METHOD(book, getPage);
PHP_DESIGN_STARTUP_FUNCTION(book);
#endif
