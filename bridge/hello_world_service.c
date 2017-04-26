#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "bridge/service.h"
#include "bridge/hello_world_service.h"

PHP_METHOD(hello_world_service, get)
{
    zval *object;
    zval function_name;
    zval hello_world_string;
    /* set function name*/
    ZVAL_STRING(&function_name, "format");
    /* set param string */
    ZVAL_STRING(&hello_world_string, "Hello World");

    /* read $this->implementation */
    hello_world_service_ce = Z_OBJCE_P(getThis());
    object = zend_read_property(hello_world_service_ce, getThis(), ZEND_STRL("implementation"), 0, 0 TSRMLS_CC);
    call_user_function(CG(function_table), object, &function_name ,return_value, 1, &hello_world_string TSRMLS_CC);
    zval_dtor(&function_name);
    zval_ptr_dtor(return_value);
    zval_dtor(&hello_world_string);
}

zend_function_entry hello_world_service_methods[] = {
    PHP_ME(hello_world_service, get, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(hello_world_service)
{
    zend_class_entry hello_world_service_container_ce;
    zend_string *service_name, *service_name_tolower;
    service_name = strpprintf(0, "PHPDesign\\Service");
    service_name_tolower = zend_string_tolower(service_name);
    INIT_CLASS_ENTRY(hello_world_service_container_ce, "PHPDesign\\HelloWorldService", hello_world_service_methods);
    if ((service_ce = zend_hash_find_ptr(CG(class_table), service_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not extends PHPDesign\\Service class");
        return FAILURE;
    }
    hello_world_service_ce = zend_register_internal_class_ex(&hello_world_service_container_ce, service_ce);
    zend_string_release(service_name);
    zend_string_release(service_name_tolower);
    return SUCCESS;
}
