#ifndef LINUX_OS_H
#define LINUX_OS_H
zend_class_entry *linux_os_ce;
PHP_METHOD(linux_os, halt);
PHP_METHOD(linux_os, getName);
PHP_DESIGN_STARTUP_FUNCTION(linux_os);
#endif
