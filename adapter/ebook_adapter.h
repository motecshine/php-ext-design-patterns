#ifndef EBOOK_ADAPTER_H
#define EBOOK_ADAPTER_H
PHP_METHOD(ebook_adapter, construct);
PHP_METHOD(ebook_adapter, open);
PHP_METHOD(ebook_adapter, turnPage);
PHP_METHOD(ebook_adapter, getPage);
PHP_DESIGN_STARTUP_FUNCTION(ebook_adapter);
#endif
