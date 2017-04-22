#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H
zend_class_entry *abstract_factory_ce;
PHP_METHOD(abstract_factory, CreateButton);
PHP_METHOD(abstract_factory, CreateBorder);
PHP_DESIGN_STARTUP_FUNCTION(abstract_factory);
#endif
