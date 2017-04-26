#ifndef HTML_FORMATTER_H
#define HTML_FORMATTER_H
zend_class_entry *html_formatter_ce;
PHP_METHOD(html_formatter, format);
PHP_DESIGN_STARTUP_FUNCTION(html_formatter);
#endif
