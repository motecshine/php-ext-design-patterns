#ifndef PLAIN_TEXT_FORMATTER_H
#define PLAIN_TEXT_FORMATTER_H
static zend_class_entry *plain_text_formatter_ce;
PHP_METHOD(plain_text_formatter, format);
PHP_DESIGN_STARTUP_FUNCTION(plain_text_formatter);
#endif

