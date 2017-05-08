#ifndef  KINDLE_H
#define  KINDLE_H
extern zend_class_entry *kindle_ce;
PHP_METHOD(kindle, pressNext);
PHP_METHOD(kindle, unlock);
PHP_METHOD(kindle, getPage);
PHP_DESIGN_STARTUP_FUNCTION(kindle);
#endif
