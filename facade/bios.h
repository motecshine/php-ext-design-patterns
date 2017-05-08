#ifndef BIOS_H
#define BIOS_H
zend_class_entry *bios_ce;
PHP_METHOD(bios, launch);
PHP_METHOD(bios, execute);
PHP_METHOD(bios, waitForKeyPress);
PHP_DESIGN_STARTUP_FUNCTION(bios);
#endif
