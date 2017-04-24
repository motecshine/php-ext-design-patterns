#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/book_interface.h"
#include "adapter/ebook_adapter.h"

ZEND_BEGIN_ARG_INFO(ebook_adapter_arg_info, 0)
    ZEND_ARG_INFO(0, ebook_object)
ZEND_END_ARG_INFO()

zend_class_entry *ebook_adapter_ce;

PHP_METHOD(ebook_adapter, __construct)
{
    zval * object;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(object)
    ZEND_PARSE_PARAMETERS_END();

    ebook_adapter_ce = Z_OBJCE_P(getThis());
    zend_update_property(ebook_adapter_ce, getThis(), ZEND_STRL("ebook"), object);
}

PHP_METHOD(ebook_adapter, open)
{
    zval *object, *retval_ptr;
    zval function_name;
    ZVAL_STRING(&function_name, "unlock");
    ebook_adapter_ce = Z_OBJCE_P(getThis());
    object = zend_read_property(ebook_adapter_ce, getThis(), ZEND_STRL("ebook"), 0, 0 TSRMLS_CC);
    call_user_function(CG(function_table), object, &function_name, retval_ptr, 0, NULL TSRMLS_CC);
    zval_ptr_dtor(retval_ptr);
    zval_dtor(&function_name);
}

PHP_METHOD(ebook_adapter, turnPage)
{
    zval *object, *retval_ptr;
    zval function_name;
    ZVAL_STRING(&function_name, "pressNext");
    ebook_adapter_ce = Z_OBJCE_P(getThis());
    object = zend_read_property(ebook_adapter_ce, getThis(), ZEND_STRL("ebook"), 0, 0 TSRMLS_CC);
    call_user_function(CG(function_table), object, &function_name, retval_ptr, 0, NULL TSRMLS_CC);
    zval_ptr_dtor(retval_ptr);
}

PHP_METHOD(ebook_adapter, getPage)
{

    zval *object, *retval_ptr;
    zval function_name;
    ZVAL_STRING(&function_name, "getPage");
    ebook_adapter_ce = Z_OBJCE_P(getThis());
    object = zend_read_property(ebook_adapter_ce, getThis(), ZEND_STRL("ebook"), 0, 0 TSRMLS_CC);
    call_user_function(CG(function_table), object, &function_name, retval_ptr, 0, NULL TSRMLS_CC);
    zval_ptr_dtor(retval_ptr);
}

static zend_function_entry ebook_adapter_methods[] = {
    PHP_ME(ebook_adapter, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(ebook_adapter, open,        NULL, ZEND_ACC_PUBLIC)
    PHP_ME(ebook_adapter, turnPage,    NULL, ZEND_ACC_PUBLIC)
    PHP_ME(ebook_adapter, getPage,     NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(ebook_adapter)
{
    zend_string *book_interface_name;
    zend_class_entry ebook_adapter_container_ce;
    zval *object;
    book_interface_name = strpprintf(0, "PHPDesign\\BookInterface");

    INIT_CLASS_ENTRY(ebook_adapter_container_ce, "PHPDesign\\EBookAdapter", ebook_adapter_methods);
    ebook_adapter_ce = zend_register_internal_class(&ebook_adapter_container_ce TSRMLS_CC);
    if ((book_interface_ce = zend_hash_find_ptr(CG(class_table), zend_string_tolower(book_interface_name))) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement book_interface");
        return FAILURE;
    }

    zend_class_implements(ebook_adapter_ce TSRMLS_CC, 1, book_interface_ce);
    zend_string_release(book_interface_name);
    zend_declare_property(ebook_adapter_ce, ZEND_STRL("ebook"), object, ZEND_ACC_PUBLIC);
    return SUCCESS;
}
