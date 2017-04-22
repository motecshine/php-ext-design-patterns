#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
<<<<<<< HEAD
=======
#include "php_ini.h"
>>>>>>> 81cfa56efaa7d57f0d48b0a75a2906fd6759a448

/* include global headers*/
#include "php_design_patterns.h"
#include "abstract_factory/abstract_factory.h"

zend_class_entry *simple_abstract_factory_ce;
PHP_METHOD(abstract_factory, CreateButton)
{
        printf("hello\n");
}
zend_function_entry abstract_factory_methods[] = {
    PHP_ME(abstract_factory, CreateButton, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

PHP_DESIGN_STARTUP_FUNCTION(abstract_factory)
{
    zend_class_entry abstract_factory_container_ce;
    INIT_CLASS_ENTRY(abstract_factory_container_ce, "PHPDesign\\AbstractFactory", abstract_factory_methods);
    simple_abstract_factory_ce  = zend_register_internal_class_ex(&abstract_factory_container_ce, abstract_factory_ce);
    simple_abstract_factory_ce->ce_flags |= ZEND_ACC_INTERFACE;
    return SUCCESS;
}

