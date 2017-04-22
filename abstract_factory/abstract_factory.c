#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "abstract_factory/abstract_factory.h"

PHP_METHOD(abstract_factory, CreateButton){}
PHP_METHOD(abstract_factory, CreateBorder){}

zend_function_entry abstract_factory_methods[] = {
    PHP_ME(abstract_factory, CreateButton, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_INTERFACE)
    PHP_ME(abstract_factory, CreateBorder, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_INTERFACE)
    {NULL, NULL, NULL}
};

PHP_DESIGN_STARTUP_FUNCTION(abstract_factory)
{
    zend_class_entry abstract_factory_container_ce;
    INIT_CLASS_ENTRY(abstract_factory_container_ce, "PHPDesign\\AbstractFactory", abstract_factory_methods);
    abstract_factory_ce  = zend_register_internal_class_ex(&abstract_factory_container_ce, abstract_factory_ce);
    abstract_factory_ce->ce_flags |= ZEND_ACC_INTERFACE;
    return SUCCESS;
}

