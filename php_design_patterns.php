<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('php_design_patterns')) {
	dl('php_design_patterns.' . PHP_SHLIB_SUFFIX);
}
use PHPDesign\MacFactory;
$macObj = new MacFactory();
var_dump($macObj->CreateButton());
?>
